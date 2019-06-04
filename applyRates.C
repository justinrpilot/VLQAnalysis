#include "TH1F.h"
#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include <iostream>
#include <algorithm>
using namespace std;

void loadHists();
TH1F* getHistogram(int index, string tag);
TFile *templates = new TFile("jetPt_templates.root", "READ");
TFile *rates = new TFile("BEST_rates_3jet_DATA_6bin.root", "READ");
TRandom *rng = new TRandom();
std::vector< std::vector<int> > findAllPerms(int nTop, int nZ, int nW, int nH, int nB);
void makePermutations(int nTop, int nZ, int nW, int nH, int nB, int* perm);

string tagIDtoName(int ID);

void sampleEvents(int nTop, int nZ, int nW, int nH, int nB, string infilename, string outfilename, int combFactor = 1){

//cout << combFactor << " combinations" << endl;

float *thebins;
int nbins = 14;
float bins[15] = {0, 1500, 1600, 1700, 1800, 1900, 2000, 2200, 2400, 2600, 2800, 3000, 4000, 5000, 10000};
thebins = bins;
if (
(nTop == 0 && nW == 0 && nZ == 0 && nH == 1 && nB == 3) ||
(nTop == 0 && nW == 0 && nZ == 0 && nH == 2 && nB == 2) ||
(nTop == 0 && nW == 0 && nZ == 2 && nH == 1 && nB == 0) ||
(nTop == 0 && nW == 0 && nZ == 3 && nH == 0 && nB == 0) ||
(nTop == 0 && nW == 1 && nZ == 0 && nH == 0 && nB == 3) ||
(nTop == 0 && nW == 1 && nZ == 0 && nH == 2 && nB == 1) ||
(nTop == 0 && nW == 2 && nZ == 1 && nH == 0 && nB == 1) ||
(nTop == 1 && nW == 0 && nZ == 1 && nH == 2 && nB == 0) ||
(nTop == 1 && nW == 0 && nZ == 2 && nH == 1 && nB == 0) ||
(nTop == 1 && nW == 0 && nZ == 3 && nH == 0 && nB == 0) ||
(nTop == 1 && nW == 1 && nZ == 0 && nH == 2 && nB == 0) ||
(nTop == 1 && nW == 3 && nZ == 0 && nH == 0 && nB == 0) ||
(nTop == 2 && nW == 0 && nZ == 0 && nH == 2 && nB == 0) ||
(nTop == 2 && nW == 0 && nZ == 2 && nH == 0 && nB == 0)
){
nbins = 1;
float bins2[2] = {0,10000};
thebins = bins2;
}


TH1D *outHT = new TH1D("outHT", "outHT", nbins, thebins);
TH1D *outHTup = new TH1D("outHTup", "outHTup", nbins, thebins);
TH1D *outHTdn = new TH1D("outHTdn", "outHTdn", nbins, thebins);
TH1D *outpt0 = new TH1D("outpt0", "outpt0", 100, 0, 4000);
TH1D *outpt1 = new TH1D("outpt1", "outpt1", 100, 0, 4000);
TH1D *outpt2 = new TH1D("outpt2", "outpt2", 100, 0, 4000);
TH1D *outpt3 = new TH1D("outpt3", "outpt3", 100, 0, 4000);

int step = 0;
float eventHT = 0.0;

TFile *infile = TFile::Open(Form("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/%s", infilename.c_str()));

TTree *evTree = (TTree *) infile->Get("eventVars");


float jet0pt = 99999., jet1pt = 99999., jet2pt = 99999., jet3pt = 99999.;
float ht = 0.;
float jet0wt = 0.0, jet1wt = 0.0, jet2wt = 0.0, jet3wt = 0.0;
float jet0wtup = 0.0, jet1wtup = 0.0, jet2wtup = 0.0, jet3wtup = 0.0;
float jet0wtdn = 0.0, jet1wtdn = 0.0, jet2wtdn = 0.0, jet3wtdn = 0.0;
int numJets = -9;

evTree->SetBranchStatus("*", 0);
evTree->SetBranchStatus("jetPt_j0", 1);
evTree->SetBranchStatus("jetPt_j1", 1);
evTree->SetBranchStatus("jetPt_j2", 1);
evTree->SetBranchStatus("jetPt_j3", 1);
evTree->SetBranchStatus("ht", 1);
evTree->SetBranchStatus("numJets", 1);

evTree->SetBranchAddress("jetPt_j0", &jet0pt);
evTree->SetBranchAddress("jetPt_j1", &jet1pt);
evTree->SetBranchAddress("jetPt_j2", &jet2pt);
evTree->SetBranchAddress("jetPt_j3", &jet3pt);
evTree->SetBranchAddress("ht", &ht);
evTree->SetBranchAddress("numJets", &numJets);

int entries = evTree->GetEntries();
cout << "Tree has " << entries << " entries." << endl;
int entry = 0;

while (entry < entries){
	entry++;
	if (entry % 10000 == 0) cout << float(entry) / float(entries) << endl;


	evTree->GetEntry(entry);
	//cout << jet0pt << " " << ht << endl;	

	

	if (numJets != 4) continue;
	int loops = 1;	
	allPerms = findAllPerms(nTop, nZ, nW, nH, nB);
	//cout << "size of permutations = " << allPerms.size() << endl;
	for (int i = 0; i < allPerms.size(); i++){
	//int thisPerm[5] = {0,0,0,0,0};
	std::vector<int> thisPerm = allPerms.at(i);
	//makePermutations(nTop, nZ, nW, nH, nB, thisPerm);
	//cout << "MADE PERM = " << thisPerm[0] << " " << thisPerm[1] << " " << thisPerm[2] << " " << thisPerm[3] << endl;
	int mult = 0;
	if (thisPerm[0]) mult++;	
	if (thisPerm[1]) mult++;	
	if (thisPerm[2]) mult++;	
	if (thisPerm[3]) mult++;	
	//if (thisPerm[4]) mult++;	

	TH1F *hist1 = getHistogram(0, tagIDtoName(thisPerm[0]));
	jet0wt = hist1->GetBinContent( hist1->FindBin(jet0pt) );
	jet0wtup = hist1->GetBinContent( hist1->FindBin(jet0pt) ) + hist1->GetBinError( hist1->FindBin(jet0pt) );
	jet0wtdn = hist1->GetBinContent( hist1->FindBin(jet0pt) ) - hist1->GetBinError( hist1->FindBin(jet0pt) );
	delete hist1;

	TH1F *hist2 = getHistogram(1, tagIDtoName(thisPerm[1]));
	jet1wt = hist2->GetBinContent( hist2->FindBin(jet1pt) );
	jet1wtup = hist2->GetBinContent( hist2->FindBin(jet1pt) ) + hist2->GetBinError( hist2->FindBin(jet1pt) );
	jet1wtdn = hist2->GetBinContent( hist2->FindBin(jet1pt) ) - hist2->GetBinError( hist2->FindBin(jet1pt) );
	delete hist2;

	TH1F *hist3 = getHistogram(2, tagIDtoName(thisPerm[2]));
	jet2wt = hist3->GetBinContent( hist3->FindBin(jet2pt) );
	jet2wtup = hist3->GetBinContent( hist3->FindBin(jet2pt) ) + hist3->GetBinError( hist3->FindBin(jet2pt) );
	jet2wtdn = hist3->GetBinContent( hist3->FindBin(jet2pt) ) - hist3->GetBinError( hist3->FindBin(jet2pt) );
	delete hist3;

	TH1F *hist4 = getHistogram(3, tagIDtoName(thisPerm[3]));
	jet3wt = hist4->GetBinContent( hist4->FindBin(jet3pt) );
	jet3wtup = hist4->GetBinContent( hist4->FindBin(jet3pt) ) + hist4->GetBinError( hist4->FindBin(jet3pt) );
	jet3wtdn = hist4->GetBinContent( hist4->FindBin(jet3pt) ) - hist4->GetBinError( hist4->FindBin(jet3pt) );
	delete hist4;

	//cout << "Wts: " << jet0wt << " " << jet1wt << " " << jet2wt << " " << jet3wt << endl;

	//outHT->Fill(ht, combFactor*jet0wt*jet1wt*jet2wt*jet3wt/float(loops));
	//outHTup->Fill(ht, combFactor*jet0wtup*jet1wtup*jet2wtup*jet3wtup/float(loops));
	//outHTdn->Fill(ht, combFactor*jet0wtdn*jet1wtdn*jet2wtdn*jet3wtdn/float(loops));
	outHT->Fill(ht, jet0wt*jet1wt*jet2wt*jet3wt);
	outHTup->Fill(ht, jet0wtup*jet1wtup*jet2wtup*jet3wtup);
	outHTdn->Fill(ht, jet0wtdn*jet1wtdn*jet2wtdn*jet3wtdn);
	}

}


outHT->Draw();

TFile *outfile = new TFile(outfilename.c_str(), "RECREATE");
outfile->cd();
outHT->Write();
outHTup->Write();
outHTdn->Write();
outfile->Close();



}


