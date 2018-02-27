#include "PrepareGiBUU.hpp"

#define NUMBERRUNSPERMERGE 1000

PrepareGiBUU::PrepareGiBUU(){
	fInstallDirectory = util::GetEnv("GiBUU_InstallDirectory");
	fInputDirectory = util::GetEnv("GiBUU_InputDirectory");
	fMail = util::GetEnv("user_email");
	
	fInitial_Impact_Parameter  = 0.011;
	GetValues();
	CreateFolders();
	CheckJobCard();	
	PrepareGiBUUScript();
	CreateRunGiBUUScript();
	WriteJobCards();
	CreateMergeScripts();
}

float PrepareGiBUU::Get_Impact_Bin_Size(){
	
	float Nuclear_Radius = 1.4*pow(fTargetA,1/3.0);  	// 1.4 statt 1.2 zur Sicherheit -> Kern wird größer angenommen
	float Nuclear_Radius_Offset = 3.0;					// Wie weit soll über den Kernrand hinaus berechnet werden
	//~ return(Nuclear_Radius + Nuclear_Radius_Offset - fInitial_Impact_Parameter)/fDivisions);
	
	return (Nuclear_Radius + Nuclear_Radius_Offset - 0.0)/fDivisions;  // Testweise zum Vergleich, Formel fehlerhaft !
}

string PrepareGiBUU::ReplaceSubString(string ImpactParameter, int& replaceCounter, string& line){
	string temp;
	int found1=line.find("?{");
	if( found1 == string::npos) return line;
	int found2 = line.find("}");
	if(found2 == string::npos) return line;
	string subs = line.substr(found1+2, found2-found1-2);
	string ret = line.substr(0,found1);
	if(subs == "SEED") ret += to_string(random_value());
	else if(subs == "Impact_Para") ret += ImpactParameter;
	else if(subs == "Target_A") ret += to_string(fTargetA);
	else if(subs == "BUUINPUT") ret += fInputDirectory;
	else{
		ret +=fReplaceStrings[replaceCounter];
		replaceCounter++;
	}
	ret += line.substr(found2+1);
	return ret;
}

void PrepareGiBUU::WriteJobCards(){
	cout << "Creating JobCards" << endl;
	ofstream foutt;
	foutt.open(fPath+"logs/impact_para.log");
	for(int job = 1; job<=fDivisions; job++){
		string ImpactParameter = util::to_string_with_precision(fInitial_Impact_Parameter+(job-1)*Get_Impact_Bin_Size(), 3);
		foutt << job << "\t" << ImpactParameter << endl;;
		for(int run = 1; run<=job*fNumberRuns; run++){
			ofstream fout;
			fout.open(fPath+"job"+util::ZeroPadding(job)+"/run"+util::ZeroPadding(job)+"_"+util::ZeroPadding(run)+"/JobCard"+util::ZeroPadding(job)+"_"+util::ZeroPadding(run));
			if(!fout.is_open()) exit(1);
			int replaceCounter = 0;
			for(string &line : fJobCard){
				fout << ReplaceSubString(ImpactParameter,replaceCounter,line) << endl;
			}
			fout.close();
		}
	}
	foutt.close();
}

void PrepareGiBUU::GetValues(){
	cout << "Enter target directory: ";
	string Target;
	cin >> Target;
	Target = util::FormatInputPath(Target);
	util::CreateDir(Target, 0);
	
	cout << "Enter job name (eg. carbon_2.109): ";
	cin >> fPath;
	if(Target[Target.length()-1] == '/' || fPath[0] == '/') fPath = Target + fPath;
	else fPath = Target + '/' + fPath;
	if (fPath[fPath.length()-1] != '/') fPath+='/';
	
	cout << "Value for impact paramter divisions (eg. 32): ";
	cin >> fDivisions;

	cout << "Value for impact paramter runs (eg. 30): ";
	cin >> fNumberRuns;
	
	cout << "Value for Target_A: ";
	cin >> fTargetA;
}

