// ------------------------------------------------------------------------
// -----                     CbmHyppoint header file                  -----
// -----               Created by A.Sanchez                -----
// ------------------------------------------------------------------------

#ifndef THPARTICLE_H
#define THPARTICLE_H

#include "TObject.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TParticle.h"
#include "TString.h"




using namespace std;

class THParticle : public TParticle 
{

 public:

  /** Default constructor **/
  THParticle();
  

  //TParticle(2212,1,0,0,0,0,fP,fV);
  
  THParticle(Int_t pdg,  Int_t status,
	     Double_t index, const TLorentzVector &p,
            const TLorentzVector &v);
  
  /** Copy constructor **/
  THParticle(const THParticle& point) { *this = point; };
  

  /** Destructor **/
  virtual ~THParticle();
  

  /** Accessors **/
  Int_t GetPdgCode()  const { return fpdgCode; }; 
 
  Double_t    GetIndex()    const { return fIndex; };
  
  
 

  Double_t Vx()         const { return fVx; };
  Double_t Vy()         const { return fVy; };
  Double_t Vz()         const { return fVz; };
  
 
  
  /** Modifiers **/
  
 
   void SetIndex(Double_t id)          { fIndex    = id; };

   
   
  /** Output to screen **/
  virtual void Print(const Option_t* opt) const;


 protected:
  Double_t fIndex; 
 
  Int_t fstatus,fpdgCode;              // PDG code of the particle
 

  Double_t fVx,fVy,fVz;
  
  
 
  
  
  ClassDef(THParticle,2)

};



#endif
