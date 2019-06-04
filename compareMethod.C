void compareMethod(int bin){

TFile *f1 = new TFile(Form("bin%d_histos.root", bin));
f1->cd();
//TH1F *htemp = new TH1F("htemp", "htemp", 100, 0, 7000);
//#eventVars->Draw("ht>>htemp", "numTop == 3 && numQCD == 1  &&  numJets == 4");
TH1F *htemp = (TH1F *) f1->Get(Form("bin%d__qcd", bin));
htemp->Scale(1. / htemp->Integral() );

TFile *f2 = new TFile(Form("bgshape_bin%d.root", bin));
f2->cd();

TH1F *outHT = (TH1F *) f2->Get("outHT");

outHT->Scale(1./outHT->Integral() );


TCanvas *c = new TCanvas("c", "canvas", 800, 800);
TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
   pad1->SetBottomMargin(0.1); // Upper and lower plot are joined
   pad1->Draw();             // Draw the upper pad: pad1
   pad1->cd();               // pad1 becomes the current pad


outHT->SetMaximum(htemp->GetMaximum());
outHT->GetYaxis()->SetTitle("Fraction of Events");
outHT->GetXaxis()->SetTitle("Event H_{T} [GeV]");
outHT->Draw("hist");
htemp->SetLineColor(kRed);
htemp->SetLineWidth(2);
htemp->Draw("E same");

TLegend *leg = new TLegend (0.75, 0.75, 0.89, 0.89);
leg->SetFillColor(0);
leg->SetLineColor(0);
leg->AddEntry(outHT, "Model", "l");
leg->AddEntry(htemp, "QCD Sim.", "l");
leg->AddEntry(htemp, Form("Event Bin %d", bin), "");
leg->Draw("same");

gPad->SetLogy(1);

c->cd();          // Go back to the main canvas before defining pad2
   TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.2);
   pad2->SetGridx(); // vertical grid
   pad2->Draw();
   pad2->cd();


TH1F *h3 = (TH1F*)outHT->Clone("h3");
   h3->SetLineColor(kBlack);
   h3->SetMinimum(0);  // Define Y ..
   h3->SetMaximum(3); // .. range
   h3->Sumw2();
   h3->SetStats(0);      // No statistics on lower plot
   h3->Divide(htemp);
   h3->SetMarkerStyle(21);
   h3->GetXaxis()->SetTitle("Event H_{T} [GeV]");
   h3->GetYaxis()->SetTitle("Model / QCD");
	h3->Draw("p");

c->SaveAs(Form("comparison_bin%d.pdf", bin));
}