void PrepareGiBUU::CheckJobCard(){
	string line;
	ifstream fin; fin.open("JobCard");
	if(!fin.is_open()){cout << "JobCard not found" << endl; exit(1);}
	while(getline(fin, line)){
		fJobCard.push_back(line);
	}
	fin.close();
	
	for(string &line : fJobCard){
		int found1 = line.find("?{");
		if(found1 != string::npos ){
			int found2 = line.find("}");
			if(found2 != string::npos ){
				string subs = line.substr(found1+2, found2-found1-2);
				
				if(!(subs == "SEED" || subs == "Impact_Para" || subs == "Target_A" || subs == "BUUINPUT" )){
					cout << "Value for " << subs << ": ";
					string sin;
					cin >> sin;
					fReplaceStrings.push_back(sin);
				}
			}
		}
	}
}

void PrepareGiBUU::CreateFolders(){
	cout << "Creating folders" << endl;
	char dirName[250];
	util::CreateDir(fPath, 1);
	for(int i = 1; i <= fDivisions; i++)
		for( int j = 1; j <= i*fNumberRuns; j++){
			mkdir((fPath + "job" + util::ZeroPadding(i)).c_str(), 0755);
			mkdir((fPath + "job" + util::ZeroPadding(i) + "/run" + util::ZeroPadding(i) + "_" + util::ZeroPadding(j)).c_str(), 0755);
		}
	mkdir((fPath + "logs").c_str(), 0755);
	mkdir((fPath + "merger").c_str(), 0755);
}

void PrepareGiBUU::PrepareGiBUUScript(){
	cout << "Creating Jobscript" << endl;
	ofstream fout;	
	fout.open((fPath+"jobscript.sh").c_str());
		
	fout << "#!/bin/bash" << endl
	     << "#PBS -j oe" << endl
	     << "#PBS -V" << endl
	     << "#PBS -o " << fPath << "logs/run${qJob}.log" << endl
	     << "#PBS -M " << fMail << endl
	     << "#PBS -l nodes=1:ppn=1,walltime=03:00:00 " << endl
	     << "export PATH=${PBS_O_PATH}" << endl
	     << "export PBS_O_WORKDIR=${qDir}/job${qJob}/run${qJob}_$(printf %04d ${PBS_ARRAYID})/" << endl
	     << "cd  ${PBS_O_WORKDIR}" << endl
	     << "echo ${PBS_O_WORKDIR}" << endl
	     << fInstallDirectory << "/GiBUU.x < JobCard${qJob}_$(printf %04d ${PBS_ARRAYID}) > out.dat" << endl;
	
	fout.close();
	chmod((fPath+"jobscript.sh").c_str(), S_IRWXU);
}

