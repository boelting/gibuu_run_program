#include "ConvertDoHIA.hpp"

using namespace std;

ConvertDoHIA::ConvertDoHIA(string path, string pathpdg, int job_max, int run_div, int number_runs, int jobID, string outpath){
	fActiveCount = 0;
	fPath = path;
	fJobID = jobID;
	fJobMax = job_max;
	fRunDiv = run_div;
	fNumberRuns = number_runs;
	fPathPDG=pathpdg;
	
	if(outpath == "no.path") fOutPath = fPath;
	else fOutPath = outpath;
	
	// Debug
	dApG = 0;
	dApP = 0;

	FindStart();
	if(fJob == fJobMax && fRun == fJob*fRunDiv){ cout << "ERROR: JobID exceeds range specified by job_max/run_div/number_runs" << endl; exit(0); }
	   
	fFile 		= new TFile((fOutPath + "/DoHIA" + util::ZeroPadding(jobID) + ".root").c_str(),"RECREATE");
    fEventArray	= new TClonesArray("THParticle", 50);
    fTree		= new TTree("data","hypernuclei");
	   
    fTree->Branch("Npart",&fActiveCount,"Npart/I");
    fTree->Branch("Particles",&fEventArray,32000);
        
    ReadPDGCodes();
    ConvertFiles();
    
    cout << "AP:  GiBUU: " << dApG << "\t PDG: " << dApP << endl; 
}

ConvertDoHIA::~ConvertDoHIA(){
	fFile->Write();
	fFile->Close();
	
	delete fFile; fFile = NULL;
	delete fEventArray; fEventArray = NULL;
}

void ConvertDoHIA::FindStart(){
	int cnt = 0;
	for(fJob=1; fJob<=fJobMax; fJob++){
		for(fRun=1; fRun<=fJob*fRunDiv; fRun++){
			if( cnt < (fJobID-1)*fNumberRuns ) cnt++;
			else return;
		}
	}
	fJob--;
	fRun--;
}

void ConvertDoHIA::ConvertFiles(){
	for(int i=0; i<fNumberRuns; i++){
		if(fJob == fJobMax+1){
			i=fNumberRuns;
		}
		else{
			cout << "Converting File " << fJob << "_" << fRun << " now!" << endl;
			ReadFile(fPath + "job" + util::ZeroPadding(fJob) + "/run" + util::ZeroPadding(fJob) + "_" + util::ZeroPadding(fRun) + "/DoHIA.dat");
			
			if( fRun == fJob*fRunDiv){
				fRun=1;
				fJob++;
			}
			else{
				fRun++;
			}
		}
	}
}

void ConvertDoHIA::ReadFile(string FileName){
	ifstream fin;
	fin.open(FileName); // c++11
	cout << FileName << endl;
	if(!fin.is_open()){ cout << "File not found" << endl; exit(1); }
	
	float var[16];
	GiBUUtrack tmp;
	bool checkIntegrity = false;
	while ((fin >> std::ws) && !(fin.eof())){
		for(int j=0;j<16;j++) fin >> var[j];
		tmp = GiBUUtrack(var);
		if( !checkIntegrity && tmp.event_number > 1 ) checkIntegrity = true;
		if( checkIntegrity && tmp.event_number==1 ) break;
		fTracks.push_back(tmp);
		if(tmp.isAP()) dApG++;
	}
	fin.close();
	WriteToTree();
}

void ConvertDoHIA::WriteToTree(){
	int PDG_Code;
		
	fActiveCount = 0;	
	
	for(int i = 0; i<fTracks.size(); i++){
		PDG_Code = GiBUUtoPDGCode(fTracks[i].particle_ID, fTracks[i].charge);
		if( PDG_Code == -2212 ) dApP++;
		if(fTracks[i].is_free){
			
			
			new((*fEventArray)[fActiveCount++]) THParticle(PDG_Code, 1, fTracks[i].impact_parameter, fTracks[i].Get4Momentum(), fTracks[i].Get4Position());
		}
		
		if( i != 0 && fTracks[i].event_number < fTracks[i-1].event_number ){
			cout << "File is unsorted in " << i << "!" << endl;
			exit(2);
		}
		
		if( i == fTracks.size()-1 || fTracks[i].event_number != fTracks[i+1].event_number){
			if( fActiveCount !=0 ) fTree->Fill();
			fEventArray->Clear();
			fActiveCount = 0;
		}
	}
	fTracks.clear();
}

void ConvertDoHIA::ReadPDGCodes(){
	ifstream fin;
	fin.open(fPathPDG+"PDG.csv"); // c++11
	if(!fin.is_open()){ cout << "File not found" << endl; exit(1); }
	fin.ignore(200,'\n');
	
	int var[3];
	while ((fin >> std::ws) && !(fin.eof())){
		for(int j=0;j<3;j++) fin >> var[j];
		fPDGCodes.push_back(make_tuple(var[0], var[1], var[2]));
	}
	fin.close();	
}

int ConvertDoHIA::GiBUUtoPDGCode(int GiBUU_Code, int Charge){
	int &i = GiBUU_Code;
	int &q = Charge;
	if( i < 0){		
		return -GiBUUtoPDGCode(-i, -q);
	}
	auto lambda = [i, q](const std::tuple<int, int, int> in) -> bool{
		if(get<0>(in) == i && get<1>(in) == q) return true;
		return false; 
	};
	vector<tuple<int, int, int>>::iterator it = find_if(fPDGCodes.begin(), fPDGCodes.end(), lambda);
	return get<2>(*it);
}
