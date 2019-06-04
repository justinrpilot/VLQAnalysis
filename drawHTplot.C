#include "CMS_lumi.C"

void changeBinning(TH1F *&hist, bool doScale = 1){

	float bins1[15] = {0, 1500, 1600, 1700, 1800, 1900, 2000, 2200, 2400, 2600, 2800, 3000, 4000, 5000, 10000};
	int nbins = 14;
	TH1F *newhist = new TH1F(hist->GetName(), hist->GetName(), nbins, bins1);

	for (int b = 0; b <= hist->GetNbinsX(); b++){

		cout << hist->GetBinContent(b) << endl;
		newhist->SetBinContent(b, hist->GetBinContent(b));
		newhist->SetBinError(b, hist->GetBinError(b));
		if (doScale){
		newhist->SetBinContent(b, hist->GetBinContent(b) / newhist->GetBinWidth(b));
		newhist->SetBinError(b, hist->GetBinError(b) /  newhist->GetBinWidth(b));
		}
	}

	hist = (TH1F *) newhist->Clone(hist->GetName());
	delete newhist;

} 

void drawHTplot(string rootfile, string legLabel, string channel){

TFile *f1 = new TFile(rootfile.c_str(), "READ");



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
c1_2->SetBottomMargin(0.0);
c1_2->SetRightMargin(0.05);
c1_2->SetLeftMargin(0.1);
c1_2->SetFillStyle(0);

TH1F *histTT = (TH1F *) f1->Get("combined__ttbar");
TH1F *histWj = (TH1F *) f1->Get("combined__wjets");
TH1F *histZj = (TH1F *) f1->Get("combined__zjets");
TH1F *histHbb = (TH1F *) f1->Get("combined__higgs");
TH1F *histWW = (TH1F *) f1->Get("combined__diboson");
TH1F *histTTW = (TH1F *) f1->Get("combined__ttV");
TH1F *histDATA = (TH1F *) f1->Get("combined__DATA");
TH1F *histQCD_sampled = (TH1F *) f1->Get("combined__qcd");
TH1F *histQCD_sampled_up = (TH1F *) f1->Get("combined__qcd__mistag__plus");
TH1F *histQCD_sampled_dn = (TH1F *) f1->Get("combined__qcd__mistag__minus");

TH1F *hist_sig700 = (TH1F *) f1->Get("combined__tprime700");
TH1F *hist_sig800 = (TH1F *) f1->Get("combined__tprime800");
TH1F *hist_sig900 = (TH1F *) f1->Get("combined__tprime900");
TH1F *hist_sig1000 = (TH1F *) f1->Get("combined__tprime1000");
TH1F *hist_sig1100 = (TH1F *) f1->Get("combined__tprime1100");
TH1F *hist_sig1200 = (TH1F *) f1->Get("combined__tprime1200");
TH1F *hist_sig1300 = (TH1F *) f1->Get("combined__tprime1300");
TH1F *hist_sig1400 = (TH1F *) f1->Get("combined__tprime1400");
TH1F *hist_sig1500 = (TH1F *) f1->Get("combined__tprime1500");
TH1F *hist_sig1600 = (TH1F *) f1->Get("combined__tprime1600");
TH1F *hist_sig1700 = (TH1F *) f1->Get("combined__tprime1700");
TH1F *hist_sig1800 = (TH1F *) f1->Get("combined__tprime1800");

changeBinning(histTT);
changeBinning(histWj);
changeBinning(histZj);
changeBinning(histHbb);
changeBinning(histWW);
changeBinning(histTTW);
changeBinning(histDATA, 0);
changeBinning(histQCD_sampled);
changeBinning(histQCD_sampled_dn);
changeBinning(histQCD_sampled_up);
changeBinning(hist_sig700);
changeBinning(hist_sig800);
changeBinning(hist_sig900);
changeBinning(hist_sig1000);
changeBinning(hist_sig1100);
changeBinning(hist_sig1200);
changeBinning(hist_sig1300);
changeBinning(hist_sig1400);
changeBinning(hist_sig1500);
changeBinning(hist_sig1600);
changeBinning(hist_sig1700);
changeBinning(hist_sig1800);


histDATA->SetMarkerStyle(21);
histDATA->SetMarkerSize(0.8);

THStack *stack = new THStack("stack", "stack");
stack->Add(histTTW);
stack->Add(histWW);
stack->Add(histHbb);
stack->Add(histZj);
stack->Add(histWj);
stack->Add(histTT);
//stack->Add(histQCD_1);
stack->Add(histQCD_sampled);
for (int i = 0; i < histQCD_sampled->GetNbinsX(); i++){
	histQCD_sampled->SetBinError(i, (histQCD_sampled_up->GetBinContent(i) - histQCD_sampled_dn->GetBinContent(i))/2.0 );
	
}
TH1F *totalH = (TH1F *) histQCD_sampled->Clone("totalH");
totalH->Sumw2();
totalH->Add(histTT);
totalH->Add(histWj);
totalH->Add(histZj);
totalH->Add(histTTW);
totalH->Add(histWW);
totalH->Add(histHbb);


TGraphAsymmErrors * g = new TGraphAsymmErrors(histDATA);
TGraphAsymmErrors * gr = new TGraphAsymmErrors(histDATA);
double alpha = 1 - 0.6827;

for (int b = 0; b <= histDATA->GetNbinsX(); b++){



	//cout << b << " " << histDATA->GetBinContent(b) << endl;
	//if (b <= 2) histDATA->SetBinError(b, 0.0);
	//else if (histDATA->GetBinContent(b) == 0) histDATA->SetBinError(b, 1.84105);
	//else if (histDATA->GetBinContent(b) == 1) histDATA->SetBinError(b, 3.29957 - 1);

	  int N = histDATA->GetBinContent(b);
       double L =  (N==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2.,N,1.));
       double U =  ROOT::Math::gamma_quantile_c(alpha/2.,N+1,1.) ;
       cout << N <<" " <<  N-L <<" " <<  U-N<< endl;

	double W = histDATA->GetBinWidth(b);
	
       g->SetPoint(b-1, g->GetX()[b-1], float(N) / float(W) );
       g->SetPointEYlow(b-1, (float(N)-L) / float(W));
       g->SetPointEYhigh(b-1, (U-N)/W);
       gr->SetPoint(b-1, gr->GetX()[b-1], float(N) / totalH->GetBinContent(b) / W );
       g->SetPointEXlow(b-1, 0);
       g->SetPointEXhigh(b-1, 0);


       gr->SetPointEYlow(b-1, (float(N)-L)/totalH->GetBinContent(b) / W );
       gr->SetPointEYhigh(b-1, (U-N)/totalH->GetBinContent(b) / W );
       gr->SetPointEXlow(b-1, 0);
       gr->SetPointEXhigh(b-1, 0);


}
g->RemovePoint(0);
g->RemovePoint(0);
gr->RemovePoint(0);
gr->RemovePoint(0);
//histDATA->SetBinErrorOption(TH1::kPoisson);


