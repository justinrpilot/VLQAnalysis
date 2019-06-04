#include "CMS_lumi.C"


void drawROC( TH1F *histS, TH1F *histB, int color, float noCutTT, float noCutQCD);

void makeStack(string var, string label, string sel, int nbins, float xmin, float xmax, string filename, string channel){



TFile *fileQCD_1 = new TFile("outplots_qcd1.root", "READ");
TFile *fileQCD_2 = new TFile("outplots_qcd2.root", "READ");
TFile *fileQCD_3 = new TFile("outplots_qcd3.root", "READ");
TFile *fileQCD_4 = new TFile("outplots_qcd4.root", "READ");
TFile *fileQCD_5 = new TFile("outplots_qcd5.root", "READ");
TFile *fileQCD_6 = new TFile("outplots_qcd6.root", "READ");
TFile *fileQCD_7 = new TFile("outplots_qcd7.root", "READ");
TFile *fileQCD_8 = new TFile("outplots_qcd8.root", "READ");
TFile *fileQCD_9 = new TFile("outplots_qcd9.root", "READ");

TFile *fileTT = new TFile("outplots_ttbar.root", "READ");
TFile *fileWj = new TFile("outplots_wjets.root", "READ");
TFile *fileZj = new TFile("outplots_zjets.root", "READ");

TFile *sig1 = new TFile("outplots_vlq1000.root", "READ");
TFile *sig2 = new TFile("outplots_vlq1400.root", "READ");
TFile *sig3 = new TFile("outplots_vlq1800.root", "READ");
TFile *sig4 = new TFile("outplots_vlq1400.root", "READ");


TFile *fileDATA = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataALL.root", "READ");

TTree *treeQCD_1 = (TTree *) fileQCD_1->Get("jetVars");
TTree *treeQCD_2 = (TTree *) fileQCD_2->Get("jetVars");
TTree *treeQCD_3 = (TTree *) fileQCD_3->Get("jetVars");
TTree *treeQCD_4 = (TTree *) fileQCD_4->Get("jetVars");
TTree *treeQCD_5 = (TTree *) fileQCD_5->Get("jetVars");
TTree *treeQCD_6 = (TTree *) fileQCD_6->Get("jetVars");
TTree *treeQCD_7 = (TTree *) fileQCD_7->Get("jetVars");
TTree *treeQCD_8 = (TTree *) fileQCD_8->Get("jetVars");
TTree *treeQCD_9 = (TTree *) fileQCD_9->Get("jetVars");
TTree *treeDATA = (TTree *) fileDATA->Get("jetVars");

TTree *treeTT = (TTree *) fileTT->Get("jetVars");
TTree *treeWj = (TTree *) fileWj->Get("jetVars");
TTree *treeZj = (TTree *) fileZj->Get("jetVars");

TTree *tree_sig1 = (TTree *) sig1->Get("jetVars");
TTree *tree_sig2 = (TTree *) sig2->Get("jetVars");
TTree *tree_sig3 = (TTree *) sig3->Get("jetVars");
TTree *tree_sig4 = (TTree *) sig4->Get("jetVars");


TH1D *histQCD_1 = new TH1D("histQCD_1", "histQCD_1", nbins, xmin, xmax);
TH1D *histQCD_2 = new TH1D("histQCD_2", "histQCD_2", nbins, xmin, xmax);
TH1D *histQCD_3 = new TH1D("histQCD_3", "histQCD_3", nbins, xmin, xmax);
TH1D *histQCD_4 = new TH1D("histQCD_4", "histQCD_4", nbins, xmin, xmax);
TH1D *histQCD_5 = new TH1D("histQCD_5", "histQCD_5", nbins, xmin, xmax);
TH1D *histQCD_6 = new TH1D("histQCD_6", "histQCD_6", nbins, xmin, xmax);
TH1D *histQCD_7 = new TH1D("histQCD_7", "histQCD_7", nbins, xmin, xmax);
TH1D *histQCD_8 = new TH1D("histQCD_8", "histQCD_8", nbins, xmin, xmax);
TH1D *histQCD_9 = new TH1D("histQCD_9", "histQCD_9", nbins, xmin, xmax);
TH1D *histDATA = new TH1D("histDATA", "histDATA", nbins, xmin, xmax);
TH1D *histTT = new TH1D("histTT", "histTT", nbins, xmin, xmax);
TH1D *histWj = new TH1D("histWj", "histWj", nbins, xmin, xmax);
TH1D *histZj = new TH1D("histZj", "histZj", nbins, xmin, xmax);

TH1D *hist_sig1 = new TH1D("hist_sig1", "hist_sig1", nbins, xmin, xmax);
TH1D *hist_sig2 = new TH1D("hist_sig2", "hist_sig2", nbins, xmin, xmax);
TH1D *hist_sig3 = new TH1D("hist_sig3", "hist_sig3", nbins, xmin, xmax);
TH1D *hist_sig4 = new TH1D("hist_sig4", "hist_sig4", nbins, xmin, xmax);


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
c1_2->SetBottomMargin(0.1);
c1_2->SetRightMargin(0.05);
c1_2->SetLeftMargin(0.1);
c1_2->SetFillStyle(0);

treeQCD_1->Draw( Form( "%s >> histQCD_1", var.c_str() ), sel.c_str() );
treeQCD_2->Draw( Form( "%s >> histQCD_2", var.c_str() ), sel.c_str() );
treeQCD_3->Draw( Form( "%s >> histQCD_3", var.c_str() ), sel.c_str() );
treeQCD_4->Draw( Form( "%s >> histQCD_4", var.c_str() ), sel.c_str() );
treeQCD_5->Draw( Form( "%s >> histQCD_5", var.c_str() ), sel.c_str() );
treeQCD_6->Draw( Form( "%s >> histQCD_6", var.c_str() ), sel.c_str() );
treeQCD_7->Draw( Form( "%s >> histQCD_7", var.c_str() ), sel.c_str() );
treeQCD_8->Draw( Form( "%s >> histQCD_8", var.c_str() ), sel.c_str() );
treeQCD_9->Draw( Form( "%s >> histQCD_9", var.c_str() ), sel.c_str() );

string count_sel = "";

float totNumQCD = treeQCD_1->GetEntries(count_sel.c_str()) +
	       treeQCD_2->GetEntries(count_sel.c_str()) +
	       treeQCD_3->GetEntries(count_sel.c_str()) +
	       treeQCD_4->GetEntries(count_sel.c_str()) +
	       treeQCD_5->GetEntries(count_sel.c_str()) +
	       treeQCD_6->GetEntries(count_sel.c_str()) +
	       treeQCD_7->GetEntries(count_sel.c_str()) +
	       treeQCD_8->GetEntries(count_sel.c_str()) +
	       treeQCD_9->GetEntries(count_sel.c_str());

float totNumTT = tree_sig4->GetEntries(count_sel.c_str());


treeDATA->Draw( Form( "%s >> histDATA", var.c_str() ), sel.c_str() );


treeTT->Draw( Form( "%s >> histTT", var.c_str() ), sel.c_str() );
treeWj->Draw( Form( "%s >> histWj", var.c_str() ), sel.c_str() );
treeZj->Draw( Form( "%s >> histZj", var.c_str() ), sel.c_str() );

tree_sig1->Draw( Form( "%s >> hist_sig1", var.c_str() ), sel.c_str() );
tree_sig2->Draw( Form( "%s >> hist_sig2", var.c_str() ), sel.c_str() );
tree_sig3->Draw( Form( "%s >> hist_sig3", var.c_str() ), sel.c_str() );
tree_sig4->Draw( Form( "%s >> hist_sig4", var.c_str() ), sel.c_str() );


float lumi = 35289.97;

histQCD_1->Scale( 7823.0 * lumi / 5970600.);
histQCD_2->Scale(  648.2 * lumi / 3928870.);
histQCD_3->Scale(  186.9 * lumi / 3959768.);
histQCD_4->Scale(  32.29 * lumi / 3924080.);
histQCD_5->Scale(  9.418 * lumi / 2999069.);
histQCD_6->Scale(  0.84265 * lumi / 396409.);
histQCD_7->Scale(  0.114943 * lumi / 396100.);
histQCD_8->Scale(  0.0068291 * lumi / 399226.);
histQCD_9->Scale(  0.0001654 * lumi / 383926.);

histTT->Scale( 831.76 * lumi / 92925926. );
histWj->Scale( 95.14*.066*lumi / 1025005.);
histZj->Scale( 5.67 * lumi / 1000000.); 

//hist_sig800->Scale(0.196*lumi  / 766000. );
hist_sig1->Scale(0.044*lumi  / 832200. );
//hist_sig1200->Scale(0.0118*lumi  / 828600. );
hist_sig2->Scale(0.00354*lumi  / 810000. );
//hist_sig1600->Scale(0.001148*lumi  / 111800. );
hist_sig3->Scale(0.000391*lumi  / 812400. );




hist_sig1->SetLineColor(kOrange+2);
hist_sig2->SetLineColor(kMagenta+2);
hist_sig3->SetLineColor(kTeal + 3);
hist_sig4->SetLineColor(kRed + 2);

hist_sig1->SetLineWidth(2);
hist_sig2->SetLineWidth(2);
hist_sig3->SetLineWidth(2);
hist_sig4->SetLineWidth(2);


histTT->SetFillColor(kRed);
histTT->SetLineColor(kRed);
histZj->SetFillColor(kGreen+1);
histZj->SetLineColor(kGreen+1);
histWj->SetFillColor(kBlue);
histWj->SetLineColor(kBlue);

histQCD_1->SetFillColor(kYellow + 1);
histQCD_2->SetFillColor(kYellow + 1);
histQCD_3->SetFillColor(kYellow + 1);
histQCD_4->SetFillColor(kYellow + 1);
histQCD_5->SetFillColor(kYellow + 1);
histQCD_6->SetFillColor(kYellow + 1);
histQCD_7->SetFillColor(kYellow + 1);
histQCD_8->SetFillColor(kYellow + 1);
histQCD_9->SetFillColor(kYellow + 1);
histQCD_1->SetLineColor(kYellow + 1);
histQCD_2->SetLineColor(kYellow + 1);
histQCD_3->SetLineColor(kYellow + 1);
histQCD_4->SetLineColor(kYellow + 1);
histQCD_5->SetLineColor(kYellow + 1);
histQCD_6->SetLineColor(kYellow + 1);
histQCD_7->SetLineColor(kYellow + 1);
histQCD_8->SetLineColor(kYellow + 1);
histQCD_9->SetLineColor(kYellow + 1);

float totQCD = histQCD_1->Integral() + histQCD_2->Integral() + histQCD_3->Integral() + histQCD_4->Integral() + histQCD_5->Integral() + histQCD_6->Integral() + histQCD_7->Integral() + histQCD_8->Integral() + histQCD_9->Integral();
float totDATA = histDATA->Integral() - histTT->Integral() - histWj->Integral() - histZj->Integral();


cout << "Scaling QCD by: " << totDATA/totQCD << endl;

histQCD_1->Scale(totDATA / totQCD);
histQCD_2->Scale(totDATA / totQCD);
histQCD_3->Scale(totDATA / totQCD);
histQCD_4->Scale(totDATA / totQCD);
histQCD_5->Scale(totDATA / totQCD);
histQCD_6->Scale(totDATA / totQCD);
histQCD_7->Scale(totDATA / totQCD);
histQCD_8->Scale(totDATA / totQCD);
histQCD_9->Scale(totDATA / totQCD);



histDATA->SetMarkerStyle(21);
histDATA->SetMarkerSize(0.8);

THStack *stack = new THStack("stack", "stack");

stack->Add(histZj);
stack->Add(histWj);
stack->Add(histTT);
stack->Add(histQCD_1);
stack->Add(histQCD_2);
stack->Add(histQCD_3);
stack->Add(histQCD_4);
stack->Add(histQCD_5);
stack->Add(histQCD_6);
stack->Add(histQCD_7);
stack->Add(histQCD_8);
stack->Add(histQCD_9);

histDATA->Draw("axis");

histDATA->SetMaximum( 4000 * histDATA->GetMaximum() );
histDATA->SetMinimum( 0.0001 );
histDATA->GetXaxis()->SetTitle( label.c_str() );
histDATA->Draw("axis");
stack->Draw("hist same");
histDATA->Draw("E same");
hist_sig1->Draw("hist same");
hist_sig2->Draw("hist same");
hist_sig3->Draw("hist same");
//hist_sig4->Draw("same");


gPad->RedrawAxis();

TH1F *totalH = (TH1F *) histQCD_1->Clone("totalH");
totalH->Add(histQCD_2);
totalH->Add(histQCD_3);
totalH->Add(histQCD_4);
totalH->Add(histQCD_5);
totalH->Add(histQCD_6);
totalH->Add(histQCD_7);
totalH->Add(histQCD_8);
totalH->Add(histQCD_9);
totalH->Add(histTT);
totalH->Add(histWj);
totalH->Add(histZj);

TH1F *hist_totQCD = (TH1F *) histQCD_1->Clone("hist_totQCD");
hist_totQCD->Add(histQCD_2);
hist_totQCD->Add(histQCD_3);
hist_totQCD->Add(histQCD_4);
hist_totQCD->Add(histQCD_5);
hist_totQCD->Add(histQCD_6);
hist_totQCD->Add(histQCD_7);
hist_totQCD->Add(histQCD_8);
hist_totQCD->Add(histQCD_9);


TH1F *ratioH = new TH1F();
ratioH = (TH1F*) histDATA->Clone("ratioH");
ratioH->Sumw2();
ratioH->Divide(ratioH, totalH, 1, 1, "B");



TLegend *leg = new TLegend(0.55,0.61,0.92,0.86,"");
leg->SetNColumns(1);
leg->SetFillColor(0);
leg->SetLineColor(0);
leg->AddEntry(histDATA, "Data", "p");
leg->AddEntry(histQCD_1   ,  "QCD","f");
//leg->AddEntry(histQCD_1   ,  Form("QCD (x%1.3f)", totDATA/totQCD),"f");
leg->AddEntry(histTT     , "t#bar{t}+jets" ,"f");
leg->AddEntry(histWj    , "W+jets","f");
leg->AddEntry(histZj      , "Z+jets","f");
leg->AddEntry(hist_sig1, "TT (1.0 TeV)", "l");
leg->AddEntry(hist_sig2, "TT (1.4 TeV)", "l");
leg->AddEntry(hist_sig3, "TT (1.8 TeV)", "l");
//leg->AddEntry(hist_sig4, "4 TeV Z'", "l");

leg->SetNColumns(2);

leg->Draw("same");

CMS_lumi(c1_2, 4, 0);



c1_1->cd();
c1_1->SetTopMargin(0.05);
        c1_1->SetBottomMargin(0.3);
        c1_1->SetRightMargin(0.05);
        c1_1->SetLeftMargin(0.1);
        c1_1->SetFillStyle(0);
ratioH->Draw();
ratioH->GetYaxis()->SetRangeUser(0.,2.);
        ratioH->GetYaxis()->SetTitle("Data / BG Ratio");
        ratioH->GetYaxis()->SetTitleOffset(0.4);
        ratioH->GetYaxis()->SetTitleSize(0.11);
        ratioH->GetYaxis()->SetLabelSize(0.11);
        ratioH->GetXaxis()->SetLabelSize(0.11);
        ratioH->GetXaxis()->SetTitleSize(0.11);
ratioH->GetYaxis()->SetNdivisions(4, kFALSE);

TF1 *line = new TF1("line", "1", 0, 5000);
        line->SetLineColor(kBlack);
	line->SetLineWidth(1);
        line->Draw("same");
        
        gPad->RedrawAxis();

c1_2->cd();


c1->SaveAs( Form( "%s.pdf", filename.c_str() ) );

gPad->SetLogy(1);

histDATA->SetMaximum( 10000 * histDATA->GetMaximum() );
c1_2->Update();
c1->SaveAs( Form( "%s_log.pdf", filename.c_str() ) );

//TCanvas *c2 = new TCanvas("c2", "c2");
//c2->cd();
//drawROC(hist_sig4, hist_totQCD, 1, totNumTT, totNumQCD);

TFile *outFile = new TFile(Form("%s_histos.root", channel.c_str()), "RECREATE");
outFile->cd();

hist_totQCD->Write(Form("%s__qcd", channel.c_str()));
histTT->Write(Form("%s__ttbar", channel.c_str()));
hist_sig1->Write(Form("%s__tprime1000", channel.c_str()));
hist_sig2->Write(Form("%s__tprime1400", channel.c_str()));
hist_sig3->Write(Form("%s__tprime1800", channel.c_str()));
//hist_sig4->Write(Form("%s__zprime4", channel.c_str()));
outFile->Close();


return;

}


