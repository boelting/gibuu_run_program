#ifndef GIBUUTRACK_H
#define GIBUUTRACK_H

#include "TMath.h"
#include "TLorentzVector.h"
#include "iostream"
#include <iomanip>

class GiBUUtrack{
	public:
		GiBUUtrack();
		GiBUUtrack(float* var);
		~GiBUUtrack(){}
		
		double GetEnergy();
		TLorentzVector Get4Position();
		TLorentzVector Get4Momentum();
		void Print();
		bool isXiM();
		bool isAP();
				
		int particle_ID;
		int charge;
		
		float mass;
		bool is_free;
		
		float positionX;
		float positionY;
		float positionZ;
		
		float momentumX;
		float momentumY;
		float momentumZ;
		
		int event_number;
		float impact_parameter;
};

#endif
