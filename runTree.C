#include <cstdlib>
#include <iostream>
#include <map>
#include <string>


#include "TMVA/Reader.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TMVA/Tools.h"

void runTree(string inFile, string outFile) {


	TChain *origFiles = new TChain("eventVars", "eventVars");
	origFiles->Add(inFile.c_str());
	
	int nEntries = origFiles->GetEntries();
	cout << "The old chain contains " << nEntries << " entries." << endl;

   int npv;
   float puWt;

   origFiles->SetBranchAddress("npv", &npv);
   origFiles->SetBranchAddress("pileupWt", &puWt);

   TFile *newFile = new TFile(outFile.c_str(), "RECREATE");
   TTree *newTree = origFiles->CloneTree(); 

   TFile *puFile = new TFile("puWeights.root", "READ");
   TH1F *puHist = (TH1F *) puFile->Get("pileupWeight");

   newTree->Branch("newpileupWt", &puWt, "newpileupWt/F");
   int nEvents = origFiles->GetEntries();
   for (int i = 0; i < origFiles->GetEntries(); i++){
	
		origFiles->GetEntry(i);

		puWt = puHist->GetBinContent(npv);

	

		newTree->Fill();

	}

	newFile->cd();
	newTree->Write();
	newFile->Write();
	newFile->Close();


}