void PrepareGiBUU::CreateRunGiBUUScript(){
	cout << "Creating RunGiBUU-Script" << endl;
	ofstream fout;
	fout.open(fPath+"runGiBUU.sh");
	
	fout << "#!/bin/bash" << endl
	     << endl 
	     << "user=$USER" << endl 
	     << "Directory=" << fPath << endl 
	     << "MaxQueueSize=1700" << endl 
	     << "RunsSend=0" << endl 
	     << "MaxJobs=" << fDivisions << endl
	     << "NumberRuns=" << fNumberRuns << endl
	     << endl 
	     << "for((jobs=1;jobs<=${MaxJobs};jobs++));" << endl 
	     << "do" << endl 
	     << "	for((run=1;run<=${jobs};run++));" << endl 
	     << "	do" << endl 
	     << "		x=$(qstat -t | grep -c ${user})" << endl 
	     << "		while [ ${x} -gt $((${MaxQueueSize} - 60)) ]" << endl 
	     << "		do" << endl 
	     << "			echo \"Still ${x} jobs running: waiting to start new jobs\"" << endl 
	     << "			date" << endl 
	     << "			sleep 1m" << endl 
	     << "			x=$(qstat -t | grep -c ${user})" << endl 
	     << "		done" << endl 
	     << endl 
	     << "		qsub -V -t $(((${run} - 1) * ${NumberRuns} + 1))-$((${run} * ${NumberRuns} + 1)) -N gibuu_${jobs}_${run} -v qJob=\"$(printf %04d ${jobs})\",qDir=\"${Directory}\" jobscript.sh" << endl 
	     << "		for((i=$(((${run} - 1) * ${NumberRuns} + 1));i<=$((${run} * ${NumberRuns} + 1));i++));" << endl 
	     << "		do" << endl
	     << "			Array[$((jobs*(jobs-1)*${NumberRuns}/2 + ${i}))]=0" << endl 
	     << "		done" << endl 
	     << "		RunsSend=$((${RunsSend}+${NumberRuns}))" << endl
	     << "		echo \"Runs sent: ${RunsSend}\"" << endl
	     << "	done" << endl 
	     << "done" << endl 
	     << endl 
	     << "y=$(qstat -t | grep ${user} | grep -c \"gibuu_\")" << endl 
	     << "while [ ${y} -gt 0 ]" << endl 
	     << "		do" << endl 
	     << "			echo \"Still ${y} jobs running: waiting for jobs to end\"" << endl 
	     << "			date" << endl 
	     << "			sleep 1m" << endl 
	     << "			y=$(qstat -t | grep ${user} | grep -c \"gibuu_\")" << endl 
	     << "done" << endl 
	     << "RunsCompleted=0" << endl 
	     << "WhileRuns=0" << endl 
	     << endl 
	     << "while ! [ ${RunsCompleted} -eq $((${MaxJobs}*(${MaxJobs}+1)*${NumberRuns})) ] && [ ${WhileRuns} -lt 3 ]" << endl 
	     << "do" << endl 
	     << "	RunsSend=0" << endl 
	     << endl 
	     << "	for((jobs=1;jobs<=${MaxJobs};jobs++));" << endl 
	     << "	do" << endl 
	     << "		for((run=1;run<=${jobs};run++));" << endl 
	     << "		do" << endl 
	     << "			for((i=1;i<=${NumberRuns};i++));" << endl 
	     << "			do" << endl 
	     << "				runID=$(((${run} - 1)*${NumberRuns} + ${i}))" << endl 
	     << "				x=$(qstat -t | grep -c ${user})" << endl 
	     << "				while [ ${x} -gt $((${MaxQueueSize} - 10)) ]" << endl 
	     << "				do" << endl 
	     << "					echo \"Still ${x} jobs running: waiting to start new jobs\"" << endl 
	     << "					date" << endl 
	     << "					sleep 1m" << endl 
	     << "					x=$(qstat -t | grep -c ${user})" << endl 
	     << "				done" << endl 
	     << "				if [ ${Array[$((${jobs}*(${jobs} - 1)*${NumberRuns}/2 + ${runID}))]} -eq 0 ]" << endl 
	     << "				then" << endl 
	     << "					if [ -e ${Directory}job$(printf %04d ${jobs})/run$(printf %04d ${jobs})_$(printf %04d ${runID})/DoHIA.dat ]" << endl 
	     << "					then" << endl 
	     << "						Array[$((${jobs}*(${jobs} - 1)*${NumberRuns}/2 + ${runID}))]=1" << endl 
	     << "						RunsCompleted=$((${RunsCompleted}+1))" << endl 
	     << "					else" << endl 
	     << "						qsub -V -t ${runID}-${runID} -N gibuu_${jobs} -v qJob=\"$(printf %04d ${jobs})\",qDir=\"${Directory}\" jobscript.sh" << endl 
	     << "						RunsSend=$((${RunsSend}+1))" << endl 
	     << "						echo \"Runs sent: ${RunsSend}\"" << endl
	     << "					fi" << endl 
	     << "				fi" << endl 
	     << "			done" << endl 
	     << "		done" << endl 
	     << "	done" << endl 
	     << "	y=$(qstat -t | grep ${user} | grep -c \"gibuu_\")" << endl 
	     << "	while [ ${y} -gt 0 ]" << endl 
	     << "		do" << endl 
	     << "			echo \"Still ${y} jobs running: waiting for jobs to end\"" << endl 
	     << "			date" << endl 
	     << "			sleep 1m" << endl 
	     << "			y=$(qstat -t | grep ${user} | grep -c \"gibuu_\")" << endl 
	     << "	done" << endl 
	     << "	WhileRuns=$((${WhileRuns}+1))" << endl 
	     << "done" << endl 
	     << endl 
	     << endl 
	     << "if [ ${RunsCompleted} -eq $((${MaxJobs}*(${MaxJobs}+1)*${NumberRuns}/2)) ]" << endl 
	     << "then" << endl 
	     << "	echo Done" << endl 
	     << "else" << endl 
	     << "	echo Failed" << endl 
	     << "fi" << endl; 

	fout.close();
	chmod((fPath+"runGiBUU.sh").c_str(), S_IRWXU);
}

