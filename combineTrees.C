{

TFile *fTop = new TFile("JMAR/TT3.root");
TTree *tTop = (TTree *) fTop->Get("jetVars");
TFile *fW = new TFile("JMAR/WW3.root");
TTree *tW = (TTree *) fW->Get("jetVars");
TFile *fZ = new TFile("JMAR/outplots_JMAR_ZZ.root");
TTree *tZ = (TTree *) fZ->Get("jetVars");
TFile *fH = new TFile("JMAR/outplots_JMAR_HH.root");
TTree *tH = (TTree *) fH->Get("jetVars");
TFile *fQCD = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_QCDflat.root");
TTree *tQCD = (TTree *) fQCD->Get("jetVars");

int best_class, sample, npv;
float prob_t, prob_W, prob_Z, prob_H, prob_QCD, prob_b;
float genPt, jetSDmass, jetEta, dRgenParticle, genSize;


tTop->SetBranchStatus("*", 0);
tTop->SetBranchStatus("prob_t", 1);
tTop->SetBranchStatus("prob_Z", 1);
tTop->SetBranchStatus("prob_W", 1);
tTop->SetBranchStatus("prob_H", 1);
tTop->SetBranchStatus("prob_j", 1);
tTop->SetBranchStatus("prob_b", 1);
tTop->SetBranchStatus("best_class", 1);
tTop->SetBranchStatus("topSize", 1);
tTop->SetBranchStatus("npv", 1);

TFile *outF = new TFile("test_combine_tree.root", "RECREATE");
outF->cd();
TTree *newTree = tTop->CloneTree(0);

tTop->SetBranchStatus("jetEta", 1);
tTop->SetBranchStatus("dRgenParticle", 1);
tTop->SetBranchStatus("genPt", 1);
tTop->SetBranchStatus("jetSDmass", 1);

tW->SetBranchStatus("jetEta", 1);
tW->SetBranchStatus("dRgenParticle", 1);
tW->SetBranchStatus("genPt", 1);
tW->SetBranchStatus("jetSDmass", 1);
tZ->SetBranchStatus("jetEta", 1);
tZ->SetBranchStatus("dRgenParticle", 1);
tZ->SetBranchStatus("genPt", 1);
tZ->SetBranchStatus("jetSDmass", 1);
tH->SetBranchStatus("jetEta", 1);
tH->SetBranchStatus("dRgenParticle", 1);
tH->SetBranchStatus("genPt", 1);
tH->SetBranchStatus("jetSDmass", 1);
tQCD->SetBranchStatus("jetEta", 1);
tQCD->SetBranchStatus("dRgenParticle", 1);
tQCD->SetBranchStatus("genPt", 1);
tQCD->SetBranchStatus("jetSDmass", 1);


//newTree->Branch("prob_t", &prob_t, "prob_t/F");
//newTree->Branch("prob_H", &prob_H, "prob_H/F");
//newTree->Branch("prob_Z", &prob_Z, "prob_Z/F");
//newTree->Branch("prob_W", &prob_W, "prob_W/F");
//newTree->Branch("prob_QCD", &prob_QCD, "prob_QCD/F");
newTree->Branch("type", &sample, "type/I");
newTree->Branch("gen_pt", &genPt, "gen_pt/F");
newTree->Branch("gen_eta", &jetEta, "gen_eta/F");
newTree->Branch("fj_corr_sdmass", &jetSDmass, "fj_corr_sdmass/F");
newTree->Branch("topSize", &genSize, "topSize/F");
//newTree->Branch("best_class", &best_class, "best_class/I");

tTop->SetBranchAddress("prob_t", &prob_t);
tTop->SetBranchAddress("prob_b", &prob_b);
tTop->SetBranchAddress("prob_W", &prob_W);
tTop->SetBranchAddress("prob_Z", &prob_Z);
tTop->SetBranchAddress("prob_H", &prob_H);
tTop->SetBranchAddress("prob_j", &prob_QCD);
tTop->SetBranchAddress("genPt", &genPt);
tTop->SetBranchAddress("npv", &npv);
tTop->SetBranchAddress("best_class", &best_class);
tTop->SetBranchAddress("jetEta", &jetEta);
tTop->SetBranchAddress("jetSDmass", &jetSDmass);
tTop->SetBranchAddress("topSize", &genSize);
tTop->SetBranchAddress("dRgenParticle", &dRgenParticle);


tW->SetBranchAddress("prob_t", &prob_t);
tW->SetBranchAddress("prob_b", &prob_b);
tW->SetBranchAddress("prob_W", &prob_W);
tW->SetBranchAddress("prob_Z", &prob_Z);
tW->SetBranchAddress("prob_H", &prob_H);
tW->SetBranchAddress("prob_j", &prob_QCD);
tW->SetBranchAddress("genPt", &genPt);
tW->SetBranchAddress("npv", &npv);
tW->SetBranchAddress("best_class", &best_class);
tW->SetBranchAddress("jetEta", &jetEta);
tW->SetBranchAddress("jetSDmass", &jetSDmass);
tW->SetBranchAddress("topSize", &genSize);
tW->SetBranchAddress("dRgenParticle", &dRgenParticle);

tZ->SetBranchAddress("prob_t", &prob_t);
tZ->SetBranchAddress("prob_b", &prob_b);
tZ->SetBranchAddress("prob_W", &prob_W);
tZ->SetBranchAddress("prob_Z", &prob_Z);
tZ->SetBranchAddress("prob_H", &prob_H);
tZ->SetBranchAddress("prob_j", &prob_QCD);
tZ->SetBranchAddress("genPt", &genPt);
tZ->SetBranchAddress("npv", &npv);
tZ->SetBranchAddress("best_class", &best_class);
tZ->SetBranchAddress("jetEta", &jetEta);
tZ->SetBranchAddress("jetSDmass", &jetSDmass);
tZ->SetBranchAddress("topSize", &genSize);
tZ->SetBranchAddress("dRgenParticle", &dRgenParticle);

tH->SetBranchAddress("prob_t", &prob_t);
tH->SetBranchAddress("prob_b", &prob_b);
tH->SetBranchAddress("prob_W", &prob_W);
tH->SetBranchAddress("prob_Z", &prob_Z);
tH->SetBranchAddress("prob_H", &prob_H);
tH->SetBranchAddress("prob_j", &prob_QCD);
tH->SetBranchAddress("genPt", &genPt);
tH->SetBranchAddress("npv", &npv);
tH->SetBranchAddress("best_class", &best_class);
tH->SetBranchAddress("jetEta", &jetEta);
tH->SetBranchAddress("jetSDmass", &jetSDmass);
tH->SetBranchAddress("topSize", &genSize);
tH->SetBranchAddress("dRgenParticle", &dRgenParticle);



tQCD->SetBranchAddress("prob_t", &prob_t);
tQCD->SetBranchAddress("prob_b", &prob_b);
tQCD->SetBranchAddress("prob_W", &prob_W);
tQCD->SetBranchAddress("prob_Z", &prob_Z);
tQCD->SetBranchAddress("prob_H", &prob_H);
tQCD->SetBranchAddress("prob_j", &prob_QCD);
tQCD->SetBranchAddress("genPt", &genPt);
tQCD->SetBranchAddress("npv", &npv);
tQCD->SetBranchAddress("best_class", &best_class);
tQCD->SetBranchAddress("jetSDmass", &jetSDmass);
tQCD->SetBranchAddress("jetEta", &jetEta);
tQCD->SetBranchAddress("topSize", &genSize);
tQCD->SetBranchAddress("dRgenParticle", &dRgenParticle);

int nEntries_H = tH->GetEntries();
sample = 4;
for (int i = 0; i < nEntries_H; i++){

	tH->GetEntry(i);
	if (!(abs(jetEta) < 1.5 && dRgenParticle < 0.6)) continue;
	newTree->Fill();

}

int nEntries_Z = tZ->GetEntries();
sample = 3;
for (int i = 0; i < nEntries_Z; i++){

	tZ->GetEntry(i);
	if (!(abs(jetEta) < 1.5 && dRgenParticle < 0.6)) continue;
	newTree->Fill();

}

int nEntries_top = tTop->GetEntries();
sample = 2;
for (int i = 0; i < nEntries_top; i++){

	tTop->GetEntry(i);
	if (!(abs(jetEta) < 1.5 && dRgenParticle < 0.6)) continue;
	newTree->Fill();

}


int nEntries_W = tW->GetEntries();
sample = 1;
for (int i = 0; i < nEntries_W; i++){

	tW->GetEntry(i);

	if (!(abs(jetEta) < 1.5 && dRgenParticle < 0.6)) continue;

	newTree->Fill();


}

int nEntries_QCD = tQCD->GetEntries();
sample = 0;
for (int i = 0; i < nEntries_QCD; i++){

	tQCD->GetEntry(i);
	if (!(abs(jetEta) < 1.5 && dRgenParticle < 0.6)) continue;

	
	newTree->Fill();


}

outF->cd();
outF->Write();
outF->Close();


}


