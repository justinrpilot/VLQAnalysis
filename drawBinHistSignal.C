#include "CMS_lumi.C"

void drawBinHist(){

TFile *infile = new TFile("TT_bins.root", "READ");

TH1F *hSig1 = (TH1F *) infile->Get("bin__tprime800");
TH1F *hSig2 = (TH1F *) infile->Get("bin__tprime1000");
TH1F *hSig3 = (TH1F *) infile->Get("bin__tprime1200");
TH1F *hSig4 = (TH1F *) infile->Get("bin__tprime1400");
TH1F *hSig5 = (TH1F *) infile->Get("bin__tprime1600");
TH1F *hSig6 = (TH1F *) infile->Get("bin__tprime1800");

gStyle->SetPalette(kLightTemperature);

hSig1->SetLineColor(TColor::GetColorPalette(0));
hSig2->SetLineColor(TColor::GetColorPalette(255/5));
hSig3->SetLineColor(TColor::GetColorPalette(255*2/5));
hSig4->SetLineColor(TColor::GetColorPalette(255*3/5));
hSig5->SetLineColor(TColor::GetColorPalette(255*4/5));
hSig6->SetLineColor(TColor::GetColorPalette(254));

hSig1->Scale( 1. / hSig1->Integral() );
hSig2->Scale( 1. / hSig2->Integral() );
hSig3->Scale( 1. / hSig3->Integral() );
hSig4->Scale( 1. / hSig4->Integral() );
hSig5->Scale( 1. / hSig5->Integral() );
hSig6->Scale( 1. / hSig6->Integral() );

TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 800, 500);
c1->SetTopMargin(0.15);
c1->Divide(1,2);
c1->cd(1);
hSig1->Draw("hist same");
hSig1->SetMinimum(0.0001);
hSig1->SetMaximum(5.);
hSig1->GetXaxis()->SetTitle("Event Bin");
hSig1->GetYaxis()->SetTitle("Fraction of Events");
hSig1->GetYaxis()->SetTitleSize(0.10);
hSig1->GetYaxis()->SetTitleOffset(0.30);
hSig2->Draw("hist same");
hSig3->Draw("hist same");
hSig4->Draw("hist same");
hSig5->Draw("hist same");
hSig6->Draw("hist same");