c1_2->cd();
histDATA->Draw("axis");

hist_sig800->SetLineColor(kOrange+2);
hist_sig1000->SetLineColor(kMagenta+2);
hist_sig1200->SetLineColor(kMagenta + 2);
hist_sig1400->SetLineColor(kRed + 2);
hist_sig1600->SetLineColor(kTeal + 3);
histTT->SetFillColor(kRed);
histTT->SetLineColor(kRed);
histZj->SetFillColor(kGreen+1);
histZj->SetLineColor(kGreen+1);
histWj->SetFillColor(kBlue);
histWj->SetLineColor(kBlue);
histWW->SetLineColor(kViolet);
histWW->SetFillColor(kViolet);
histTTW->SetFillColor(kOrange);
histTTW->SetLineColor(kOrange);
histHbb->SetFillColor(kCyan+1);
histHbb->SetLineColor(kCyan+1);
hist_sig1800->SetLineColor(kCyan);
histQCD_sampled->SetLineColor(kAzure-4);
histQCD_sampled->SetFillColor(kAzure-4);


stack->SetMaximum( 1.5 * (1+histDATA->GetMaximum()) );
stack->SetMinimum( 0.0001 );
histDATA->GetXaxis()->SetTitle( "AK8 H_{T} [GeV]" );
stack->Draw("hist");
//histDATA->Draw("E0 same");
g->Draw("P same");

hist_sig800->SetLineWidth(2);
hist_sig1200->SetLineWidth(2);
hist_sig1600->SetLineWidth(2);

hist_sig800->Draw("hist same");
//hist_sig1000->Draw("hist same");
hist_sig1200->Draw("hist same");
//hist_sig1400->Draw("hist same");
hist_sig1600->Draw("hist same");
//hist_sig1800->Draw("hist same");

stack->GetHistogram()->GetXaxis()->SetTitle( "AK8 H_{T} [GeV]" );
stack->GetHistogram()->GetYaxis()->SetTitle("< Events / GeV >");
stack->GetHistogram()->GetXaxis()->SetTitleSize(0.00);
stack->GetHistogram()->GetYaxis()->SetTitleSize(0.06);
stack->GetHistogram()->GetYaxis()->SetTitleOffset(0.75);
stack->GetHistogram()->GetXaxis()->SetLabelSize(0.0);
stack->GetHistogram()->GetYaxis()->SetLabelSize(0.05);
stack->GetHistogram()->GetXaxis()->SetLabelFont(42);
stack->GetHistogram()->GetYaxis()->SetLabelFont(42);
stack->GetHistogram()->GetXaxis()->SetTitleFont(42);
stack->GetHistogram()->GetYaxis()->SetTitleFont(42);

