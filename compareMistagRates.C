void drawRate(string pID, int jetIndex){

TFile *infile_DATA = new TFile("BEST_rates_DATA_6bin.root");
TFile *infile_QCD = new TFile("BEST_rates_6bin.root");
TFile *infile_ttbar = new TFile("rates_ttbar.root");
TFile *infile_Wjets = new TFile("rates_wjets.root");
TFile *infile_Zjets = new TFile("rates_zjets.root");

TH1F *dataH = (TH1F *) infile_DATA->Get(Form("%s_j%d_rate", pID.c_str(), jetIndex));
TH1F *qcdH = (TH1F *) infile_QCD->Get(Form("%s_j%d_rate", pID.c_str(), jetIndex));
TH1F *ttbarH = (TH1F *) infile_ttbar->Get(Form("%s_j%d_rate", pID.c_str(), jetIndex));
TH1F *wjetsH = (TH1F *) infile_Wjets->Get(Form("%s_j%d_rate", pID.c_str(), jetIndex));
TH1F *zjetsH = (TH1F *) infile_Zjets->Get(Form("%s_j%d_rate", pID.c_str(), jetIndex));

dataH->SetLineColor(kBlack);
dataH->SetLineWidth(2);
qcdH->SetLineColor(kYellow+3);
qcdH->SetLineWidth(2);
ttbarH->SetLineColor(kRed);
ttbarH->SetLineWidth(2);
wjetsH->SetLineColor(kGreen+1);
wjetsH->SetLineWidth(2);
zjetsH->SetLineColor(kBlue);
zjetsH->SetLineWidth(2);

dataH->GetXaxis()->SetTitle(Form("Jet %d p_{T} [GeV]", jetIndex));
dataH->GetYaxis()->SetTitle(Form("%s Tagging Rate", pID.c_str()));
dataH->SetMinimum(0.001);dataH->SetMaximum(1.1);
dataH->Draw();
qcdH->Draw("same");
ttbarH->Draw("same");
wjetsH->Draw("same");
zjetsH->Draw("same");

TLegend *leg = new TLegend(0.67,0.18,0.88,0.42);
leg->SetLineWidth(0);
leg->SetFillColor(0);
leg->AddEntry(dataH, "Data", "l");
leg->AddEntry(qcdH, "QCD MC", "l");
leg->AddEntry(ttbarH, "t#bar t", "l");
leg->AddEntry(wjetsH, "W+jets", "l");
leg->AddEntry(zjetsH, "Z+jets", "l");
leg->Draw("same");

gPad->SetLogy(1);

gPad->SaveAs(Form("%s_jet%d_MCratecomp.pdf", pID.c_str(), jetIndex));

}
