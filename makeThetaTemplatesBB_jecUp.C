#include "CMS_lumi.C"
#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TH1.h"
#include "TPad.h"
#include "TF1.h"
#include "TH2F.h"
#include "TChain.h"
#include "THStack.h"
#include "TGraph.h"

void makeThetaTemplatesBB_jecUp(int numTop, int numW, int numZ, int numH, int numB, float br_bw = 0.3333333, float br_tz = 0.3333333, float br_th = 0.333333){


cout << "Running " << numTop << " " << numW << " " << numZ << " " << numH << " " << numB << endl;

gROOT->SetStyle("Empty");
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);

int nbins = 50;
int xmin = 0;
int xmax = 10000;
//int nbins = 6;
//int xmin = 0;
//int xmax = 6;
float *bins;
nbins = 14;
float bins1[15] = {0, 1500, 1600, 1700, 1800, 1900, 2000, 2200, 2400, 2600, 2800, 3000, 4000, 5000, 10000};
bins = bins1;
if (
(numTop == 0 && numW == 0 && numZ == 0 && numH == 1 && numB == 3) ||
(numTop == 0 && numW == 0 && numZ == 0 && numH == 2 && numB == 2) ||
(numTop == 0 && numW == 0 && numZ == 2 && numH == 1 && numB == 0) ||
(numTop == 0 && numW == 0 && numZ == 3 && numH == 0 && numB == 0) ||
(numTop == 0 && numW == 1 && numZ == 0 && numH == 0 && numB == 3) ||
(numTop == 0 && numW == 1 && numZ == 0 && numH == 2 && numB == 1) ||
(numTop == 0 && numW == 2 && numZ == 1 && numH == 0 && numB == 1) ||
(numTop == 1 && numW == 0 && numZ == 1 && numH == 2 && numB == 0) ||
(numTop == 1 && numW == 0 && numZ == 2 && numH == 1 && numB == 0) ||
(numTop == 1 && numW == 0 && numZ == 3 && numH == 0 && numB == 0) ||
(numTop == 1 && numW == 1 && numZ == 0 && numH == 2 && numB == 0) ||
(numTop == 1 && numW == 3 && numZ == 0 && numH == 0 && numB == 0) ||
(numTop == 2 && numW == 0 && numZ == 0 && numH == 2 && numB == 0) ||
(numTop == 2 && numW == 0 && numZ == 2 && numH == 0 && numB == 0)
){
nbins = 1;
float bins2[2] = {0,10000};
bins = bins2;
}

TFile *fileQCD_1 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd1.root", "READ");
TFile *fileQCD_2 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd2.root", "READ");
TFile *fileQCD_3 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd3.root", "READ");
TFile *fileQCD_4 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd4.root", "READ");
TFile *fileQCD_5 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd5.root", "READ");
TFile *fileQCD_6 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd6.root", "READ");
TFile *fileQCD_7 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd7.root", "READ");
TFile *fileQCD_8 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd8.root", "READ");
TFile *fileQCD_9 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd9.root", "READ");

TFile *fileTT = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ttbar_jecUp.root", "READ");
TFile *fileWj = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_wjets_jecUp.root", "READ");
TFile *fileZj = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_zjets_jecUp.root", "READ");

TFile *fileWW = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_WW_jecUp.root", "READ");
TFile *fileWZ = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_WZ_jecUp.root", "READ");
TFile *fileZZ = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ZZ_jecUp.root", "READ");

TFile *fileTTW = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ttW_jecUp.root", "READ");
TFile *fileTTZ = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ttZ_jecUp.root", "READ");
TFile *fileTTTT = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_tttt_jecUp.root", "READ");

TFile *fileHbb = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_Hbb.root", "READ");
TFile *fileHWW = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_HWW.root", "READ");
TFile *fileWplusH = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_WplusH.root", "READ");
TFile *fileWminusH = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_WminusH.root", "READ");