gPad->SetTickx(1);
gPad->SetTicky(1);
gPad->RedrawAxis();


totalH->SetFillColor(16);
totalH->SetFillStyle(3244);
totalH->Draw("E2 same");

TH1F *ratioH = new TH1F();
ratioH = (TH1F*) histDATA->Clone("ratioH");
ratioH->Sumw2();
ratioH->Divide(ratioH, totalH, 1, 1, "B");

TH1F *ratioMCH = new TH1F();
ratioMCH->Sumw2();
ratioMCH = (TH1F*) totalH->Clone("ratioMCH");
ratioMCH->Divide(ratioMCH, totalH, 1,1);

TLegend *leg = new TLegend(0.46,0.61,0.92,0.86,"");
leg->SetNColumns(2);
leg->SetFillColor(0);
leg->SetLineColor(0);
leg->SetTextFont(42);
//leg->AddEntry(histDATA, Form("%s", legLabel.c_str()), "");
//leg->AddEntry(histDATA, "== 4 Jets", "");
leg->AddEntry(histDATA, "Data", "p");
leg->AddEntry(histQCD_sampled   ,  "Multijet (DD)","f");
//leg->AddEntry(histQCD_1   ,  Form("QCD (x%1.3f)", totDATA/totQCD),"f");
leg->AddEntry(histTT     , "t#bar{t}+jets" ,"f");
leg->AddEntry(histWj    , "W+jets","f");
leg->AddEntry(histZj      , "Z+jets","f");
leg->AddEntry(histHbb      , "H","f");
leg->AddEntry(histTTW, "t#bar{t}V+t#bar{t}t#bar{t}", "f");
leg->AddEntry(histWW, "VV", "f");
leg->AddEntry(hist_sig800, "TT (0.8 TeV)", "l");
//leg->AddEntry(hist_sig1000, "TT (1.0 TeV)", "l");
leg->AddEntry(hist_sig1200, "TT (1.2 TeV)", "l");
//leg->AddEntry(hist_sig1400, "TT (1.4 TeV)", "l");
leg->AddEntry(hist_sig1600, "TT (1.6 TeV)", "l");
//leg->AddEntry(hist_sig1800, "TT (1.8 TeV)", "l");
//
//

TLatex *t1 = new TLatex();
t1->SetTextFont(42);
t1->SetTextSize(0.06);
t1->DrawLatexNDC(0.15, 0.65, Form("%s", legLabel.c_str()));


leg->Draw("same");

CMS_lumi(c1_2, 4, 10);



c1_1->cd();
c1_1->SetTopMargin(0.05);
        c1_1->SetBottomMargin(0.4);
        c1_1->SetRightMargin(0.05);
        c1_1->SetLeftMargin(0.1);
        c1_1->SetFillStyle(0);
ratioH->Draw("axis");
ratioH->GetYaxis()->SetRangeUser(0.,2.);
        ratioH->GetYaxis()->SetTitle("Data / BG");
        ratioH->GetYaxis()->SetTitleOffset(0.4);
        ratioH->GetYaxis()->SetTitleSize(0.1);
        ratioH->GetYaxis()->SetLabelSize(0.1);
        ratioH->GetXaxis()->SetLabelSize(0.14);
        ratioH->GetXaxis()->SetTitleSize(0.2);
	ratioH->GetXaxis()->SetLabelFont(42);
	ratioH->GetYaxis()->SetLabelFont(42);
	ratioH->GetXaxis()->SetTitleFont(42);
	ratioH->GetYaxis()->SetTitleFont(42);
ratioH->GetYaxis()->SetNdivisions(4, kFALSE);
ratioMCH->SetFillColor(16);
ratioMCH->SetFillStyle(1001);
ratioMCH->Draw("E2 same");
//ratioH->Draw("E same");
gr->Draw("P same");
TF1 *line = new TF1("line", "1", 0, 10000);
        line->SetLineColor(kBlack);
	line->SetLineWidth(1);
        line->Draw("same");
        
        //gPad->RedrawAxis();

gPad->SetTickx(1);
gPad->SetTicky(1);
gPad->RedrawAxis();

c1_2->cd();

c1->SaveAs( TString::Format( "HT_%s.pdf", channel.c_str() ) );

gPad->SetLogy(1);
stack->SetMaximum( 1000 * (1+histDATA->GetMaximum()) );
c1_2->Update();
c1->SaveAs( TString::Format( "HT_%s_log.pdf", channel.c_str() ) ); 

}