void drawROC( TH1F *histS, TH1F *histB, int color, float noCutTT, float noCutQCD){


TGraph *rocG = new TGraph();

float sEntries = 0.0;
float bEntries = 0.0;

int n =0;

cout << "tt: " << histS->GetEntries() << "  " << noCutTT << endl;
cout << "qcd: " << histB->GetEntries() << " " << noCutQCD << endl;


for (int i = 0; i < histS->GetNbinsX(); i++){

	
	sEntries = (float(histS->GetEntries()) / noCutTT) * histS->Integral(0, i) / histS->Integral();
	bEntries = (float(histB->GetEntries()) / noCutQCD) * histB->Integral(0, i) / histB->Integral();

	cout << sEntries << "   " << bEntries << endl;

	rocG->SetPoint(++n, sEntries, bEntries);

}


TH2F *axisH = new TH2F("axisH", "axisH", 10000, 0, 1, 10000, 0, 1);
axisH->GetXaxis()->SetTitle( Form("%s Efficiency", histS->GetName() ) );
axisH->GetYaxis()->SetTitle( Form("%s Efficiency", histB->GetName() ) );
axisH->Draw("axis");

rocG->Draw("same");
rocG->SetLineWidth(2);
rocG->SetLineColor(color);
gPad->SetLogy(1);

return;

}


