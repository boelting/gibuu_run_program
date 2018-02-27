/////////////////////////////////////////////////////////////
//
//  PndHypPoint
//
//  Geant point for Hyp detector
//
//
///////////////////////////////////////////////////////////////
#include <fstream>
using std::fstream;
 #include "Riostream.h" 
#include <cmath>
#include "TROOT.h"
#include <iostream>
using std::cout;
using std::endl;

#include "THParticle.hpp"

// -----   Default constructor   -------------------------------------------
THParticle::THParticle() : TParticle() {
  
 
  fstatus =0;
  fIndex =0;
  
 
  fpdgCode = 0;
  fPx = fPy = fPz =fVx = fVy = fVz = 0.;
 
}
// -------------------------------------------------------------------------

// -----   Standard constructor   ------------------------------------------
THParticle::THParticle(Int_t pdg,  Int_t status,
		       Double_t index, 
			 const TLorentzVector &p,
            const TLorentzVector &v)
  : TParticle(pdg, status, 0,0,0,0,p,v)
  {
  
  fstatus = status; 
  fIndex = index; 
 
  fpdgCode = pdg;
  fPx = p.Px();
  fPy = p.Py(); 
  fPz = p.Pz();
  fVx = v.X();
  fVy = v.Y(); 
  fVz = v.Z();
}


// -----   Destructor   ----------------------------------------------------
THParticle::~THParticle() { }
// -------------------------------------------------------------------------

// -----   Public method Print   -------------------------------------------
void THParticle::Print(const Option_t* opt) const {
  cout << "-I- THParticle: HYP fragment for track " << fpdgCode << endl;
  
 
}
// -------------------------------------------------------------------------



ClassImp(THParticle)