TFile *sig700 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB700_jecUp.root", "READ");
TFile *sig800 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB800_jecUp.root", "READ");
TFile *sig900 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB900_jecUp.root", "READ");
TFile *sig1000 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB1000_jecUp.root", "READ");
TFile *sig1100 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB1100_jecUp.root", "READ");
TFile *sig1200 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB1200_jecUp.root", "READ");
TFile *sig1300 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB1300_jecUp.root", "READ");
TFile *sig1400 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB1400_jecUp.root", "READ");
TFile *sig1500 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB1500_jecUp.root", "READ");
TFile *sig1600 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB1600_jecUp.root", "READ");
TFile *sig1700 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB1700_jecUp.root", "READ");
TFile *sig1800 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlqBB1800_jecUp.root", "READ");


gROOT->cd();

TTree *treeQCD_1 = (TTree *) fileQCD_1->Get("eventVars");
TTree *treeQCD_2 = (TTree *) fileQCD_2->Get("eventVars");
TTree *treeQCD_3 = (TTree *) fileQCD_3->Get("eventVars");
TTree *treeQCD_4 = (TTree *) fileQCD_4->Get("eventVars");
TTree *treeQCD_5 = (TTree *) fileQCD_5->Get("eventVars");
TTree *treeQCD_6 = (TTree *) fileQCD_6->Get("eventVars");
TTree *treeQCD_7 = (TTree *) fileQCD_7->Get("eventVars");
TTree *treeQCD_8 = (TTree *) fileQCD_8->Get("eventVars");
TTree *treeQCD_9 = (TTree *) fileQCD_9->Get("eventVars");
TChain *treeDATA = new TChain("eventVars");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataB.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataC.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataD.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataE.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataF.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataG.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataH.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_DATA_H2.root");


TTree *treeTT = (TTree *) fileTT->Get("eventVars");
TTree *treeWj = (TTree *) fileWj->Get("eventVars");
TTree *treeZj = (TTree *) fileZj->Get("eventVars");
TTree *treeWW = (TTree *) fileWW->Get("eventVars");
TTree *treeWZ = (TTree *) fileWZ->Get("eventVars");
TTree *treeZZ = (TTree *) fileZZ->Get("eventVars");

TTree *treeTTW = (TTree *) fileTTW->Get("eventVars");
TTree *treeTTZ = (TTree *) fileTTZ->Get("eventVars");
TTree *treeTTTT = (TTree *) fileTTTT->Get("eventVars");
TTree *treeHbb = (TTree *) fileHbb->Get("eventVars");
TTree *treeHWW = (TTree *) fileHWW->Get("eventVars");
TTree *treeWplusH = (TTree *) fileWplusH->Get("eventVars");
TTree *treeWminusH = (TTree *) fileWminusH->Get("eventVars");

TTree *tree_sig700 = (TTree *) sig700->Get("eventVars");
TTree *tree_sig800 = (TTree *) sig800->Get("eventVars");
TTree *tree_sig900 = (TTree *) sig900->Get("eventVars");
TTree *tree_sig1000 = (TTree *) sig1000->Get("eventVars");
TTree *tree_sig1100 = (TTree *) sig1100->Get("eventVars");
TTree *tree_sig1200 = (TTree *) sig1200->Get("eventVars");
TTree *tree_sig1300 = (TTree *) sig1300->Get("eventVars");
TTree *tree_sig1400 = (TTree *) sig1400->Get("eventVars");
TTree *tree_sig1500 = (TTree *) sig1500->Get("eventVars");
TTree *tree_sig1600 = (TTree *) sig1600->Get("eventVars");
TTree *tree_sig1700 = (TTree *) sig1700->Get("eventVars");
TTree *tree_sig1800 = (TTree *) sig1800->Get("eventVars");


