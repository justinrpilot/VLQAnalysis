#include "CMS_lumi.C"

void drawRate(){



//TFile *infile = new TFile("BEST_rates_3jet_DATA_6bin.root");
TFile *infile = new TFile("rebinned_3jet_rates.root");

TH1F *jet1H = (TH1F *) infile->Get("W_rate");
TH1F *jet2H = (TH1F *) infile->Get("Z_rate");
TH1F *jet3H = (TH1F *) infile->Get("H_rate");
TH1F *jet4H = (TH1F *) infile->Get("b_rate");
TH1F *jet5H = (TH1F *) infile->Get("t_rate");
TH1F *jet6H = (TH1F *) infile->Get("QCD_rate");

jet1H->SetLineColor(kGreen+1);
jet1H->SetLineWidth(3);
jet2H->SetLineColor(kOrange);
jet2H->SetLineWidth(3);
jet3H->SetLineColor(kViolet);
jet3H->SetLineWidth(3);
jet4H->SetLineColor(kCyan);
jet4H->SetLineWidth(3);
jet5H->SetLineColor(kRed);
jet5H->SetLineWidth(3);
jet6H->SetLineColor(kBlack);
jet6H->SetLineWidth(3);

jet1H->SetLineStyle(1);
jet2H->SetLineStyle(2);
jet3H->SetLineStyle(3);
jet4H->SetLineStyle(4);
jet5H->SetLineStyle(5);
jet6H->SetLineStyle(6);

TCanvas *c1 = new TCanvas();
c1->cd();
c1->SetLeftMargin(0.15);
c1->SetBottomMargin(0.15);

jet1H->GetXaxis()->SetTitle(Form("Jet p_{T} [GeV]"));
jet1H->GetYaxis()->SetTitle("Classification Rate");
jet1H->GetXaxis()->SetRangeUser(400, 3000);
jet1H->GetXaxis()->SetLabelSize(0.05);
jet1H->GetYaxis()->SetLabelSize(0.05);
jet1H->GetXaxis()->SetTitleSize(0.06);
jet1H->GetYaxis()->SetTitleSize(0.06);
jet1H->GetXaxis()->SetLabelFont(42);
jet1H->GetYaxis()->SetLabelFont(42);
jet1H->GetXaxis()->SetTitleFont(42);
jet1H->GetYaxis()->SetTitleFont(42);
jet1H->SetMinimum(0.001);jet1H->SetMaximum(10.1);
jet1H->Draw();
jet2H->Draw("same");
jet3H->Draw("same");
jet4H->Draw("same");
jet5H->Draw("same");
jet6H->Draw("same");



TLegend *leg = new TLegend(0.5,0.18,0.88,0.42);
leg->SetLineWidth(0);
leg->SetFillColor(0);
leg->SetNColumns(2);
leg->SetTextFont(42);
//leg->AddEntry(jet1H, "4 JETS", "");
leg->AddEntry(jet1H, "W    ", "l");
leg->AddEntry(jet2H, "Z    ", "l");
leg->AddEntry(jet3H, "H    ", "l");
leg->AddEntry(jet4H, "b    ", "l");
leg->AddEntry(jet5H, "t    ");
leg->AddEntry(jet6H, "Light flavor", "l");
leg->Draw("same");

gPad->SetLogy(1);
CMS_lumi(c1,4,10);

gPad->SaveAs("tagRates_6bin_4jet.pdf");

}
