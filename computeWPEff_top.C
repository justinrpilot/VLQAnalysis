{

TFile *sigF = new TFile("outplots_TT_3TeV.root");
TFile *bkgF = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd5_matched.root");

TTree *sigTree = (TTree *) sigF->Get("jetVars");
TTree *bkgTree = (TTree *) bkgF->Get("jetVars");

string cut = "best_class == 4";


TH1F *sigNumH = new TH1F("sigNumH", "sigNumH", 20, 1000, 1400);
TH1F *bkgNumH = new TH1F("bkgNumH", "bkgNumH", 20, 1000, 1400);
TH1F *sigDenH = new TH1F("sigDenH", "sigDenH", 20, 1000, 1400);
TH1F *bkgDenH = new TH1F("bkgDenH", "bkgDenH", 20, 1000, 1400);
sigNumH->Sumw2();
sigDenH->Sumw2();
bkgNumH->Sumw2();
bkgDenH->Sumw2();


sigTree->Draw("genPt>>sigDenH") ;
bkgTree->Draw("genPt>>bkgDenH");
sigTree->Draw("genPt>>sigNumH", cut.c_str());
bkgTree->Draw("genPt>>bkgNumH", cut.c_str());

sigNumH->Divide(sigNumH, sigDenH, 1, 1);
bkgNumH->Divide(bkgNumH, bkgDenH, 1, 1);

TCanvas *c1 = new TCanvas();
sigNumH->GetXaxis()->SetTitle("Jet p_{T} [GeV]");
sigNumH->GetYaxis()->SetTitle("Efficiency");
sigNumH->SetLineWidth(2); sigNumH->SetLineColor(kBlue);
bkgNumH->SetLineWidth(2); bkgNumH->SetLineColor(kBlack);


sigNumH->Draw("E");
bkgNumH->Draw("E same");




gPad->SetBottomMargin(0.13);
gPad->SetLeftMargin(0.13);
gPad->SetLogy(1);

TLegend *leg = new TLegend(0.15, 0.68, 0.43,0.88);
leg->AddEntry(sigNumH, "Z' #rightarrow tt (3 TeV)", "l");
leg->AddEntry(bkgNumH, "QCD", "l");
leg->AddEntry(bkgNumH, "BEST t Category", "");
leg->SetFillColor(0);
leg->SetLineWidth(0);
leg->Draw("same");




}