TH1D *histQCD_1 = new TH1D("histQCD_1", "histQCD_1", nbins, bins);
TH1D *histQCD_2 = new TH1D("histQCD_2", "histQCD_2", nbins, bins);
TH1D *histQCD_3 = new TH1D("histQCD_3", "histQCD_3", nbins, bins);
TH1D *histQCD_4 = new TH1D("histQCD_4", "histQCD_4", nbins, bins);
TH1D *histQCD_5 = new TH1D("histQCD_5", "histQCD_5", nbins, bins);
TH1D *histQCD_6 = new TH1D("histQCD_6", "histQCD_6", nbins, bins);
TH1D *histQCD_7 = new TH1D("histQCD_7", "histQCD_7", nbins, bins);
TH1D *histQCD_8 = new TH1D("histQCD_8", "histQCD_8", nbins, bins);
TH1D *histQCD_9 = new TH1D("histQCD_9", "histQCD_9", nbins, bins);
TH1D *histDATA = new TH1D("histDATA", "histDATA", nbins, bins);
TH1D *histTT = new TH1D("histTT", "histTT", nbins, bins);
TH1D *histWj = new TH1D("histWj", "histWj", nbins, bins);
TH1D *histZj = new TH1D("histZj", "histZj", nbins, bins);

TH1D *histWW = new TH1D("histWW", "histWW", nbins, bins);
TH1D *histZZ = new TH1D("histZZ", "histZZ", nbins, bins);
TH1D *histWZ = new TH1D("histWZ", "histWZ", nbins, bins);

TH1D *histTTW = new TH1D("histTTW", "histTTW", nbins, bins);
TH1D *histTTZ = new TH1D("histTTZ", "histTTZ", nbins, bins);
TH1D *histTTTT = new TH1D("histTTTT", "histTTTT", nbins, bins);
TH1D *histHbb = new TH1D("histHbb", "histHbb", nbins, bins);
TH1D *histHWW = new TH1D("histHWW", "histHWW", nbins, bins);
TH1D *histWplusH = new TH1D("histWplusH", "histWplusH", nbins, bins);
TH1D *histWminusH = new TH1D("histWminusH", "histWminusH", nbins, bins);


TH1D *hist_sig700 = new TH1D("hist_sig700", "hist_sig700", nbins, bins);
TH1D *hist_sig800 = new TH1D("hist_sig800", "hist_sig800", nbins, bins);
TH1D *hist_sig900 = new TH1D("hist_sig900", "hist_sig900", nbins, bins);
TH1D *hist_sig1000 = new TH1D("hist_sig1000", "hist_sig1000", nbins, bins);
TH1D *hist_sig1100 = new TH1D("hist_sig1100", "hist_sig1100", nbins, bins);
TH1D *hist_sig1200 = new TH1D("hist_sig1200", "hist_sig1200", nbins, bins);
TH1D *hist_sig1300 = new TH1D("hist_sig1300", "hist_sig1300", nbins, bins);
TH1D *hist_sig1400 = new TH1D("hist_sig1400", "hist_sig1400", nbins, bins);
TH1D *hist_sig1500 = new TH1D("hist_sig1500", "hist_sig1500", nbins, bins);
TH1D *hist_sig1600 = new TH1D("hist_sig1600", "hist_sig1600", nbins, bins);
TH1D *hist_sig1700 = new TH1D("hist_sig1700", "hist_sig1700", nbins, bins);
TH1D *hist_sig1800 = new TH1D("hist_sig1800", "hist_sig1800", nbins, bins);


TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 600, 500);
c1->Range(0,0,1,1);
c1->Draw();

TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.25);
c1_1->Draw();
TPad *c1_2 = new TPad("c1_2", "newpad",0.01,0.25,0.99,0.99);
c1_2->Draw();

c1->cd();
c1_2->cd();
c1_2->SetTopMargin(0.1);
c1_2->SetBottomMargin(0.1);
c1_2->SetRightMargin(0.05);
c1_2->SetLeftMargin(0.1);
c1_2->SetFillStyle(0);

string var = "ht";
TString selT = Form("numJets == 4 && jetPt_j3 > 400. && numTop == %d && numW == %d && numZ == %d && numH == %d && numB == %d", numTop, numW, numZ, numH, numB);
//TString selT = Form("numJets == 3");
string sel = selT.Data();