TH1F* getHistogram(int index, string tag){


string jetIndex = "";

switch (index){
	case 0:  jetIndex = "j0";break;
	case 1:  jetIndex = "j1";break;
	case 2:  jetIndex = "j2";break;
	case 3:  jetIndex = "j3";break;
}

//string histName = tag+"_"+jetIndex+"_rate";
string histName = tag+"_rate";
//cout << "Getting histogram " << histName << endl;

TH1F *hist = (TH1F *) rates->Get(histName.c_str());

return hist;


}


std::vector< std::vector<int> > findAllPerms(int nTop, int nZ, int nW, int nH, int nB ){

std::vector< std::vector<int> > allPerms;
std::vector<int> myInts;

int nQCD = max(0, 4 - nTop - nZ - nW - nH - nB);

while (nTop > 0){ myInts.push_back(1); nTop--; }
while (nZ > 0){ myInts.push_back(2); nZ--; }
while (nW > 0){ myInts.push_back(3); nW--; }
while (nH > 0){ myInts.push_back(4); nH--; }
while (nB > 0){ myInts.push_back(5); nB--; }
while (nQCD > 0){ myInts.push_back(0); nQCD--; }

int theseInts[] = {myInts[0], myInts[1], myInts[2], myInts[3] };

std::sort (theseInts, theseInts+4);
std::vector<int> thisPerm;
std::cout << "The possible permutations :\n";
  do {
    std::cout << theseInts[0] << ' ' << theseInts[1] << ' ' << theseInts[2] << ' ' << theseInts[3] << '\n';
    thisPerm.clear();
    thisPerm.push_back(theseInts[0]);
    thisPerm.push_back(theseInts[1]);
    thisPerm.push_back(theseInts[2]);
    thisPerm.push_back(theseInts[3]);
    allPerms.push_back( thisPerm );
  } while ( std::next_permutation(theseInts,theseInts+4) );

  std::cout << "After loop: " << theseInts[0] << ' ' << theseInts[1] << ' ' << theseInts[2] << ' ' << theseInts[3] << '\n';

  return allPerms;

}

