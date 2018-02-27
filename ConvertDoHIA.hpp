#ifndef CONVERTDOHIA_H
#define CONVERTDOHIA_H

#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <tuple>
#include <algorithm>

#include "THParticle.hpp"
#include "GiBUUtrack.hpp" 
#include "Utility.hpp"

class ConvertDoHIA{
	public:
		// Default constructor. Not used.
		ConvertDoHIA(){}
		// Constructor. Initialize class: copy input to class members. Read all relevant files and convert to THParticle. Stores Data in TFile->TTree
		// path: folder where simulation was executed; pathpdg: folder where PDG.csv is stored; job_max: number of jobs simulated; run_div: number of runs in job1
		// number_runs: how many runs shall this skript convert; jobID: start with the number_runs*jobID-th run 
		ConvertDoHIA(string path, string pathpdg, int job_max, int run_div, int number_runs, int jobID, string outpath="no.path");
		// Default Deconstructor: Deletes all objects and frees memory. Writes and closes TFIle 
		~ConvertDoHIA();		
		
	private:
		// Calculates fJob and fRun starting values 
		void FindStart();
		// Reads PDG.csv in location specified in fPathPDG. Stores information in vector<3-tuples> for comparison with GiBUUtracks
		void ReadPDGCodes();
		// Main file routine. Cyles through all necessary files. Calls ReadFile() for read-in
		void ConvertFiles();
		// Read-in of DoHIA.dat. Stores data as vector in GiBUUtrack format and calls WriteToTree()
		void ReadFile(string FileName);
		// Main analysis routine. Converts GiBUUtracks to THParticle ( using GiBUUtoPDGCode() ) and fills fTree
		void WriteToTree();
		// Translates GiBUU particle_id to PDG code 
		int GiBUUtoPDGCode(int GiBUU_Code, int Charge);
		
		
		// Private variables
	
		TFile *fFile;
		TClonesArray *fEventArray;
		TTree *fTree;
				
		int fActiveCount;
		int fJobID;
		int fJob, fRun;
		int fJobMax, fRunDiv, fNumberRuns;
		string fPath;
		string fPathPDG;
		string fOutPath;
		
		std::vector<GiBUUtrack> fTracks;
		std::vector<std::tuple<int, int, int>> fPDGCodes;
		
		int dApG, dApP;
};

#endif