treeQCD_1->Draw( Form( "%s >> histQCD_1", var.c_str() ), sel.c_str() );
treeQCD_2->Draw( Form( "%s >> histQCD_2", var.c_str() ), sel.c_str() );
treeQCD_3->Draw( Form( "%s >> histQCD_3", var.c_str() ), sel.c_str() );
treeQCD_4->Draw( Form( "%s >> histQCD_4", var.c_str() ), sel.c_str() );
treeQCD_5->Draw( Form( "%s >> histQCD_5", var.c_str() ), sel.c_str() );
treeQCD_6->Draw( Form( "%s >> histQCD_6", var.c_str() ), sel.c_str() );
treeQCD_7->Draw( Form( "%s >> histQCD_7", var.c_str() ), sel.c_str() );
treeQCD_8->Draw( Form( "%s >> histQCD_8", var.c_str() ), sel.c_str() );
treeQCD_9->Draw( Form( "%s >> histQCD_9", var.c_str() ), sel.c_str() );

string count_sel = "";

float totNumQCD = treeQCD_1->GetEntries(count_sel.c_str()) +
	       treeQCD_2->GetEntries(count_sel.c_str()) +
	       treeQCD_3->GetEntries(count_sel.c_str()) +
	       treeQCD_4->GetEntries(count_sel.c_str()) +
	       treeQCD_5->GetEntries(count_sel.c_str()) +
	       treeQCD_6->GetEntries(count_sel.c_str()) +
	       treeQCD_7->GetEntries(count_sel.c_str()) +
	       treeQCD_8->GetEntries(count_sel.c_str()) +
	       treeQCD_9->GetEntries(count_sel.c_str());

float totNumTT = treeTT->GetEntries(count_sel.c_str());


treeDATA->Draw( Form( "%s >> histDATA", var.c_str() ), sel.c_str() );


treeTT->Draw( Form( "%s >> histTT", var.c_str() ), sel.c_str() );
treeWj->Draw( Form( "%s >> histWj", var.c_str() ), sel.c_str() );
treeZj->Draw( Form( "%s >> histZj", var.c_str() ), sel.c_str() );

treeWW->Draw( Form( "%s >> histWW", var.c_str() ), sel.c_str() );
treeZZ->Draw( Form( "%s >> histZZ", var.c_str() ), sel.c_str() );
treeWZ->Draw( Form( "%s >> histWZ", var.c_str() ), sel.c_str() );
treeTTW->Draw( Form( "%s >> histTTW", var.c_str() ), sel.c_str() );
treeTTZ->Draw( Form( "%s >> histTTZ", var.c_str() ), sel.c_str() );
treeTTTT->Draw( Form( "%s >> histTTTT", var.c_str() ), sel.c_str() );
treeHbb->Draw( Form( "%s >> histHbb", var.c_str() ), sel.c_str() );
treeHWW->Draw( Form( "%s >> histHWW", var.c_str() ), sel.c_str() );
treeWplusH->Draw( Form( "%s >> histWplusH", var.c_str() ), sel.c_str() );
treeWminusH->Draw( Form( "%s >> histWminusH", var.c_str() ), sel.c_str() );


