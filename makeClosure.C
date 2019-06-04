#include "CMS_lumi.C"
#include "TH1F.h"
#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TH2F.h"
#include "TF1.h"
#include <iostream>
using namespace std;


void drawROC( TH1F *histS, TH1F *histB, int color, float noCutTT, float noCutQCD);

void makeStack(string var, string label, string sel, int nbins, float xmin, float xmax, string filename, string channel){


nbins = 14;
float bins[15] = {0, 1500, 1600, 1700, 1800, 1900, 2000, 2200, 2400, 2600, 2800, 3000, 4000, 5000, 10000};

TFile *fileQCD_1 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd1.root", "READ");
TFile *fileQCD_2 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd2.root", "READ");
TFile *fileQCD_3 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd3.root", "READ");
TFile *fileQCD_4 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd4.root", "READ");
TFile *fileQCD_5 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd5.root", "READ");
TFile *fileQCD_6 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd6.root", "READ");
TFile *fileQCD_7 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd7.root", "READ");
TFile *fileQCD_8 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd8.root", "READ");
TFile *fileQCD_9 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd9.root", "READ");

TFile *fileQCDSIM_1 = TFile::Open("shapes_qcd1.root", "READ");
TFile *fileQCDSIM_2 = TFile::Open("shapes_qcd2.root", "READ");
TFile *fileQCDSIM_3 = TFile::Open("shapes_qcd3.root", "READ");
TFile *fileQCDSIM_4 = TFile::Open("shapes_qcd4.root", "READ");
TFile *fileQCDSIM_5 = TFile::Open("shapes_qcd5.root", "READ");
TFile *fileQCDSIM_6 = TFile::Open("shapes_qcd6.root", "READ");
TFile *fileQCDSIM_7 = TFile::Open("shapes_qcd7.root", "READ");
TFile *fileQCDSIM_8 = TFile::Open("shapes_qcd8.root", "READ");
TFile *fileQCDSIM_9 = TFile::Open("shapes_qcd9.root", "READ");



TTree *treeQCD_1 = (TTree *) fileQCD_1->Get("eventVars");
TTree *treeQCD_2 = (TTree *) fileQCD_2->Get("eventVars");
TTree *treeQCD_3 = (TTree *) fileQCD_3->Get("eventVars");
TTree *treeQCD_4 = (TTree *) fileQCD_4->Get("eventVars");
TTree *treeQCD_5 = (TTree *) fileQCD_5->Get("eventVars");
TTree *treeQCD_6 = (TTree *) fileQCD_6->Get("eventVars");
TTree *treeQCD_7 = (TTree *) fileQCD_7->Get("eventVars");
TTree *treeQCD_8 = (TTree *) fileQCD_8->Get("eventVars");
TTree *treeQCD_9 = (TTree *) fileQCD_9->Get("eventVars");



TH1D *histQCD_1 = new TH1D("histQCD_1", "histQCD_1", nbins, bins);
TH1D *histQCD_2 = new TH1D("histQCD_2", "histQCD_2", nbins, bins);
TH1D *histQCD_3 = new TH1D("histQCD_3", "histQCD_3", nbins, bins);
TH1D *histQCD_4 = new TH1D("histQCD_4", "histQCD_4", nbins, bins);
TH1D *histQCD_5 = new TH1D("histQCD_5", "histQCD_5", nbins, bins);
TH1D *histQCD_6 = new TH1D("histQCD_6", "histQCD_6", nbins, bins);
TH1D *histQCD_7 = new TH1D("histQCD_7", "histQCD_7", nbins, bins);
TH1D *histQCD_8 = new TH1D("histQCD_8", "histQCD_8", nbins, bins);
TH1D *histQCD_9 = new TH1D("histQCD_9", "histQCD_9", nbins, bins);

TH1F *histQCDSIM_1 = (TH1F *) fileQCDSIM_1->Get("outHT");
TH1F *histQCDSIM_2 = (TH1F *) fileQCDSIM_2->Get("outHT");
TH1F *histQCDSIM_3 = (TH1F *) fileQCDSIM_3->Get("outHT");
TH1F *histQCDSIM_4 = (TH1F *) fileQCDSIM_4->Get("outHT");
TH1F *histQCDSIM_5 = (TH1F *) fileQCDSIM_5->Get("outHT");
TH1F *histQCDSIM_6 = (TH1F *) fileQCDSIM_6->Get("outHT");
TH1F *histQCDSIM_7 = (TH1F *) fileQCDSIM_7->Get("outHT");
TH1F *histQCDSIM_8 = (TH1F *) fileQCDSIM_8->Get("outHT");
TH1F *histQCDSIM_9 = (TH1F *) fileQCDSIM_9->Get("outHT");
TH1F *histQCDSIMup_1 = (TH1F *) fileQCDSIM_1->Get("outHTup");
TH1F *histQCDSIMup_2 = (TH1F *) fileQCDSIM_2->Get("outHTup");
TH1F *histQCDSIMup_3 = (TH1F *) fileQCDSIM_3->Get("outHTup");
TH1F *histQCDSIMup_4 = (TH1F *) fileQCDSIM_4->Get("outHTup");
TH1F *histQCDSIMup_5 = (TH1F *) fileQCDSIM_5->Get("outHTup");
TH1F *histQCDSIMup_6 = (TH1F *) fileQCDSIM_6->Get("outHTup");
TH1F *histQCDSIMup_7 = (TH1F *) fileQCDSIM_7->Get("outHTup");
TH1F *histQCDSIMup_8 = (TH1F *) fileQCDSIM_8->Get("outHTup");
TH1F *histQCDSIMup_9 = (TH1F *) fileQCDSIM_9->Get("outHTup");
TH1F *histQCDSIMdn_1 = (TH1F *) fileQCDSIM_1->Get("outHTdn");
TH1F *histQCDSIMdn_2 = (TH1F *) fileQCDSIM_2->Get("outHTdn");
TH1F *histQCDSIMdn_3 = (TH1F *) fileQCDSIM_3->Get("outHTdn");
TH1F *histQCDSIMdn_4 = (TH1F *) fileQCDSIM_4->Get("outHTdn");
TH1F *histQCDSIMdn_5 = (TH1F *) fileQCDSIM_5->Get("outHTdn");
TH1F *histQCDSIMdn_6 = (TH1F *) fileQCDSIM_6->Get("outHTdn");
TH1F *histQCDSIMdn_7 = (TH1F *) fileQCDSIM_7->Get("outHTdn");
TH1F *histQCDSIMdn_8 = (TH1F *) fileQCDSIM_8->Get("outHTdn");
TH1F *histQCDSIMdn_9 = (TH1F *) fileQCDSIM_9->Get("outHTdn");

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

treeQCD_1->Draw( Form( "%s >> histQCD_1", var.c_str() ), sel.c_str() );
treeQCD_2->Draw( Form( "%s >> histQCD_2", var.c_str() ), sel.c_str() );
treeQCD_3->Draw( Form( "%s >> histQCD_3", var.c_str() ), sel.c_str() );
treeQCD_4->Draw( Form( "%s >> histQCD_4", var.c_str() ), sel.c_str() );
treeQCD_5->Draw( Form( "%s >> histQCD_5", var.c_str() ), sel.c_str() );
treeQCD_6->Draw( Form( "%s >> histQCD_6", var.c_str() ), sel.c_str() );
treeQCD_7->Draw( Form( "%s >> histQCD_7", var.c_str() ), sel.c_str() );
treeQCD_8->Draw( Form( "%s >> histQCD_8", var.c_str() ), sel.c_str() );
treeQCD_9->Draw( Form( "%s >> histQCD_9", var.c_str() ), sel.c_str() );


float lumi = 35289.97;//8529.407;
float sf = 1.0;

histQCD_1->Scale( 7823.0 * lumi / 5970600.);
histQCD_2->Scale(  648.2 * lumi / 3928870.);
histQCD_3->Scale(  186.9 * lumi / 3959768.);
histQCD_4->Scale(  32.29 * lumi / 3924080.);
histQCD_5->Scale(  9.418 * lumi / 2999069.);
histQCD_6->Scale(  0.84265 * lumi / 396409.);
histQCD_7->Scale(  0.114943 * lumi / 396100.);
histQCD_8->Scale(  0.0068291 * lumi / 399226.);
histQCD_9->Scale(  0.0001654 * lumi / 383926.);
histQCDSIM_1->Scale( 7823.0 * lumi*sf / 5970600.);
histQCDSIM_2->Scale(  648.2 * lumi*sf / 3928870.);
histQCDSIM_3->Scale(  186.9 * lumi*sf / 3959768.);
histQCDSIM_4->Scale(  32.29 * lumi*sf / 3924080.);
histQCDSIM_5->Scale(  9.418 * lumi*sf / 2999069.);
histQCDSIM_6->Scale(  0.84265 * lumi*sf / 396409.);
histQCDSIM_7->Scale(  0.114943 * lumi*sf / 396100.);
histQCDSIM_8->Scale(  0.0068291 * lumi*sf / 399226.);
histQCDSIM_9->Scale(  0.0001654 * lumi*sf / 383926.);
histQCDSIMup_1->Scale( 7823.0 * lumi*sf / 5970600.);
histQCDSIMup_2->Scale(  648.2 * lumi*sf / 3928870.);
histQCDSIMup_3->Scale(  186.9 * lumi*sf / 3959768.);
histQCDSIMup_4->Scale(  32.29 * lumi*sf / 3924080.);
histQCDSIMup_5->Scale(  9.418 * lumi*sf / 2999069.);
histQCDSIMup_6->Scale(  0.84265 * lumi*sf / 396409.);
histQCDSIMup_7->Scale(  0.114943 * lumi*sf / 396100.);
histQCDSIMup_8->Scale(  0.0068291 * lumi*sf / 399226.);
histQCDSIMup_9->Scale(  0.0001654 * lumi*sf / 383926.);
histQCDSIMdn_1->Scale( 7823.0 * lumi*sf / 5970600.);
histQCDSIMdn_2->Scale(  648.2 * lumi*sf / 3928870.);
histQCDSIMdn_3->Scale(  186.9 * lumi*sf / 3959768.);
histQCDSIMdn_4->Scale(  32.29 * lumi*sf / 3924080.);
histQCDSIMdn_5->Scale(  9.418 * lumi*sf / 2999069.);
histQCDSIMdn_6->Scale(  0.84265 * lumi*sf / 396409.);
histQCDSIMdn_7->Scale(  0.114943 * lumi*sf / 396100.);
histQCDSIMdn_8->Scale(  0.0068291 * lumi*sf / 399226.);
histQCDSIMdn_9->Scale(  0.0001654 * lumi*sf / 383926.);

histQCDSIM_1->SetFillColor(kCyan + 1);
histQCDSIM_2->SetFillColor(kCyan + 1);
histQCDSIM_3->SetFillColor(kCyan + 1);
histQCDSIM_4->SetFillColor(kCyan + 1);
histQCDSIM_5->SetFillColor(kCyan + 1);
histQCDSIM_6->SetFillColor(kCyan + 1);
histQCDSIM_7->SetFillColor(kCyan + 1);
histQCDSIM_8->SetFillColor(kCyan + 1);
histQCDSIM_9->SetFillColor(kCyan + 1);
histQCDSIM_1->SetLineColor(kCyan + 1);
histQCDSIM_2->SetLineColor(kCyan + 1);
histQCDSIM_3->SetLineColor(kCyan + 1);
histQCDSIM_4->SetLineColor(kCyan + 1);
histQCDSIM_5->SetLineColor(kCyan + 1);
histQCDSIM_6->SetLineColor(kCyan + 1);
histQCDSIM_7->SetLineColor(kCyan + 1);
histQCDSIM_8->SetLineColor(kCyan + 1);
histQCDSIM_9->SetLineColor(kCyan + 1);

TH1F *histQCDTot =(TH1F *) histQCD_1->Clone("histQCDTot");
histQCDTot->Add(histQCD_2);
histQCDTot->Add(histQCD_3);
histQCDTot->Add(histQCD_4);
histQCDTot->Add(histQCD_5);
histQCDTot->Add(histQCD_6);
histQCDTot->Add(histQCD_7);
histQCDTot->Add(histQCD_8);
histQCDTot->Add(histQCD_9);

TH1F *histQCDupTot =(TH1F *) histQCDSIMup_1->Clone("histQCDupTot");
histQCDupTot->Add(histQCDSIMup_2);
histQCDupTot->Add(histQCDSIMup_3);
histQCDupTot->Add(histQCDSIMup_4);
histQCDupTot->Add(histQCDSIMup_5);
histQCDupTot->Add(histQCDSIMup_6);
histQCDupTot->Add(histQCDSIMup_7);
histQCDupTot->Add(histQCDSIMup_8);
histQCDupTot->Add(histQCDSIMup_9);
TH1F *histQCDdnTot =(TH1F *) histQCDSIMdn_1->Clone("histQCDdnTot");
histQCDdnTot->Add(histQCDSIMdn_2);
histQCDdnTot->Add(histQCDSIMdn_3);
histQCDdnTot->Add(histQCDSIMdn_4);
histQCDdnTot->Add(histQCDSIMdn_5);
histQCDdnTot->Add(histQCDSIMdn_6);
histQCDdnTot->Add(histQCDSIMdn_7);
histQCDdnTot->Add(histQCDSIMdn_8);
histQCDdnTot->Add(histQCDSIMdn_9);


THStack *stack = new THStack("stack", "stack");

stack->Add(histQCDSIM_1);
stack->Add(histQCDSIM_2);
stack->Add(histQCDSIM_3);
stack->Add(histQCDSIM_4);
stack->Add(histQCDSIM_5);
stack->Add(histQCDSIM_6);
stack->Add(histQCDSIM_7);
stack->Add(histQCDSIM_8);
stack->Add(histQCDSIM_9);
histQCDTot->Draw("axis");

histQCDTot->SetMaximum( 1.5 * (1+histQCDTot->GetMaximum()) );
histQCDTot->SetMinimum( 0.000001 );
histQCDTot->GetXaxis()->SetTitle( label.c_str() );
histQCDTot->Draw("axis");
stack->Draw("hist same");
histQCDTot->Draw("E same");




TH1F *totalH = (TH1F *) histQCDSIM_1->Clone("totalH");
totalH->Add(histQCDSIM_2);
totalH->Add(histQCDSIM_3);
totalH->Add(histQCDSIM_4);
totalH->Add(histQCDSIM_5);
totalH->Add(histQCDSIM_6);
totalH->Add(histQCDSIM_7);
totalH->Add(histQCDSIM_8);
totalH->Add(histQCDSIM_9);

for (int i = 0; i < totalH->GetNbinsX(); i++){
	totalH->SetBinError(i, (histQCDupTot->GetBinContent(i) - histQCDdnTot->GetBinContent(i)) / 2.0);
}

totalH->SetFillColor(16);
totalH->SetFillStyle(3244);
totalH->Draw("E2 same");



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
ratioH = (TH1F*) histQCDTot->Clone("ratioH");
ratioH->Sumw2();
ratioH->Divide(ratioH, totalH, 1, 1, "B");


TH1F *ratioMCH = new TH1F();
ratioMCH = (TH1F*) totalH->Clone("ratioMCH");
ratioMCH->Divide(ratioMCH, totalH, 1, 1);

TLegend *leg = new TLegend(0.6,0.7,0.92,0.86,"");
leg->SetNColumns(1);
leg->SetFillColor(0);
leg->SetLineColor(0);
leg->AddEntry(histQCDTot, "QCD Actual", "pl");
leg->AddEntry(histQCDSIM_1   ,  "QCD Estimated","f");
leg->AddEntry(histQCDTot, channel.c_str(), "");

leg->Draw("same");

CMS_lumi(c1_2, 4, 0);



c1_1->cd();
c1_1->SetTopMargin(0.05);
        c1_1->SetBottomMargin(0.3);
        c1_1->SetRightMargin(0.05);
        c1_1->SetLeftMargin(0.1);
        c1_1->SetFillStyle(0);
ratioH->Draw();
ratioH->GetYaxis()->SetRangeUser(0.,2.);
        ratioH->GetYaxis()->SetTitle("Actual / Estimated");
        ratioH->GetYaxis()->SetTitleOffset(0.4);
        ratioH->GetYaxis()->SetTitleSize(0.11);
        ratioH->GetYaxis()->SetLabelSize(0.11);
        ratioH->GetXaxis()->SetLabelSize(0.11);
        ratioH->GetXaxis()->SetTitleSize(0.11);
ratioH->GetYaxis()->SetNdivisions(4, kFALSE);
ratioMCH->SetFillColor(16);
ratioMCH->SetFillStyle(1001);
ratioMCH->Draw("E2 same");
ratioH->Draw("E same");

TF1 *line = new TF1("line", "1", 0, 10000);
        line->SetLineColor(kBlack);
	line->SetLineWidth(1);
        line->Draw("same");
        
        gPad->RedrawAxis();

c1_2->cd();


c1->SaveAs( Form( "%s.pdf", filename.c_str() ) );

gPad->SetLogy(1);

histQCDTot->SetMaximum( 10000 * histQCDTot->GetMaximum() );
c1_2->Update();
c1->SaveAs( Form( "%s_log.pdf", filename.c_str() ) );

//TCanvas *c2 = new TCanvas("c2", "c2");
//c2->cd();
//drawROC(hist_sig4, hist_totQCD, 1, totNumTT, totNumQCD);


fileQCD_1->Close();
fileQCD_2->Close();
fileQCD_3->Close();
fileQCD_4->Close();
fileQCD_5->Close();
fileQCD_6->Close();
fileQCD_7->Close();
fileQCD_8->Close();
fileQCD_9->Close();
return;

}


