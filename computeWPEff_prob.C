#include "CMS_lumi.C"


void computeWPEff(string cutN, string cutD, string sigFile, int color, string label, string cutDesc, string filename) {

TFile *sigF = new TFile(sigFile.c_str());
//TFile *bkgF = TFile::Open("JMAR/outplots_JMAR_QCD.root");

TTree *sigTree = (TTree *) sigF->Get("jetVars");
TChain *bkgTree = new TChain("jetVars");
bkgTree->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd1.root");
bkgTree->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd2.root");
bkgTree->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd3.root");
bkgTree->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd4.root");
bkgTree->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd5.root");
bkgTree->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd6.root");
//bkgTree->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd7.root");
//bkgTree->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd8.root");
//bkgTree->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd9.root");

//string cut = "best_class == 1";


TH1F *sigNumH = new TH1F("sigNumH", "sigNumH", 50, 400, 2500);
TH1F *bkgNumH = new TH1F("bkgNumH", "bkgNumH", 50, 400, 2500);
TH1F *sigDenH = new TH1F("sigDenH", "sigDenH", 50, 400, 2500);
TH1F *bkgDenH = new TH1F("bkgDenH", "bkgDenH", 50, 400, 2500);
sigNumH->Sumw2();
sigDenH->Sumw2();
bkgNumH->Sumw2();
bkgDenH->Sumw2();


sigTree->Draw("jetPt>>sigDenH", cutD.c_str()) ;
bkgTree->Draw("jetPt>>bkgDenH", cutD.c_str());
sigTree->Draw("jetPt>>sigNumH", cutN.c_str());
bkgTree->Draw("jetPt>>bkgNumH", cutN.c_str());

float integralEffS = sigNumH->Integral() / sigDenH->Integral();
float integralEffB = bkgNumH->Integral() / bkgDenH->Integral();
cout << "Integrated Signal Eff = " << integralEffS << endl;
cout << "Integrated Bkgrnd Eff = " << integralEffB << endl;

sigNumH->Divide(sigNumH, sigDenH, 1, 1);
bkgNumH->Divide(bkgNumH, bkgDenH, 1, 1);

TCanvas *c1 = new TCanvas();
sigNumH->GetXaxis()->SetTitle("Generator Particle p_{T} [GeV]");
sigNumH->GetYaxis()->SetTitle("Efficiency");
sigNumH->SetLineWidth(2); sigNumH->SetLineColor(color);
bkgNumH->SetLineWidth(2); bkgNumH->SetLineColor(kBlack);

sigNumH->SetMinimum(0.001);
sigNumH->SetMaximum(20);
sigNumH->Draw("E");
bkgNumH->Draw("E same");

gPad->SetBottomMargin(0.13);
gPad->SetLeftMargin(0.13);
gPad->SetLogy(1);

TLegend *leg = new TLegend(0.15, 0.68, 0.43,0.88);
leg->AddEntry(sigNumH, label.c_str(), "l");
leg->AddEntry(bkgNumH, "QCD", "l");
leg->AddEntry(bkgNumH, cutDesc.c_str(), "");
leg->SetFillColor(0);
leg->SetLineWidth(0);
leg->Draw("same");

CMS_lumi(c1, 4, 0);

c1->SaveAs(Form("%s.pdf", filename.c_str()));

}

