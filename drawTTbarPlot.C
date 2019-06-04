
void changeBinning(TH1F *&hist){

	float bins1[15] = {0, 1500, 1600, 1700, 1800, 1900, 2000, 2200, 2400, 2600, 2800, 3000, 4000, 5000, 10000};
	int nbins = 14;
	TH1F *newhist = new TH1F(hist->GetName(), hist->GetName(), nbins, bins1);

	for (int b = 0; b <= hist->GetNbinsX(); b++){

		newhist->SetBinContent(b, hist->GetBinContent(b));
		newhist->SetBinError(b, hist->GetBinError(b));

	}

	hist = (TH1F *) newhist->Clone(hist->GetName());
	delete newhist;

}


void drawTTbarPlot(){

TFile *fnom = new TFile("out2t_nom.root", "READ");
TFile *fq2up = new TFile("out2t_q2up.root", "READ");
TFile *fq2down = new TFile("out2t_q2dn.root", "READ");
TFile *fxsup = new TFile("out2t_xsup.root", "READ");
TFile *fxsdown = new TFile("out2t_xsdn.root", "READ");
TFile *fxsupq2twodown = new TFile("out2t_xsupq2twodn.root", "READ");

TH1F *hnom = (TH1F *) fnom->Get("combined__ttbar");
TH1F *hq2up = (TH1F *) fq2up->Get("combined__ttbar");
TH1F *hq2down = (TH1F *) fq2down->Get("combined__ttbar");
TH1F *hxsup = (TH1F *) fxsup->Get("combined__ttbar");
TH1F *hxsdown = (TH1F *) fxsdown->Get("combined__ttbar");
TH1F *hboth = (TH1F *) fxsupq2twodown->Get("combined__ttbar");

changeBinning(hnom);
changeBinning(hq2up);
changeBinning(hq2down);
changeBinning(hxsup);
changeBinning(hxsdown);
changeBinning(hboth);

hnom->SetLineWidth(2);
hq2up->SetLineWidth(2);
hq2down->SetLineWidth(2);
hxsup->SetLineWidth(2);
hxsdown->SetLineWidth(2);
hxsup->SetLineStyle(2);
hxsdown->SetLineStyle(2);
hboth->SetLineWidth(2);
hnom->SetLineColor(kBlack);
hq2up->SetLineColor(kGreen + 1);
hq2down->SetLineColor(kRed);
hxsup->SetLineColor(kGreen + 1);
hxsdown->SetLineColor(kRed);
hboth->SetLineColor(kViolet);


hnom->Draw("hist");
hq2up->Draw("hist same");
hq2down->Draw("hist same");
hxsup->Draw("hist same");
hxsdown->Draw("hist same");
hboth->Draw("hist same");

TLegend *leg = new TLegend(0.65,0.65,0.80,0.89);
leg->SetFillColor(0);
leg->SetLineColor(0);
leg->AddEntry(hnom, "Nominal t#bar{t}", "l");
leg->AddEntry(hq2up, "Q^2 +1#sigma", "l");
leg->AddEntry(hq2down, "Q^2 -1#sigma", "l");
leg->AddEntry(hxsup, "XS +1#sigma", "l");
leg->AddEntry(hxsdown, "XS -1#sigma", "l");
leg->AddEntry(hboth, "XS +1#sigma and Q^2 -2#sigma", "l");
leg->Draw("same");

TH1F *ratioq2Up = (TH1F *) hq2up->Clone("ratioq2Up");
TH1F *ratioq2Dn = (TH1F *) hq2down->Clone("ratioq2Dn");
TH1F *ratioxsUp = (TH1F *) hxsup->Clone("ratioxsUp");
TH1F *ratioxsDn = (TH1F *) hxsdown->Clone("ratioxsDn");
TH1F *ratioBoth = (TH1F *) hboth->Clone("ratioBoth");
TH1F *ratioNom = (TH1F *) hnom->Clone("ratioNom");
ratioq2Up->Divide(ratioq2Up, hnom, 1, 1);
ratioq2Dn->Divide(ratioq2Dn, hnom, 1, 1);
ratioxsUp->Divide(ratioxsUp, hnom, 1, 1);
ratioxsDn->Divide(ratioxsDn, hnom, 1, 1);
ratioBoth->Divide(ratioBoth, hnom, 1, 1);
ratioNom->Divide(ratioNom, hnom, 1, 1);

TCanvas *c2 = new TCanvas();

c2->cd();

ratioNom->Draw("hist");
ratioNom->GetYaxis()->SetRangeUser(0.4, 1.8);
ratioq2Up->Draw("hist same");
ratioq2Dn->Draw("hist same");
ratioxsUp->Draw("hist same");
ratioxsDn->Draw("hist same");
ratioBoth->Draw("hist same");
leg->Draw("same");

}
