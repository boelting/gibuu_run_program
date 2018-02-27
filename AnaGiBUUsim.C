// C++ Program to analyze the output of GiBUU simulations
// by Sebastian Bleser
// gives uniform distributions of particles

#include <iostream>
#include "TString.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TStopwatch.h"
#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TParticle.h"
//#include "THParticle.h"
//#include "../hyp/THParticle.h"
#include "THParticle.hpp"
#include "TLorentzVector.h"
#include "TVector3.h"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "TMath.h"
#include "TH1.h"
#include "TH2.h"


using namespace std;
using std::ifstream;


int main(int argc, char *argv[]) {
	
	TString path_in = (TString) argv[1];
	TString path_out = (TString) argv[2];

	// ----  Input ----
	TString stringbuffer_in = path_in;

	// ---- Output ----
	TString stringbuffer_out = path_out;
	cout << "ROOT output file path: " << stringbuffer_out << endl << endl;
	
	// ----- Load libraries ---------------------------------------------------

	gROOT->Macro("$VMCWORKDIR/gconfig/rootlogon.C");
	gSystem->Load("librazhyp");
	gSystem->Load("libHyp");

	// ----- Timer ------------------------------------------------------------

	TStopwatch timer;
	timer.Start();


	// ------------------------------------------------------------------------

	TFile *f = new TFile(stringbuffer_in, "OPEN");  // the sim output file to analyze
	TTree *t = (TTree *) f->Get("data");

	TClonesArray *Particles_array = new TClonesArray("THParticle");
	t->SetBranchAddress("Particles", &Particles_array);  // branch name

	TFile *out = TFile::Open(stringbuffer_out, "RECREATE"); // ROOT output of this analysis


	// ----- Histograms (87+1//) ------------------------------------------------

	TH1D *hisMultiplicity = new TH1D("hisMultiplicity", "Multiplicity of particles", 40, 0., 40.);
	TH1D *hisPDGCodesForMultiplicity1 = new TH1D("hisPDGCodesForMultiplicity1", "PDG codes for multiplicity of particles = 1", 7000, -3500, 3500);
	TH1D *hisPDGCodesForMultiplicity2 = new TH1D("hisPDGCodesForMultiplicity2", "PDG codes for multiplicity of particles = 2", 7000, -3500, 3500);
	TH1D *hisPDGCodesForMultiplicity3 = new TH1D("hisPDGCodesForMultiplicity3", "PDG codes for multiplicity of particles = 3", 7000, -3500, 3500);
	TH1D *hisPDGCodesForMultiplicity4 = new TH1D("hisPDGCodesForMultiplicity4", "PDG codes for multiplicity of particles = 4", 7000, -3500, 3500);
	TH1D *hisMultiplicityOfAntiprotonsInEvent = new TH1D("hisMultiplicityOfAntiprotonsInEvent", "Multiplicity of Antiprotons", 40, 0., 40.);
	TH1D *hisMultiplicityWhenAntiprotonsInEvent = new TH1D("hisMultiplicityWhenAntiprotonsInEvent", "Multiplicity of particles in events with Antiprotons", 40, 0., 40.);

	TH1D *hisXimImpactparDistr;
	TH1D *hisXimbarImpactparDistr;
	TH1D *hisXimXimbarPairsImpactparDistr;
	TH1D *hisXi0barImpactparDistr;
	TH1D *hisXimXi0barPairsImpactparDistr;
	TH1D *hisXi0ImpactparDistr;
	TH1D *hisXi0Xi0barPairsImpactparDistr;
	hisXimImpactparDistr = new TH1D("hisXimImpactparDistr", "Impact parameter distribution of #Xi^{-}", 33, 0., 6.27);
	hisXimbarImpactparDistr = new TH1D("hisXimbarImpactparDistr", "Impact parameter distribution of Anti-#Xi^{-}", 33, 0., 6.27);
	hisXimXimbarPairsImpactparDistr = new TH1D("hisXimXimbarPairsImpactparDistr", "Impact parameter distribution of #Xi^{-} Anti-#Xi^{-} pairs", 33, 0., 6.27);
	hisXi0barImpactparDistr = new TH1D("hisXi0barImpactparDistr", "Impact parameter distribution of Anti-#Xi^{0}", 33, 0., 6.27);
	hisXimXi0barPairsImpactparDistr = new TH1D("hisXimXi0barPairsImpactparDistr", "Impact parameter distribution of #Xi^{-} Anti-#Xi^{0} pairs", 33, 0., 6.27);
	hisXi0ImpactparDistr = new TH1D("hisXi0ImpactparDistr", "Impact parameter distribution of #Xi^{0}", 33, 0., 6.27);
	hisXi0Xi0barPairsImpactparDistr = new TH1D("hisXi0Xi0barPairsImpactparDistr", "Impact parameter distribution of #Xi^{0} Anti-#Xi^{0} pairs", 33, 0., 6.27);
	
	TH1D *hisXiMomDistr = new TH1D("hisXiMomDistr", "Momentum distribution of #Xi", 190, 0., 3.8);  // Combination of #Xi^{-} and #Xi^{0}
	TH1D *hisXimMomDistr = new TH1D("hisXimMomDistr", "Momentum distribution of #Xi^{-}", 190, 0., 3.8);
	TH1D *hisXim500MomDistr = new TH1D("hisXim500MomDistr", "Momentum distribution of #Xi^{-} < 500 MeV/c", 190, 0., 3.8);
	TH1D *hisXimbarMomDistr = new TH1D("hisXimbarMomDistr", "Momentum distribution of Anti-#Xi^{-}", 190, 0., 3.8);
	TH1D *hisXi0barMomDistr = new TH1D("hisXi0barMomDistr", "Momentum distribution of Anti-#Xi^{0}", 190, 0., 3.8);
	TH1D *hisXi0MomDistr = new TH1D("hisXi0MomDistr", "Momentum distribution of #Xi^{0}", 190, 0., 3.8);
	TH1D *hisXiThetaDistr = new TH1D("hisXiThetaDistr", "Theta distribution of #Xi", 181, 0., 181.);  // Combination of #Xi^{-} and #Xi^{0}
	TH1D *hisXimThetaDistr = new TH1D("hisXimThetaDistr", "Theta distribution of #Xi^{-}", 181, 0., 181.);
	TH1D *hisXim500ThetaDistr = new TH1D("hisXim500ThetaDistr", "Theta distribution of #Xi^{-} < 500 MeV/c", 181, 0., 181.);
	TH1D *hisXimbarThetaDistr = new TH1D("hisXimbarThetaDistr", "Theta distribution of Anti-#Xi^{-}", 181, 0., 181.);
	TH1D *hisXi0barThetaDistr = new TH1D("hisXi0barThetaDistr", "Theta distribution of Anti-#Xi^{0}", 181, 0., 181.);
	TH1D *hisXi0ThetaDistr = new TH1D("hisXi0ThetaDistr", "Theta distribution of Anti #Xi^{-}", 181, 0., 181.);
	TH2D *hisXiThetaMomDistr = new TH2D("hisXiThetaMomDistr", "Theta-momentum distribution of #Xi", 181, 0., 181., 190, 0., 3.8);  // Combination of #Xi^{-} and #Xi^{0}
	TH2D *hisXimThetaMomDistr = new TH2D("hisXimThetaMomDistr", "Theta-momentum distribution of #Xi^{-}", 181, 0., 181., 190, 0., 3.8);
	TH2D *hisXimbarThetaMomDistr = new TH2D("hisXimbarThetaMomDistr", "Theta-momentum distribution of Anti-#Xi^{-}", 181, 0., 181., 190, 0., 3.8);
	TH2D *hisXi0barThetaMomDistr = new TH2D("hisXi0barThetaMomDistr", "Theta-momentum distribution of Anti-#Xi^{0}", 181, 0., 181., 190, 0., 3.8);
	TH2D *hisXi0ThetaMomDistr = new TH2D("hisXi0ThetaMomDistr", "Theta-momentum distribution of #Xi^{0}", 181, 0., 181., 190, 0., 3.8);

	TH1D *hisAntiProtonImpactparDistr;
	TH1D *hisAntiProtonImpactparDistr_tLUMIcut;
	hisAntiProtonImpactparDistr = new TH1D("hisAntiProtonImpactparDistr", "Impact parameter distribution of Antiprotons", 33, 0., 6.27);
	hisAntiProtonImpactparDistr_tLUMIcut = new TH1D("hisAntiProtonImpactparDistr_tLUMIcut", "Impact parameter distribution of Antiprotons", 33, 0., 6.27);

	TH1D *hisAntiProtonPositionDistr = new TH1D("hisAntiProtonPositionDistr", "Position distribution of Antiprotons", 200, 0., 400.);
	TH1D *hisAntiProtonMomDistr = new TH1D("hisAntiProtonMomDistr", "Momentum distribution of Antiprotons", 190, 0., 3.8);
	TH2D *hisAntiProtonPositionMomDistr = new TH2D("hisAntiProtonPositionMomDistr", "Position-momentum distribution of Antiprotons", 200, 0., 400., 190, 0., 3.8);
	TH1D *hisAntiProtonThetaDistr = new TH1D("hisAntiProtonThetaDistr", "Theta distribution of Antiprotons", 181, 0., 181.);
	TH1D *hisAntiProtonThetaDistr_tcut = new TH1D("hisAntiProtonThetaDistr_tcut", "Theta distribution of Antiprotons", 500, 0., 5.);
	TH1D *hisAntiProtonThetaDistr_tLUMIcut = new TH1D("hisAntiProtonThetaDistr_tLUMIcut", "Theta distribution of Antiprotons", 500, 0., 5.);
	TH1D *hisAntiProtonThetaDistr_mrad = new TH1D("hisAntiProtonThetaDistr_mrad", "Theta distribution of Antiprotons", 300, 0., 3.);
	TH1D *hisAntiProtonThetaDistr_mradcut = new TH1D("hisAntiProtonThetaDistr_mradcut", "Theta distribution of Antiprotons", 300, 0., 3.);
	TH2D *hisAntiProtonThetaMomDistr = new TH2D("hisAntiProtonThetaMomDistr", "Theta-momentum distribution of Antiprotons", 181, 0., 181., 190, 0., 3.8);
	TH2D *hisAntiProtonThetaMomDistr_tpcut = new TH2D("hisAntiProtonThetaMomDistr_tpcut", "Theta-momentum distribution of Antiprotons", 500, 0., 5., 121, 2.82, 2.941);

	TH1D *hisProtonPositionDistr = new TH1D("hisProtonPositionDistr", "Position distribution of Protons", 200, 0., 400.);
	TH1D *hisProtonMomDistr = new TH1D("hisProtonMomDistr", "Momentum distribution of Protons", 190, 0., 3.8);
	TH2D *hisProtonPositionMomDistr = new TH2D("hisProtonPositionMomDistr", "Position-momentum distribution of Protons", 200, 0., 400., 190, 0., 3.8);
	TH1D *hisProtonThetaDistr = new TH1D("hisProtonThetaDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH1D *hisProtonThetaFWDistr = new TH1D("hisProtonThetaFWDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH1D *hisProtonThetaSiDistr = new TH1D("hisProtonThetaSiDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH1D *hisProtonThetaSiGeDistr = new TH1D("hisProtonThetaSiGeDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH1D *hisProtonThetaGeDistr = new TH1D("hisProtonThetaGeDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH1D *hisProtonThetaBWDistr = new TH1D("hisProtonThetaBWDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH2D *hisProtonThetaMomDistr = new TH2D("hisProtonThetaMomDistr", "Theta-momentum distribution of Protons", 181, 0., 181., 190, 0., 3.8);

	TH1D *hisNeutronPositionDistr = new TH1D("hisNeutronPositionDistr", "Position distribution of Neutrons", 200, 0., 400.);
	TH1D *hisNeutronMomDistr = new TH1D("hisNeutronMomDistr", "Momentum distribution of Neutrons", 190, 0., 3.8);
	TH2D *hisNeutronPositionMomDistr = new TH2D("hisNeutronPositionMomDistr", "Position-momentum distribution of Neutrons", 200, 0., 400., 190, 0., 3.8);
	TH1D *hisNeutronThetaDistr = new TH1D("hisNeutronThetaDistr", "Theta distribution of Neutrons", 181, 0., 181.);
	TH1D *hisNeutronThetaFWDistr = new TH1D("hisNeutronThetaFWDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH1D *hisNeutronThetaSiDistr = new TH1D("hisNeutronThetaSiDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH1D *hisNeutronThetaSiGeDistr = new TH1D("hisNeutronThetaSiGeDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH1D *hisNeutronThetaGeDistr = new TH1D("hisNeutronThetaGeDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH1D *hisNeutronThetaBWDistr = new TH1D("hisNeutronThetaBWDistr", "Theta distribution of Protons", 181, 0., 181.);
	TH2D *hisNeutronThetaMomDistr = new TH2D("hisNeutronThetaMomDistr", "Theta-momentum distribution of Neutrons", 181, 0., 181., 190, 0., 3.8);

	TH1D *hisPionMultiplicity = new TH1D("hisPionMultiplicity", "Multiplicity of Pions", 10, 0., 10.);
	TH1D *hisPimMultiplicity = new TH1D("hisPimMultiplicity", "Multiplicity of #pi^{-}", 10, 0., 10.);
	TH1D *hisPimMomDistr = new TH1D("hisPimMomDistr", "Momentum distribution of #pi^{-}", 190, 0., 3.8);
	TH1D *hisPipMomDistr = new TH1D("hisPipMomDistr", "Momentum distribution of #pi^{+}", 190, 0., 3.8);
	TH1D *hisPimThetaDistr = new TH1D("hisPimThetaDistr", "Theta distribution of #pi^{-}", 181, 0., 181.);
	TH1D *hisPipThetaDistr = new TH1D("hisPipThetaDistr", "Theta distribution of #pi^{+}", 181, 0., 181.);
	TH2D *hisPimThetaMomDistr = new TH2D("hisPimThetaMomDistr", "Theta-momentum distribution of #pi^{-}", 181, 0., 181., 190, 0., 3.8);
	TH2D *hisPipThetaMomDistr = new TH2D("hisPipThetaMomDistr", "Theta-momentum distribution of #pi^{+}", 181, 0., 181., 190, 0., 3.8);

	TH1D *hisKaonmMomDistr = new TH1D("hisKaonmMomDistr", "Momentum distribution of K^{-}", 190, 0., 3.8);
	TH1D *hisKaonpMomDistr = new TH1D("hisKaonpMomDistr", "Momentum distribution of K^{+}", 190, 0., 3.8);
	TH1D *hisKaonmThetaDistr = new TH1D("hisKaonmThetaDistr", "Theta distribution of K^{-}", 181, 0., 181.);
	TH1D *hisKaonpThetaDistr = new TH1D("hisKaonpThetaDistr", "Theta distribution of K^{+}", 181, 0., 181.);
	TH2D *hisKaonmThetaMomDistr = new TH2D("hisKaonmThetaMomDistr", "Theta-momentum distribution of K^{-}", 181, 0., 181., 190, 0., 3.8);
	TH2D *hisKaonpThetaMomDistr = new TH2D("hisKaonpThetaMomDistr", "Theta-momentum distribution of K^{+}", 181, 0., 181., 190, 0., 3.8);

	TH1D *hisChargedParticleThetaSiliconDistr = new TH1D("hisChargedParticleThetaSiliconDistr", "Theta distribution of charged particles on Silicon", 181, 0., 181.);
	TH1D *hisChargedAntiNukleonThetaSiliconDistr = new TH1D("hisChargedAntiNukleonThetaSiliconDistr", "Theta distribution of Antiprotons on Silicon", 181, 0., 181.);
	TH1D *hisChargedNukleonThetaSiliconDistr = new TH1D("hisChargedNukleonThetaSiliconDistr", "Theta distribution of Protons on Silicon", 181, 0., 181.);
	TH1D *hisChargedPionThetaSiliconDistr = new TH1D("hisChargedPionThetaSiliconDistr", "Theta distribution of charged Pions on Silicon", 181, 0., 181.);
	TH1D *hisChargedKaonThetaSiliconDistr = new TH1D("hisChargedKaonThetaSiliconDistr", "Theta distribution of charged Kaons on Silicon", 181, 0., 181.);
	TH1D *hisNeutronThetaGeArrayDistr = new TH1D("hisNeutronThetaGeArrayDistr", "Theta distribution of Neutrons on Germanium array", 181, 0., 181.);

	TH1D *hisChargedParticleThetaSiliconDistr_pcut = new TH1D("hisChargedParticleThetaSiliconDistr_pcut", "Theta distribution of charged particles on Silicon", 181, 0., 181.);
	//TH1D *hisChargedAntiNukleonThetaSiliconDistr_pcut = new TH1D("hisChargedAntiNukleonThetaSiliconDistr_pcut", "Theta distribution of Antiprotons on Silicon", 181, 0., 181.);
	TH1D *hisChargedNukleonThetaSiliconDistr_pcut = new TH1D("hisChargedNukleonThetaSiliconDistr_pcut", "Theta distribution of Protons on Silicon", 181, 0., 181.);
	TH1D *hisChargedPionThetaSiliconDistr_pcut = new TH1D("hisChargedPionThetaSiliconDistr_pcut", "Theta distribution of charged Pions on Silicon", 181, 0., 181.);
	TH1D *hisChargedKaonThetaSiliconDistr_pcut = new TH1D("hisChargedKaonThetaSiliconDistr_pcut", "Theta distribution of charged Kaons on Silicon", 181, 0., 181.);


	// ----- Analysis ---------------------------------------------------------

	Int_t Multiplicity = 0;
	Int_t PionMultiplicity = 0, PimMultiplicity = 0;
	Int_t AntiprotonsInEventCounter = 0;
	TVector3 vecV, vecP;
	Double_t v = 0., p = 0., theta = 0., theta_mrad = 0., ImpParXim = 0., ImpParXimbar = 0., ImpParXi0bar = 0., ImpParXi0 = 0., ImpParAntiP = 0.;
	Double_t p_threshold = 0.1537;  // for Protons
	Bool_t XimEvent = kFALSE, XimbarEvent = kFALSE, Xi0barEvent = kFALSE, Xi0Event = kFALSE;

	std::cout << "Number of simulated Reactions: " << t->GetEntriesFast() << std::endl;


	// - - - i-loop for events - - - - - - - - - - - - - - - - - - - - - - - -
	for (Int_t i = 0; i < t->GetEntriesFast(); i++) {
	//for (Int_t i = 0; i < 200001; i++) {
		t->GetEntry(i);
		if (i % 100000 == 0)
		std::cout << "\n" << "Number of events: " << i << std::endl;
		//else std::cout <<  i+1 << ", ";

		Multiplicity = Particles_array->GetEntriesFast();  // number of all the particles in the event
		hisMultiplicity->Fill(Multiplicity);


		// - - - j-loop for particles in event i - - - - - - - - - - - - - - - -
		for (Int_t j = 0; j < Particles_array->GetEntriesFast(); j++) {
			THParticle *Particle = (THParticle *) Particles_array->At(j);
			Int_t mcpdg = -1;
			mcpdg = Particle->GetPdgCode();

			switch(Multiplicity) {
			case 1:  // only 1 particle in the event
				hisPDGCodesForMultiplicity1->Fill(mcpdg);
				break;
			case 2:  // 2 particles in the event
				hisPDGCodesForMultiplicity2->Fill(mcpdg);
				break;
			case 3:  // 3 particles in the event
				hisPDGCodesForMultiplicity3->Fill(mcpdg);
				break;
			case 4:  // 3 particles in the event
				hisPDGCodesForMultiplicity4->Fill(mcpdg);
				break;
			}

			if(mcpdg == 3312) {  // Xim filter
				XimEvent = kTRUE;
				ImpParXim = Particle->GetIndex();
				hisXimImpactparDistr->Fill(ImpParXim);
				//vecP.SetXYZ(Particle->GetPx(), Particle->GetPy(), Particle->GetPz());  // Does not work this way with "Get"!
				vecP.SetXYZ(Particle->Px(), Particle->Py(), Particle->Pz());
				p = vecP.Mag();
				hisXimMomDistr->Fill(p);
				hisXiMomDistr->Fill(p);  // Combination of #Xi^{-} and #Xi^{0}
				theta = TMath::ACos(vecP.z()/p)*180/3.14159265358979323846;
				hisXimThetaDistr->Fill(theta);
				hisXiThetaDistr->Fill(theta);  // Combination of #Xi^{-} and #Xi^{0}
				hisXimThetaMomDistr->Fill(theta, p);
				hisXiThetaMomDistr->Fill(theta, p);  // Combination of #Xi^{-} and #Xi^{0}
				if(p <= 0.5) {
					hisXim500MomDistr->Fill(p);
					hisXim500ThetaDistr->Fill(theta);
				}
			}

			if(mcpdg == -3312) {  // Ximbar filter
				XimbarEvent = kTRUE;
				ImpParXimbar = Particle->GetIndex();
				hisXimbarImpactparDistr->Fill(ImpParXimbar);
				//vecP.SetXYZ(Particle->GetPx(), Particle->GetPy(), Particle->GetPz());  // Does not work this way with "Get"!
				vecP.SetXYZ(Particle->Px(), Particle->Py(), Particle->Pz());
				p = vecP.Mag();
				hisXimbarMomDistr->Fill(p);
				theta = TMath::ACos(vecP.z()/p)*180/3.14159265358979323846;
				hisXimbarThetaDistr->Fill(theta);
				hisXimbarThetaMomDistr->Fill(theta, p);
			}

			if(mcpdg == -3322) {  // Xi0bar filter
				Xi0barEvent = kTRUE;
				ImpParXi0bar = Particle->GetIndex();
				hisXi0barImpactparDistr->Fill(ImpParXi0bar);
				//vecP.SetXYZ(Particle->GetPx(), Particle->GetPy(), Particle->GetPz());  // Does not work this way with "Get"!
				vecP.SetXYZ(Particle->Px(), Particle->Py(), Particle->Pz());
				p = vecP.Mag();
				hisXi0barMomDistr->Fill(p);
				theta = TMath::ACos(vecP.z()/p)*180/3.14159265358979323846;
				hisXi0barThetaDistr->Fill(theta);
				hisXi0barThetaMomDistr->Fill(theta, p);
			}

			if(mcpdg == 3322) {  // Xi0 filter
				Xi0Event = kTRUE;
				ImpParXi0 = Particle->GetIndex();
				hisXi0ImpactparDistr->Fill(ImpParXi0);
				//vecP.SetXYZ(Particle->GetPx(), Particle->GetPy(), Particle->GetPz());  // Does not work this way with "Get"!
				vecP.SetXYZ(Particle->Px(), Particle->Py(), Particle->Pz());
				p = vecP.Mag();
				hisXi0MomDistr->Fill(p);
				hisXiMomDistr->Fill(p);  // Combination of #Xi^{-} and #Xi^{0}
				theta = TMath::ACos(vecP.z()/p)*180/3.14159265358979323846;
				hisXi0ThetaDistr->Fill(theta);
				hisXiThetaDistr->Fill(theta);  // Combination of #Xi^{-} and #Xi^{0}
				hisXi0ThetaMomDistr->Fill(theta, p);
				hisXiThetaMomDistr->Fill(theta, p);  // Combination of #Xi^{-} and #Xi^{0}
			}

			if(mcpdg == -2212) {  // Antiproton filter
				AntiprotonsInEventCounter++;
				ImpParAntiP = Particle->GetIndex();
				//cout << ImpParAntiP << " " ;
				hisAntiProtonImpactparDistr->Fill(ImpParAntiP);
				vecV.SetXYZ(Particle->Vx(), Particle->Vy(), Particle->Vz());
				v = vecV.Mag();
				hisAntiProtonPositionDistr->Fill(v);
				//vecP.SetXYZ(Particle->GetPx(), Particle->GetPy(), Particle->GetPz());  // Does not work this way with "Get"!
				vecP.SetXYZ(Particle->Px(), Particle->Py(), Particle->Pz());
				p = vecP.Mag();
				hisAntiProtonMomDistr->Fill(p);
				hisAntiProtonPositionMomDistr->Fill(v, p);
				theta = TMath::ACos(vecP.z()/p)*180/3.14159265358979323846;
				theta_mrad = TMath::ACos(vecP.z()/p)*1000.;  // These mrad-lines cause too long runtimes for the macro!
				hisAntiProtonThetaDistr->Fill(theta);
				if(theta < 5.) hisAntiProtonThetaDistr_tcut->Fill(theta);
				//if(theta < 0.17188734) {  // > 3 mrad reaches LUMI detector from PANDA vertex
				if(theta < 0.163702273) {  // > 2.857 mrad reaches LUMI detector from HYP vertex
					hisAntiProtonThetaDistr_tLUMIcut->Fill(theta);
					hisAntiProtonImpactparDistr_tLUMIcut->Fill(ImpParAntiP);
				}
				//if(theta_mrad < 3.) hisAntiProtonThetaDistr_mrad->Fill(theta_mrad);  // These mrad-lines cause too long runtimes for the macro!
				if(theta_mrad < 2.857143654) hisAntiProtonThetaDistr_mrad->Fill(theta_mrad);  // These mrad-lines cause too long runtimes for the macro!
				if(theta_mrad < 0.2) hisAntiProtonThetaDistr_mradcut->Fill(theta_mrad);  // These mrad-lines cause too long runtimes for the macro!
				if(theta >= 21.8 && theta < 158.2) {
					hisChargedAntiNukleonThetaSiliconDistr->Fill(theta);
					hisChargedParticleThetaSiliconDistr->Fill(theta);
				}
				hisAntiProtonThetaMomDistr->Fill(theta, p);
				if(theta < 5. && p > 2.82 && p <= 2.94) hisAntiProtonThetaMomDistr_tpcut->Fill(theta, p);  // !!! This line is only reasonable for runs with p(Pbar) = 2.9 GeV/c !!!
			}

			if(mcpdg == 2212) {  // Proton filter
				vecV.SetXYZ(Particle->Vx(), Particle->Vy(), Particle->Vz());
				v = vecV.Mag();
				hisProtonPositionDistr->Fill(v);
				//vecP.SetXYZ(Particle->GetPx(), Particle->GetPy(), Particle->GetPz());  // Does not work this way with "Get"!
				vecP.SetXYZ(Particle->Px(), Particle->Py(), Particle->Pz());
				p = vecP.Mag();
				hisProtonMomDistr->Fill(p);
				hisProtonPositionMomDistr->Fill(v, p);
				theta = TMath::ACos(vecP.z()/p)*180/3.14159265358979323846;
				hisProtonThetaDistr->Fill(theta);
				if(theta < 21.8) hisProtonThetaFWDistr->Fill(theta);
				if(theta >= 21.8 && theta < 110) {
					hisProtonThetaSiDistr->Fill(theta);
					hisChargedNukleonThetaSiliconDistr->Fill(theta);  // Combination of angles to Silicon region for Protons
					hisChargedParticleThetaSiliconDistr->Fill(theta);  // Combination of angles to Silicon region as contribution of Protons to all charged particles
					if(p > p_threshold) {
						hisChargedNukleonThetaSiliconDistr_pcut->Fill(theta);
						hisChargedParticleThetaSiliconDistr_pcut->Fill(theta);
					}
				}
				if(theta >= 110 && theta < 158.2) {
					hisProtonThetaSiGeDistr->Fill(theta);
					hisChargedNukleonThetaSiliconDistr->Fill(theta);  // Combination of angles to Silicon region for Protons
					hisChargedParticleThetaSiliconDistr->Fill(theta);  // Combination of angles to Silicon region as contribution of Protons to all charged particles
					if(p > p_threshold) {
						hisChargedNukleonThetaSiliconDistr_pcut->Fill(theta);
						hisChargedParticleThetaSiliconDistr_pcut->Fill(theta);
					}
				}
				if(theta >= 158.2 && theta < 165) hisProtonThetaGeDistr->Fill(theta);
				if(theta >= 165) hisProtonThetaBWDistr->Fill(theta);
				hisProtonThetaMomDistr->Fill(theta, p);
			}

			if(mcpdg == 2112) {  // Neutron filter
				vecV.SetXYZ(Particle->Vx(), Particle->Vy(), Particle->Vz());
				v = vecV.Mag();
				hisNeutronPositionDistr->Fill(v);
				//vecP.SetXYZ(Particle->GetPx(), Particle->GetPy(), Particle->GetPz());  // Does not work this way with "Get"!
				vecP.SetXYZ(Particle->Px(), Particle->Py(), Particle->Pz());
				p = vecP.Mag();
				hisNeutronMomDistr->Fill(p);
				hisNeutronPositionMomDistr->Fill(v, p);
				theta = TMath::ACos(vecP.z()/p)*180/3.14159265358979323846;
				hisNeutronThetaDistr->Fill(theta);
				if(theta < 21.8) hisNeutronThetaFWDistr->Fill(theta);
				if(theta >= 21.8 && theta < 110) hisNeutronThetaSiDistr->Fill(theta);
				if(theta >= 110 && theta < 158.2) {
					hisNeutronThetaSiGeDistr->Fill(theta);
					hisNeutronThetaGeArrayDistr->Fill(theta);  // Combination of angles to Germanium region for Neutrons
				}
				if(theta >= 158.2 && theta < 165) {
					hisNeutronThetaGeDistr->Fill(theta);
					hisNeutronThetaGeArrayDistr->Fill(theta);  // Combination of angles to Germanium region for Neutrons
				}
				if(theta >= 165) hisNeutronThetaBWDistr->Fill(theta);
				hisNeutronThetaMomDistr->Fill(theta, p);
			}

			if(mcpdg == -211 || mcpdg == 211) {  // charged Pion filter
				PionMultiplicity++;
				//vecP.SetXYZ(Particle->GetPx(), Particle->GetPy(), Particle->GetPz());  // Does not work this way with "Get"!
				vecP.SetXYZ(Particle->Px(), Particle->Py(), Particle->Pz());
				p = vecP.Mag();
				theta = TMath::ACos(vecP.z()/p)*180/3.14159265358979323846;
				if(theta >= 21.8 && theta < 158.2) {
					hisChargedPionThetaSiliconDistr->Fill(theta);
					hisChargedParticleThetaSiliconDistr->Fill(theta);  // Contribution of charged Pions to all charged particles into Silicon region
					hisChargedPionThetaSiliconDistr_pcut->Fill(theta);
					hisChargedParticleThetaSiliconDistr_pcut->Fill(theta);
				}
				if(mcpdg == -211) {
					PimMultiplicity++;
					hisPimMomDistr->Fill(p);
					hisPimThetaDistr->Fill(theta);
					hisPimThetaMomDistr->Fill(theta, p);
				}
				else {
					hisPipMomDistr->Fill(p);
					hisPipThetaDistr->Fill(theta);
					hisPipThetaMomDistr->Fill(theta, p);
				}
			}

			if(mcpdg == 111) {  // neutral Pion filter
				PionMultiplicity++;
			}

			if(mcpdg == -321 || mcpdg == 321) {  // charged Kaon filter
				//vecP.SetXYZ(Particle->GetPx(), Particle->GetPy(), Particle->GetPz());  // Does not work this way with "Get"!
				vecP.SetXYZ(Particle->Px(), Particle->Py(), Particle->Pz());
				p = vecP.Mag();
				theta = TMath::ACos(vecP.z()/p)*180/3.14159265358979323846;
				if(theta >= 21.8 && theta < 158.2) {
					hisChargedKaonThetaSiliconDistr->Fill(theta);
					hisChargedParticleThetaSiliconDistr->Fill(theta);  // Contribution of charged Kaons to all charged particles into Silicon region
					hisChargedKaonThetaSiliconDistr_pcut->Fill(theta);
					hisChargedParticleThetaSiliconDistr_pcut->Fill(theta);
				}
				if(mcpdg == -321) {
					hisKaonmMomDistr->Fill(p);
					hisKaonmThetaDistr->Fill(theta);
					hisKaonmThetaMomDistr->Fill(theta, p);
				}
				else {
					hisKaonpMomDistr->Fill(p);
					hisKaonpThetaDistr->Fill(theta);
					hisKaonpThetaMomDistr->Fill(theta, p);
				}
			}

		}  // end for j (particles in event)

		if(XimEvent == kTRUE && XimbarEvent == kTRUE) hisXimXimbarPairsImpactparDistr->Fill(ImpParXim);
		if(XimEvent == kTRUE && Xi0barEvent == kTRUE) hisXimXi0barPairsImpactparDistr->Fill(ImpParXim);
		if(Xi0Event == kTRUE && Xi0barEvent == kTRUE) hisXi0Xi0barPairsImpactparDistr->Fill(ImpParXi0);
		XimEvent = kFALSE;
		XimbarEvent = kFALSE;
		Xi0barEvent = kFALSE;
		Xi0Event = kFALSE;
		if(AntiprotonsInEventCounter != 0) {
			hisMultiplicityOfAntiprotonsInEvent->Fill(AntiprotonsInEventCounter);
			hisMultiplicityWhenAntiprotonsInEvent->Fill(Multiplicity);
			AntiprotonsInEventCounter = 0;
		}
		hisPionMultiplicity->Fill(PionMultiplicity);
		hisPimMultiplicity->Fill(PimMultiplicity);
		PionMultiplicity = 0;
		PimMultiplicity = 0;

	}  // end for i (events)
	std::cout << "end of event loop." << std::endl;


	// ----- ROOT-Output of the Histograms ------------------------------------

	// associated with line:
	// TFile *out = TFile::Open(stringbuffer_out, "RECREATE");
	out->cd();

	hisMultiplicity->Write();
	hisPDGCodesForMultiplicity1->Write();
	hisPDGCodesForMultiplicity2->Write();
	hisPDGCodesForMultiplicity3->Write();
	hisPDGCodesForMultiplicity4->Write();
	hisMultiplicityOfAntiprotonsInEvent->Write();
	hisMultiplicityWhenAntiprotonsInEvent->Write();
	hisXimImpactparDistr->Write();
	hisXimbarImpactparDistr->Write();
	hisXimXimbarPairsImpactparDistr->Write();
	hisXi0barImpactparDistr->Write();
	hisXimXi0barPairsImpactparDistr->Write();
	hisXi0ImpactparDistr->Write();
	hisXi0Xi0barPairsImpactparDistr->Write();
	hisXiMomDistr->Write();
	hisXimMomDistr->Write();
	hisXim500MomDistr->Write();
	hisXimbarMomDistr->Write();
	hisXi0barMomDistr->Write();
	hisXi0MomDistr->Write();
	hisXiThetaDistr->Write();
	hisXimThetaDistr->Write();
	hisXim500ThetaDistr->Write();
	hisXimbarThetaDistr->Write();
	hisXi0barThetaDistr->Write();
	hisXi0ThetaDistr->Write();
	hisXiThetaMomDistr->Write();
	hisXimThetaMomDistr->Write();
	hisXimbarThetaMomDistr->Write();
	hisXi0barThetaMomDistr->Write();
	hisXi0ThetaMomDistr->Write();
	hisAntiProtonImpactparDistr->Write();
	hisAntiProtonImpactparDistr_tLUMIcut->Write();
	hisAntiProtonPositionDistr->Write();
	hisAntiProtonMomDistr->Write();
	hisAntiProtonPositionMomDistr->Write();
	hisAntiProtonThetaDistr->Write();
	hisAntiProtonThetaDistr_tcut->Write();
	hisAntiProtonThetaDistr_tLUMIcut->Write();
	hisAntiProtonThetaDistr_mrad->Write();
	hisAntiProtonThetaDistr_mradcut->Write();
	hisAntiProtonThetaMomDistr->Write();
	hisAntiProtonThetaMomDistr_tpcut->Write();
	hisProtonPositionDistr->Write();
	hisProtonMomDistr->Write();
	hisProtonPositionMomDistr->Write();
	hisProtonThetaDistr->Write();
	hisProtonThetaFWDistr->Write();
	hisProtonThetaSiDistr->Write();
	hisProtonThetaSiGeDistr->Write();
	hisProtonThetaGeDistr->Write();
	hisProtonThetaBWDistr->Write();
	hisProtonThetaMomDistr->Write();
	hisNeutronPositionDistr->Write();
	hisNeutronMomDistr->Write();
	hisNeutronPositionMomDistr->Write();
	hisNeutronThetaDistr->Write();
	hisNeutronThetaFWDistr->Write();
	hisNeutronThetaSiDistr->Write();
	hisNeutronThetaSiGeDistr->Write();
	hisNeutronThetaGeDistr->Write();
	hisNeutronThetaBWDistr->Write();
	hisNeutronThetaMomDistr->Write();
	hisPionMultiplicity->Write();
	hisPimMultiplicity->Write();
	hisPimMomDistr->Write();
	hisPipMomDistr->Write();
	hisPimThetaDistr->Write();
	hisPipThetaDistr->Write();
	hisPimThetaMomDistr->Write();
	hisPipThetaMomDistr->Write();
	hisKaonmMomDistr->Write();
	hisKaonpMomDistr->Write();
	hisKaonmThetaDistr->Write();
	hisKaonpThetaDistr->Write();
	hisKaonmThetaMomDistr->Write();
	hisKaonpThetaMomDistr->Write();
	hisChargedParticleThetaSiliconDistr->Write();
	hisChargedAntiNukleonThetaSiliconDistr->Write();
	hisChargedNukleonThetaSiliconDistr->Write();
	hisChargedPionThetaSiliconDistr->Write();
	hisChargedKaonThetaSiliconDistr->Write();
	hisNeutronThetaGeArrayDistr->Write();
	hisChargedParticleThetaSiliconDistr_pcut->Write();
	//hisChargedAntiNukleonThetaSiliconDistr_pcut->Write();
	hisChargedNukleonThetaSiliconDistr_pcut->Write();
	hisChargedPionThetaSiliconDistr_pcut->Write();
	hisChargedKaonThetaSiliconDistr_pcut->Write();

	out->Save();


	// ----- Finish -----------------------------------------------------------

	timer.Stop();
	Double_t rtime = timer.RealTime();
	Double_t ctime = timer.CpuTime();
	std::cout << std::endl << std::endl;
	std::cout << "Macro finished succesfully." << std::endl;
	//std::cout << "Output file is "    << outFile << std::endl;
	//std::cout << "Parameter file is " << parFile << std::endl;
	std::cout << "Real time " << rtime << " s, CPU time " << ctime << " s" << std::endl;
	std::cout << std::endl;

}

