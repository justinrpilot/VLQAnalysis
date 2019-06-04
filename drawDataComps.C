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

void drawDataComps(string var, string label, string sel, int nbins, float min, float max, string blah1, string blah2){


gROOT->SetStyle("Empty");
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);

TChain *treeDATA2016 = new TChain("jetVars");
treeDATA2016->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataB.root");
treeDATA2016->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataC.root");
treeDATA2016->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataD.root");
treeDATA2016->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataE.root");
treeDATA2016->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataF.root");
treeDATA2016->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataG.root");
treeDATA2016->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataH.root");
treeDATA2016->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_DATA_H2.root");


TFile *fileDATA2017 = TFile::Open("~/3DayLifetime/outplots_data2017F.root");
TFile *fileDATA2018 = TFile::Open("~/3DayLifetime/outplots_data2018D.root");
TTree *treeDATA2017 = (TTree *) fileDATA2017->Get("jetVars");
TTree *treeDATA2018 = (TTree *) fileDATA2018->Get("jetVars");


TH1D *histDATA2016 = new TH1D("histDATA2016", "histDATA2016", nbins, min, max);
TH1D *histDATA2017 = new TH1D("histDATA2017", "histDATA2017", nbins, min, max);
TH1D *histDATA2018 = new TH1D("histDATA2018", "histDATA2018", nbins, min, max);


treeDATA2016->Draw( Form( "%s >> histDATA2016", var.c_str() ), sel.c_str() );
treeDATA2017->Draw( Form( "%s >> histDATA2017", var.c_str() ), sel.c_str() );
treeDATA2018->Draw( Form( "%s >> histDATA2018", var.c_str() ), sel.c_str() );

float norm = histDATA2016->Integral();
histDATA2017->Scale( histDATA2016->Integral() / histDATA2017->Integral() );
histDATA2018->Scale( histDATA2016->Integral() / histDATA2018->Integral() );

histDATA2016->GetXaxis()->SetTitle(label.c_str());

histDATA2016->SetLineColor(kBlack);
histDATA2017->SetLineColor(kBlue);
histDATA2018->SetLineColor(kRed);
histDATA2016->SetMarkerColor(kBlack);
histDATA2017->SetMarkerColor(kBlue);
histDATA2018->SetMarkerColor(kRed);
TH1F *ratio17H = new TH1F();
ratio17H = (TH1F*) histDATA2017->Clone("ratio17H");
ratio17H->Sumw2();
ratio17H->Divide(ratio17H, histDATA2016, 1, 1, "B");
TH1F *ratio18H = new TH1F();
ratio18H = (TH1F*) histDATA2018->Clone("ratio18H");
ratio18H->Sumw2();
ratio18H->Divide(ratio18H, histDATA2016, 1, 1, "B");




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



c1_2->cd();
histDATA2016->SetMinimum(0.01);
histDATA2016->SetMaximum(20*histDATA2016->GetMaximum());

histDATA2016->Draw("axis");
histDATA2016->Draw("E");
histDATA2017->Draw("E same");
histDATA2018->Draw("E same");


gPad->RedrawAxis();

TLegend *leg = new TLegend(0.11,0.91,0.89,0.99,"");
leg->SetNColumns(4);
leg->SetFillColor(0);
leg->SetLineColor(0);
leg->AddEntry(histDATA2016, "== 4 Jets", "");
leg->AddEntry(histDATA2016, "2016 Data (35.9 /fb)", "pl");
leg->AddEntry(histDATA2017, "2017 Data (13.5 /fb)", "pl");
leg->AddEntry(histDATA2018, "2018 Data (31.95 /fb)", "pl");


leg->Draw("same");

c1_1->cd();
c1_1->SetTopMargin(0.05);
        c1_1->SetBottomMargin(0.3);
        c1_1->SetRightMargin(0.05);
        c1_1->SetLeftMargin(0.1);
        c1_1->SetFillStyle(0);
ratio17H->Draw("axis");
ratio17H->GetYaxis()->SetRangeUser(0.,2.);
        ratio17H->GetYaxis()->SetTitle("Ratio to 2016");
        ratio17H->GetYaxis()->SetTitleOffset(0.4);
        ratio17H->GetYaxis()->SetTitleSize(0.11);
        ratio17H->GetYaxis()->SetLabelSize(0.11);
        ratio17H->GetXaxis()->SetLabelSize(0.11);
        ratio17H->GetXaxis()->SetTitleSize(0.11);
ratio17H->Draw("E same");
ratio18H->Draw("E same");
TF1 *line = new TF1("line", "1", 0, 10000);
        line->SetLineColor(kBlack);
	line->SetLineWidth(1);
        line->Draw("same");
        
gPad->RedrawAxis();

c1->SaveAs(Form("%s_dataComp.pdf", blah1.c_str()));

c1_2->cd();
gPad->SetLogy(1);
c1->SaveAs(Form("%s_dataComp_log.pdf", blah1.c_str()));


}

