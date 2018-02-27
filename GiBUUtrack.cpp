#include "GiBUUtrack.hpp"

using namespace std;

GiBUUtrack::GiBUUtrack(){
	particle_ID		= 0;
	charge			= 0;
	mass			= 0.0;
	is_free			= false;
	positionX		= 0.0;
	positionY		= 0.0;
	positionZ		= 0.0;
	momentumX		= 0.0;
	momentumY		= 0.0;
	momentumZ		= 0.0;
	event_number	= 0;
	impact_parameter= 0.0;
}

GiBUUtrack::GiBUUtrack(float* var){
	particle_ID		= (int) var[0];
	charge			= (int) var[1];
	mass			= 		var[5];
	is_free			= 	   ((int) var[6] == 1)? true: false;
	positionX		= 		var[7];
	positionY		= 		var[8];
	positionZ		= 		var[9];
	momentumX		= 		var[10];
	momentumY		= 		var[11];
	momentumZ		= 		var[12];
	event_number	= (int) var[13];
	impact_parameter= 		var[15];
}

double GiBUUtrack::GetEnergy(){
	return TMath::Sqrt( TMath::Power(mass,2)  +  TMath::Power(TMath::Sqrt( TMath::Power(momentumX,2) + TMath::Power(momentumY,2) + TMath::Power(momentumZ,2) ),2) );
}

TLorentzVector GiBUUtrack::Get4Position(){
	return TLorentzVector(positionX, positionY, positionZ, 0.0);
}

TLorentzVector GiBUUtrack::Get4Momentum(){
	return TLorentzVector(momentumX, momentumY, momentumZ, GetEnergy());
}

void GiBUUtrack::Print(){
	cout << "\t" <<  particle_ID << "\t" << charge << "\t" << mass << "\t" << is_free << "\t" << fixed << setw(8) << setprecision( 3 ) 
          << setfill( ' ' ) << positionX << "\t" <<fixed << setw(8) << setprecision( 3 ) 
          << setfill( ' ' ) << positionY << "\t" <<fixed << setw(8) << setprecision( 3 ) 
          << setfill( ' ' ) << positionZ << "\t" <<fixed << setw(8) << setprecision( 3 ) 
          << setfill( ' ' ) << momentumX << "\t" <<fixed << setw(8) << setprecision( 3 ) 
          << setfill( ' ' ) << momentumY << "\t" <<fixed << setw(8) << setprecision( 3 ) 
          << setfill( ' ' ) << momentumZ  << "\t" << event_number  << "\t" <<fixed << setw(8) << setprecision( 3 ) 
          << setfill( ' ' ) << impact_parameter << endl;  
}

bool GiBUUtrack::isXiM(){
	if( particle_ID == 53 && charge == -1) return true;
	else return false;
}

bool GiBUUtrack::isAP(){
	if( particle_ID == -1 && charge == -1) return true;
	else return false;
}