void drawROC( TH1F *histS, TH1F *histB, int color, float noCutTT, float noCutQCD){


TGraph *rocG = new TGraph();

float sEntries = 0.0;
float bEntries = 0.0;

int n =0;

cout << "tt: " << histS->GetEntries() << "  " << noCutTT << endl;
cout << "qcd: " << histB->GetEntries() << " " << noCutQCD << endl;


for (int i = 0; i < histS->GetNbinsX(); i++){

	
	sEntries = (float(histS->GetEntries()) / noCutTT) * histS->Integral(0, i) / histS->Integral();
	bEntries = (float(histB->GetEntries()) / noCutQCD) * histB->Integral(0, i) / histB->Integral();

	cout << sEntries << "   " << bEntries << endl;

	rocG->SetPoint(++n, sEntries, bEntries);

}


TH2F *axisH = new TH2F("axisH", "axisH", 10000, 0, 1, 10000, 0, 1);
axisH->GetXaxis()->SetTitle( Form("%s Efficiency", histS->GetName() ) );
axisH->GetYaxis()->SetTitle( Form("%s Efficiency", histB->GetName() ) );
axisH->Draw("axis");

rocG->Draw("same");
rocG->SetLineWidth(2);
rocG->SetLineColor(color);
gPad->SetLogy(1);

return;

}