void makePermutations(int nTop, int nZ, int nW, int nH, int nB, int* perm){

TH1F *topIndex = (TH1F *) templates->Get("h_topTagIndex");
TH1F *WIndex = (TH1F *) templates->Get("h_ZTagIndex");
TH1F *ZIndex = (TH1F *) templates->Get("h_WTagIndex");
TH1F *HIndex = (TH1F *) templates->Get("h_HTagIndex");
TH1F *bIndex = (TH1F *) HIndex->Clone("h_bTagIndex");

TH1F *indexHists[] = {topIndex, ZIndex, WIndex, HIndex, bIndex};
int mults[] = {nTop, nZ, nW, nH, nB};

int startID = rng->Integer(5);

int totalMult = TMath::Min(4, nTop + nZ + nW + nH + nB);

for (int h = 0; h < 5; h++) indexHists[h]->SetBinContent(1, 1.0);
for (int h = 0; h < 5; h++) indexHists[h]->SetBinContent(2, 1.0);
for (int h = 0; h < 5; h++) indexHists[h]->SetBinContent(3, 1.0);
for (int h = 0; h < 5; h++) indexHists[h]->SetBinContent(4, 1.0);
for (int h = 0; h < 5; h++) indexHists[h]->SetBinContent(5, 1.0);

//cout << "startID " << startID << endl;
while (totalMult > 0){
	
//	cout << "testing for tags " << startID << endl;
	if (mults[startID] > 0) {
		int pos = indexHists[startID]->GetRandom();
		//int pos = rng->Integer(4);
		perm[pos] = startID+1;
		//cout << "got index for tag" << startID << ", index " << pos << endl;
		mults[startID]--;
		totalMult--;
//		cout << "set bin content 0 for tagType " << startID << ", bin " << pos+1 << endl;
		for (int h = 0; h < 5; h++) indexHists[h]->SetBinContent(pos+1, 0.0);
		
	}	
	
	startID = (startID + 1) % 5;
//	cout << "newStartID " << startID << endl;
}

delete topIndex;
delete ZIndex;
delete WIndex;
delete HIndex;
delete bIndex;
}

