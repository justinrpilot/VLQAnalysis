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

void makeBinHistogram(int numTop, int numW, int numZ, int numH, int numB, int bin){


cout << "Running " << numTop << " " << numW << " " << numZ << " " << numH << " " << numB << endl;

int nbins = 140;
int xmin = 0;
int xmax = 140;


TFile *fileQCD_1 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd1.root", "READ");
TFile *fileQCD_2 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd2.root", "READ");
TFile *fileQCD_3 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd3.root", "READ");
TFile *fileQCD_4 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd4.root", "READ");
TFile *fileQCD_5 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd5.root", "READ");
TFile *fileQCD_6 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd6.root", "READ");
TFile *fileQCD_7 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd7.root", "READ");
TFile *fileQCD_8 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd8.root", "READ");
TFile *fileQCD_9 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd9.root", "READ");

TFile *fileTT = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ttbar.root", "READ");
TFile *fileWj = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_wjets.root", "READ");
TFile *fileZj = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_zjets.root", "READ");

TFile *fileWW = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_WW.root", "READ");
TFile *fileWZ = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_WZ.root", "READ");
TFile *fileZZ = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ZZ.root", "READ");
TFile *fileTTW = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ttW.root", "READ");
TFile *fileTTZ = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ttZ.root", "READ");
TFile *fileTTTT = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_tttt.root", "READ");

TFile *fileHbb = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_Hbb.root", "READ");
TFile *fileHWW = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_HWW.root", "READ");
TFile *fileWplusH = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_WplusH.root", "READ");
TFile *fileWminusH = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_WminusH.root", "READ");


TFile *sig700 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq700.root", "READ");
TFile *sig800 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq800.root", "READ");
TFile *sig900 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq900.root", "READ");
TFile *sig1000 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq1000.root", "READ");
TFile *sig1100 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq1100.root", "READ");
TFile *sig1200 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq1200.root", "READ");
TFile *sig1300 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq1300.root", "READ");
TFile *sig1400 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq1400.root", "READ");
TFile *sig1500 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq1500.root", "READ");
TFile *sig1600 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq1600.root", "READ");
TFile *sig1700 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq1700.root", "READ");
TFile *sig1800 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_vlq1800.root", "READ");


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


TH1D *histQCD_1 = new TH1D("histQCD_1", "histQCD_1", nbins, xmin, xmax);
TH1D *histQCD_2 = new TH1D("histQCD_2", "histQCD_2", nbins, xmin, xmax);
TH1D *histQCD_3 = new TH1D("histQCD_3", "histQCD_3", nbins, xmin, xmax);
TH1D *histQCD_4 = new TH1D("histQCD_4", "histQCD_4", nbins, xmin, xmax);
TH1D *histQCD_5 = new TH1D("histQCD_5", "histQCD_5", nbins, xmin, xmax);
TH1D *histQCD_6 = new TH1D("histQCD_6", "histQCD_6", nbins, xmin, xmax);
TH1D *histQCD_7 = new TH1D("histQCD_7", "histQCD_7", nbins, xmin, xmax);
TH1D *histQCD_8 = new TH1D("histQCD_8", "histQCD_8", nbins, xmin, xmax);
TH1D *histQCD_9 = new TH1D("histQCD_9", "histQCD_9", nbins, xmin, xmax);
TH1D *histDATA = new TH1D("histDATA", "histDATA", nbins, xmin, xmax);
TH1D *histTT = new TH1D("histTT", "histTT", nbins, xmin, xmax);
TH1D *histWj = new TH1D("histWj", "histWj", nbins, xmin, xmax);
TH1D *histZj = new TH1D("histZj", "histZj", nbins, xmin, xmax);
TH1D *histDDQCD = new TH1D("histDDQCD", "histDDQCD", nbins, xmin, xmax);
TH1D *histWW = new TH1D("histWW", "histWW", nbins, xmin, xmax);
TH1D *histZZ = new TH1D("histZZ", "histZZ", nbins, xmin, xmax);
TH1D *histWZ = new TH1D("histWZ", "histWZ", nbins, xmin, xmax);

TH1D *histTTW = new TH1D("histTTW", "histTTW", nbins, xmin, xmax);
TH1D *histTTZ = new TH1D("histTTZ", "histTTZ", nbins, xmin, xmax);
TH1D *histTTTT = new TH1D("histTTTT", "histTTTT", nbins, xmin, xmax);
TH1D *histHbb = new TH1D("histHbb", "histHbb", nbins, xmin, xmax);
TH1D *histHWW = new TH1D("histHWW", "histHWW", nbins, xmin, xmax);
TH1D *histWplusH = new TH1D("histWplusH", "histWplusH", nbins, xmin, xmax);
TH1D *histWminusH = new TH1D("histWminusH", "histWminusH", nbins, xmin, xmax);


TH1D *hist_sig700 = new TH1D("hist_sig700", "hist_sig700", nbins, xmin, xmax);
TH1D *hist_sig800 = new TH1D("hist_sig800", "hist_sig800", nbins, xmin, xmax);
TH1D *hist_sig900 = new TH1D("hist_sig900", "hist_sig900", nbins, xmin, xmax);
TH1D *hist_sig1000 = new TH1D("hist_sig1000", "hist_sig1000", nbins, xmin, xmax);
TH1D *hist_sig1100 = new TH1D("hist_sig1100", "hist_sig1100", nbins, xmin, xmax);
TH1D *hist_sig1200 = new TH1D("hist_sig1200", "hist_sig1200", nbins, xmin, xmax);
TH1D *hist_sig1300 = new TH1D("hist_sig1300", "hist_sig1300", nbins, xmin, xmax);
TH1D *hist_sig1400 = new TH1D("hist_sig1400", "hist_sig1400", nbins, xmin, xmax);
TH1D *hist_sig1500 = new TH1D("hist_sig1500", "hist_sig1500", nbins, xmin, xmax);
TH1D *hist_sig1600 = new TH1D("hist_sig1600", "hist_sig1600", nbins, xmin, xmax);
TH1D *hist_sig1700 = new TH1D("hist_sig1700", "hist_sig1700", nbins, xmin, xmax);
TH1D *hist_sig1800 = new TH1D("hist_sig1800", "hist_sig1800", nbins, xmin, xmax);


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
TString selT = Form("numJets == 4 && numTop == %d && numW == %d && numZ == %d && numH == %d && numB == %d", numTop, numW, numZ, numH, numB);
string sel = selT.Data();
/*
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
*/

float nData = treeDATA->GetEntries( sel.c_str() );


float nTT = treeTT->GetEntries( sel.c_str() );
float nWj = treeWj->GetEntries( sel.c_str() );
float nZj = treeZj->GetEntries( sel.c_str() );

float nWW = treeWW->GetEntries( sel.c_str() );
float nWZ = treeWZ->GetEntries( sel.c_str() );
float nZZ = treeZZ->GetEntries( sel.c_str() );

float nTTW = treeTTW->GetEntries( sel.c_str() );
float nTTZ = treeTTZ->GetEntries( sel.c_str() );
float nTTTT = treeTTTT->GetEntries( sel.c_str() );

float nHbb = treeHbb->GetEntries( sel.c_str() );
float nHWW = treeHWW->GetEntries( sel.c_str() );
float nWplusH = treeWplusH->GetEntries( sel.c_str() );
float nWminusH = treeWminusH->GetEntries( sel.c_str() );


TString sigselT = Form("numJets == 4 && numTop == %d && numW == %d && numZ == %d && numH == %d && numB == %d", numTop, numW, numZ, numH, numB);
string sigsel = sigselT.Data();
float nSig1 = tree_sig800->GetEntries( sigsel.c_str() );
float nSig2 = tree_sig1000->GetEntries( sigsel.c_str() );
float nSig3 = tree_sig1200->GetEntries( sigsel.c_str() );
float nSig4 = tree_sig1400->GetEntries( sigsel.c_str() );
float nSig5 = tree_sig1600->GetEntries( sigsel.c_str() );
float nSig6 = tree_sig1800->GetEntries( sigsel.c_str() );

histDATA->SetBinContent(bin, nData);
histTT->SetBinContent(bin, nTT);
histWj->SetBinContent(bin, nWj);
histZj->SetBinContent(bin, nZj);
histWW->SetBinContent(bin, nWW);
histWZ->SetBinContent(bin, nWZ);
histZZ->SetBinContent(bin, nZZ);
histTTW->SetBinContent(bin, nTTW);
histTTZ->SetBinContent(bin, nTTZ);
histTTTT->SetBinContent(bin, nTTTT);
histHbb->SetBinContent(bin, nHbb);
histHWW->SetBinContent(bin, nHWW);
histWplusH->SetBinContent(bin, nWplusH);
histWminusH->SetBinContent(bin, nWminusH);
hist_sig800->SetBinContent(bin, nSig1);
hist_sig1000->SetBinContent(bin, nSig2);
hist_sig1200->SetBinContent(bin, nSig3);
hist_sig1400->SetBinContent(bin, nSig4);
hist_sig1600->SetBinContent(bin, nSig5);
hist_sig1800->SetBinContent(bin, nSig6);

float lumi = 35289.97+215;//8529.407;

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


hist_sig700->Scale(0.455*lumi  / 816800. );
hist_sig800->Scale(0.196*lumi  / 795000. );
hist_sig900->Scale(0.090*lumi  / 831200. );
hist_sig1000->Scale(0.044*lumi  / 829600. );
hist_sig1100->Scale(0.022*lumi  / 832800. );
hist_sig1200->Scale(0.0118*lumi  / 832600. );
hist_sig1300->Scale(0.0064*lumi  / 831000. );
hist_sig1400->Scale(0.0035*lumi  / 832600. );
hist_sig1500->Scale(0.0020*lumi  / 832800. );
hist_sig1600->Scale(0.00115*lumi  / 832600. );
hist_sig1700->Scale(0.00067*lumi  / 797000. );
hist_sig1800->Scale(0.00039*lumi  / 833000. );

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




hist_sig800->SetLineColor(kOrange+2);
hist_sig1000->SetLineColor(kMagenta+2);
hist_sig1200->SetLineColor(kTeal + 3);
hist_sig1400->SetLineColor(kRed + 2);
hist_sig1600->SetLineColor(kCyan + 2);
hist_sig1800->SetLineColor(kCyan);

hist_sig800->SetLineWidth(2);
hist_sig1000->SetLineWidth(2);
hist_sig1200->SetLineWidth(2);
hist_sig1400->SetLineWidth(2);
hist_sig1600->SetLineWidth(2);
hist_sig1800->SetLineWidth(2);


histTT->SetFillColor(kRed);
histTT->SetLineColor(kRed);
histZj->SetFillColor(kGreen+1);
histZj->SetLineColor(kGreen+1);
histWj->SetFillColor(kBlue);
histWj->SetLineColor(kBlue);

histWW->SetLineColor(kViolet);
histWW->SetFillColor(kViolet);
histTTW->SetFillColor(kOrange);
histTTW->SetLineColor(kOrange);
histHbb->SetFillColor(kCyan+1);
histHbb->SetLineColor(kCyan+1);
histQCD_1->SetFillColor(kYellow + 1);
histQCD_2->SetFillColor(kYellow + 1);
histQCD_3->SetFillColor(kYellow + 1);
histQCD_4->SetFillColor(kYellow + 1);
histQCD_5->SetFillColor(kYellow + 1);
histQCD_6->SetFillColor(kYellow + 1);
histQCD_7->SetFillColor(kYellow + 1);
histQCD_8->SetFillColor(kYellow + 1);
histQCD_9->SetFillColor(kYellow + 1);
histQCD_1->SetLineColor(kYellow + 1);
histQCD_2->SetLineColor(kYellow + 1);
histQCD_3->SetLineColor(kYellow + 1);
histQCD_4->SetLineColor(kYellow + 1);
histQCD_5->SetLineColor(kYellow + 1);
histQCD_6->SetLineColor(kYellow + 1);
histQCD_7->SetLineColor(kYellow + 1);
histQCD_8->SetLineColor(kYellow + 1);
histQCD_9->SetLineColor(kYellow + 1);
/*
float totQCD = histQCD_1->Integral() + histQCD_2->Integral() + histQCD_3->Integral() + histQCD_4->Integral() + histQCD_5->Integral() + histQCD_6->Integral() + histQCD_7->Integral() + histQCD_8->Integral() + histQCD_9->Integral();
float totDATA = histDATA->Integral() - histTT->Integral() - histWj->Integral() - histZj->Integral();



cout << "Scaling QCD by: " << totDATA/totQCD << endl;
histQCD_1->Scale(totDATA / totQCD);
histQCD_2->Scale(totDATA / totQCD);
histQCD_3->Scale(totDATA / totQCD);
histQCD_4->Scale(totDATA / totQCD);
histQCD_5->Scale(totDATA / totQCD);
histQCD_6->Scale(totDATA / totQCD);
histQCD_7->Scale(totDATA / totQCD);
histQCD_8->Scale(totDATA / totQCD);
histQCD_9->Scale(totDATA / totQCD);
*/


histDATA->SetMarkerStyle(21);
histDATA->SetMarkerSize(0.8);


TFile *sampledF = TFile::Open(Form("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/shapes_%dt_%dW_%dZ_%dH_%db.root",numTop, numW, numZ, numH, numB), "READ");

gROOT->cd();
TH1F * histQCD_sampled = (TH1F *) sampledF->Get("outHT")->Clone("histQCD_sampled");
histQCD_sampled->SetLineColor(kAzure-4);
histQCD_sampled->SetFillColor(kAzure-4);
//histQCD_sampled->Scale(totQCD / histQCD_sampled->Integral() );

histDDQCD->SetBinContent( bin, histQCD_sampled->Integral() );

gROOT->cd();
THStack *stack = new THStack("stack", "stack");
stack->Add(histTTW);
stack->Add(histWW);
stack->Add(histHbb);
stack->Add(histZj);
stack->Add(histWj);

stack->Add(histTT);
stack->Add(histQCD_sampled);


c1_2->cd();
histDATA->Draw("axis");

stack->SetMaximum( 1.5 * (1+histDATA->GetMaximum()) );
stack->SetMinimum( 0.0001 );
histDATA->GetXaxis()->SetTitle( "H_{T} [GeV]" );
stack->Draw("hist");
histDATA->Draw("E same");
hist_sig800->Draw("hist same");
hist_sig1000->Draw("hist same");
hist_sig1200->Draw("hist same");
hist_sig1400->Draw("hist same");
hist_sig1600->Draw("hist same");
hist_sig1800->Draw("hist same");

stack->GetHistogram()->GetXaxis()->SetTitle( "H_{T} [GeV]" );

gPad->RedrawAxis();

TH1F *totalH = (TH1F *) histQCD_1->Clone("totalH");
totalH->Add(histQCD_2);
totalH->Add(histQCD_3);
totalH->Add(histQCD_4);
totalH->Add(histQCD_5);
totalH->Add(histQCD_6);
totalH->Add(histQCD_7);
totalH->Add(histQCD_8);
totalH->Add(histQCD_9);
totalH->Add(histTT);
totalH->Add(histWj);
totalH->Add(histZj);

TH1F *hist_totQCD = (TH1F *) histQCD_1->Clone("hist_totQCD");
hist_totQCD->Add(histQCD_2);
hist_totQCD->Add(histQCD_3);
hist_totQCD->Add(histQCD_4);
hist_totQCD->Add(histQCD_5);
hist_totQCD->Add(histQCD_6);
hist_totQCD->Add(histQCD_7);
hist_totQCD->Add(histQCD_8);
hist_totQCD->Add(histQCD_9);


TH1F *ratioH = new TH1F();
ratioH = (TH1F*) histDATA->Clone("ratioH");
ratioH->Sumw2();
ratioH->Divide(ratioH, totalH, 1, 1, "B");



TLegend *leg = new TLegend(0.7,0.39,0.92,0.86,"");
leg->SetNColumns(1);
leg->SetFillColor(0);
leg->SetLineColor(0);
leg->AddEntry(histDATA, Form("%dt, %dW, %dZ, %dH, %db", numTop, numW, numZ, numH, numB), "");
leg->AddEntry(histDATA, "Data", "p");
leg->AddEntry(histQCD_sampled   ,  "Multijet (DD)","f");
//leg->AddEntry(histQCD_1   ,  Form("QCD (x%1.3f)", totDATA/totQCD),"f");
leg->AddEntry(histTT     , "t#bar{t}+jets" ,"f");
leg->AddEntry(histWj    , "W+jets","f");
leg->AddEntry(histZj      , "Z+jets","f");
leg->AddEntry(histHbb      , "H","f");
leg->AddEntry(histTTW, "ttV+4t", "f");
leg->AddEntry(histWW, "VV", "f");
leg->AddEntry(hist_sig800, "TT (0.8 TeV)", "l");
leg->AddEntry(hist_sig1000, "TT (1.0 TeV)", "l");
leg->AddEntry(hist_sig1200, "TT (1.2 TeV)", "l");
leg->AddEntry(hist_sig1400, "TT (1.4 TeV)", "l");
leg->AddEntry(hist_sig1600, "TT (1.6 TeV)", "l");
leg->AddEntry(hist_sig1800, "TT (1.8 TeV)", "l");
//leg->AddEntry(hist_sig4, "4 TeV Z'", "l");


leg->Draw("same");

CMS_lumi(c1_2, 4, 0);



c1_1->cd();
c1_1->SetTopMargin(0.05);
        c1_1->SetBottomMargin(0.3);
        c1_1->SetRightMargin(0.05);
        c1_1->SetLeftMargin(0.1);
        c1_1->SetFillStyle(0);
ratioH->Draw("axis");
ratioH->GetYaxis()->SetRangeUser(0.,2.);
        ratioH->GetYaxis()->SetTitle("Data / BG Ratio");
        ratioH->GetYaxis()->SetTitleOffset(0.4);
        ratioH->GetYaxis()->SetTitleSize(0.11);
        ratioH->GetYaxis()->SetLabelSize(0.11);
        ratioH->GetXaxis()->SetLabelSize(0.11);
        ratioH->GetXaxis()->SetTitleSize(0.11);
ratioH->GetYaxis()->SetNdivisions(4, kFALSE);


TF1 *line = new TF1("line", "1", 0, 10000);
        line->SetLineColor(kBlack);
	line->SetLineWidth(1);
        line->Draw("same");
        
        //gPad->RedrawAxis();

c1_2->cd();

TString channelT = TString::Format("%dt_%dW_%dZ_%dH_%db", numTop, numW, numZ, numH, numB);
string channel = channelT.Data();
cout << channel << endl;

gDirectory->ls("-m");
gDirectory->ls("-d");

c1->SaveAs( TString::Format( "bin_%s.pdf", channel.c_str() ) );

gPad->SetLogy(1);

stack->SetMaximum( 1000 * (1+histDATA->GetMaximum()) );
c1_2->Update();
c1->SaveAs( TString::Format( "bin_%s_log.pdf", channel.c_str() ) );

cout << "HERE " << endl;
TFile *outFile = new TFile(TString::Format("%s_binhistos.root", channel.c_str()), "RECREATE");

channel = "bin";
histDATA->Write(TString::Format("%s__DATA", channel.c_str()));
histDDQCD->Write(TString::Format("%s__qcd", channel.c_str()));
histTT->Write(TString::Format("%s__ttbar", channel.c_str()));
histWj->Write(TString::Format("%s__wjets", channel.c_str()));
histZj->Write(TString::Format("%s__zjets", channel.c_str()));
histWW->Write(TString::Format("%s__diboson", channel.c_str()));
histTTW->Write(TString::Format("%s__ttV", channel.c_str()));
histHbb->Write(TString::Format("%s__higgs", channel.c_str()));
hist_sig800->Write(TString::Format("%s__tprime800", channel.c_str()));
hist_sig1000->Write(TString::Format("%s__tprime1000", channel.c_str()));
hist_sig1200->Write(TString::Format("%s__tprime1200", channel.c_str()));
hist_sig1400->Write(TString::Format("%s__tprime1400", channel.c_str()));
hist_sig1600->Write(TString::Format("%s__tprime1600", channel.c_str()));
hist_sig1800->Write(TString::Format("%s__tprime1800", channel.c_str()));

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

