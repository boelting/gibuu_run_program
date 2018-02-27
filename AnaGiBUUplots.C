//void GiBUUsim_ana_output_plotting_1Case(TString path="/data/work/kpha1/bleser/GiBUU-data2b/jobs/carbon0003/Conversion_Class_apr13_carbon0003_allParticles/AnaOutput_ParticleDistributions_1Case", TString input_filename ="carbon0003_allParticles_1_32") {
void AnaGiBUUplots(TString path="/data/work/himspecf/schupp/data/GiBuu/carbon_2.109_0.011/", TString input_filename ="carbon_allParticles_02_06") {


	// ----- Histograms (87+1//) ------------------------------------------------

	TH1D *hisMultiplicity;
	TH1D *hisPDGCodesForMultiplicity1;
	TH1D *hisPDGCodesForMultiplicity2;
	TH1D *hisPDGCodesForMultiplicity3;
	TH1D *hisPDGCodesForMultiplicity4;
	TH1D *hisMultiplicityOfAntiprotonsInEvent;
	TH1D *hisMultiplicityWhenAntiprotonsInEvent;
	TH1D *hisXimImpactparDistr;
	TH1D *hisXimbarImpactparDistr;
	TH1D *hisXimXimbarPairsImpactparDistr;
	TH1D *hisXi0barImpactparDistr;
	TH1D *hisXimXi0barPairsImpactparDistr;
	TH1D *hisXi0ImpactparDistr;
	TH1D *hisXi0Xi0barPairsImpactparDistr;
	TH1D *hisXiMomDistr;
	TH1D *hisXimMomDistr;
	TH1D *hisXim500MomDistr;
	TH1D *hisXimbarMomDistr;
	TH1D *hisXi0barMomDistr;
	TH1D *hisXi0MomDistr;
	TH1D *hisXiThetaDistr;
	TH1D *hisXimThetaDistr;
	TH1D *hisXim500ThetaDistr;
	TH1D *hisXimbarThetaDistr;
	TH1D *hisXi0barThetaDistr;
	TH1D *hisXi0ThetaDistr;
	TH2D *hisXiThetaMomDistr;
	TH2D *hisXimThetaMomDistr;
	TH2D *hisXimbarThetaMomDistr;
	TH2D *hisXi0barThetaMomDistr;
	TH2D *hisXi0ThetaMomDistr;
	TH1D *hisAntiProtonImpactparDistr;
	TH1D *hisAntiProtonImpactparDistr_tLUMIcut;
	TH1D *hisAntiProtonPositionDistr;
	TH1D *hisAntiProtonMomDistr;
	TH2D *hisAntiProtonPositionMomDistr;
	TH1D *hisAntiProtonThetaDistr;
	TH1D *hisAntiProtonThetaDistr_tcut;
	TH1D *hisAntiProtonThetaDistr_tLUMIcut;
	TH1D *hisAntiProtonThetaDistr_mrad;
	TH1D *hisAntiProtonThetaDistr_mradcut;
	TH2D *hisAntiProtonThetaMomDistr;
	TH2D *hisAntiProtonThetaMomDistr_tpcut;
	TH1D *hisProtonPositionDistr;
	TH1D *hisProtonMomDistr;
	TH2D *hisProtonPositionMomDistr;
	TH1D *hisProtonThetaDistr;
	TH1D *hisProtonThetaFWDistr;
	TH1D *hisProtonThetaSiDistr;
	TH1D *hisProtonThetaSiGeDistr;
	TH1D *hisProtonThetaGeDistr;
	TH1D *hisProtonThetaBWDistr;
	TH2D *hisProtonThetaMomDistr;
	TH1D *hisNeutronPositionDistr;
	TH1D *hisNeutronMomDistr;
	TH2D *hisNeutronPositionMomDistr;
	TH1D *hisNeutronThetaDistr;
	TH1D *hisNeutronThetaFWDistr;
	TH1D *hisNeutronThetaSiDistr;
	TH1D *hisNeutronThetaSiGeDistr;
	TH1D *hisNeutronThetaGeDistr;
	TH1D *hisNeutronThetaBWDistr;
	TH2D *hisNeutronThetaMomDistr;
	TH1D *hisPionMultiplicity;
	TH1D *hisPimMultiplicity;
	TH1D *hisPimMomDistr;
	TH1D *hisPipMomDistr;
	TH1D *hisPimThetaDistr;
	TH1D *hisPipThetaDistr;
	TH2D *hisPimThetaMomDistr;
	TH2D *hisPipThetaMomDistr;
	TH1D *hisKaonmMomDistr;
	TH1D *hisKaonpMomDistr;
	TH1D *hisKaonmThetaDistr;
	TH1D *hisKaonpThetaDistr;
	TH2D *hisKaonmThetaMomDistr;
	TH2D *hisKaonpThetaMomDistr;
	TH1D *hisChargedParticleThetaSiliconDistr;
	TH1D *hisChargedAntiNukleonThetaSiliconDistr;
	TH1D *hisChargedNukleonThetaSiliconDistr;
	TH1D *hisChargedPionThetaSiliconDistr;
	TH1D *hisChargedKaonThetaSiliconDistr;
	TH1D *hisNeutronThetaGeArrayDistr;
	TH1D *hisChargedParticleThetaSiliconDistr_pcut;
	//TH1D *hisChargedAntiNukleonThetaSiliconDistr_pcut;
	TH1D *hisChargedNukleonThetaSiliconDistr_pcut;
	TH1D *hisChargedPionThetaSiliconDistr_pcut;
	TH1D *hisChargedKaonThetaSiliconDistr_pcut;


	TFile *f = new TFile(path+"out.root", "OPEN");  // the sim output file to analyze

	f->GetObject("hisMultiplicity", hisMultiplicity);
	f->GetObject("hisPDGCodesForMultiplicity1", hisPDGCodesForMultiplicity1);
	f->GetObject("hisPDGCodesForMultiplicity2", hisPDGCodesForMultiplicity2);
	f->GetObject("hisPDGCodesForMultiplicity3", hisPDGCodesForMultiplicity3);
	f->GetObject("hisPDGCodesForMultiplicity4", hisPDGCodesForMultiplicity4);
	f->GetObject("hisMultiplicityOfAntiprotonsInEvent", hisMultiplicityOfAntiprotonsInEvent);
	f->GetObject("hisMultiplicityWhenAntiprotonsInEvent", hisMultiplicityWhenAntiprotonsInEvent);
	f->GetObject("hisXimImpactparDistr", hisXimImpactparDistr);
	f->GetObject("hisXimbarImpactparDistr", hisXimbarImpactparDistr);
	f->GetObject("hisXimXimbarPairsImpactparDistr", hisXimXimbarPairsImpactparDistr);
	f->GetObject("hisXi0barImpactparDistr", hisXi0barImpactparDistr);
	f->GetObject("hisXimXi0barPairsImpactparDistr", hisXimXi0barPairsImpactparDistr);
	f->GetObject("hisXi0ImpactparDistr", hisXi0ImpactparDistr);
	f->GetObject("hisXi0Xi0barPairsImpactparDistr", hisXi0Xi0barPairsImpactparDistr);
	f->GetObject("hisXiMomDistr", hisXiMomDistr);
	f->GetObject("hisXimMomDistr", hisXimMomDistr);
	f->GetObject("hisXim500MomDistr", hisXim500MomDistr);
	f->GetObject("hisXimbarMomDistr", hisXimbarMomDistr);
	f->GetObject("hisXi0barMomDistr", hisXi0barMomDistr);
	f->GetObject("hisXi0MomDistr", hisXi0MomDistr);
	f->GetObject("hisXiThetaDistr", hisXiThetaDistr);
	f->GetObject("hisXimThetaDistr", hisXimThetaDistr);
	f->GetObject("hisXim500ThetaDistr", hisXim500ThetaDistr);
	f->GetObject("hisXimbarThetaDistr", hisXimbarThetaDistr);
	f->GetObject("hisXi0barThetaDistr", hisXi0barThetaDistr);
	f->GetObject("hisXi0ThetaDistr", hisXi0ThetaDistr);
	f->GetObject("hisXiThetaMomDistr", hisXiThetaMomDistr);
	f->GetObject("hisXimThetaMomDistr", hisXimThetaMomDistr);
	f->GetObject("hisXimbarThetaMomDistr", hisXimbarThetaMomDistr);
	f->GetObject("hisXi0barThetaMomDistr", hisXi0barThetaMomDistr);
	f->GetObject("hisXi0ThetaMomDistr", hisXi0ThetaMomDistr);
	f->GetObject("hisAntiProtonImpactparDistr", hisAntiProtonImpactparDistr);
	f->GetObject("hisAntiProtonImpactparDistr_tLUMIcut", hisAntiProtonImpactparDistr_tLUMIcut);
	f->GetObject("hisAntiProtonPositionDistr", hisAntiProtonPositionDistr);
	f->GetObject("hisAntiProtonMomDistr", hisAntiProtonMomDistr);
	f->GetObject("hisAntiProtonPositionMomDistr", hisAntiProtonPositionMomDistr);
	f->GetObject("hisAntiProtonThetaDistr", hisAntiProtonThetaDistr);
	f->GetObject("hisAntiProtonThetaDistr_tcut", hisAntiProtonThetaDistr_tcut);
	f->GetObject("hisAntiProtonThetaDistr_tLUMIcut", hisAntiProtonThetaDistr_tLUMIcut);
	f->GetObject("hisAntiProtonThetaDistr_mrad", hisAntiProtonThetaDistr_mrad);
	f->GetObject("hisAntiProtonThetaDistr_mradcut", hisAntiProtonThetaDistr_mradcut);
	f->GetObject("hisAntiProtonThetaMomDistr", hisAntiProtonThetaMomDistr);
	f->GetObject("hisAntiProtonThetaMomDistr_tpcut", hisAntiProtonThetaMomDistr_tpcut);
	f->GetObject("hisProtonPositionDistr", hisProtonPositionDistr);
	f->GetObject("hisProtonMomDistr", hisProtonMomDistr);
	f->GetObject("hisProtonPositionMomDistr", hisProtonPositionMomDistr);
	f->GetObject("hisProtonThetaDistr", hisProtonThetaDistr);
	f->GetObject("hisProtonThetaFWDistr", hisProtonThetaFWDistr);
	f->GetObject("hisProtonThetaSiDistr", hisProtonThetaSiDistr);
	f->GetObject("hisProtonThetaSiGeDistr", hisProtonThetaSiGeDistr);
	f->GetObject("hisProtonThetaGeDistr", hisProtonThetaGeDistr);
	f->GetObject("hisProtonThetaBWDistr", hisProtonThetaBWDistr);
	f->GetObject("hisProtonThetaMomDistr", hisProtonThetaMomDistr);
	f->GetObject("hisNeutronPositionDistr", hisNeutronPositionDistr);
	f->GetObject("hisNeutronMomDistr", hisNeutronMomDistr);
	f->GetObject("hisNeutronPositionMomDistr", hisNeutronPositionMomDistr);
	f->GetObject("hisNeutronThetaDistr", hisNeutronThetaDistr);
	f->GetObject("hisNeutronThetaFWDistr", hisNeutronThetaFWDistr);
	f->GetObject("hisNeutronThetaSiDistr", hisNeutronThetaSiDistr);
	f->GetObject("hisNeutronThetaSiGeDistr", hisNeutronThetaSiGeDistr);
	f->GetObject("hisNeutronThetaGeDistr", hisNeutronThetaGeDistr);
	f->GetObject("hisNeutronThetaBWDistr", hisNeutronThetaBWDistr);
	f->GetObject("hisNeutronThetaMomDistr", hisNeutronThetaMomDistr);
	f->GetObject("hisPionMultiplicity", hisPionMultiplicity);
	f->GetObject("hisPimMultiplicity", hisPimMultiplicity);
	f->GetObject("hisPimMomDistr", hisPimMomDistr);
	f->GetObject("hisPipMomDistr", hisPipMomDistr);
	f->GetObject("hisPimThetaDistr", hisPimThetaDistr);
	f->GetObject("hisPipThetaDistr", hisPipThetaDistr);
	f->GetObject("hisPimThetaMomDistr", hisPimThetaMomDistr);
	f->GetObject("hisPipThetaMomDistr", hisPipThetaMomDistr);
	f->GetObject("hisKaonmMomDistr", hisKaonmMomDistr);
	f->GetObject("hisKaonpMomDistr", hisKaonpMomDistr);
	f->GetObject("hisKaonmThetaDistr", hisKaonmThetaDistr);
	f->GetObject("hisKaonpThetaDistr", hisKaonpThetaDistr);
	f->GetObject("hisKaonmThetaMomDistr", hisKaonmThetaMomDistr);
	f->GetObject("hisKaonpThetaMomDistr", hisKaonpThetaMomDistr);
	f->GetObject("hisChargedParticleThetaSiliconDistr", hisChargedParticleThetaSiliconDistr);
	f->GetObject("hisChargedAntiNukleonThetaSiliconDistr", hisChargedAntiNukleonThetaSiliconDistr);
	f->GetObject("hisChargedNukleonThetaSiliconDistr", hisChargedNukleonThetaSiliconDistr);
	f->GetObject("hisChargedPionThetaSiliconDistr", hisChargedPionThetaSiliconDistr);
	f->GetObject("hisChargedKaonThetaSiliconDistr", hisChargedKaonThetaSiliconDistr);
	f->GetObject("hisNeutronThetaGeArrayDistr", hisNeutronThetaGeArrayDistr);
	f->GetObject("hisChargedParticleThetaSiliconDistr_pcut", hisChargedParticleThetaSiliconDistr_pcut);
	//f->GetObject("hisChargedAntiNukleonThetaSiliconDistr_pcut", hisChargedAntiNukleonThetaSiliconDistr_pcut);
	f->GetObject("hisChargedNukleonThetaSiliconDistr_pcut", hisChargedNukleonThetaSiliconDistr_pcut);
	f->GetObject("hisChargedPionThetaSiliconDistr_pcut", hisChargedPionThetaSiliconDistr_pcut);
	f->GetObject("hisChargedKaonThetaSiliconDistr_pcut", hisChargedKaonThetaSiliconDistr_pcut);

	Int_t Multiplicity = hisMultiplicity->GetEntries();
	Int_t MultiplicityWhenAntiprotonsInEvent = hisMultiplicityWhenAntiprotonsInEvent->GetEntries();
	Int_t XimImpactparNumber = hisXimImpactparDistr->GetEntries();
	Int_t XimbarImpactparNumber = hisXimbarImpactparDistr->GetEntries();
	Int_t XimXimbarPairsImpactparNumber = hisXimXimbarPairsImpactparDistr->GetEntries();
	Int_t Xi0barImpactparNumber = hisXi0barImpactparDistr->GetEntries();
	Int_t XimXi0barPairsImpactparNumber = hisXimXi0barPairsImpactparDistr->GetEntries();
	Int_t Xi0ImpactparNumber = hisXi0ImpactparDistr->GetEntries();
	Int_t Xi0Xi0barPairsImpactparNumber = hisXi0Xi0barPairsImpactparDistr->GetEntries();
	Int_t XiNumber = hisXiMomDistr->GetEntries();
	Int_t XimNumber = hisXimMomDistr->GetEntries();
	Int_t Xim500Number = hisXim500MomDistr->GetEntries();
	Int_t XimbarNumber = hisXimbarMomDistr->GetEntries();
	Int_t Xi0barNumber = hisXi0barMomDistr->GetEntries();
	Int_t Xi0Number = hisXi0MomDistr->GetEntries();
	Int_t XiThetaNumber = hisXiThetaDistr->GetEntries();
	Int_t XimThetaNumber = hisXimThetaDistr->GetEntries();
	Int_t Xim500ThetaNumber = hisXim500ThetaDistr->GetEntries();
	Int_t XimbarThetaNumber = hisXimbarThetaDistr->GetEntries();
	Int_t Xi0barThetaNumber = hisXi0barThetaDistr->GetEntries();
	Int_t Xi0ThetaNumber = hisXi0ThetaDistr->GetEntries();
	Int_t AntiProtonImpactparNumber = hisAntiProtonImpactparDistr->GetEntries();
	Int_t AntiProtonImpactparNumber_tLUMIcut = hisAntiProtonImpactparDistr_tLUMIcut->GetEntries();
	Int_t AntiProtonNumber = hisAntiProtonMomDistr->GetEntries();
	Int_t AntiProtonThetaNumber = hisAntiProtonThetaDistr->GetEntries();
	Int_t AntiProtonThetaNumber_tcut = hisAntiProtonThetaDistr_tcut->GetEntries();
	Int_t AntiProtonThetaNumber_tLUMIcut = hisAntiProtonThetaDistr_tLUMIcut->GetEntries();
	Int_t AntiProtonThetaNumber_mrad = hisAntiProtonThetaDistr_mrad->GetEntries();
	Int_t AntiProtonThetaNumber_mradcut = hisAntiProtonThetaDistr_mradcut->GetEntries();
	Int_t ProtonNumber = hisProtonMomDistr->GetEntries();
	Int_t ProtonThetaNumber = hisProtonThetaDistr->GetEntries();
	Int_t ProtonThetaFWNumber = hisProtonThetaFWDistr->GetEntries();
	Int_t ProtonThetaSiNumber = hisProtonThetaSiDistr->GetEntries();
	Int_t ProtonThetaSiGeNumber = hisProtonThetaSiGeDistr->GetEntries();
	Int_t ProtonThetaGeNumber = hisProtonThetaGeDistr->GetEntries();
	Int_t ProtonThetaBWNumber = hisProtonThetaBWDistr->GetEntries();
	Int_t NeutronNumber = hisNeutronMomDistr->GetEntries();
	Int_t NeutronThetaNumber = hisNeutronThetaDistr->GetEntries();
	Int_t NeutronThetaFWNumber = hisNeutronThetaFWDistr->GetEntries();
	Int_t NeutronThetaSiNumber = hisNeutronThetaSiDistr->GetEntries();
	Int_t NeutronThetaSiGeNumber = hisNeutronThetaSiGeDistr->GetEntries();
	Int_t NeutronThetaGeNumber = hisNeutronThetaGeDistr->GetEntries();
	Int_t NeutronThetaBWNumber = hisNeutronThetaBWDistr->GetEntries();
	Int_t PionMultiplicityNumber = hisPionMultiplicity->GetEntries();
	Int_t PimMultiplicityNumber = hisPimMultiplicity->GetEntries();
	Int_t PimNumber = hisPimMomDistr->GetEntries();
	Int_t PipNumber = hisPipMomDistr->GetEntries();
	Int_t PimThetaNumber = hisPimThetaDistr->GetEntries();
	Int_t PipThetaNumber = hisPipThetaDistr->GetEntries();
	Int_t KaonmNumber = hisKaonmMomDistr->GetEntries();
	Int_t KaonpNumber = hisKaonpMomDistr->GetEntries();
	Int_t KaonmThetaNumber = hisKaonmThetaDistr->GetEntries();
	Int_t KaonpThetaNumber = hisKaonpThetaDistr->GetEntries();
	Int_t ChargedParticleThetaSiliconNumber = hisChargedParticleThetaSiliconDistr->GetEntries();
	Int_t ChargedAntiNukleonThetaSiliconNumber = hisChargedAntiNukleonThetaSiliconDistr->GetEntries();
	Int_t ChargedNukleonThetaSiliconNumber = hisChargedNukleonThetaSiliconDistr->GetEntries();
	Int_t ChargedPionThetaSiliconNumber = hisChargedPionThetaSiliconDistr->GetEntries();
	Int_t ChargedKaonThetaSiliconNumber = hisChargedKaonThetaSiliconDistr->GetEntries();
	Int_t NeutronThetaGeArrayNumber = hisNeutronThetaGeArrayDistr->GetEntries();
	Int_t ChargedParticleThetaSiliconNumber_pcut = hisChargedParticleThetaSiliconDistr_pcut->GetEntries();
	//Int_t ChargedAntiNukleonThetaSiliconNumber_pcut = hisChargedAntiNukleonThetaSiliconDistr_pcut->GetEntries();
	Int_t ChargedNukleonThetaSiliconNumber_pcut = hisChargedNukleonThetaSiliconDistr_pcut->GetEntries();
	Int_t ChargedPionThetaSiliconNumber_pcut = hisChargedPionThetaSiliconDistr_pcut->GetEntries();
	Int_t ChargedKaonThetaSiliconNumber_pcut = hisChargedKaonThetaSiliconDistr_pcut->GetEntries();


	// ----- Output of numbers --------------------------------------------------

	ofstream fOutputFile(path+"out.txt", std::ios::out);

	fOutputFile << "Numbers in " << path << "/ana_output_pd1c_" << input_filename << ".root" << endl;
	fOutputFile << "" << endl;
	fOutputFile << XiNumber << "\t" << "\t" << " = Number of Xi" << endl;
	fOutputFile << XimNumber << "\t" << "\t" << " = Number of Xi-" << endl;
	fOutputFile << Xim500Number << "\t" << "\t" << " = Number of Xi- below 500 MeV/c" << endl;
	fOutputFile << XimbarNumber << "\t" << "\t" << " = Number of Anti-Xi-" << endl;
	fOutputFile << XimXimbarPairsImpactparNumber << "\t" << "\t" << " = Number of Xi- Anti-Xi- pairs" << endl;
	fOutputFile << Xi0barNumber << "\t" << "\t" << " = Number of Anti-Xi0" << endl;
	fOutputFile << XimXi0barPairsImpactparNumber << "\t" << "\t" << " = Number of Xi- Anti-Xi0 pairs" << endl;
	fOutputFile << Xi0Number << "\t" << "\t" << " = Number of Xi0" << endl;
	fOutputFile << Xi0Xi0barPairsImpactparNumber << "\t" << "\t" << " = Number of Xi0 Anti-Xi0 pairs" << endl;
	fOutputFile << "" << endl;
	fOutputFile << "Real reactions:" << endl;
	fOutputFile << AntiProtonThetaNumber << "\t" << " = Number of Antiprotons" << endl;
	fOutputFile << AntiProtonThetaNumber_tLUMIcut << "\t" << "\t" << " = Number of Antiprotons in theta below LUMI" << endl;
	fOutputFile << "" << endl;
	fOutputFile << "Background:" << endl;
	fOutputFile << ChargedParticleThetaSiliconNumber << "\t" << " = Number of charged particles in theta of Silicon" << endl;
	fOutputFile << ChargedAntiNukleonThetaSiliconNumber << "\t" << "\t" << " = Number of Antiprotons in theta of Silicon" << endl;
	fOutputFile << ChargedNukleonThetaSiliconNumber << "\t" << "\t" << " = Number of Protons in theta of Silicon" << endl;
	fOutputFile << ChargedPionThetaSiliconNumber << "\t" << " = Number of charged Pions in theta of Silicon" << endl;
	fOutputFile << ChargedKaonThetaSiliconNumber << "\t" << "\t" << " = Number of charged Kaons in theta of Silicon" << endl;
	fOutputFile << NeutronThetaGeArrayNumber << "\t" << "\t" << " = Number of Neutrons in theta of Germanium array" << endl;
	fOutputFile << "" << endl;
	fOutputFile << "Background with cuts on momentum:" << endl;
	fOutputFile << ChargedParticleThetaSiliconNumber_pcut << "\t" << " = Number of charged particles in theta of Silicon (momentum cut)" << endl;
	//fOutputFile << ChargedAntiNukleonThetaSiliconNumber_pcut << "\t" << "\t" << " = Number of Antiprotons in theta of Silicon" << endl;
	fOutputFile << ChargedNukleonThetaSiliconNumber_pcut << "\t" << "\t" << " = Number of Protons in theta of Silicon" << endl;
	fOutputFile << ChargedPionThetaSiliconNumber_pcut << "\t" << " = Number of charged Pions in theta of Silicon" << endl;
	fOutputFile << ChargedKaonThetaSiliconNumber_pcut << "\t" << "\t" << " = Number of charged Kaons in theta of Silicon" << endl;
	fOutputFile << NeutronThetaGeArrayNumber << "\t" << "\t" << " = Number of Neutrons in theta of Germanium array" << endl;

	fOutputFile.close();


	// ----- Draw histograms (50*3) -------------------------------------------

	gROOT->SetStyle("Plain");
	gStyle->SetPalette(1);  // gStyle = global definitions, cannot be chosen for single canvas
	//gStyle->SetLineStyleString(11,"400 200");
	//gStyle->SetOptStat(1111111);  // Set stat options
	// statistics box top right:
	gStyle->SetStatX(0.87);  // Set x-position (fraction of pad size)
	gStyle->SetStatY(0.865);  // Set y-position (fraction of pad size)
	gStyle->SetStatW(0.20);  // Set width of stat-box (fraction of pad size)
	gStyle->SetStatH(0.12);  // Set height of stat-box (fraction of pad size)  // changes automatically in case of additional lines! Why?
	// statistics box top left:
	//gStyle->SetStatX(0.37);
	//gStyle->SetStatY(0.865);
	//gStyle->SetStatW(0.20);
	//gStyle->SetStatH(0.12);
	// statistics box colors:
	//gStyle->SetStatColor(kMagenta+3);
	//gStyle->SetStatTextColor(kMagenta+3);
	//gPad->UseCurrentStyle();  // Does not work with this line!
	TGaxis::SetMaxDigits(4);  // values at the axis only with X places

	Bool_t SavePictures = kTRUE;
	char buffer_multiplicity[100], buffer_multiplicityWhenAntiprotonsInEvent[100];
	char buffer_ximImpactpar[100], buffer_ximbarImpactpar[100], buffer_ximximbarpairsImpactpar[100];
	char buffer_xi0Impactpar[100], buffer_xi0barImpactpar[100], buffer_xi0xi0barpairsImpactpar[100];
	char buffer_ximxi0barpairsImpactpar[100];
	char buffer_xi[100], buffer_xim[100], buffer_xim500[100], buffer_ximbar[100], buffer_xi0bar[100], buffer_xi0[100];
	char buffer_xiTheta[100], buffer_ximTheta[100], buffer_xim500Theta[100], buffer_ximbarTheta[100], buffer_xi0barTheta[100], buffer_xi0Theta[100];
	char buffer_antipImpactpar[100], buffer_antipImpactpar_tLUMIcut[100];
	char buffer_antip[100], buffer_antipTheta[100], buffer_antipTheta_tcut[100], buffer_antipTheta_tLUMIcut[100];
	char buffer_antipTheta_mrad[100], buffer_antipTheta_mradcut[100];
	char buffer_p[100], buffer_n[100];
	char buffer_pThetaFW[100], buffer_pThetaSi[100], buffer_pThetaSiGe[100], buffer_pThetaGe[100], buffer_pThetaBW[100], buffer_pThetaSum[100];
	char buffer_nThetaFW[100], buffer_nThetaSi[100], buffer_nThetaSiGe[100], buffer_nThetaGe[100], buffer_nThetaBW[100], buffer_nThetaSum[100];
	char buffer_pionMultiplicity[100], buffer_pimMultiplicity[100];
	char buffer_pim[100], buffer_pip[100], buffer_kaonm[100], buffer_kaonp[100];
	char buffer_pimTheta[100], buffer_pipTheta[100], buffer_kaonmTheta[100], buffer_kaonpTheta[100];
	char buffer_cparticleThetaSilicon[100], buffer_cantinukleonThetaSilicon[100], buffer_cnukleonThetaSilicon[100], buffer_cpionThetaSilicon[100], buffer_ckaonThetaSilicon[100], buffer_sumThetaSilicon[100];
	char buffer_nparticleThetaGeArray[100];
	char buffer_cparticleThetaSilicon_pcut[100], buffer_cantinukleonThetaSilicon_pcut[100], buffer_cnukleonThetaSilicon_pcut[100], buffer_cpionThetaSilicon_pcut[100], buffer_ckaonThetaSilicon_pcut[100], buffer_sumThetaSilicon_pcut[100];
	sprintf(buffer_multiplicity, "all events = %d", Multiplicity);
	sprintf(buffer_multiplicityWhenAntiprotonsInEvent, "events with #bar{p} = %d", MultiplicityWhenAntiprotonsInEvent);
	sprintf(buffer_ximImpactpar, "#Xi^{-} = %d", XimImpactparNumber);
	sprintf(buffer_ximbarImpactpar, "#bar{#Xi}^{+} = %d", XimbarImpactparNumber);
	sprintf(buffer_ximximbarpairsImpactpar, "#Xi^{-} #bar{#Xi}^{+} pairs = %d", XimXimbarPairsImpactparNumber);
	sprintf(buffer_xi0barImpactpar, "#bar{#Xi}^{0} = %d", Xi0barImpactparNumber);
	sprintf(buffer_ximxi0barpairsImpactpar, "#Xi^{-} #bar{#Xi}^{0} pairs = %d", XimXi0barPairsImpactparNumber);
	sprintf(buffer_xi0Impactpar, "#Xi^{0} = %d", Xi0ImpactparNumber);
	sprintf(buffer_xi0xi0barpairsImpactpar, "#Xi^{-} #bar{#Xi}^{0} pairs = %d", XimXi0barPairsImpactparNumber);
	sprintf(buffer_xi, "all #Xi = %d", XiNumber);
	sprintf(buffer_xim, "#Xi^{-} = %d", XimNumber);
	sprintf(buffer_xim500, "#Xi^{-} < 500 MeV/c = %d", Xim500Number);
	sprintf(buffer_ximbar, "#bar{#Xi}^{+} = %d", XimbarNumber);
	sprintf(buffer_xi0bar, "#bar{#Xi}^{0} = %d", Xi0barNumber);
	sprintf(buffer_xi0, "#Xi^{0} = %d", Xi0Number);
	sprintf(buffer_xiTheta, "all #Xi = %d", XiThetaNumber);
	sprintf(buffer_ximTheta, "#Xi^{-} = %d", XimThetaNumber);
	sprintf(buffer_xim500Theta, "#Xi^{-} < 500 MeV/c = %d", Xim500ThetaNumber);
	sprintf(buffer_ximbarTheta, "#bar{#Xi}^{+} = %d", XimbarThetaNumber);
	sprintf(buffer_xi0barTheta, "#bar{#Xi}^{0} = %d", Xi0barThetaNumber);
	sprintf(buffer_xi0Theta, "#Xi^{0} = %d", Xi0ThetaNumber);
	sprintf(buffer_antipImpactpar, "#bar{p} = %d", AntiProtonImpactparNumber);
	//sprintf(buffer_antipImpactpar_tLUMIcut, "#bar{p} < 3 mrad = %d", AntiProtonImpactparNumber_tLUMIcut);
	sprintf(buffer_antipImpactpar_tLUMIcut, "#bar{p} < 2.857 mrad = %d", AntiProtonImpactparNumber_tLUMIcut);
	sprintf(buffer_antip, "#bar{p} = %d", AntiProtonNumber);
	sprintf(buffer_antipTheta, "#bar{p} = %d", AntiProtonThetaNumber);
	sprintf(buffer_antipTheta_tcut, "#bar{p} < 5#circ = %d", AntiProtonThetaNumber_tcut);
	//sprintf(buffer_antipTheta_tLUMIcut, "#bar{p} < 3 mrad = %d", AntiProtonThetaNumber_tLUMIcut);
	sprintf(buffer_antipTheta_tLUMIcut, "#bar{p} < 2.857 mrad = %d", AntiProtonThetaNumber_tLUMIcut);
	//sprintf(buffer_antipTheta_mrad, "#bar{p} < 3 mrad = %d", AntiProtonThetaNumber_mrad);
	sprintf(buffer_antipTheta_mrad, "#bar{p} < 2.857 mrad = %d", AntiProtonThetaNumber_mrad);
	sprintf(buffer_antipTheta_mradcut, "#bar{p} < 0.2 mrad = %d", AntiProtonThetaNumber_mradcut);
	sprintf(buffer_p, "p = %d", ProtonNumber);
	sprintf(buffer_n, "n = %d", NeutronNumber);
	sprintf(buffer_pThetaFW, "pFW = %d", ProtonThetaFWNumber);
	sprintf(buffer_pThetaSi, "pSi = %d", ProtonThetaSiNumber);
	sprintf(buffer_pThetaSiGe, "pSiGe = %d", ProtonThetaSiGeNumber);
	sprintf(buffer_pThetaGe, "pGe = %d", ProtonThetaGeNumber);
	sprintf(buffer_pThetaBW, "pBW = %d", ProtonThetaBWNumber);
	sprintf(buffer_pThetaSum, "sum = %d", ProtonThetaFWNumber + ProtonThetaSiNumber + ProtonThetaSiGeNumber + ProtonThetaGeNumber + ProtonThetaBWNumber);
	sprintf(buffer_nThetaFW, "nFW = %d", NeutronThetaFWNumber);
	sprintf(buffer_nThetaSi, "nSi = %d", NeutronThetaSiNumber);
	sprintf(buffer_nThetaSiGe, "nSiGe = %d", NeutronThetaSiGeNumber);
	sprintf(buffer_nThetaGe, "nGe = %d", NeutronThetaGeNumber);
	sprintf(buffer_nThetaBW, "nBW = %d", NeutronThetaBWNumber);
	sprintf(buffer_nThetaSum, "sum = %d", NeutronThetaFWNumber + NeutronThetaSiNumber + NeutronThetaSiGeNumber + NeutronThetaGeNumber + NeutronThetaBWNumber);
	sprintf(buffer_pionMultiplicity, "#pi entries = %d", PionMultiplicityNumber);
	sprintf(buffer_pimMultiplicity, "#pi^{-} entries = %d", PimMultiplicityNumber);
	sprintf(buffer_pim, "#pi^{-} = %d", PimNumber);
	sprintf(buffer_pip, "#pi^{+} = %d", PipNumber);
	sprintf(buffer_pimTheta, "#pi^{-} = %d", PimThetaNumber);
	sprintf(buffer_pipTheta, "#pi^{+} = %d", PipThetaNumber);
	sprintf(buffer_kaonm, "K^{-} = %d", KaonmNumber);
	sprintf(buffer_kaonp, "K^{+} = %d", KaonpNumber);
	sprintf(buffer_kaonmTheta, "K^{-} = %d", KaonmThetaNumber);
	sprintf(buffer_kaonpTheta, "K^{+} = %d", KaonpThetaNumber);
	sprintf(buffer_cparticleThetaSilicon, "cp = %d", ChargedParticleThetaSiliconNumber);
	sprintf(buffer_cantinukleonThetaSilicon, "#bar{p} = %d", ChargedAntiNukleonThetaSiliconNumber);
	sprintf(buffer_cnukleonThetaSilicon, "p = %d", ChargedNukleonThetaSiliconNumber);
	sprintf(buffer_cpionThetaSilicon, "#pi^{+/-} = %d", ChargedPionThetaSiliconNumber);
	sprintf(buffer_ckaonThetaSilicon, "K^{+/-} = %d", ChargedKaonThetaSiliconNumber);
	sprintf(buffer_sumThetaSilicon, "sum = %d", ChargedAntiNukleonThetaSiliconNumber + ChargedNukleonThetaSiliconNumber + ChargedPionThetaSiliconNumber + ChargedKaonThetaSiliconNumber);
	sprintf(buffer_nparticleThetaGeArray, "n = %d", NeutronThetaGeArrayNumber);
	sprintf(buffer_cparticleThetaSilicon_pcut, "cp = %d", ChargedParticleThetaSiliconNumber_pcut);
	//sprintf(buffer_cantinukleonThetaSilicon_pcut, "#bar{p} = %d", ChargedNukleonThetaSiliconNumber_pcut);
	sprintf(buffer_cnukleonThetaSilicon_pcut, "#splitline{p = %d}{(p_{p} > 153.7 MeV/c)}", ChargedNukleonThetaSiliconNumber_pcut);
	sprintf(buffer_cpionThetaSilicon_pcut, "#pi^{+/-} = %d", ChargedPionThetaSiliconNumber_pcut);
	sprintf(buffer_ckaonThetaSilicon_pcut, "K^{+/-} = %d", ChargedKaonThetaSiliconNumber_pcut);
	sprintf(buffer_sumThetaSilicon_pcut, "sum = %d", ChargedNukleonThetaSiliconNumber_pcut + ChargedPionThetaSiliconNumber_pcut + ChargedKaonThetaSiliconNumber_pcut);



	// Multiplicity histograms

	TCanvas *canMultiplicity = new TCanvas("canMultiplicity", "canMultiplicity", 0., 0., 800, 600);
	canMultiplicity->SetTicks(1,1);
	canMultiplicity->SetGridx(1);
	canMultiplicity->SetGridy(1);
	canMultiplicity->SetLogy(1);
	hisMultiplicity->Draw("");
	hisMultiplicity->SetLineWidth(2);
	hisMultiplicity->SetLineColor(kBlue);
	hisMultiplicityWhenAntiprotonsInEvent->Draw("same");
	hisMultiplicityWhenAntiprotonsInEvent->SetLineWidth(2);
	hisMultiplicityWhenAntiprotonsInEvent->SetLineColor(kRed);
	hisMultiplicity->SetTitle("Multiplicity of particles in events from GiBUU");
	//hisMultiplicity->GetXaxis()->SetRangeUser(,);
	hisMultiplicity->GetXaxis()->SetTitle("multiplicity");
	hisMultiplicity->GetXaxis()->SetTitleOffset(1.3);
	//hisMultiplicity->GetXaxis()->CenterTitle();
	hisMultiplicity->GetYaxis()->SetTitle("entries");
	hisMultiplicity->GetYaxis()->SetTitleOffset(1.2);
	//hisMultiplicity->GetYaxis()->CenterTitle();
	hisMultiplicity->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.50, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisMultiplicity, buffer_multiplicity, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisMultiplicityWhenAntiprotonsInEvent, buffer_multiplicityWhenAntiprotonsInEvent, "l");

	if(SavePictures == true) {
		canMultiplicity->Print(path+"/output_pd1c_multiplicity.png");
	}


	TCanvas *canMultiplicityOfAntiprotons = new TCanvas("canMultiplicityOfAntiprotons", "canMultiplicityOfAntiprotons", 0., 0., 800, 600);
	canMultiplicityOfAntiprotons->SetTicks(1,1);
	canMultiplicityOfAntiprotons->SetGridx(1);
	canMultiplicityOfAntiprotons->SetGridy(1);
	canMultiplicityOfAntiprotons->SetLogy(1);
	hisMultiplicityOfAntiprotonsInEvent->Draw("");
	hisMultiplicityOfAntiprotonsInEvent->SetLineWidth(2);
	hisMultiplicityOfAntiprotonsInEvent->SetLineColor(kBlue);
	hisMultiplicityOfAntiprotonsInEvent->SetTitle("Multiplicity of #bar{p} in events from GiBUU");
	//hisMultiplicityOfAntiprotonsInEvent->GetXaxis()->SetRangeUser(,);
	hisMultiplicityOfAntiprotonsInEvent->GetXaxis()->SetTitle("multiplicity");
	hisMultiplicityOfAntiprotonsInEvent->GetXaxis()->SetTitleOffset(1.3);
	//hisMultiplicityOfAntiprotonsInEvent->GetXaxis()->CenterTitle();
	hisMultiplicityOfAntiprotonsInEvent->GetYaxis()->SetTitle("entries");
	hisMultiplicityOfAntiprotonsInEvent->GetYaxis()->SetTitleOffset(1.2);
	//hisMultiplicityOfAntiprotonsInEvent->GetYaxis()->CenterTitle();
	//hisMultiplicityOfAntiprotonsInEvent->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canMultiplicityOfAntiprotons->Print(path+"/output_pd1c_multiplicity_antiprotons.png");
	}


	TCanvas *canPDGCodesForMultiplicity1 = new TCanvas("canPDGCodesForMultiplicity1", "canPDGCodesForMultiplicity1", 0., 0., 800, 600);
	canPDGCodesForMultiplicity1->SetTicks(1,1);
	canPDGCodesForMultiplicity1->SetGridx(1);
	canPDGCodesForMultiplicity1->SetGridy(1);
	//canPDGCodesForMultiplicity1->SetLogx(1);
	canPDGCodesForMultiplicity1->SetLogy(1);
	hisPDGCodesForMultiplicity1->Draw("");
	hisPDGCodesForMultiplicity1->SetLineWidth(1);
	hisPDGCodesForMultiplicity1->SetLineColor(kBlue);
	hisPDGCodesForMultiplicity1->SetTitle("PDG code for Multiplicity = 1 events from GiBUU");
	//hisPDGCodesForMultiplicity1->GetXaxis()->SetRangeUser(,);
	hisPDGCodesForMultiplicity1->GetXaxis()->SetTitle("PDG code");
	hisPDGCodesForMultiplicity1->GetXaxis()->SetTitleOffset(1.3);
	//hisPDGCodesForMultiplicity1->GetXaxis()->CenterTitle();
	hisPDGCodesForMultiplicity1->GetYaxis()->SetTitle("entries");
	hisPDGCodesForMultiplicity1->GetYaxis()->SetTitleOffset(1.2);
	//hisPDGCodesForMultiplicity1->GetYaxis()->CenterTitle();
	//hisPDGCodesForMultiplicity1->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canPDGCodesForMultiplicity1->Print(path+"/output_pd1c_pdgcodes_multiplicity1.png");
	}


	TCanvas *canPDGCodesForMultiplicity2 = new TCanvas("canPDGCodesForMultiplicity2", "canPDGCodesForMultiplicity2", 0., 0., 800, 600);
	canPDGCodesForMultiplicity2->SetTicks(1,1);
	canPDGCodesForMultiplicity2->SetGridx(1);
	canPDGCodesForMultiplicity2->SetGridy(1);
	//canPDGCodesForMultiplicity2->SetLogx(1);
	canPDGCodesForMultiplicity2->SetLogy(1);
	hisPDGCodesForMultiplicity2->Draw("");
	hisPDGCodesForMultiplicity2->SetLineWidth(1);
	hisPDGCodesForMultiplicity2->SetLineColor(kBlue);
	hisPDGCodesForMultiplicity2->SetTitle("PDG code for Multiplicity = 2 events from GiBUU");
	//hisPDGCodesForMultiplicity2->GetXaxis()->SetRangeUser(,);
	hisPDGCodesForMultiplicity2->GetXaxis()->SetTitle("PDG code");
	hisPDGCodesForMultiplicity2->GetXaxis()->SetTitleOffset(1.3);
	//hisPDGCodesForMultiplicity2->GetXaxis()->CenterTitle();
	hisPDGCodesForMultiplicity2->GetYaxis()->SetTitle("entries");
	hisPDGCodesForMultiplicity2->GetYaxis()->SetTitleOffset(1.2);
	//hisPDGCodesForMultiplicity2->GetYaxis()->CenterTitle();
	//hisPDGCodesForMultiplicity2->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canPDGCodesForMultiplicity2->Print(path+"/output_pd1c_pdgcodes_multiplicity2.png");
	}


	TCanvas *canPDGCodesForMultiplicity3 = new TCanvas("canPDGCodesForMultiplicity3", "canPDGCodesForMultiplicity3", 0., 0., 800, 600);
	canPDGCodesForMultiplicity3->SetTicks(1,1);
	canPDGCodesForMultiplicity3->SetGridx(1);
	canPDGCodesForMultiplicity3->SetGridy(1);
	//canPDGCodesForMultiplicity3->SetLogx(1);
	canPDGCodesForMultiplicity3->SetLogy(1);
	hisPDGCodesForMultiplicity3->Draw("");
	hisPDGCodesForMultiplicity3->SetLineWidth(1);
	hisPDGCodesForMultiplicity3->SetLineColor(kBlue);
	hisPDGCodesForMultiplicity3->SetTitle("PDG code for Multiplicity = 3 events from GiBUU");
	//hisPDGCodesForMultiplicity3->GetXaxis()->SetRangeUser(,);
	hisPDGCodesForMultiplicity3->GetXaxis()->SetTitle("PDG code");
	hisPDGCodesForMultiplicity3->GetXaxis()->SetTitleOffset(1.3);
	//hisPDGCodesForMultiplicity3->GetXaxis()->CenterTitle();
	hisPDGCodesForMultiplicity3->GetYaxis()->SetTitle("entries");
	hisPDGCodesForMultiplicity3->GetYaxis()->SetTitleOffset(1.2);
	//hisPDGCodesForMultiplicity3->GetYaxis()->CenterTitle();
	//hisPDGCodesForMultiplicity3->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canPDGCodesForMultiplicity3->Print(path+"/output_pd1c_pdgcodes_multiplicity3.png");
	}


	TCanvas *canPDGCodesForMultiplicity4 = new TCanvas("canPDGCodesForMultiplicity4", "canPDGCodesForMultiplicity4", 0., 0., 800, 600);
	canPDGCodesForMultiplicity4->SetTicks(1,1);
	canPDGCodesForMultiplicity4->SetGridx(1);
	canPDGCodesForMultiplicity4->SetGridy(1);
	//canPDGCodesForMultiplicity4->SetLogx(1);
	canPDGCodesForMultiplicity4->SetLogy(1);
	hisPDGCodesForMultiplicity4->Draw("");
	hisPDGCodesForMultiplicity4->SetLineWidth(1);
	hisPDGCodesForMultiplicity4->SetLineColor(kBlue);
	hisPDGCodesForMultiplicity4->SetTitle("PDG code for Multiplicity = 4 events from GiBUU");
	//hisPDGCodesForMultiplicity4->GetXaxis()->SetRangeUser(,);
	hisPDGCodesForMultiplicity4->GetXaxis()->SetTitle("PDG code");
	hisPDGCodesForMultiplicity4->GetXaxis()->SetTitleOffset(1.3);
	//hisPDGCodesForMultiplicity4->GetXaxis()->CenterTitle();
	hisPDGCodesForMultiplicity4->GetYaxis()->SetTitle("entries");
	hisPDGCodesForMultiplicity4->GetYaxis()->SetTitleOffset(1.2);
	//hisPDGCodesForMultiplicity4->GetYaxis()->CenterTitle();
	//hisPDGCodesForMultiplicity4->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canPDGCodesForMultiplicity4->Print(path+"/output_pd1c_pdgcodes_multiplicity4.png");
	}


	TCanvas *canPionMultiplicity = new TCanvas("canPionMultiplicity", "canPionMultiplicity", 0., 0., 800, 600);
	canPionMultiplicity->SetTicks(1,1);
	canPionMultiplicity->SetGridx(1);
	canPionMultiplicity->SetGridy(1);
	//canPionMultiplicity->SetLogy(1);
	hisPimMultiplicity->Draw("");
	hisPimMultiplicity->SetLineWidth(2);
	hisPimMultiplicity->SetLineColor(kBlue);
	hisPionMultiplicity->Draw("same");
	hisPionMultiplicity->SetLineWidth(2);
	hisPionMultiplicity->SetLineColor(kBlack);
	hisPimMultiplicity->SetTitle("Multiplicity of #pi in events from GiBUU");
	//hisPimMultiplicity->GetXaxis()->SetRangeUser(,);
	hisPimMultiplicity->GetXaxis()->SetTitle("multiplicity");
	hisPimMultiplicity->GetXaxis()->SetTitleOffset(1.3);
	//hisPimMultiplicity->GetXaxis()->CenterTitle();
	hisPimMultiplicity->GetYaxis()->SetTitle("entries");
	hisPimMultiplicity->GetYaxis()->SetTitleOffset(1.2);
	//hisPimMultiplicity->GetYaxis()->CenterTitle();
	hisPimMultiplicity->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.50, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisPionMultiplicity, buffer_pionMultiplicity, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisPimMultiplicity, buffer_pimMultiplicity, "l");

	if(SavePictures == true) {
		canPionMultiplicity->Print(path+"/output_pd1c_multiplicity_pions.png");
	}



	// Xi histograms

	TCanvas *canImpactparXimXimbar = new TCanvas("canImpactparXimXimbar", "canImpactparXimXimbar", 0., 0., 800, 600);
	canImpactparXimXimbar->SetTicks(1,1);
	canImpactparXimXimbar->SetGridx(1);
	canImpactparXimXimbar->SetGridy(1);
	hisXimImpactparDistr->Draw("");
	hisXimImpactparDistr->SetLineWidth(1);
	hisXimImpactparDistr->SetLineColor(kBlue);
	hisXimbarImpactparDistr->Draw("same");
	hisXimbarImpactparDistr->SetLineWidth(1);
	hisXimbarImpactparDistr->SetLineColor(kOrange+7);
	hisXimXimbarPairsImpactparDistr->Draw("same");
	hisXimXimbarPairsImpactparDistr->SetLineWidth(2);
	hisXimXimbarPairsImpactparDistr->SetLineColor(kYellow+1);
	hisXimImpactparDistr->SetTitle("Impact parameter distribution of #Xi^{-}, #bar{#Xi}^{+} and pairs from GiBUU");
	//hisXimImpactparDistr->GetXaxis()->SetRangeUser(,);
	hisXimImpactparDistr->GetXaxis()->SetTitle("impact parameter [fm]");
	hisXimImpactparDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXimImpactparDistr->GetXaxis()->CenterTitle();
	hisXimImpactparDistr->GetYaxis()->SetTitle("entries");
	hisXimImpactparDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXimImpactparDistr->GetYaxis()->CenterTitle();
	hisXimImpactparDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.62, 0.705, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisXimImpactparDistr, buffer_ximImpactpar, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisXimbarImpactparDistr, buffer_ximbarImpactpar, "l");
	leg->AddEntry(hisXimXimbarPairsImpactparDistr, buffer_ximximbarpairsImpactpar, "l");

	if(SavePictures == true) {
		canImpactparXimXimbar->Print(path+"/output_pd1c_ximximbar_impactpar.png");
	}


	TCanvas *canImpactparXimXi0bar = new TCanvas("canImpactparXimXi0bar", "canImpactparXimXi0bar", 0., 0., 800, 600);
	canImpactparXimXi0bar->SetTicks(1,1);
	canImpactparXimXi0bar->SetGridx(1);
	canImpactparXimXi0bar->SetGridy(1);
	hisXimImpactparDistr->Draw("");
	hisXimImpactparDistr->SetLineWidth(1);
	hisXimImpactparDistr->SetLineColor(kBlue);
	hisXi0barImpactparDistr->Draw("same");
	hisXi0barImpactparDistr->SetLineWidth(1);
	hisXi0barImpactparDistr->SetLineColor(kOrange+7);
	hisXimXi0barPairsImpactparDistr->Draw("same");
	hisXimXi0barPairsImpactparDistr->SetLineWidth(2);
	hisXimXi0barPairsImpactparDistr->SetLineColor(kYellow+1);
	hisXimImpactparDistr->SetTitle("Impact parameter distribution of #Xi^{-}, #bar{#Xi}^{0} and pairs from GiBUU");
	//hisXimImpactparDistr->GetXaxis()->SetRangeUser(,);
	hisXimImpactparDistr->GetXaxis()->SetTitle("impact parameter [fm]");
	hisXimImpactparDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXimImpactparDistr->GetXaxis()->CenterTitle();
	hisXimImpactparDistr->GetYaxis()->SetTitle("entries");
	hisXimImpactparDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXimImpactparDistr->GetYaxis()->CenterTitle();
	hisXimImpactparDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.62, 0.705, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisXimImpactparDistr, buffer_ximImpactpar, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisXi0barImpactparDistr, buffer_xi0barImpactpar, "l");
	leg->AddEntry(hisXimXi0barPairsImpactparDistr, buffer_ximxi0barpairsImpactpar, "l");

	if(SavePictures == true) {
		canImpactparXimXi0bar->Print(path+"/output_pd1c_ximxi0bar_impactpar.png");
	}


	TCanvas *canImpactparXi0Xi0bar = new TCanvas("canImpactparXi0Xi0bar", "canImpactparXi0Xi0bar", 0., 0., 800, 600);
	canImpactparXi0Xi0bar->SetTicks(1,1);
	canImpactparXi0Xi0bar->SetGridx(1);
	canImpactparXi0Xi0bar->SetGridy(1);
	hisXi0ImpactparDistr->Draw("");
	hisXi0ImpactparDistr->SetLineWidth(1);
	hisXi0ImpactparDistr->SetLineColor(kBlue);
	hisXi0barImpactparDistr->Draw("same");
	hisXi0barImpactparDistr->SetLineWidth(1);
	hisXi0barImpactparDistr->SetLineColor(kOrange+7);
	hisXi0Xi0barPairsImpactparDistr->Draw("same");
	hisXi0Xi0barPairsImpactparDistr->SetLineWidth(2);
	hisXi0Xi0barPairsImpactparDistr->SetLineColor(kYellow+1);
	hisXi0ImpactparDistr->SetTitle("Impact parameter distribution of #Xi^{0}, #bar{#Xi}^{0} and pairs from GiBUU");
	//hisXi0ImpactparDistr->GetXaxis()->SetRangeUser(,);
	hisXi0ImpactparDistr->GetXaxis()->SetTitle("impact parameter [fm]");
	hisXi0ImpactparDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXi0ImpactparDistr->GetXaxis()->CenterTitle();
	hisXi0ImpactparDistr->GetYaxis()->SetTitle("entries");
	hisXi0ImpactparDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXi0ImpactparDistr->GetYaxis()->CenterTitle();
	hisXi0ImpactparDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.62, 0.705, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisXi0ImpactparDistr, buffer_xi0Impactpar, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisXi0barImpactparDistr, buffer_xi0barImpactpar, "l");
	leg->AddEntry(hisXi0Xi0barPairsImpactparDistr, buffer_xi0xi0barpairsImpactpar, "l");

	if(SavePictures == true) {
		canImpactparXi0Xi0bar->Print(path+"/output_pd1c_xi0xi0bar_impactpar.png");
	}


	TCanvas *canMomXim = new TCanvas("canMomXim", "canMomXim", 0., 0., 800, 600);
	canMomXim->SetTicks(1,1);
	canMomXim->SetGridx(1);
	canMomXim->SetGridy(1);
	hisXimMomDistr->Draw("");
	hisXimMomDistr->SetLineWidth(1);
	hisXimMomDistr->SetLineColor(kBlue);
	hisXim500MomDistr->Draw("same");
	hisXim500MomDistr->SetLineWidth(1);
	hisXim500MomDistr->SetLineColor(kGreen-3);
	hisXimMomDistr->SetTitle("Momentum distribution of #Xi^{-} from GiBUU");
	//hisXimMomDistr->GetXaxis()->SetRangeUser(,);
	hisXimMomDistr->GetXaxis()->SetTitle("momentum [GeV/c]");
	hisXimMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXimMomDistr->GetXaxis()->CenterTitle();
	hisXimMomDistr->GetYaxis()->SetTitle("entries");
	hisXimMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXimMomDistr->GetYaxis()->CenterTitle();
	hisXimMomDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.59, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisXimMomDistr, buffer_xim, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisXim500MomDistr, buffer_xim500, "l");

	if(SavePictures == true) {
		canMomXim->Print(path+"/output_pd1c_xim_mom.png");
	}


	TCanvas *canMomXiXibar = new TCanvas("canMomXiXibar", "canMomXiXibar", 0., 0., 800, 600);
	canMomXiXibar->SetTicks(1,1);
	canMomXiXibar->SetGridx(1);
	canMomXiXibar->SetGridy(1);
	TH1D *hisXimMomDistr2 = (TH1D*) hisXimMomDistr->Clone(); 
	hisXimMomDistr2->Draw("");
	hisXimMomDistr2->SetLineWidth(1);
	hisXimMomDistr2->SetLineColor(kBlue);
	hisXimbarMomDistr->Draw("same");
	hisXimbarMomDistr->SetLineWidth(1);
	hisXimbarMomDistr->SetLineColor(kOrange+7);
	hisXi0barMomDistr->Draw("same");
	hisXi0barMomDistr->SetLineWidth(1);
	hisXi0barMomDistr->SetLineColor(kBlack);
	hisXi0MomDistr->Draw("same");
	hisXi0MomDistr->SetLineWidth(1);
	hisXi0MomDistr->SetLineColor(kMagenta+1);
	hisXimMomDistr2->SetTitle("Momentum distribution of #Xi^{-}, #bar{#Xi}^{+}, #bar{#Xi}^{0} and #Xi^{0} from GiBUU");
	//hisXimMomDistr2->GetXaxis()->SetRangeUser(,);
	hisXimMomDistr2->GetXaxis()->SetTitle("momentum [GeV/c]");
	hisXimMomDistr2->GetXaxis()->SetTitleOffset(1.3);
	//hisXimMomDistr2->GetXaxis()->CenterTitle();
	hisXimMomDistr2->GetYaxis()->SetTitle("entries");
	hisXimMomDistr2->GetYaxis()->SetTitleOffset(1.2);
	//hisXimMomDistr2->GetYaxis()->CenterTitle();
	hisXimMomDistr2->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.71, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisXimMomDistr2, buffer_xim, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisXimbarMomDistr, buffer_ximbar, "l");
	leg->AddEntry(hisXi0barMomDistr, buffer_xi0bar, "l");
	leg->AddEntry(hisXi0MomDistr, buffer_xi0, "l");

	if(SavePictures == true) {
		canMomXiXibar->Print(path+"/output_pd1c_xixibar_mom.png");
	}


	TCanvas *canMomXi = new TCanvas("canMomXi", "canMomXi", 0., 0., 800, 600);
	canMomXi->SetTicks(1,1);
	canMomXi->SetGridx(1);
	canMomXi->SetGridy(1);
	hisXiMomDistr->Draw("");
	hisXiMomDistr->SetLineWidth(1);
	hisXiMomDistr->SetLineColor(kBlack);
	hisXimMomDistr->Draw("same");
	//hisXimMomDistr->SetLineWidth(1);  // already defined above
	//hisXimMomDistr->SetLineColor(kBlue);  // already defined above
	hisXi0MomDistr->Draw("same");
	hisXi0MomDistr->SetLineWidth(1);
	hisXi0MomDistr->SetLineColor(kMagenta+1);
	hisXiMomDistr->SetTitle("Momentum distribution of #Xi from GiBUU");
	//hisXiMomDistr->GetXaxis()->SetRangeUser(,);
	hisXiMomDistr->GetXaxis()->SetTitle("momentum [GeV/c]");
	hisXiMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXiMomDistr->GetXaxis()->CenterTitle();
	hisXiMomDistr->GetYaxis()->SetTitle("entries");
	hisXiMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXiMomDistr->GetYaxis()->CenterTitle();
	hisXiMomDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.68, 0.705, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisXiMomDistr, buffer_xi, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisXimMomDistr, buffer_xim, "l");
	leg->AddEntry(hisXi0MomDistr, buffer_xi0, "l");

	if(SavePictures == true) {
		canMomXi->Print(path+"/output_pd1c_xis_mom.png");
	}


	TCanvas *canThetaXim = new TCanvas("canThetaXim", "canThetaXim", 0., 0., 800, 600);
	canThetaXim->SetTicks(1,1);
	canThetaXim->SetGridx(1);
	canThetaXim->SetGridy(1);
	hisXimThetaDistr->Draw("");
	hisXimThetaDistr->SetLineWidth(1);
	hisXimThetaDistr->SetLineColor(kBlue);
	hisXim500ThetaDistr->Draw("same");
	hisXim500ThetaDistr->SetLineWidth(1);
	hisXim500ThetaDistr->SetLineColor(kGreen-3);
	hisXimThetaDistr->SetTitle("Theta distribution of #Xi^{-} from GiBUU");
	//hisXimThetaDistr->GetXaxis()->SetRangeUser(,);
	hisXimThetaDistr->GetXaxis()->SetTitle("theta [degree]");
	hisXimThetaDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXimThetaDistr->GetXaxis()->CenterTitle();
	hisXimThetaDistr->GetYaxis()->SetTitle("entries");
	hisXimThetaDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXimThetaDistr->GetYaxis()->CenterTitle();
	hisXimThetaDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.59, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisXimThetaDistr, buffer_ximTheta, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisXim500ThetaDistr, buffer_xim500Theta, "l");

	if(SavePictures == true) {
		canThetaXim->Print(path+"/output_pd1c_xim_theta.png");
	}


	TCanvas *canThetaXiXibar = new TCanvas("canThetamXiXibar", "canThetaXiXibar", 0., 0., 800, 600);
	canThetaXiXibar->SetTicks(1,1);
	canThetaXiXibar->SetGridx(1);
	canThetaXiXibar->SetGridy(1);
	TH1D *hisXimThetaDistr2 = (TH1D*) hisXimThetaDistr->Clone(); 
	hisXimThetaDistr2->Draw("");
	hisXimThetaDistr2->SetLineWidth(1);
	hisXimThetaDistr2->SetLineColor(kBlue);
	hisXimbarThetaDistr->Draw("same");
	hisXimbarThetaDistr->SetLineWidth(1);
	hisXimbarThetaDistr->SetLineColor(kOrange+7);
	hisXi0barThetaDistr->Draw("same");
	hisXi0barThetaDistr->SetLineWidth(1);
	hisXi0barThetaDistr->SetLineColor(kBlack);
	hisXi0ThetaDistr->Draw("same");
	hisXi0ThetaDistr->SetLineWidth(1);
	hisXi0ThetaDistr->SetLineColor(kMagenta+1);
	hisXimThetaDistr2->SetTitle("Theta distribution of #Xi^{-}, #bar{#Xi}^{+}, #bar{#Xi}^{0} and #Xi^{0} from GiBUU");
	//hisXimThetaDistr2->GetXaxis()->SetRangeUser(,);
	hisXimThetaDistr2->GetXaxis()->SetTitle("theta [degree]");
	hisXimThetaDistr2->GetXaxis()->SetTitleOffset(1.3);
	//hisXimThetaDistr2->GetXaxis()->CenterTitle();
	hisXimThetaDistr2->GetYaxis()->SetTitle("entries");
	hisXimThetaDistr2->GetYaxis()->SetTitleOffset(1.2);
	//hisXimThetaDistr2->GetYaxis()->CenterTitle();
	hisXimThetaDistr2->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.71, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisXimThetaDistr2, buffer_ximTheta, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisXimbarThetaDistr, buffer_ximbarTheta, "l");
	leg->AddEntry(hisXi0barThetaDistr, buffer_xi0barTheta, "l");
	leg->AddEntry(hisXi0ThetaDistr, buffer_xi0Theta, "l");

	if(SavePictures == true) {
		canThetaXiXibar->Print(path+"/output_pd1c_xixibar_theta.png");
	}


	TCanvas *canThetaXi = new TCanvas("canThetaXi", "canThetaXi", 0., 0., 800, 600);
	canThetaXi->SetTicks(1,1);
	canThetaXi->SetGridx(1);
	canThetaXi->SetGridy(1);
	hisXiThetaDistr->Draw("");
	hisXiThetaDistr->SetLineWidth(1);
	hisXiThetaDistr->SetLineColor(kBlack);
	hisXimThetaDistr->Draw("same");
	//hisXimThetaDistr->SetLineWidth(1);  // already defined above
	//hisXimThetaDistr->SetLineColor(kBlue);  // already defined above
	hisXi0ThetaDistr->Draw("same");
	hisXi0ThetaDistr->SetLineWidth(1);
	hisXi0ThetaDistr->SetLineColor(kMagenta+1);
	hisXiThetaDistr->SetTitle("Theta distribution of #Xi from GiBUU");
	//hisXiThetaDistr->GetXaxis()->SetRangeUser(,);
	hisXiThetaDistr->GetXaxis()->SetTitle("theta [degree]");
	hisXiThetaDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXiThetaDistr->GetXaxis()->CenterTitle();
	hisXiThetaDistr->GetYaxis()->SetTitle("entries");
	hisXiThetaDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXiThetaDistr->GetYaxis()->CenterTitle();
	hisXiThetaDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.68, 0.705, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisXiThetaDistr, buffer_xiTheta, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisXimThetaDistr, buffer_ximTheta, "l");
	leg->AddEntry(hisXi0ThetaDistr, buffer_xi0Theta, "l");

	if(SavePictures == true) {
		canThetaXi->Print(path+"/output_pd1c_xis_theta.png");
	}


	TCanvas *canThetaMomXi = new TCanvas("canThetaMomXi", "canThetaMomXi", 0., 0., 800, 600);
	canThetaMomXi->SetTicks(1,1);
	canThetaMomXi->SetGridx(1);
	canThetaMomXi->SetGridy(1);
	hisXiThetaMomDistr->Draw("colz");
	hisXiThetaMomDistr->SetLineWidth(1);
	hisXiThetaMomDistr->SetLineColor(kBlack);
	hisXiThetaMomDistr->SetTitle("Theta-momentum distribution of #Xi from GiBUU");
	//hisXiThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisXiThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisXiThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXiThetaMomDistr->GetXaxis()->CenterTitle();
	hisXiThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisXiThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXiThetaMomDistr->GetYaxis()->CenterTitle();
	//hisXiThetaMomDistr->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canThetaMomXi->Print(path+"/output_pd1c_xis_theta_mom.png");
	}


	TCanvas *canThetaMomXim = new TCanvas("canThetaMomXim", "canThetaMomXim", 0., 0., 800, 600);
	canThetaMomXim->SetTicks(1,1);
	canThetaMomXim->SetGridx(1);
	canThetaMomXim->SetGridy(1);
	hisXimThetaMomDistr->Draw("colz");
	hisXimThetaMomDistr->SetLineWidth(1);
	hisXimThetaMomDistr->SetLineColor(kBlack);
	hisXimThetaMomDistr->SetTitle("Theta-momentum distribution of #Xi^{-} from GiBUU");
	//hisXimThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisXimThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisXimThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXimThetaMomDistr->GetXaxis()->CenterTitle();
	hisXimThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisXimThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXimThetaMomDistr->GetYaxis()->CenterTitle();
	//hisXimThetaMomDistr->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canThetaMomXim->Print(path+"/output_pd1c_xim_theta_mom.png");
	}


	TCanvas *canThetaMomXimbar = new TCanvas("canThetaMomXimbar", "canThetaMomXimbar", 0., 0., 800, 600);
	canThetaMomXimbar->SetTicks(1,1);
	canThetaMomXimbar->SetGridx(1);
	canThetaMomXimbar->SetGridy(1);
	hisXimbarThetaMomDistr->Draw("colz");
	hisXimbarThetaMomDistr->SetLineWidth(1);
	hisXimbarThetaMomDistr->SetLineColor(kBlack);
	hisXimbarThetaMomDistr->SetTitle("Theta-momentum distribution of #bar{#Xi}^{+} from GiBUU");
	//hisXimbarThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisXimbarThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisXimbarThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXimbarThetaMomDistr->GetXaxis()->CenterTitle();
	hisXimbarThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisXimbarThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXimbarThetaMomDistr->GetYaxis()->CenterTitle();
	//hisXimbarThetaMomDistr->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canThetaMomXimbar->Print(path+"/output_pd1c_ximbar_theta_mom.png");
	}


	TCanvas *canThetaMomXi0bar = new TCanvas("canThetaMomXi0bar", "canThetaMomXi0bar", 0., 0., 800, 600);
	canThetaMomXi0bar->SetTicks(1,1);
	canThetaMomXi0bar->SetGridx(1);
	canThetaMomXi0bar->SetGridy(1);
	hisXi0barThetaMomDistr->Draw("colz");
	hisXi0barThetaMomDistr->SetLineWidth(1);
	hisXi0barThetaMomDistr->SetLineColor(kBlack);
	hisXi0barThetaMomDistr->SetTitle("Theta-momentum distribution of #bar{#Xi}^{0} from GiBUU");
	//hisXi0barThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisXi0barThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisXi0barThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXi0barThetaMomDistr->GetXaxis()->CenterTitle();
	hisXi0barThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisXi0barThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXi0barThetaMomDistr->GetYaxis()->CenterTitle();
	//hisXi0barThetaMomDistr->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canThetaMomXi0bar->Print(path+"/output_pd1c_xi0bar_theta_mom.png");
	}


	TCanvas *canThetaMomXi0 = new TCanvas("canThetaMomXi0", "canThetaMomXi0", 0., 0., 800, 600);
	canThetaMomXi0->SetTicks(1,1);
	canThetaMomXi0->SetGridx(1);
	canThetaMomXi0->SetGridy(1);
	hisXi0ThetaMomDistr->Draw("colz");
	hisXi0ThetaMomDistr->SetLineWidth(1);
	hisXi0ThetaMomDistr->SetLineColor(kBlack);
	hisXi0ThetaMomDistr->SetTitle("Theta-momentum distribution of #Xi^{0} from GiBUU");
	//hisXi0ThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisXi0ThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisXi0ThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisXi0ThetaMomDistr->GetXaxis()->CenterTitle();
	hisXi0ThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisXi0ThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisXi0ThetaMomDistr->GetYaxis()->CenterTitle();
	//hisXi0ThetaMomDistr->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canThetaMomXi0->Print(path+"/output_pd1c_xi0_theta_mom.png");
	}



	// Antiproton histograms

	TCanvas *canImpactparAntiProtons = new TCanvas("canImpactparAntiProtons", "canImpactparAntiProtons", 0., 0., 800, 600);
	canImpactparAntiProtons->SetTicks(1,1);
	canImpactparAntiProtons->SetGridx(1);
	canImpactparAntiProtons->SetGridy(1);
	hisAntiProtonImpactparDistr->Draw("");
	hisAntiProtonImpactparDistr->SetLineWidth(1);
	hisAntiProtonImpactparDistr->SetLineColor(kBlue);
	hisAntiProtonImpactparDistr_tLUMIcut->Draw("same");
	hisAntiProtonImpactparDistr_tLUMIcut->SetLineWidth(1);
	hisAntiProtonImpactparDistr_tLUMIcut->SetLineColor(kGreen-3);
	hisAntiProtonImpactparDistr->SetTitle("Impact parameter distribution of #bar{p} from GiBUU");
	//hisAntiProtonImpactparDistr->GetXaxis()->SetRangeUser(,);
	hisAntiProtonImpactparDistr->GetXaxis()->SetTitle("impact parameter [fm]");
	hisAntiProtonImpactparDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisAntiProtonImpactparDistr->GetXaxis()->CenterTitle();
	hisAntiProtonImpactparDistr->GetYaxis()->SetTitle("entries");
	hisAntiProtonImpactparDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisAntiProtonImpactparDistr->GetYaxis()->CenterTitle();
	//hisAntiProtonImpactparDistr->GetYaxis()->SetNoExponent(kTRUE);  // Bool_t noExponent = kTRUE  // no exponent at the axis
	hisAntiProtonImpactparDistr->SetStats(0);  // removes statistics

	//canImpactparAntiProtons->Update();
	//TPaveStats* statsbox_hisAntiProtonImpactparDistr = (TPaveStats*) hisAntiProtonImpactparDistr->GetListOfFunctions()->FindObject("stats");
	//statsbox_hisAntiProtonImpactparDistr->SetX1NDC(0.17); // new x start position
	//statsbox_hisAntiProtonImpactparDistr->SetX2NDC(0.37); // new x end position
	//statsbox_hisAntiProtonImpactparDistr->SetY1NDC(0.745);
	//statsbox_hisAntiProtonImpactparDistr->SetY2NDC(0.865);
	//statsbox_hisAntiProtonImpactparDistr->SetTextColor(kBlack);
	//canImpactparAntiProtons->Modified();
	//canImpactparAntiProtons->Update();

	// ------ Creation of a legend ------
	//TLegend* leg = new TLegend(0.17, 0.665, 0.47, 0.745);  // (x1, y1, x2, y2) with statistics box
	TLegend* leg = new TLegend(0.17, 0.765, 0.47, 0.865);  // (x1, y1, x2, y2) without statistics box
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisAntiProtonImpactparDistr, buffer_antipImpactpar, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisAntiProtonImpactparDistr_tLUMIcut, buffer_antipImpactpar_tLUMIcut, "l");

	if(SavePictures == true) {
		canImpactparAntiProtons->Print(path+"/output_pd1c_antiprotons_impactpar.png");
	}


	TCanvas *canPositionAntiProtons = new TCanvas("canPositionAntiProtons", "canPositionAntiProtons", 0., 0., 800, 600);
	canPositionAntiProtons->SetTicks(1,1);
	canPositionAntiProtons->SetGridx(1);
	canPositionAntiProtons->SetGridy(1);
	canPositionAntiProtons->SetLogy(1);
	hisAntiProtonPositionDistr->Draw("");
	hisAntiProtonPositionDistr->SetLineWidth(1);
	hisAntiProtonPositionDistr->SetLineColor(kBlue);
	hisAntiProtonPositionDistr->SetTitle("Position distribution of #bar{p} from GiBUU");
	//hisAntiProtonPositionDistr->GetXaxis()->SetRangeUser(,);
	hisAntiProtonPositionDistr->GetXaxis()->SetTitle("radial position [fm]");
	hisAntiProtonPositionDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisAntiProtonPositionDistr->GetXaxis()->CenterTitle();
	hisAntiProtonPositionDistr->GetYaxis()->SetTitle("entries");
	hisAntiProtonPositionDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisAntiProtonPositionDistr->GetYaxis()->CenterTitle();
	//hisAntiProtonPositionDistr->GetYaxis()->SetNoExponent(kTRUE);  // Bool_t noExponent = kTRUE  // no exponent at the axis
	//hisAntiProtonPositionDistr->SetStats(0);  // removes statistics

	//canPositionAntiProtons->Update();
	//TPaveStats* statsbox_hisAntiProtonPositionDistr = (TPaveStats*) hisAntiProtonPositionDistr->GetListOfFunctions()->FindObject("stats");
	//statsbox_hisAntiProtonPositionDistr->SetX1NDC(0.17); // new x start position
	//statsbox_hisAntiProtonPositionDistr->SetX2NDC(0.37); // new x end position
	//statsbox_hisAntiProtonPositionDistr->SetY1NDC(0.745);
	//statsbox_hisAntiProtonPositionDistr->SetY2NDC(0.865);
	//statsbox_hisAntiProtonPositionDistr->SetTextColor(kBlack);
	//canPositionAntiProtons->Modified();
	//canPositionAntiProtons->Update();

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.67, 0.685, 0.87, 0.745);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisAntiProtonPositionDistr, buffer_antip, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canPositionAntiProtons->Print(path+"/output_pd1c_antiprotons_position.png");
	}


	TCanvas *canMomAntiProtons = new TCanvas("canMomAntiProtons", "canMomAntiProtons", 0., 0., 800, 600);
	canMomAntiProtons->SetTicks(1,1);
	canMomAntiProtons->SetGridx(1);
	canMomAntiProtons->SetGridy(1);
	hisAntiProtonMomDistr->Draw("");
	hisAntiProtonMomDistr->SetLineWidth(1);
	hisAntiProtonMomDistr->SetLineColor(kBlue);
	hisAntiProtonMomDistr->SetTitle("Momentum distribution of #bar{p} from GiBUU");
	//hisAntiProtonMomDistr->GetXaxis()->SetRangeUser(,);
	hisAntiProtonMomDistr->GetXaxis()->SetTitle("momentum [GeV/c]");
	hisAntiProtonMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisAntiProtonMomDistr->GetXaxis()->CenterTitle();
	hisAntiProtonMomDistr->GetYaxis()->SetTitle("entries");
	hisAntiProtonMomDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisAntiProtonMomDistr->GetYaxis()->CenterTitle();
	//hisAntiProtonMomDistr->GetYaxis()->SetNoExponent(kTRUE);  // Bool_t noExponent = kTRUE  // no exponent at the axis
	//hisAntiProtonMomDistr->SetStats(0);  // removes statistics

	canMomAntiProtons->Update();
	TPaveStats* statsbox_hisAntiProtonMomDistr = (TPaveStats*) hisAntiProtonMomDistr->GetListOfFunctions()->FindObject("stats");
	statsbox_hisAntiProtonMomDistr->SetX1NDC(0.17); // new x start position
	statsbox_hisAntiProtonMomDistr->SetX2NDC(0.37); // new x end position
	statsbox_hisAntiProtonMomDistr->SetY1NDC(0.745);
	statsbox_hisAntiProtonMomDistr->SetY2NDC(0.865);
	statsbox_hisAntiProtonMomDistr->SetTextColor(kBlack);
	canMomAntiProtons->Modified();
	canMomAntiProtons->Update();

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.17, 0.685, 0.37, 0.745);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisAntiProtonMomDistr, buffer_antip, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canMomAntiProtons->Print(path+"/output_pd1c_antiprotons_mom.png");
	}


	TCanvas *canPositionMomAntiProtons = new TCanvas("canPositionMomAntiProtons", "canPositionMomAntiProtons", 0., 0., 800, 600);
	canPositionMomAntiProtons->SetTicks(1,1);
	canPositionMomAntiProtons->SetGridx(1);
	canPositionMomAntiProtons->SetGridy(1);
	//canPositionMomAntiProtons->SetLeftMargin(0.15);
	//canPositionMomAntiProtons->SetRightMargin(0.15);
	//canPositionMomAntiProtons->SetTopMargin(0.15);
	//canPositionMomAntiProtons->SetBottomMargin(0.15);
	hisAntiProtonPositionMomDistr->Draw("colz");
	hisAntiProtonPositionMomDistr->SetLineWidth(1);
	hisAntiProtonPositionMomDistr->SetLineColor(kBlack);
	hisAntiProtonPositionMomDistr->SetTitle("Position-momentum distribution of #bar{p} from GiBUU");
	//hisAntiProtonPositionMomDistr->GetXaxis()->SetRangeUser(,);
	hisAntiProtonPositionMomDistr->GetXaxis()->SetTitle("radial position [fm]");
	hisAntiProtonPositionMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisAntiProtonPositionMomDistr->GetXaxis()->CenterTitle();
	hisAntiProtonPositionMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisAntiProtonPositionMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisAntiProtonPositionMomDistr->GetYaxis()->CenterTitle();
	//hisAntiProtonPositionMomDistr->SetStats(0);  // removes statistics

	if(hisAntiProtonPositionMomDistr->GetEntries() != 0) {
		canPositionMomAntiProtons->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisAntiProtonPositionMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canPositionMomAntiProtons->Modified();
		canPositionMomAntiProtons->Update();
	}

	if(SavePictures == true) {
		canPositionMomAntiProtons->Print(path+"/output_pd1c_antiprotons_position_mom.png");
	}
		
	
	TCanvas *canThetaAntiProtons = new TCanvas("canThetaAntiProtons", "canThetaAntiProtons", 0., 0., 800, 600);
	canThetaAntiProtons->SetTicks(1,1);
	canThetaAntiProtons->SetGridx(1);
	canThetaAntiProtons->SetGridy(1);
	canThetaAntiProtons->SetLogy(1);
	
	hisAntiProtonThetaDistr->Draw("");
	hisAntiProtonThetaDistr->SetLineWidth(1);
	hisAntiProtonThetaDistr->SetLineColor(kBlue);
	hisAntiProtonThetaDistr->SetTitle("Theta distribution of #bar{p} from GiBUU");
	//hisAntiProtonThetaDistr->GetXaxis()->SetRangeUser(,);
	hisAntiProtonThetaDistr->GetXaxis()->SetTitle("theta [degree]");
	hisAntiProtonThetaDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisAntiProtonThetaDistr->GetXaxis()->CenterTitle();
	hisAntiProtonThetaDistr->GetYaxis()->SetTitle("entries");
	hisAntiProtonThetaDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisAntiProtonThetaDistr->GetYaxis()->CenterTitle();
	//hisAntiProtonThetaDistr->GetYaxis()->SetNoExponent(kTRUE);  // Bool_t noExponent = kTRUE  // no exponent at the axis
	//hisAntiProtonThetaDistr->SetStats(0);  // removes statistics

	if(SavePictures == true) {
		canThetaAntiProtons->Print(path+"/output_pd1c_antiprotons_theta.png");
	}


	TCanvas *canThetaAntiProtons_tcut = new TCanvas("canThetaAntiProtons_tcut", "canThetaAntiProtons_tcut", 0., 0., 800, 600);
	canThetaAntiProtons_tcut->SetTicks(1,1);
	canThetaAntiProtons_tcut->SetGridx(1);
	canThetaAntiProtons_tcut->SetGridy(1);
	canThetaAntiProtons_tcut->SetLogy(1);
	hisAntiProtonThetaDistr_tcut->Draw("");
	hisAntiProtonThetaDistr_tcut->SetLineWidth(1);
	hisAntiProtonThetaDistr_tcut->SetLineColor(kBlue);
	hisAntiProtonThetaDistr_tLUMIcut->Draw("same");
	hisAntiProtonThetaDistr_tLUMIcut->SetLineWidth(1);
	hisAntiProtonThetaDistr_tLUMIcut->SetLineColor(kGreen-3);
	hisAntiProtonThetaDistr_tcut->SetTitle("Theta distribution of #bar{p} from GiBUU zoom");
	//hisAntiProtonThetaDistr_tcut->GetXaxis()->SetRangeUser(,);
	hisAntiProtonThetaDistr_tcut->GetXaxis()->SetTitle("theta [degree]");
	hisAntiProtonThetaDistr_tcut->GetXaxis()->SetTitleOffset(1.3);
	//hisAntiProtonThetaDistr_tcut->GetXaxis()->CenterTitle();
	hisAntiProtonThetaDistr_tcut->GetYaxis()->SetTitle("entries");
	hisAntiProtonThetaDistr_tcut->GetYaxis()->SetTitleOffset(1.4);
	//hisAntiProtonThetaDistr_tcut->GetYaxis()->CenterTitle();
	//hisAntiProtonThetaDistr_tcut->GetYaxis()->SetNoExponent(kTRUE);  // Bool_t noExponent = kTRUE  // no exponent at the axis
	hisAntiProtonThetaDistr_tcut->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.57, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisAntiProtonThetaDistr_tcut, buffer_antipTheta_tcut, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisAntiProtonThetaDistr_tLUMIcut, buffer_antipTheta_tLUMIcut, "l");

	if(SavePictures == true) {
		canThetaAntiProtons_tcut->Print(path+"/output_pd1c_antiprotons_theta_tcut.png");
	}


	TCanvas *canThetaAntiProtons_mrad = new TCanvas("canThetaAntiProtons_mrad", "canThetaAntiProtons_mrad", 0., 0., 800, 600);
	canThetaAntiProtons_mrad->SetTicks(1,1);
	canThetaAntiProtons_mrad->SetGridx(1);
	canThetaAntiProtons_mrad->SetGridy(1);
	//canThetaAntiProtons_mrad->SetLogy(1);
	hisAntiProtonThetaDistr_mrad->Draw("");
	hisAntiProtonThetaDistr_mrad->SetLineWidth(1);
	hisAntiProtonThetaDistr_mrad->SetLineColor(kBlue);
	hisAntiProtonThetaDistr_mradcut->Draw("same");
	hisAntiProtonThetaDistr_mradcut->SetLineWidth(1);
	hisAntiProtonThetaDistr_mradcut->SetLineColor(kGreen-3);
	hisAntiProtonThetaDistr_mrad->SetTitle("Theta distribution of #bar{p} from GiBUU zoom");
	//hisAntiProtonThetaDistr_mrad->GetXaxis()->SetRangeUser(,);
	hisAntiProtonThetaDistr_mrad->GetXaxis()->SetTitle("theta [mrad]");
	hisAntiProtonThetaDistr_mrad->GetXaxis()->SetTitleOffset(1.3);
	//hisAntiProtonThetaDistr_mrad->GetXaxis()->CenterTitle();
	hisAntiProtonThetaDistr_mrad->GetYaxis()->SetTitle("entries");
	hisAntiProtonThetaDistr_mrad->GetYaxis()->SetTitleOffset(1.4);
	//hisAntiProtonThetaDistr_mrad->GetYaxis()->CenterTitle();
	//hisAntiProtonThetaDistr_mrad->GetYaxis()->SetNoExponent(kTRUE);  // Bool_t noExponent = kTRUE  // no exponent at the axis
	hisAntiProtonThetaDistr_mrad->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.57, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisAntiProtonThetaDistr_mrad, buffer_antipTheta_mrad, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisAntiProtonThetaDistr_mradcut, buffer_antipTheta_mradcut, "l");

	if(SavePictures == true) {
		canThetaAntiProtons_mrad->Print(path+"/output_pd1c_antiprotons_theta_mrad.png");
	}


	TCanvas *canThetaMomAntiProtons = new TCanvas("canThetaMomAntiProtons", "canThetaMomAntiProtons", 0., 0., 800, 600);
	canThetaMomAntiProtons->SetTicks(1,1);
	canThetaMomAntiProtons->SetGridx(1);
	canThetaMomAntiProtons->SetGridy(1);
	//canThetaMomAntiProtons->SetLeftMargin(0.15);
	//canThetaMomAntiProtons->SetRightMargin(0.15);
	//canThetaMomAntiProtons->SetTopMargin(0.15);
	//canThetaMomAntiProtons->SetBottomMargin(0.15);
	hisAntiProtonThetaMomDistr->Draw("colz");
	hisAntiProtonThetaMomDistr->SetLineWidth(1);
	hisAntiProtonThetaMomDistr->SetLineColor(kBlack);
	hisAntiProtonThetaMomDistr->SetTitle("Theta-momentum distribution of #bar{p} from GiBUU");
	//hisAntiProtonThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisAntiProtonThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisAntiProtonThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisAntiProtonThetaMomDistr->GetXaxis()->CenterTitle();
	hisAntiProtonThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisAntiProtonThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisAntiProtonThetaMomDistr->GetYaxis()->CenterTitle();
	//hisAntiProtonThetaMomDistr->SetStats(0);  // removes statistics

	if(hisAntiProtonThetaMomDistr->GetEntries() != 0) { 
		canThetaMomAntiProtons->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisAntiProtonThetaMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canThetaMomAntiProtons->Modified();
		canThetaMomAntiProtons->Update();
	}

	if(SavePictures == true) {
		canThetaMomAntiProtons->Print(path+"/output_pd1c_antiprotons_theta_mom.png");
	}


	// !!! This histogram is only reasonable for runs with p(Pbar) = 2.9 GeV/c !!!
	TCanvas *canThetaMomAntiProtons_tpcut = new TCanvas("canThetaMomAntiProtons_tpcut", "canThetaMomAntiProtons_tpcut", 0., 0., 800, 600);
	canThetaMomAntiProtons_tpcut->SetTicks(1,1);
	canThetaMomAntiProtons_tpcut->SetGridx(1);
	canThetaMomAntiProtons_tpcut->SetGridy(1);
	//canThetaMomAntiProtons_tpcut->SetLeftMargin(0.15);
	//canThetaMomAntiProtons_tpcut->SetRightMargin(0.15);
	//canThetaMomAntiProtons_tpcut->SetTopMargin(0.15);
	//canThetaMomAntiProtons_tpcut->SetBottomMargin(0.15);
	hisAntiProtonThetaMomDistr_tpcut->Draw("colz");
	hisAntiProtonThetaMomDistr_tpcut->SetLineWidth(1);
	hisAntiProtonThetaMomDistr_tpcut->SetLineColor(kBlack);
	hisAntiProtonThetaMomDistr_tpcut->SetTitle("Theta-momentum distribution of #bar{p} from GiBUU zoom");
	//hisAntiProtonThetaMomDistr_tpcut->GetXaxis()->SetRangeUser(,);
	hisAntiProtonThetaMomDistr_tpcut->GetXaxis()->SetTitle("theta [degree]");
	hisAntiProtonThetaMomDistr_tpcut->GetXaxis()->SetTitleOffset(1.3);
	//hisAntiProtonThetaMomDistr_tpcut->GetXaxis()->CenterTitle();
	hisAntiProtonThetaMomDistr_tpcut->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisAntiProtonThetaMomDistr_tpcut->GetYaxis()->SetTitleOffset(1.4);
	//hisAntiProtonThetaMomDistr_tpcut->GetYaxis()->CenterTitle();
	//hisAntiProtonThetaMomDistr_tpcut->SetStats(0);  // removes statistics

	if(hisAntiProtonThetaMomDistr_tpcut->GetEntries() != 0) {
		canThetaMomAntiProtons_tpcut->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisAntiProtonThetaMomDistr_tpcut->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canThetaMomAntiProtons_tpcut->Modified();
		canThetaMomAntiProtons_tpcut->Update();
	}

	if(SavePictures == true) {
		canThetaMomAntiProtons_tpcut->Print(path+"/output_pd1c_antiprotons_theta_mom_tpcut.png");
	}



	// Proton histograms

	TCanvas *canPositionProtons = new TCanvas("canPositionProtons", "canPositionProtons", 0., 0., 800, 600);
	canPositionProtons->SetTicks(1,1);
	canPositionProtons->SetGridx(1);
	canPositionProtons->SetGridy(1);
	hisProtonPositionDistr->Draw("");
	hisProtonPositionDistr->SetLineWidth(1);
	hisProtonPositionDistr->SetLineColor(kBlue);
	hisProtonPositionDistr->SetTitle("Position distribution of Protons from GiBUU");
	//hisProtonPositionDistr->GetXaxis()->SetRangeUser(,);
	hisProtonPositionDistr->GetXaxis()->SetTitle("radial position [fm]");
	hisProtonPositionDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisProtonPositionDistr->GetXaxis()->CenterTitle();
	hisProtonPositionDistr->GetYaxis()->SetTitle("entries");
	hisProtonPositionDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisProtonPositionDistr->GetYaxis()->CenterTitle();
	//hisProtonPositionDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.67, 0.685, 0.87, 0.745);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisProtonPositionDistr, buffer_p, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canPositionProtons->Print(path+"/output_pd1c_protons_position.png");
	}


	TCanvas *canMomProtons = new TCanvas("canMomProtons", "canMomProtons", 0., 0., 800, 600);
	canMomProtons->SetTicks(1,1);
	canMomProtons->SetGridx(1);
	canMomProtons->SetGridy(1);
	hisProtonMomDistr->Draw("");
	hisProtonMomDistr->SetLineWidth(1);
	hisProtonMomDistr->SetLineColor(kBlue);
	hisProtonMomDistr->SetTitle("Momentum distribution of Protons from GiBUU");
	//hisProtonMomDistr->GetXaxis()->SetRangeUser(,);
	hisProtonMomDistr->GetXaxis()->SetTitle("momentum [GeV/c]");
	hisProtonMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisProtonMomDistr->GetXaxis()->CenterTitle();
	hisProtonMomDistr->GetYaxis()->SetTitle("entries");
	hisProtonMomDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisProtonMomDistr->GetYaxis()->CenterTitle();
	//hisProtonMomDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.67, 0.685, 0.87, 0.745);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisProtonMomDistr, buffer_p, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canMomProtons->Print(path+"/output_pd1c_protons_mom.png");
	}


	TCanvas *canPositionMomProtons = new TCanvas("canPositionMomProtons", "canPositionMomProtons", 0., 0., 800, 600);
	canPositionMomProtons->SetTicks(1,1);
	canPositionMomProtons->SetGridx(1);
	canPositionMomProtons->SetGridy(1);
	//canPositionMomProtons->SetLeftMargin(0.15);
	//canPositionMomProtons->SetRightMargin(0.15);
	//canPositionMomProtons->SetTopMargin(0.15);
	//canPositionMomProtons->SetBottomMargin(0.15);
	hisProtonPositionMomDistr->Draw("colz");
	hisProtonPositionMomDistr->SetLineWidth(1);
	hisProtonPositionMomDistr->SetLineColor(kBlack);
	hisProtonPositionMomDistr->SetTitle("Position-momentum distribution of Protons from GiBUU");
	//hisProtonPositionMomDistr->GetXaxis()->SetRangeUser(,);
	hisProtonPositionMomDistr->GetXaxis()->SetTitle("radial position [fm]");
	hisProtonPositionMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisProtonPositionMomDistr->GetXaxis()->CenterTitle();
	hisProtonPositionMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisProtonPositionMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisProtonPositionMomDistr->GetYaxis()->CenterTitle();
	//hisProtonPositionMomDistr->SetStats(0);  // removes statistics

	if(hisProtonPositionMomDistr->GetEntries() != 0) {
		canPositionMomProtons->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisProtonPositionMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canPositionMomProtons->Modified();
		canPositionMomProtons->Update();
	}

	if(SavePictures == true) {
		canPositionMomProtons->Print(path+"/output_pd1c_protons_position_mom.png");
	}


	TCanvas *canThetaProtons = new TCanvas("canThetaProtons", "canThetaProtons", 0., 0., 800, 600);
	canThetaProtons->SetTicks(1,1);
	canThetaProtons->SetGridx(1);
	canThetaProtons->SetGridy(1);
	hisProtonThetaDistr->Draw("");
	hisProtonThetaDistr->SetLineWidth(1);
	hisProtonThetaDistr->SetLineColor(kBlack);
	hisProtonThetaFWDistr->Draw("same");
	hisProtonThetaFWDistr->SetLineWidth(1);
	hisProtonThetaFWDistr->SetLineColor(kBlue);
	hisProtonThetaSiDistr->Draw("same");
	hisProtonThetaSiDistr->SetLineWidth(1);
	hisProtonThetaSiDistr->SetLineColor(kRed);
	hisProtonThetaSiGeDistr->Draw("same");
	hisProtonThetaSiGeDistr->SetLineWidth(1);
	hisProtonThetaSiGeDistr->SetLineColor(kOrange+7);
	hisProtonThetaGeDistr->Draw("same");
	hisProtonThetaGeDistr->SetLineWidth(1);
	hisProtonThetaGeDistr->SetLineColor(kGreen-3);
	hisProtonThetaBWDistr->Draw("same");
	hisProtonThetaBWDistr->SetLineWidth(1);
	hisProtonThetaBWDistr->SetLineColor(kMagenta+1);

	hisProtonThetaDistr->SetTitle("Theta distribution of Protons from GiBUU");
	//hisProtonThetaDistr->GetXaxis()->SetRangeUser(,);
	hisProtonThetaDistr->GetXaxis()->SetTitle("theta [degree]");
	hisProtonThetaDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisProtonThetaDistr->GetXaxis()->CenterTitle();
	hisProtonThetaDistr->GetYaxis()->SetTitle("entries");
	hisProtonThetaDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisProtonThetaDistr->GetYaxis()->CenterTitle();
	hisProtonThetaDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.63, 0.665, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisProtonThetaFWDistr, buffer_pThetaFW, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisProtonThetaSiDistr, buffer_pThetaSi, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisProtonThetaSiGeDistr, buffer_pThetaSiGe, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisProtonThetaGeDistr, buffer_pThetaGe, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisProtonThetaBWDistr, buffer_pThetaBW, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisProtonThetaDistr, buffer_pThetaSum, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canThetaProtons->Print(path+"/output_pd1c_protons_theta.png");
	}


	TCanvas *canThetaMomProtons = new TCanvas("canThetaMomProtons", "canThetaMomProtons", 0., 0., 800, 600);
	canThetaMomProtons->SetTicks(1,1);
	canThetaMomProtons->SetGridx(1);
	canThetaMomProtons->SetGridy(1);
	//canThetaMomProtons->SetLeftMargin(0.15);
	//canThetaMomProtons->SetRightMargin(0.15);
	//canThetaMomProtons->SetTopMargin(0.15);
	//canThetaMomProtons->SetBottomMargin(0.15);
	hisProtonThetaMomDistr->Draw("colz");
	hisProtonThetaMomDistr->SetLineWidth(1);
	hisProtonThetaMomDistr->SetLineColor(kBlack);
	hisProtonThetaMomDistr->SetTitle("Theta-momentum distribution of Protons from GiBUU");
	//hisProtonThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisProtonThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisProtonThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisProtonThetaMomDistr->GetXaxis()->CenterTitle();
	hisProtonThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisProtonThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisProtonThetaMomDistr->GetYaxis()->CenterTitle();
	//hisProtonThetaMomDistr->SetStats(0);  // removes statistics

	if(hisProtonThetaMomDistr->GetEntries() != 0) {
		canThetaMomProtons->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisProtonThetaMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canThetaMomProtons->Modified();
		canThetaMomProtons->Update();
	}

	if(SavePictures == true) {
		canThetaMomProtons->Print(path+"/output_pd1c_protons_theta_mom.png");
	}



	// Neutron histograms

	TCanvas *canPositionNeutrons = new TCanvas("canPositionNeutrons", "canPositionNeutrons", 0., 0., 800, 600);
	canPositionNeutrons->SetTicks(1,1);
	canPositionNeutrons->SetGridx(1);
	canPositionNeutrons->SetGridy(1);
	hisNeutronPositionDistr->Draw("");
	hisNeutronPositionDistr->SetLineWidth(1);
	hisNeutronPositionDistr->SetLineColor(kBlue);
	hisNeutronPositionDistr->SetTitle("Position distribution of Neutrons from GiBUU");
	//hisNeutronPositionDistr->GetXaxis()->SetRangeUser(,);
	hisNeutronPositionDistr->GetXaxis()->SetTitle("radial position [fm]");
	hisNeutronPositionDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisNeutronPositionDistr->GetXaxis()->CenterTitle();
	hisNeutronPositionDistr->GetYaxis()->SetTitle("entries");
	hisNeutronPositionDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisNeutronPositionDistr->GetYaxis()->CenterTitle();
	//hisNeutronPositionDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.67, 0.685, 0.87, 0.745);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisNeutronPositionDistr, buffer_n, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canPositionNeutrons->Print(path+"/output_pd1c_neutrons_position.png");
	}


	TCanvas *canMomNeutrons = new TCanvas("canMomNeutrons", "canMomNeutrons", 0., 0., 800, 600);
	canMomNeutrons->SetTicks(1,1);
	canMomNeutrons->SetGridx(1);
	canMomNeutrons->SetGridy(1);
	hisNeutronMomDistr->Draw("");
	hisNeutronMomDistr->SetLineWidth(1);
	hisNeutronMomDistr->SetLineColor(kBlue);
	hisNeutronMomDistr->SetTitle("Momentum distribution of Neutrons from GiBUU");
	//hisNeutronMomDistr->GetXaxis()->SetRangeUser(,);
	hisNeutronMomDistr->GetXaxis()->SetTitle("momentum [GeV/c]");
	hisNeutronMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisNeutronMomDistr->GetXaxis()->CenterTitle();
	hisNeutronMomDistr->GetYaxis()->SetTitle("entries");
	hisNeutronMomDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisNeutronMomDistr->GetYaxis()->CenterTitle();
	//hisNeutronMomDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.67, 0.685, 0.87, 0.745);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisNeutronMomDistr, buffer_n, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canMomNeutrons->Print(path+"/output_pd1c_neutrons_mom.png");
	}


	TCanvas *canPositionMomNeutrons = new TCanvas("canPositionMomNeutrons", "canPositionMomNeutrons", 0., 0., 800, 600);
	canPositionMomNeutrons->SetTicks(1,1);
	canPositionMomNeutrons->SetGridx(1);
	canPositionMomNeutrons->SetGridy(1);
	//canPositionMomNeutrons->SetLeftMargin(0.15);
	//canPositionMomNeutrons->SetRightMargin(0.15);
	//canPositionMomNeutrons->SetTopMargin(0.15);
	//canPositionMomNeutrons->SetBottomMargin(0.15);
	hisNeutronPositionMomDistr->Draw("colz");
	hisNeutronPositionMomDistr->SetLineWidth(1);
	hisNeutronPositionMomDistr->SetLineColor(kBlack);
	hisNeutronPositionMomDistr->SetTitle("Position-momentum distribution of Neutrons from GiBUU");
	//hisNeutronPositionMomDistr->GetXaxis()->SetRangeUser(,);
	hisNeutronPositionMomDistr->GetXaxis()->SetTitle("radial position [fm]");
	hisNeutronPositionMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisNeutronPositionMomDistr->GetXaxis()->CenterTitle();
	hisNeutronPositionMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisNeutronPositionMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisNeutronPositionMomDistr->GetYaxis()->CenterTitle();
	//hisNeutronPositionMomDistr->SetStats(0);  // removes statistics

	if(hisNeutronPositionMomDistr->GetEntries() != 0) {
		canPositionMomNeutrons->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisNeutronPositionMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canPositionMomNeutrons->Modified();
		canPositionMomNeutrons->Update();
	}

	if(SavePictures == true) {
		canPositionMomNeutrons->Print(path+"/output_pd1c_neutrons_position_mom.png");
	}


	TCanvas *canThetaNeutrons = new TCanvas("canThetaNeutrons", "canThetaNeutrons", 0., 0., 800, 600);
	canThetaNeutrons->SetTicks(1,1);
	canThetaNeutrons->SetGridx(1);
	canThetaNeutrons->SetGridy(1);
	hisNeutronThetaDistr->Draw("");
	hisNeutronThetaDistr->SetLineWidth(1);
	hisNeutronThetaDistr->SetLineColor(kBlack);
	hisNeutronThetaFWDistr->Draw("same");
	hisNeutronThetaFWDistr->SetLineWidth(1);
	hisNeutronThetaFWDistr->SetLineColor(kBlue);
	hisNeutronThetaSiDistr->Draw("same");
	hisNeutronThetaSiDistr->SetLineWidth(1);
	hisNeutronThetaSiDistr->SetLineColor(kGreen-3);
	hisNeutronThetaSiGeDistr->Draw("same");
	hisNeutronThetaSiGeDistr->SetLineWidth(1);
	hisNeutronThetaSiGeDistr->SetLineColor(kOrange+7);
	hisNeutronThetaGeDistr->Draw("same");
	hisNeutronThetaGeDistr->SetLineWidth(1);
	hisNeutronThetaGeDistr->SetLineColor(kRed);
	hisNeutronThetaBWDistr->Draw("same");
	hisNeutronThetaBWDistr->SetLineWidth(1);
	hisNeutronThetaBWDistr->SetLineColor(kMagenta+1);

	hisNeutronThetaDistr->SetTitle("Theta distribution of Neutrons from GiBUU");
	//hisNeutronThetaDistr->GetXaxis()->SetRangeUser(,);
	hisNeutronThetaDistr->GetXaxis()->SetTitle("theta [degree]");
	hisNeutronThetaDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisNeutronThetaDistr->GetXaxis()->CenterTitle();
	hisNeutronThetaDistr->GetYaxis()->SetTitle("entries");
	hisNeutronThetaDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisNeutronThetaDistr->GetYaxis()->CenterTitle();
	hisNeutronThetaDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.63, 0.665, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisNeutronThetaFWDistr, buffer_nThetaFW, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisNeutronThetaSiDistr, buffer_nThetaSi, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisNeutronThetaSiGeDistr, buffer_nThetaSiGe, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisNeutronThetaGeDistr, buffer_nThetaGe, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisNeutronThetaBWDistr, buffer_nThetaBW, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisNeutronThetaDistr, buffer_nThetaSum, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canThetaNeutrons->Print(path+"/output_pd1c_neutrons_theta.png");
	}


	TCanvas *canThetaMomNeutrons = new TCanvas("canThetaMomNeutrons", "canThetaMomNeutrons", 0., 0., 800, 600);
	canThetaMomNeutrons->SetTicks(1,1);
	canThetaMomNeutrons->SetGridx(1);
	canThetaMomNeutrons->SetGridy(1);
	//canThetaMomNeutrons->SetLeftMargin(0.15);
	//canThetaMomNeutrons->SetRightMargin(0.15);
	//canThetaMomNeutrons->SetTopMargin(0.15);
	//canThetaMomNeutrons->SetBottomMargin(0.15);
	hisNeutronThetaMomDistr->Draw("colz");
	hisNeutronThetaMomDistr->SetLineWidth(1);
	hisNeutronThetaMomDistr->SetLineColor(kBlack);
	hisNeutronThetaMomDistr->SetTitle("Theta-momentum distribution of Neutrons from GiBUU");
	//hisNeutronThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisNeutronThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisNeutronThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisNeutronThetaMomDistr->GetXaxis()->CenterTitle();
	hisNeutronThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisNeutronThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisNeutronThetaMomDistr->GetYaxis()->CenterTitle();
	//hisNeutronThetaMomDistr->SetStats(0);  // removes statistics

	if(hisNeutronThetaMomDistr->GetEntries() != 0) {
		canThetaMomNeutrons->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisNeutronThetaMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canThetaMomNeutrons->Modified();
		canThetaMomNeutrons->Update();
	}

	if(SavePictures == true) {
		canThetaMomNeutrons->Print(path+"/output_pd1c_neutrons_theta_mom.png");
	}



	// Pion histograms

	TCanvas *canMomPions = new TCanvas("canMomPions", "canMomPions", 0., 0., 800, 600);
	canMomPions->SetTicks(1,1);
	canMomPions->SetGridx(1);
	canMomPions->SetGridy(1);
	const Int_t pimMomMaxY = hisPimMomDistr->GetMaximum();
	const Int_t pipMomMaxY = hisPipMomDistr->GetMaximum();
	if(pimMomMaxY > pipMomMaxY) {
		hisPimMomDistr->Draw("");
		hisPimMomDistr->SetLineWidth(1);
		hisPimMomDistr->SetLineColor(kBlue);
		hisPipMomDistr->Draw("same");
		hisPipMomDistr->SetLineWidth(1);
		hisPipMomDistr->SetLineColor(kOrange+7);
		hisPimMomDistr->SetTitle("Momentum distribution of #pi^{-} and #pi^{+} from GiBUU");
		//hisPimMomDistr->GetXaxis()->SetRangeUser(,);
		hisPimMomDistr->GetXaxis()->SetTitle("momentum [GeV/c]");
		hisPimMomDistr->GetXaxis()->SetTitleOffset(1.3);
		//hisPimMomDistr->GetXaxis()->CenterTitle();
		hisPimMomDistr->GetYaxis()->SetTitle("entries");
		hisPimMomDistr->GetYaxis()->SetTitleOffset(1.4);
		//hisPimMomDistr->GetYaxis()->CenterTitle();
		hisPimMomDistr->SetStats(0);  // removes statistics
	}
	else {
		hisPipMomDistr->Draw("");
		hisPipMomDistr->SetLineWidth(1);
		hisPipMomDistr->SetLineColor(kOrange+7);
		hisPimMomDistr->Draw("same");
		hisPimMomDistr->SetLineWidth(1);
		hisPimMomDistr->SetLineColor(kBlue);
		hisPipMomDistr->SetTitle("Momentum distribution of #pi^{-} and #pi^{+} from GiBUU");
		//hisPipMomDistr->GetXaxis()->SetRangeUser(,);
		hisPipMomDistr->GetXaxis()->SetTitle("momentum [GeV/c]");
		hisPipMomDistr->GetXaxis()->SetTitleOffset(1.3);
		//hisPipMomDistr->GetXaxis()->CenterTitle();
		hisPipMomDistr->GetYaxis()->SetTitle("entries");
		hisPipMomDistr->GetYaxis()->SetTitleOffset(1.4);
		//hisPipMomDistr->GetYaxis()->CenterTitle();
		hisPipMomDistr->SetStats(0);  // removes statistics
	}

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.68, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisPimMomDistr, buffer_pim, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisPipMomDistr, buffer_pip, "l");

	if(SavePictures == true) {
		canMomPions->Print(path+"/output_pd1c_pions_mom.png");
	}


	TCanvas *canThetaPions = new TCanvas("canThetaPions", "canThetaPions", 0., 0., 800, 600);
	canThetaPions->SetTicks(1,1);
	canThetaPions->SetGridx(1);
	canThetaPions->SetGridy(1);
	const Int_t pimThetaMaxY = hisPimThetaDistr->GetMaximum();
	const Int_t pipThetaMaxY = hisPipThetaDistr->GetMaximum();
	if(pimThetaMaxY > pipThetaMaxY) {
		hisPimThetaDistr->Draw("");
		hisPimThetaDistr->SetLineWidth(1);
		hisPimThetaDistr->SetLineColor(kBlue);
		hisPipThetaDistr->Draw("same");
		hisPipThetaDistr->SetLineWidth(1);
		hisPipThetaDistr->SetLineColor(kOrange+7);
		hisPimThetaDistr->SetTitle("Theta distribution of #pi^{-} and #pi^{+} from GiBUU");
		//hisPimThetaDistr->GetXaxis()->SetRangeUser(,);
		hisPimThetaDistr->GetXaxis()->SetTitle("theta [degree]");
		hisPimThetaDistr->GetXaxis()->SetTitleOffset(1.3);
		//hisPimThetaDistr->GetXaxis()->CenterTitle();
		hisPimThetaDistr->GetYaxis()->SetTitle("entries");
		hisPimThetaDistr->GetYaxis()->SetTitleOffset(1.4);
		//hisPimThetaDistr->GetYaxis()->CenterTitle();
		hisPimThetaDistr->SetStats(0);  // removes statistics
	}
	else {
		hisPipThetaDistr->Draw("");
		hisPipThetaDistr->SetLineWidth(1);
		hisPipThetaDistr->SetLineColor(kOrange+7);
		hisPimThetaDistr->Draw("same");
		hisPimThetaDistr->SetLineWidth(1);
		hisPimThetaDistr->SetLineColor(kBlue);
		hisPipThetaDistr->SetTitle("Theta distribution of #pi^{-} and #pi^{+} from GiBUU");
		//hisPipThetaDistr->GetXaxis()->SetRangeUser(,);
		hisPipThetaDistr->GetXaxis()->SetTitle("theta [degree]");
		hisPipThetaDistr->GetXaxis()->SetTitleOffset(1.3);
		//hisPipThetaDistr->GetXaxis()->CenterTitle();
		hisPipThetaDistr->GetYaxis()->SetTitle("entries");
		hisPipThetaDistr->GetYaxis()->SetTitleOffset(1.4);
		//hisPipThetaDistr->GetYaxis()->CenterTitle();
		hisPipThetaDistr->SetStats(0);  // removes statistics 
	}

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.68, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisPimThetaDistr, buffer_pimTheta, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisPipThetaDistr, buffer_pipTheta, "l");

	if(SavePictures == true) {
		canThetaPions->Print(path+"/output_pd1c_pions_theta.png");
	}


	TCanvas *canThetaMomPim = new TCanvas("canThetaMomPim", "canThetaMomPim", 0., 0., 800, 600);
	canThetaMomPim->SetTicks(1,1);
	canThetaMomPim->SetGridx(1);
	canThetaMomPim->SetGridy(1);
	hisPimThetaMomDistr->Draw("colz");
	hisPimThetaMomDistr->SetLineWidth(1);
	hisPimThetaMomDistr->SetLineColor(kBlack);
	hisPimThetaMomDistr->SetTitle("Theta-momentum distribution of #pi^{-} from GiBUU");
	//hisPimThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisPimThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisPimThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisPimThetaMomDistr->GetXaxis()->CenterTitle();
	hisPimThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisPimThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisPimThetaMomDistr->GetYaxis()->CenterTitle();
	//hisPimThetaMomDistr->SetStats(0);  // removes statistics

	if(hisPimThetaMomDistr->GetEntries() != 0) {
		canThetaMomPim->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisPimThetaMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canThetaMomPim->Modified();
		canThetaMomPim->Update();
	}

	if(SavePictures == true) {
		canThetaMomPim->Print(path+"/output_pd1c_pim_theta_mom.png");
	}


	TCanvas *canThetaMomPip = new TCanvas("canThetaMomPip", "canThetaMomPip", 0., 0., 800, 600);
	canThetaMomPip->SetTicks(1,1);
	canThetaMomPip->SetGridx(1);
	canThetaMomPip->SetGridy(1);
	hisPipThetaMomDistr->Draw("colz");
	hisPipThetaMomDistr->SetLineWidth(1);
	hisPipThetaMomDistr->SetLineColor(kBlack);
	hisPipThetaMomDistr->SetTitle("Theta-momentum distribution of #pi^{+} from GiBUU");
	//hisPipThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisPipThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisPipThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisPipThetaMomDistr->GetXaxis()->CenterTitle();
	hisPipThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisPipThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisPipThetaMomDistr->GetYaxis()->CenterTitle();
	//hisPipThetaMomDistr->SetStats(0);  // removes statistics

	if(hisPipThetaMomDistr->GetEntries() != 0) {
		canThetaMomPip->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisPipThetaMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canThetaMomPip->Modified();
		canThetaMomPip->Update();
	}

	if(SavePictures == true) {
		canThetaMomPip->Print(path+"/output_pd1c_pip_theta_mom.png");
	}



	// Kaon histograms

	TCanvas *canMomKaons = new TCanvas("canMomKaons", "canMomKaons", 0., 0., 800, 600);
	canMomKaons->SetTicks(1,1);
	canMomKaons->SetGridx(1);
	canMomKaons->SetGridy(1);
	const Int_t kaonmMomMaxY = hisKaonmMomDistr->GetMaximum();
	const Int_t kaonpMomMaxY = hisKaonpMomDistr->GetMaximum();
	if(kaonmMomMaxY > kaonpMomMaxY) {
		hisKaonmMomDistr->Draw("");
		hisKaonmMomDistr->SetLineWidth(1);
		hisKaonmMomDistr->SetLineColor(kBlue);
		hisKaonpMomDistr->Draw("same");
		hisKaonpMomDistr->SetLineWidth(1);
		hisKaonpMomDistr->SetLineColor(kOrange+7);
		hisKaonmMomDistr->SetTitle("Momentum distribution of K^{-} and K^{+} from GiBUU");
		//hisKaonmMomDistr->GetXaxis()->SetRangeUser(,);
		hisKaonmMomDistr->GetXaxis()->SetTitle("momentum [GeV/c]");
		hisKaonmMomDistr->GetXaxis()->SetTitleOffset(1.3);
		//hisKaonmMomDistr->GetXaxis()->CenterTitle();
		//    Alternative setting of the range on the y-axis
		//    if(kaonmMomMaxY < kaonpMomMaxY) hisKaonmMomDistr->GetYaxis()->SetRangeUser(0., kaonpMomMaxY+300);
		//    else hisKaonmMomDistr->GetYaxis()->SetRangeUser(0., kaonmMomMaxY+300);
		hisKaonmMomDistr->GetYaxis()->SetTitle("entries");
		hisKaonmMomDistr->GetYaxis()->SetTitleOffset(1.4);
		//hisKaonmMomDistr->GetYaxis()->CenterTitle();
		hisKaonmMomDistr->SetStats(0);  // removes statistics
	}
	else {
		hisKaonpMomDistr->Draw("");
		hisKaonpMomDistr->SetLineWidth(1);
		hisKaonpMomDistr->SetLineColor(kOrange+7);
		hisKaonmMomDistr->Draw("same");
		hisKaonmMomDistr->SetLineWidth(1);
		hisKaonmMomDistr->SetLineColor(kBlue);
		hisKaonpMomDistr->SetTitle("Momentum distribution of K^{-} and K^{+} from GiBUU");
		//hisKaonpMomDistr->GetXaxis()->SetRangeUser(,);
		hisKaonpMomDistr->GetXaxis()->SetTitle("momentum [GeV/c]");
		hisKaonpMomDistr->GetXaxis()->SetTitleOffset(1.3);
		//hisKaonpMomDistr->GetXaxis()->CenterTitle();
		hisKaonpMomDistr->GetYaxis()->SetTitle("entries");
		hisKaonpMomDistr->GetYaxis()->SetTitleOffset(1.4);
		//hisKaonpMomDistr->GetYaxis()->CenterTitle();
		hisKaonpMomDistr->SetStats(0);  // removes statistics
	}

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.68, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisKaonmMomDistr, buffer_kaonm, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisKaonpMomDistr, buffer_kaonp, "l");

	if(SavePictures == true) {
		canMomKaons->Print(path+"/output_pd1c_kaons_mom.png");
	}


	TCanvas *canThetaKaons = new TCanvas("canThetaKaons", "canThetaKaons", 0., 0., 800, 600);
	canThetaKaons->SetTicks(1,1);
	canThetaKaons->SetGridx(1);
	canThetaKaons->SetGridy(1);
	const Int_t kaonmThetaMaxY = hisKaonmThetaDistr->GetMaximum();
	const Int_t kaonpThetaMaxY = hisKaonpThetaDistr->GetMaximum();
	if(kaonmThetaMaxY > kaonpThetaMaxY) {
		hisKaonmThetaDistr->Draw("");
		hisKaonmThetaDistr->SetLineWidth(1);
		hisKaonmThetaDistr->SetLineColor(kBlue);
		hisKaonpThetaDistr->Draw("same");
		hisKaonpThetaDistr->SetLineWidth(1);
		hisKaonpThetaDistr->SetLineColor(kOrange+7);
		hisKaonmThetaDistr->SetTitle("Theta distribution of K^{-} and K^{+} from GiBUU");
		//hisKaonmThetaDistr->GetXaxis()->SetRangeUser(,);
		hisKaonmThetaDistr->GetXaxis()->SetTitle("theta [degree]");
		hisKaonmThetaDistr->GetXaxis()->SetTitleOffset(1.3);
		//hisKaonmThetaDistr->GetXaxis()->CenterTitle();
		//    Alternative setting of the range on the y-axis
		//    if(kaonmThetaMaxY < kaonpThetaMaxY) hisKaonmThetaDistr->GetYaxis()->SetRangeUser(0., kaonpThetaMaxY+300);
		//    else hisKaonmThetaDistr->GetYaxis()->SetRangeUser(0., kaonmThetaMaxY+300);
		hisKaonmThetaDistr->GetYaxis()->SetTitle("entries");
		hisKaonmThetaDistr->GetYaxis()->SetTitleOffset(1.4);
		//hisKaonmThetaDistr->GetYaxis()->CenterTitle();
		hisKaonmThetaDistr->SetStats(0);  // removes statistics
	}
	else {
		hisKaonpThetaDistr->Draw("");
		hisKaonpThetaDistr->SetLineWidth(1);
		hisKaonpThetaDistr->SetLineColor(kOrange+7);
		hisKaonmThetaDistr->Draw("same");
		hisKaonmThetaDistr->SetLineWidth(1);
		hisKaonmThetaDistr->SetLineColor(kBlue);
		hisKaonpThetaDistr->SetTitle("Theta distribution of K^{-} and K^{+} from GiBUU");
		//hisKaonpThetaDistr->GetXaxis()->SetRangeUser(,);
		hisKaonpThetaDistr->GetXaxis()->SetTitle("theta [degree]");
		hisKaonpThetaDistr->GetXaxis()->SetTitleOffset(1.3);
		//hisKaonpThetaDistr->GetXaxis()->CenterTitle();
		hisKaonpThetaDistr->GetYaxis()->SetTitle("entries");
		hisKaonpThetaDistr->GetYaxis()->SetTitleOffset(1.4);
		//hisKaonpThetaDistr->GetYaxis()->CenterTitle();
		hisKaonpThetaDistr->SetStats(0);  // removes statistics
	}

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.68, 0.765, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisKaonmThetaDistr, buffer_kaonmTheta, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisKaonpThetaDistr, buffer_kaonpTheta, "l");

	if(SavePictures == true) {
		canThetaKaons->Print(path+"/output_pd1c_kaons_theta.png");
	}


	TCanvas *canThetaMomKaonm = new TCanvas("canThetaMomKaonm", "canThetaMomKaonm", 0., 0., 800, 600);
	canThetaMomKaonm->SetTicks(1,1);
	canThetaMomKaonm->SetGridx(1);
	canThetaMomKaonm->SetGridy(1);
	hisKaonmThetaMomDistr->Draw("colz");
	hisKaonmThetaMomDistr->SetLineWidth(1);
	hisKaonmThetaMomDistr->SetLineColor(kBlack);
	hisKaonmThetaMomDistr->SetTitle("Theta-momentum distribution of K^{-} from GiBUU");
	//hisKaonmThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisKaonmThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisKaonmThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisKaonmThetaMomDistr->GetXaxis()->CenterTitle();
	hisKaonmThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisKaonmThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisKaonmThetaMomDistr->GetYaxis()->CenterTitle();
	//hisKaonmThetaMomDistr->SetStats(0);  // removes statistics

	if(hisKaonmThetaMomDistr->GetEntries() != 0) {
		canThetaMomKaonm->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisKaonmThetaMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canThetaMomKaonm->Modified();
		canThetaMomKaonm->Update();
	}

	if(SavePictures == true) {
		canThetaMomKaonm->Print(path+"/output_pd1c_kaonm_theta_mom.png");
	}


	TCanvas *canThetaMomKaonp = new TCanvas("canThetaMomKaonp", "canThetaMomKaonp", 0., 0., 800, 600);
	canThetaMomKaonp->SetTicks(1,1);
	canThetaMomKaonp->SetGridx(1);
	canThetaMomKaonp->SetGridy(1);
	hisKaonpThetaMomDistr->Draw("colz");
	hisKaonpThetaMomDistr->SetLineWidth(1);
	hisKaonpThetaMomDistr->SetLineColor(kBlack);
	hisKaonpThetaMomDistr->SetTitle("Theta-momentum distribution of K^{+} from GiBUU");
	//hisKaonpThetaMomDistr->GetXaxis()->SetRangeUser(,);
	hisKaonpThetaMomDistr->GetXaxis()->SetTitle("theta [degree]");
	hisKaonpThetaMomDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisKaonpThetaMomDistr->GetXaxis()->CenterTitle();
	hisKaonpThetaMomDistr->GetYaxis()->SetTitle("momentum [GeV/c]");
	hisKaonpThetaMomDistr->GetYaxis()->SetTitleOffset(1.2);
	//hisKaonpThetaMomDistr->GetYaxis()->CenterTitle();
	//hisKaonpThetaMomDistr->SetStats(0);  // removes statistics

	if(hisKaonpThetaMomDistr->GetEntries() != 0) {
		canThetaMomKaonp->Update();
		TPaletteAxis *palette = (TPaletteAxis*) hisKaonpThetaMomDistr->GetListOfFunctions()->FindObject("palette");
		//palette->SetX1NDC(0.905); // new x start position
		palette->SetX2NDC(0.93); // new x end position
		//palette->SetY1NDC(0.2);
		//palette->SetY2NDC(0.8);
		canThetaMomKaonp->Modified();
		canThetaMomKaonp->Update();
	}

	if(SavePictures == true) {
		canThetaMomKaonp->Print(path+"/output_pd1c_kaonp_theta_mom.png");
	}



	// charged particles in Silicon region histogram

	TCanvas *canThetaChargedParticles = new TCanvas("canThetaChargedParticles", "canThetaChargedParticles", 0., 0., 800, 600);
	canThetaChargedParticles->SetTicks(1,1);
	canThetaChargedParticles->SetGridx(1);
	canThetaChargedParticles->SetGridy(1);
	hisChargedParticleThetaSiliconDistr->Draw("");
	hisChargedParticleThetaSiliconDistr->SetLineWidth(1);
	hisChargedParticleThetaSiliconDistr->SetLineColor(kBlack);
	hisChargedAntiNukleonThetaSiliconDistr->Draw("same");
	hisChargedAntiNukleonThetaSiliconDistr->SetLineWidth(1);
	hisChargedAntiNukleonThetaSiliconDistr->SetLineColor(kOrange+7);
	hisChargedNukleonThetaSiliconDistr->Draw("same");
	hisChargedNukleonThetaSiliconDistr->SetLineWidth(1);
	hisChargedNukleonThetaSiliconDistr->SetLineColor(kBlue);
	hisChargedPionThetaSiliconDistr->Draw("same");
	hisChargedPionThetaSiliconDistr->SetLineWidth(1);
	hisChargedPionThetaSiliconDistr->SetLineColor(kGreen-3);
	hisChargedKaonThetaSiliconDistr->Draw("same");
	hisChargedKaonThetaSiliconDistr->SetLineWidth(1);
	hisChargedKaonThetaSiliconDistr->SetLineColor(kMagenta+1);

	hisChargedParticleThetaSiliconDistr->SetTitle("Theta distribution of charged particles from GiBUU");
	//hisChargedParticleThetaSiliconDistr->GetXaxis()->SetRangeUser(,);
	hisChargedParticleThetaSiliconDistr->GetXaxis()->SetTitle("theta [degree]");
	hisChargedParticleThetaSiliconDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisChargedParticleThetaSiliconDistr->GetXaxis()->CenterTitle();
	hisChargedParticleThetaSiliconDistr->GetYaxis()->SetTitle("entries");
	hisChargedParticleThetaSiliconDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisChargedParticleThetaSiliconDistr->GetYaxis()->CenterTitle();
	hisChargedParticleThetaSiliconDistr->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.63, 0.665, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisChargedParticleThetaSiliconDistr, buffer_cparticleThetaSilicon, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisChargedAntiNukleonThetaSiliconDistr, buffer_cantinukleonThetaSilicon, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisChargedNukleonThetaSiliconDistr, buffer_cnukleonThetaSilicon, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisChargedPionThetaSiliconDistr, buffer_cpionThetaSilicon, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisChargedKaonThetaSiliconDistr, buffer_ckaonThetaSilicon, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisChargedParticleThetaSiliconDistr, buffer_sumThetaSilicon, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canThetaChargedParticles->Print(path+"/output_pd1c_chargedParticles_theta.png");
	}



	// Neutrons in Germanium region histogram

	TCanvas *canThetaNeutralParticles = new TCanvas("canThetaNeutralParticles", "canThetaNeutralParticles", 0., 0., 800, 600);
	canThetaNeutralParticles->SetTicks(1,1);
	canThetaNeutralParticles->SetGridx(1);
	canThetaNeutralParticles->SetGridy(1);
	hisNeutronThetaGeArrayDistr->Draw("");
	hisNeutronThetaGeArrayDistr->SetLineWidth(1);
	hisNeutronThetaGeArrayDistr->SetLineColor(kBlue);
	hisNeutronThetaGeArrayDistr->SetTitle("Theta distribution of Neutrons from GiBUU");
	//hisNeutronThetaGeArrayDistr->GetXaxis()->SetRangeUser(,);
	hisNeutronThetaGeArrayDistr->GetXaxis()->SetTitle("theta [degree]");
	hisNeutronThetaGeArrayDistr->GetXaxis()->SetTitleOffset(1.3);
	//hisNeutronThetaGeArrayDistr->GetXaxis()->CenterTitle();
	hisNeutronThetaGeArrayDistr->GetYaxis()->SetTitle("entries");
	hisNeutronThetaGeArrayDistr->GetYaxis()->SetTitleOffset(1.4);
	//hisNeutronThetaGeArrayDistr->GetYaxis()->CenterTitle();
	//hisNeutronThetaGeArrayDistr->SetStats(0);  // removes statistics

	canThetaNeutralParticles->Update();
	TPaveStats* statsbox_hisNeutronThetaGeArrayDistr = (TPaveStats*) hisNeutronThetaGeArrayDistr->GetListOfFunctions()->FindObject("stats");
	statsbox_hisNeutronThetaGeArrayDistr->SetX1NDC(0.17); // new x start position
	statsbox_hisNeutronThetaGeArrayDistr->SetX2NDC(0.37); // new x end position
	statsbox_hisNeutronThetaGeArrayDistr->SetY1NDC(0.745);
	statsbox_hisNeutronThetaGeArrayDistr->SetY2NDC(0.865);
	statsbox_hisNeutronThetaGeArrayDistr->SetTextColor(kBlack);
	canThetaNeutralParticles->Modified();
	canThetaNeutralParticles->Update();

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.17, 0.685, 0.37, 0.745);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisNeutronThetaGeArrayDistr, buffer_nparticleThetaGeArray, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canThetaNeutralParticles->Print(path+"/output_pd1c_neutralParticles_theta.png");
	}



	// charged particles in Silicon region histogram (momentumcuts)

	TCanvas *canThetaChargedParticles_pcut = new TCanvas("canThetaChargedParticles_pcut", "canThetaChargedParticles_pcut", 0., 0., 800, 600);
	canThetaChargedParticles_pcut->SetTicks(1,1);
	canThetaChargedParticles_pcut->SetGridx(1);
	canThetaChargedParticles_pcut->SetGridy(1);
	hisChargedParticleThetaSiliconDistr_pcut->Draw("");
	hisChargedParticleThetaSiliconDistr_pcut->SetLineWidth(1);
	hisChargedParticleThetaSiliconDistr_pcut->SetLineColor(kBlack);
	//hisChargedAntiNukleonThetaSiliconDistr_pcut->Draw("same");
	//hisChargedAntiNukleonThetaSiliconDistr_pcut->SetLineWidth(1);
	//hisChargedAntiNukleonThetaSiliconDistr_pcut->SetLineColor(kOrange+7);
	hisChargedNukleonThetaSiliconDistr_pcut->Draw("same");
	hisChargedNukleonThetaSiliconDistr_pcut->SetLineWidth(1);
	hisChargedNukleonThetaSiliconDistr_pcut->SetLineColor(kBlue);
	hisChargedPionThetaSiliconDistr_pcut->Draw("same");
	hisChargedPionThetaSiliconDistr_pcut->SetLineWidth(1);
	hisChargedPionThetaSiliconDistr_pcut->SetLineColor(kGreen-3);
	hisChargedKaonThetaSiliconDistr_pcut->Draw("same");
	hisChargedKaonThetaSiliconDistr_pcut->SetLineWidth(1);
	hisChargedKaonThetaSiliconDistr_pcut->SetLineColor(kMagenta+1);

	hisChargedParticleThetaSiliconDistr_pcut->SetTitle("Theta distribution of charged particles from GiBUU with cut on momenta");
	//hisChargedParticleThetaSiliconDistr_pcut->GetXaxis()->SetRangeUser(,);
	hisChargedParticleThetaSiliconDistr_pcut->GetXaxis()->SetTitle("theta [degree]");
	hisChargedParticleThetaSiliconDistr_pcut->GetXaxis()->SetTitleOffset(1.3);
	//hisChargedParticleThetaSiliconDistr_pcut->GetXaxis()->CenterTitle();
	hisChargedParticleThetaSiliconDistr_pcut->GetYaxis()->SetTitle("entries");
	hisChargedParticleThetaSiliconDistr_pcut->GetYaxis()->SetTitleOffset(1.4);
	//hisChargedParticleThetaSiliconDistr_pcut->GetYaxis()->CenterTitle();
	hisChargedParticleThetaSiliconDistr_pcut->SetStats(0);  // removes statistics

	// ------ Creation of a legend ------
	TLegend* leg = new TLegend(0.63, 0.605, 0.87, 0.865);  // (x1, y1, x2, y2)
	leg->Draw();
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetLineColor(kBlack);
	//leg->SetFillStyle(0);  // 0 stands for a hollow area
	leg->SetFillColor(kWhite);  // background color of the legend
	leg->SetTextSize(0.03);  // size of the letters
	leg->SetTextColor(kBlack);
	//leg->SetHeader("");
	leg->AddEntry(hisChargedParticleThetaSiliconDistr_pcut, buffer_cparticleThetaSilicon_pcut, "l");  // l stands for line, p stands for points
	//leg->AddEntry(hisChargedAntiNukleonThetaSiliconDistr_pcut, buffer_cantinukleonThetaSilicon_pcut, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisChargedNukleonThetaSiliconDistr_pcut, buffer_cnukleonThetaSilicon_pcut, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisChargedPionThetaSiliconDistr_pcut, buffer_cpionThetaSilicon_pcut, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisChargedKaonThetaSiliconDistr_pcut, buffer_ckaonThetaSilicon_pcut, "l");  // l stands for line, p stands for points
	leg->AddEntry(hisChargedParticleThetaSiliconDistr_pcut, buffer_sumThetaSilicon_pcut, "l");  // l stands for line, p stands for points

	if(SavePictures == true) {
		canThetaChargedParticles_pcut->Print(path+"/output_pd1c_chargedParticles_theta_pcut.png");
	}

}