string tagIDtoName(int ID){

	string out = "QCD";
	if (ID == 1) out = "t";
	if (ID == 2) out = "Z";
	if (ID == 3) out = "W";
	if (ID == 4) out = "H";
	if (ID == 5) out = "b";
	return out;
}


void loadHists(){

TFile *templates = new TFile("jetPt_templates.root", "READ");

TH1D *jet0_notag = (TH1D *) templates->Get("h_jet0pt_notag");
TH1D *jet0_Ttag = (TH1D *) templates->Get("h_jet0pt_Ttag");
TH1D *jet0_Htag = (TH1D *) templates->Get("h_jet0pt_Htag");
TH1D *jet0_Wtag = (TH1D *) templates->Get("h_jet0pt_Wtag");
TH1D *jet0_Ztag = (TH1D *) templates->Get("h_jet0pt_Ztag");
TH1D *jet1_notag_1 = (TH1D *) templates->Get("h_jet1pt_notag_1");
TH1D *jet2_notag_1 = (TH1D *) templates->Get("h_jet2pt_notag_1");
TH1D *jet3_notag_1 = (TH1D *) templates->Get("h_jet3pt_notag_1");
TH1D *jet1_Ttag_1 = (TH1D *) templates->Get("h_jet1pt_Ttag_1");
TH1D *jet1_Ttag_2 = (TH1D *) templates->Get("h_jet1pt_Ttag_2");
TH1D *jet1_Ttag_3 = (TH1D *) templates->Get("h_jet1pt_Ttag_3");
TH1D *jet1_Ttag_4 = (TH1D *) templates->Get("h_jet1pt_Ttag_4");
TH1D *jet1_Ttag_5 = (TH1D *) templates->Get("h_jet1pt_Ttag_5");
TH1D *jet1_Ttag_6 = (TH1D *) templates->Get("h_jet1pt_Ttag_6");
TH1D *jet1_Ttag_7 = (TH1D *) templates->Get("h_jet1pt_Ttag_7");
TH1D *jet1_Ttag_8 = (TH1D *) templates->Get("h_jet1pt_Ttag_8");
TH1D *jet1_Htag_1 = (TH1D *) templates->Get("h_jet1pt_Htag_1");
TH1D *jet1_Htag_2 = (TH1D *) templates->Get("h_jet1pt_Htag_2");
TH1D *jet1_Htag_3 = (TH1D *) templates->Get("h_jet1pt_Htag_3");
TH1D *jet1_Htag_4 = (TH1D *) templates->Get("h_jet1pt_Htag_4");
TH1D *jet1_Htag_5 = (TH1D *) templates->Get("h_jet1pt_Htag_5");
TH1D *jet1_Htag_6 = (TH1D *) templates->Get("h_jet1pt_Htag_6");
TH1D *jet1_Htag_7 = (TH1D *) templates->Get("h_jet1pt_Htag_7");
TH1D *jet1_Htag_8 = (TH1D *) templates->Get("h_jet1pt_Htag_8");
TH1D *jet2_Ttag_1 = (TH1D *) templates->Get("h_jet2pt_Ttag_1");
TH1D *jet2_Ttag_2 = (TH1D *) templates->Get("h_jet2pt_Ttag_2");
TH1D *jet2_Ttag_3 = (TH1D *) templates->Get("h_jet2pt_Ttag_3");
TH1D *jet2_Ttag_4 = (TH1D *) templates->Get("h_jet2pt_Ttag_4");
TH1D *jet2_Ttag_5 = (TH1D *) templates->Get("h_jet2pt_Ttag_5");
TH1D *jet2_Ttag_6 = (TH1D *) templates->Get("h_jet2pt_Ttag_6");
TH1D *jet2_Ttag_7 = (TH1D *) templates->Get("h_jet2pt_Ttag_7");
TH1D *jet2_Ttag_8 = (TH1D *) templates->Get("h_jet2pt_Ttag_8");
TH1D *jet3_Ttag_1 = (TH1D *) templates->Get("h_jet3pt_Ttag_1");
TH1D *jet3_Ttag_2 = (TH1D *) templates->Get("h_jet3pt_Ttag_2");
TH1D *jet3_Ttag_3 = (TH1D *) templates->Get("h_jet3pt_Ttag_3");
TH1D *jet3_Ttag_4 = (TH1D *) templates->Get("h_jet3pt_Ttag_4");
TH1D *jet3_Ttag_5 = (TH1D *) templates->Get("h_jet3pt_Ttag_5");
TH1D *jet3_Ttag_6 = (TH1D *) templates->Get("h_jet3pt_Ttag_6");
TH1D *jet3_Ttag_7 = (TH1D *) templates->Get("h_jet3pt_Ttag_7");
TH1D *jet3_Ttag_8 = (TH1D *) templates->Get("h_jet3pt_Ttag_8");
TH1D *jet1_notag_2 = (TH1D *) templates->Get("h_jet1pt_notag_2");
TH1D *jet2_notag_2 = (TH1D *) templates->Get("h_jet2pt_notag_2");
TH1D *jet3_notag_2 = (TH1D *) templates->Get("h_jet3pt_notag_2");
TH1D *jet1_notag_3 = (TH1D *) templates->Get("h_jet1pt_notag_3");
TH1D *jet2_notag_3 = (TH1D *) templates->Get("h_jet2pt_notag_3");
TH1D *jet3_notag_3 = (TH1D *) templates->Get("h_jet3pt_notag_3");
TH1D *jet1_notag_4 = (TH1D *) templates->Get("h_jet1pt_notag_4");
TH1D *jet2_notag_4 = (TH1D *) templates->Get("h_jet2pt_notag_4");
TH1D *jet3_notag_4 = (TH1D *) templates->Get("h_jet3pt_notag_4");
TH1D *jet1_notag_5 = (TH1D *) templates->Get("h_jet1pt_notag_5");
TH1D *jet2_notag_5 = (TH1D *) templates->Get("h_jet2pt_notag_5");
TH1D *jet3_notag_5 = (TH1D *) templates->Get("h_jet3pt_notag_5");
TH1D *jet1_notag_6 = (TH1D *) templates->Get("h_jet1pt_notag_6");
TH1D *jet2_notag_6 = (TH1D *) templates->Get("h_jet2pt_notag_6");
TH1D *jet3_notag_6 = (TH1D *) templates->Get("h_jet3pt_notag_6");
TH1D *jet1_notag_7 = (TH1D *) templates->Get("h_jet1pt_notag_7");
TH1D *jet2_notag_7 = (TH1D *) templates->Get("h_jet2pt_notag_7");
TH1D *jet3_notag_7 = (TH1D *) templates->Get("h_jet3pt_notag_7");
TH1D *jet1_notag_8 = (TH1D *) templates->Get("h_jet1pt_notag_8");
TH1D *jet2_notag_8 = (TH1D *) templates->Get("h_jet2pt_notag_8");
TH1D *jet3_notag_8 = (TH1D *) templates->Get("h_jet3pt_notag_8");
}