TString sigselT = Form("(((decayMode1 == 1 && decayMode2 == 1) || (decayMode2 == 1 && decayMode1 == 1))*%f + ((decayMode1 == 1 && decayMode2 == 2) || (decayMode1 == 2 && decayMode2 == 1))*%f + ((decayMode1 == 1 && decayMode2 == 3) || (decayMode1 == 3 && decayMode2 == 1))*%f + ((decayMode1 == 2 && decayMode2 == 3) || (decayMode1 == 3 && decayMode2 == 2))*%f +((decayMode1 == 2 && decayMode2 == 2) || (decayMode2 == 2 && decayMode1 == 2))*%f + ((decayMode1 == 3 && decayMode2 == 3) || (decayMode2 == 3 && decayMode1 == 3))*%f  ) * (numJets == 4 && jetPt_j3 > 400. && numTop == %d && numW == %d && numZ == %d && numH == %d && numB == %d)", 3*br_tz*3*br_tz, 3*br_tz*3*br_bw, 3*br_tz*3*br_th, 3*br_bw*3*br_th, 3*br_bw*3*br_bw, 3*br_th*3*br_th, numTop, numW, numZ, numH, numB);
//TString sigselT = Form("numJets == 3");
string sigsel = sigselT.Data();
tree_sig700->Draw( Form( "%s >> hist_sig700", var.c_str() ), sigsel.c_str() );
tree_sig800->Draw( Form( "%s >> hist_sig800", var.c_str() ), sigsel.c_str() );
tree_sig900->Draw( Form( "%s >> hist_sig900", var.c_str() ), sigsel.c_str() );
tree_sig1000->Draw( Form( "%s >> hist_sig1000", var.c_str() ), sigsel.c_str() );
tree_sig1100->Draw( Form( "%s >> hist_sig1100", var.c_str() ), sigsel.c_str() );
tree_sig1200->Draw( Form( "%s >> hist_sig1200", var.c_str() ), sigsel.c_str() );
tree_sig1300->Draw( Form( "%s >> hist_sig1300", var.c_str() ), sigsel.c_str() );
tree_sig1400->Draw( Form( "%s >> hist_sig1400", var.c_str() ), sigsel.c_str() );
tree_sig1500->Draw( Form( "%s >> hist_sig1500", var.c_str() ), sigsel.c_str() );
tree_sig1600->Draw( Form( "%s >> hist_sig1600", var.c_str() ), sigsel.c_str() );
tree_sig1700->Draw( Form( "%s >> hist_sig1700", var.c_str() ), sigsel.c_str() );
tree_sig1800->Draw( Form( "%s >> hist_sig1800", var.c_str() ), sigsel.c_str() );


float lumi = 35289.97 + 0.215;//8529.407;

histQCD_1->Scale( 7823.0 * lumi / 4150588.);
histQCD_2->Scale(  648.2 * lumi / 3959986.);
histQCD_3->Scale(  186.9 * lumi / 3896412.);
histQCD_4->Scale(  32.29 * lumi / 3992112.);
histQCD_5->Scale(  9.418 * lumi / 2999069.);
histQCD_6->Scale(  0.84265 * lumi / 396409.);
histQCD_7->Scale(  0.114943 * lumi / 397660.);
histQCD_8->Scale(  0.0068291 * lumi / 399226.);
histQCD_9->Scale(  0.0001654 * lumi / 391735.);


histTT->Scale( 831.76 * lumi / 77081156. );
histWj->Scale( 95.14*.066*lumi / 1026587.);
histZj->Scale( 5.67 * lumi / 996000.); 


histWW->Scale( 63.21 * lumi / 6987124.);
histZZ->Scale( 16.523 * lumi / 998034. );
histWZ->Scale( 47.13  * lumi / 2995828. );
histWW->Add(histZZ);
histWW->Add(histWZ);

histTTW->Scale( 0.4062 * lumi / 833298. );
histTTZ->Scale( 0.5297 * lumi / 749400. );
histTTTT->Scale( 0.009103 * lumi /  250000. );
histTTW->Add(histTTZ);
histTTW->Add(histTTTT);

histHbb->Scale( 43.92* 0.648 * lumi /  529120. );
histHWW->Scale( 43.92* 0.14*2*0.1*0.67 * lumi  / 43865.  ); //H->WW decay * WW->lvqq decay
histWplusH->Scale( 1.38* 0.648 * 0.676 * lumi / 231550. ); //H->bb, W->QQ
histWminusH->Scale( 1.38* 0.648* 0.676 * lumi / 274037. ); 
histHbb->Add(histHWW);
histHbb->Add(histWplusH);
histHbb->Add(histWminusH);

