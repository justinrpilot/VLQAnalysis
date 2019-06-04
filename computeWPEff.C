#include "CMS_lumi.C"


void computeWPEff(string cutN, string cutD, string sigFile, int color, string label, string cutDesc, string filename) {

TFile *sigF = new TFile(sigFile.c_str());
TFile *bkgF = TFile::Open("outplots.root");

TTree *sigTree = (TTree *) sigF->Get("jetVars");
TTree *bkgTree = (TTree *) bkgF->Get("jetVars");

//string cut = "best_class == 1";


TH1F *sigNumH = new TH1F("sigNumH", "sigNumH", 50, 100, 2000);
TH1F *bkgNumH = new TH1F("bkgNumH", "bkgNumH", 50, 100, 2000);
TH1F *sigDenH = new TH1F("sigDenH", "sigDenH", 50, 100, 2000);
TH1F *bkgDenH = new TH1F("bkgDenH", "bkgDenH", 50, 100, 2000);
sigNumH->Sumw2();
sigDenH->Sumw2();
bkgNumH->Sumw2();
bkgDenH->Sumw2();


sigTree->Draw("genPt>>sigDenH", cutD.c_str()) ;
bkgTree->Draw("genPt>>bkgDenH", cutD.c_str());
sigTree->Draw("genPt>>sigNumH", cutN.c_str());
bkgTree->Draw("genPt>>bkgNumH", cutN.c_str());

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
//gPad->SetLogy(1);

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