hSig1->GetXaxis()->SetBinLabel(1, "0t 0W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(2, "0t 0W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(3, "0t 0W 0Z 2H");
hSig1->GetXaxis()->SetBinLabel(4, "0t 0W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(5, "0t 0W 1Z 1H");
hSig1->GetXaxis()->SetBinLabel(6, "0t 0W 1Z 2H");
hSig1->GetXaxis()->SetBinLabel(7, "0t 0W 2Z 0H");
hSig1->GetXaxis()->SetBinLabel(8, "0t 0W 2Z 1H");
hSig1->GetXaxis()->SetBinLabel(9, "0t 0W 2Z 2H");
hSig1->GetXaxis()->SetBinLabel(10, "0t 1W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(11, "0t 1W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(12, "0t 1W 0Z 2H");
hSig1->GetXaxis()->SetBinLabel(13, "0t 1W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(14, "0t 1W 1Z 1H");
hSig1->GetXaxis()->SetBinLabel(15, "0t 1W 1Z 2H");
hSig1->GetXaxis()->SetBinLabel(16, "0t 1W 2Z 0H");
hSig1->GetXaxis()->SetBinLabel(17, "0t 1W 2Z 1H");
hSig1->GetXaxis()->SetBinLabel(18, "0t 2W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(19, "0t 2W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(20, "0t 2W 0Z 2H");
hSig1->GetXaxis()->SetBinLabel(21, "0t 2W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(22, "0t 2W 1Z 1H");
hSig1->GetXaxis()->SetBinLabel(23, "0t 2W 2Z 0H");
hSig1->GetXaxis()->SetBinLabel(24, "1t 0W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(25, "1t 0W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(26, "1t 0W 0Z 2H");
hSig1->GetXaxis()->SetBinLabel(27, "1t 0W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(28, "1t 0W 1Z 1H");
hSig1->GetXaxis()->SetBinLabel(29, "1t 0W 1Z 2H");
hSig1->GetXaxis()->SetBinLabel(30, "1t 0W 2Z 0H");
hSig1->GetXaxis()->SetBinLabel(31, "1t 0W 2Z 1H");
hSig1->GetXaxis()->SetBinLabel(32, "1t 1W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(33, "1t 1W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(34, "1t 1W 0Z 2H");
hSig1->GetXaxis()->SetBinLabel(35, "1t 1W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(36, "1t 1W 1Z 1H");
hSig1->GetXaxis()->SetBinLabel(37, "1t 1W 2Z 0H");
hSig1->GetXaxis()->SetBinLabel(38, "1t 2W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(39, "1t 2W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(40, "1t 2W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(41, "2t 0W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(42, "2t 0W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(43, "2t 0W 0Z 2H");
hSig1->GetXaxis()->SetBinLabel(44, "2t 0W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(45, "2t 0W 1Z 1H");
hSig1->GetXaxis()->SetBinLabel(46, "2t 0W 2Z 0H");
hSig1->GetXaxis()->SetBinLabel(47, "2t 1W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(48, "2t 1W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(49, "2t 1W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(50, "2t 2W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(51, "3t 0W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(52, "3t 1W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(53, "3t 0W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(54, "3t 0W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(55, "0t 3W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(56, "1t 3W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(57, "0t 3W 1Z 0H");
hSig1->GetXaxis()->SetBinLabel(58, "0t 3W 0Z 1H");
hSig1->GetXaxis()->SetBinLabel(59, "0t 0W 3Z 0H");
hSig1->GetXaxis()->SetBinLabel(60, "1t 0W 3Z 0H");
hSig1->GetXaxis()->SetBinLabel(61, "0t 1W 3Z 0H");
hSig1->GetXaxis()->SetBinLabel(62, "0t 0W 3Z 1H");
hSig1->GetXaxis()->SetBinLabel(63, "0t 0W 0Z 3H");
hSig1->GetXaxis()->SetBinLabel(64, "1t 0W 0Z 3H");
hSig1->GetXaxis()->SetBinLabel(65, "0t 1W 0Z 3H");
hSig1->GetXaxis()->SetBinLabel(66, "0t 0W 1Z 3H");
hSig1->GetXaxis()->SetBinLabel(69, "4t 0W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(70, "0t 4W 0Z 0H");
hSig1->GetXaxis()->SetBinLabel(71, "0t 0W 4Z 0H");
hSig1->GetXaxis()->SetBinLabel(72, "0t 0W 0Z 4H");

hSig1->GetXaxis()->SetLabelSize(0.03);
hSig1->GetXaxis()->SetTitleOffset(2.25);


TLegend *leg = new TLegend(0.63,0.60,0.85,0.88,"");
leg->SetNColumns(2);
leg->SetFillColor(0);
leg->SetLineColor(0);
//leg->AddEntry(histDATA, "Data", "p");
//leg->AddEntry(hQCD  ,  "Multijet (DD)","f");
//leg->AddEntry(hTop     , "t#bar{t}+jets" ,"f");
//leg->AddEntry(hWjets    , "W+jets","f");
//leg->AddEntry(hZjets      , "Z+jets","f");
leg->AddEntry(hSig1 , "TT (0.8 TeV)", "l");
leg->AddEntry(hSig2 , "TT (1.0 TeV)", "l");
leg->AddEntry(hSig3 , "TT (1.2 TeV)", "l");
leg->AddEntry(hSig4 , "TT (1.4 TeV)", "l");
leg->AddEntry(hSig5 , "TT (1.6 TeV)", "l");
leg->AddEntry(hSig6 , "TT (1.8 TeV)", "l");
leg->Draw("same");
gPad->SetLogy(1);
//CMS_lumi(c1,4,0);

c1->cd(2);

TH1F *hSig1ratio = (TH1F *) hSig1->Clone("hSig1ratio");
hSig1ratio->Divide(hSig1);
TH1F *hSig2ratio = (TH1F *) hSig2->Clone("hSig2ratio");
hSig2ratio->Divide(hSig1);
TH1F *hSig3ratio = (TH1F *) hSig3->Clone("hSig3ratio");
hSig3ratio->Divide(hSig1);
TH1F *hSig4ratio = (TH1F *) hSig4->Clone("hSig3ratio");
hSig4ratio->Divide(hSig1);
TH1F *hSig5ratio = (TH1F *) hSig5->Clone("hSig3ratio");
hSig5ratio->Divide(hSig1);
TH1F *hSig6ratio = (TH1F *) hSig6->Clone("hSig3ratio");
hSig6ratio->Divide(hSig1);

hSig1ratio->Draw("hist");
hSig1ratio->GetYaxis()->SetTitle("Ratio");
hSig1ratio->GetYaxis()->SetTitleSize(0.10);
hSig1ratio->GetYaxis()->SetTitleOffset(0.30);
hSig1ratio->SetMinimum(0.1);
hSig1ratio->SetMaximum(10.0);
hSig2ratio->Draw("hist same");
hSig3ratio->Draw("hist same");
hSig4ratio->Draw("hist same");
hSig5ratio->Draw("hist same");
hSig6ratio->Draw("hist same");
gPad->SetLogy(1);




}
