{

TFile *sigF = new TFile("outplots_WW_3TeV.root");
TFile *bkgF = new TFile("outplots_qcd5.root");

TTree *sigTree = (TTree *) sigF->Get("jetVars");
TTree *bkgTree = (TTree *) bkgF->Get("jetVars");

string cut = "best_class == 1";


TH1F *sigNumH = new TH1F("sigNumH", "sigNumH", 25, -3, 3);
TH1F *bkgNumH = new TH1F("bkgNumH", "bkgNumH", 25, -3, 3);
TH1F *sigDenH = new TH1F("sigDenH", "sigDenH", 25, -3, 3);
TH1F *bkgDenH = new TH1F("bkgDenH", "bkgDenH", 25, -3, 3);
sigNumH->Sumw2();
sigDenH->Sumw2();
bkgNumH->Sumw2();
bkgDenH->Sumw2();


sigTree->Draw("jetEta>>sigDenH") ;
bkgTree->Draw("jetEta>>bkgDenH");
sigTree->Draw("jetEta>>sigNumH", cut.c_str());
bkgTree->Draw("jetEta>>bkgNumH", cut.c_str());

sigNumH->Divide(sigNumH, sigDenH, 1, 1);
bkgNumH->Divide(bkgNumH, bkgDenH, 1, 1);

TCanvas *c1 = new TCanvas();
sigNumH->GetXaxis()->SetTitle("Jet #eta");
sigNumH->GetYaxis()->SetTitle("Efficiency");
sigNumH->SetLineWidth(2); sigNumH->SetLineColor(kGreen + 1);
bkgNumH->SetLineWidth(2); bkgNumH->SetLineColor(kBlack);


sigNumH->Draw("E");
bkgNumH->Draw("E same");

gPad->SetBottomMargin(0.13);
gPad->SetLeftMargin(0.13);
gPad->SetLogy(1);

TLegend *leg = new TLegend(0.15, 0.68, 0.43,0.88);
leg->AddEntry(sigNumH, "Z' #rightarrow WW (3 TeV)", "l");
leg->AddEntry(bkgNumH, "QCD", "l");
leg->SetFillColor(0);
leg->SetLineWidth(0);
leg->Draw("same");




}

