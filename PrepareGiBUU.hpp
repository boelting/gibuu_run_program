#ifndef PREPAREGIBUU_H
#define PREPAREGIBUU_H

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <stdio.h>

#include "Utility.hpp"

using namespace std;

class PrepareGiBUU{
	public:
		PrepareGiBUU();
		~PrepareGiBUU(){};
				
	private:
		string fPath;
		float fInitial_Impact_Parameter;
		int fDivisions;
		int fNumberRuns, fTargetA;
		vector<string> fJobCard;
		vector<string> fReplaceStrings;
		string fInstallDirectory, fInputDirectory, fMail;
		
		void GetValues();
		void CreateFolders();
		void PrepareGiBUUScript();
		void CreateRunGiBUUScript();
		void CheckJobCard();
		void WriteJobCards();
		void CreateMergeScripts();
		
		float Get_Impact_Bin_Size();
		string ReplaceSubString(string ImpactParameter, int& iCounter, string& line);
		
		static unsigned random_value() {
			static mt19937_64 engine{random_device{}()};
			static uniform_int_distribution<unsigned> distribution{0, 2147483647};
			return distribution(engine);
		}
		
};
#endif
