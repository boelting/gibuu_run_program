#include <iostream>
#include <string>

#include "TRint.h"
#include "TChain.h"

#include "Utility.hpp"
#include "THParticle.hpp"
#include "ConvertDoHIA.hpp"
#include "GiBUUtrack.hpp"
#include "PrepareGiBUU.hpp"

void MergeRootFiles(string path, int max_jobs){
	TChain chain("data");  // Read TTree structure called "data"

	// loop over all files
	for(int jobID=1; jobID <=max_jobs; jobID++){
			chain.Add(( path + "/DoHIA" + util::ZeroPadding(jobID) + ".root" ).c_str() );
			cout << "Processing file " << jobID << endl;
	}
	
	// Write combined data chain to new root file
	cout << "Writing merged root file " << endl;
	chain.Merge((path+"DoHIA_merged.root").c_str());
	
	cout << "DONE!";
}

int main(int argc, char* argv[]){
	if(argc == 1){
		cout << "Please give Operation mode" << endl
		     << "(C)onvertDoHIA to rootfiles, (M)ergeRootFiles or (P)repare GiBUU run." << endl;
			char in;
		cin >> in;
		if(in == 'C' || in =='c'){
			string path, pathPDG;
			int job_max, run_div, number_runs, jobID;
			cout << "Path to data: ";
			cin >> path;
			cout << endl << "Path to PDG table: ";
			cin >> pathPDG;
			cout << endl << "Max number of Jobs: ";
			cin >> job_max;
			cout << endl << "Number of Divisions per Run: ";
			cin >> run_div;
			cout << endl << "Number of Runs: ";
			cin >> number_runs;
			cout << endl << "jobID: ";
			cin >> jobID;
			cout << endl;			
			
			TRint *gROOT = new TRint("GiBUU_to_PDG ", &argc, argv, 0, 0, true);
						
			path = util::FormatInputPath(path);
			pathPDG = util::FormatInputPath(pathPDG);
			
			ConvertDoHIA Converter = ConvertDoHIA(path, pathPDG, job_max, run_div, number_runs, jobID);
			return 1;
		}
		
		else if(in == 'M' || in == 'm'){
			string path;
			int max_jobs;
			cout << "Path: ";
			cin >> path;
			cout << endl << "Maximum Number of Jobs :";
			cin >> max_jobs;
			
			path = util::FormatInputPath(path);
			MergeRootFiles(path, max_jobs);
			return 1;
		}
		
		else if(in == 'P' || in == 'p'){
			PrepareGiBUU a;
			return 1;
		}
		
		else{
			cout << "No Valid input" << endl;
			return 1;
		}
	}
	
	else if(argc == 3){
		string path = (string) argv[1];
		int max_jobs = stoi(((string) argv[2]));
		path = util::FormatInputPath(path);
		MergeRootFiles(path, max_jobs);
		return 1;
	}

	
	else if(argc == 7 || argc == 8){
		string path = (string) argv[1];
		string pathPDG = (string) argv[2];
		int job_max = stoi(((string) argv[3])); // c++11
		int run_div = stoi(((string) argv[4])); // c++11
		int number_runs = stoi(((string) argv[5])); // c++11
		int jobID = stoi(((string) argv[6])); // c++11
		string outpath = "no.path";
		if( argc == 8 ){
			outpath = (string) argv[7];
			outpath = util::FormatInputPath(outpath);
		}
		
		TRint *gROOT = new TRint("GiBUU_to_PDG ", &argc, argv, 0, 0, true);
		path = util::FormatInputPath(path);
		pathPDG = util::FormatInputPath(pathPDG);
		
		ConvertDoHIA Converter = ConvertDoHIA(path, pathPDG, job_max, run_div, number_runs, jobID, outpath);
		return 1;
	}
	
	else{
		cout << "Invalid number of arguments." << endl
		     << "Requires no argument for interactive Mode or" << endl
		     << "- 2 arguments (path to root files, max_jobs) for merging of root files" << endl
		     << "- 6 arguments (path_data, path_pdg_table, job_max, run_div, number_runs, jobID) to convert DoHIA to root" << endl;
		return 1;
	}
}