hist_sig700->Scale(0.455*lumi  / 816600. );
hist_sig800->Scale(0.196*lumi  / 817200. );
hist_sig900->Scale(0.090*lumi  / 799800. );
hist_sig1000->Scale(0.044*lumi  / 831400. );
hist_sig1100->Scale(0.022*lumi  / 833000. );
hist_sig1200->Scale(0.0118*lumi  / 832600. );
hist_sig1300->Scale(0.0064*lumi  / 800400. );
hist_sig1400->Scale(0.0035*lumi  / 831000. );
hist_sig1500->Scale(0.0020*lumi  / 767400. );
hist_sig1600->Scale(0.00115*lumi  / 622800. );
hist_sig1700->Scale(0.00067*lumi  / 782000. );
hist_sig1800->Scale(0.00039*lumi  / 833000. );


histQCD_1->Add(histQCD_2);
histQCD_1->Add(histQCD_3);
histQCD_1->Add(histQCD_4);
histQCD_1->Add(histQCD_5);
histQCD_1->Add(histQCD_6);
histQCD_1->Add(histQCD_7);
histQCD_1->Add(histQCD_8);
histQCD_1->Add(histQCD_9);

TString channelT = TString::Format("%dt_%dW_%dZ_%dH_%db", numTop, numW, numZ, numH, numB);
string channel = channelT.Data();
cout << channel << endl;

cout << "HERE " << endl;
TFile *outFile = new TFile(TString::Format("%s_histos_jecUp.root", channel.c_str()), "RECREATE");

//histDATA->Write(TString::Format("%s__DATA", channel.c_str()));
//histQCD_1->Write(TString::Format("%s__qcd", channel.c_str()));
//histQCD_sampled->Write(TString::Format("%s__qcd", channel.c_str()));
//histQCD_sampled_up->Write(TString::Format("%s__qcd__mistag__plus", channel.c_str()));
//histQCD_sampled_dn->Write(TString::Format("%s__qcd__mistag__minus", channel.c_str()));
histTT->Write(TString::Format("%s__ttbar__jec__plus", channel.c_str()));
histWj->Write(TString::Format("%s__wjets__jec__plus", channel.c_str()));
histZj->Write(TString::Format("%s__zjets__jec__plus", channel.c_str()));
histWW->Write(TString::Format("%s__diboson__jec__plus", channel.c_str()));
histTTW->Write(TString::Format("%s__ttV__jec__plus", channel.c_str()));

hist_sig700->Write(TString::Format("%s__tprime700__jec__plus", channel.c_str()));
hist_sig800->Write(TString::Format("%s__tprime800__jec__plus", channel.c_str()));
hist_sig900->Write(TString::Format("%s__tprime900__jec__plus", channel.c_str()));
hist_sig1000->Write(TString::Format("%s__tprime1000__jec__plus", channel.c_str()));
hist_sig1100->Write(TString::Format("%s__tprime1100__jec__plus", channel.c_str()));
hist_sig1200->Write(TString::Format("%s__tprime1200__jec__plus", channel.c_str()));
hist_sig1300->Write(TString::Format("%s__tprime1300__jec__plus", channel.c_str()));
hist_sig1400->Write(TString::Format("%s__tprime1400__jec__plus", channel.c_str()));
hist_sig1500->Write(TString::Format("%s__tprime1500__jec__plus", channel.c_str()));
hist_sig1600->Write(TString::Format("%s__tprime1600__jec__plus", channel.c_str()));
hist_sig1700->Write(TString::Format("%s__tprime1700__jec__plus", channel.c_str()));
hist_sig1800->Write(TString::Format("%s__tprime1800__jec__plus", channel.c_str()));

fileQCD_1->Close();
fileQCD_2->Close();
fileQCD_3->Close();
fileQCD_4->Close();
fileQCD_5->Close();
fileQCD_6->Close();
fileQCD_7->Close();
fileQCD_8->Close();
fileQCD_9->Close();
fileTT->Close();
fileWj->Close();
fileZj->Close();
outFile->Close();

return;
}