void PrepareGiBUU::CreateMergeScripts(){
	cout << "Creating MergeScripts" << endl;
	ofstream fout;
	
	fout.open(fPath+"runMerger.sh");
	fout << "#!/bin/bash" << endl
	     << "" << endl
	     << "user=$USER" << endl
	     << "Directory=" << fPath << endl
	     << "PDG=" << util::GetExecPath() << "/" << endl
         << "MaxQueueSize=1000" << endl
         << "RunsSend=0" << endl
         << "" << endl
         << "Max_Jobs=" << fDivisions << endl
         << "Divisions=" << fNumberRuns << endl
         << "MaxRuns=" << (int) ceil((fDivisions*(fDivisions+1)/2.0*fNumberRuns)/NUMBERRUNSPERMERGE) << endl
         << "NumberRunsPerJob="<< NUMBERRUNSPERMERGE << endl
         << "" << endl
         << "" << endl
         << "MergeArray=$(qsub -V -t 1-${MaxRuns} -N Merger -v qDir=\\\"${Directory}\\\",qPathPDG=\\\"${PDG}\\\",qJobMax=\\\"${Max_Jobs}\\\",qRunDiv=\\\"${Divisions}\\\",qNumRuns=\\\"${NumberRunsPerJob}\\\" jobscript_Conversion.sh)" << endl
	     << "qsub -W depend=afterokarray:${MergeArray} -V -N Combine -v  qDir=\\\"${Directory}\\\",qJobIDMax=\\\"${MaxRuns}\\\" jobscript_Combine.sh"<< endl;
	fout.close();
	chmod((fPath+"runMerger.sh").c_str(), S_IRWXU);
	fout.clear();
	
	fout.open(fPath+"jobscript_Conversion.sh");
	fout << "#!/bin/bash" << endl
	     << endl
	     << "#PBS -j oe" << endl
	     << "#PBS -V" << endl
	     << "#PBS -o " << fPath << "logs/Merger.log" << endl
	     << "#PBS -M " << fMail <<endl
	     << "#PBS -l nodes=1:ppn=1,walltime=00:30:00" << endl
	     << endl
	     << "export PATH=${PBS_O_PATH}" << endl
	     << "export PBS_O_WORKDIR=${qDir}/" << endl
	     << "cd  ${PBS_O_WORKDIR}" << endl
	     << util::GetExecPath(true) << " ${qDir} ${qPathPDG} ${qJobMax} ${qRunDiv} ${qNumRuns} ${PBS_ARRAYID} > ${qDir}/merger/Merger$(printf %02d ${PBS_ARRAYID}).out" << endl;
	fout.close();
	chmod((fPath+"jobscript_Conversion.sh").c_str(), S_IRWXU);
	fout.clear();
	
	fout.open(fPath+"jobscript_Combine.sh");
	fout << "#!/bin/bash" << endl
	     << endl
	     << "#PBS -j oe" << endl
	     << "#PBS -V" << endl
	     << "#PBS -o " << fPath << "logs/Combine.log" << endl
	     << "#PBS -M " << fMail <<endl
	     << "#PBS -l nodes=1:ppn=1,walltime=00:30:00" << endl
	     << endl
	     << "export PATH=${PBS_O_PATH}" << endl
	     << "export PBS_O_WORKDIR=${qDir}/" << endl
	     << "cd  ${PBS_O_WORKDIR}" << endl
	     << util::GetExecPath(true) << " ${qDir} ${qJobIDMax} > ${qDir}/merger/Combine.out" << endl;
	fout.close();
	chmod((fPath+"jobscript_Combine.sh").c_str(), S_IRWXU);
}
