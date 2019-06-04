#include "CMS_lumi.C"


void drawROC( TH1F *histS, TH1F *histB, int color, float noCutTT, float noCutQCD);

void makeStack(string var, string label, string sel, string datasel,int nbins, float xmin, float xmax, string filename, string channel){



TFile *fileQCD_0 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd0.root", "READ");
TFile *fileQCD_1 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd1.root", "READ");
TFile *fileQCD_2 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd2.root", "READ");
TFile *fileQCD_3 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd3.root", "READ");
TFile *fileQCD_4 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd4.root", "READ");
TFile *fileQCD_5 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd5.root", "READ");
TFile *fileQCD_6 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd6.root", "READ");
TFile *fileQCD_7 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd7.root", "READ");
TFile *fileQCD_8 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd8.root", "READ");
TFile *fileQCD_9 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_qcd9.root", "READ");
//TFile *fileQCD_1 = TFile::Open("~/3DayLifetime/outplots_qcd1_new.root", "READ");
//TFile *fileQCD_2 = TFile::Open("~/3DayLifetime/outplots_qcd2_new.root", "READ");
//TFile *fileQCD_3 = TFile::Open("~/3DayLifetime/outplots_qcd3_new.root", "READ");
//TFile *fileQCD_4 = TFile::Open("~/3DayLifetime/outplots_qcd4_new.root", "READ");
//TFile *fileQCD_5 = TFile::Open("~/3DayLifetime/outplots_qcd5_new.root", "READ");
//TFile *fileQCD_6 = TFile::Open("~/3DayLifetime/outplots_qcd6_new.root", "READ");
//TFile *fileQCD_7 = TFile::Open("~/3DayLifetime/outplots_qcd7_new.root", "READ");
//TFile *fileQCD_8 = TFile::Open("~/3DayLifetime/outplots_qcd8_new.root", "READ");
//TFile *fileQCD_9 = TFile::Open("~/3DayLifetime/outplots_qcd9_new.root", "READ");

TFile *fileQCDB_0 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_QCDB_700to1000.root", "READ");
TFile *fileQCDB_1 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_QCDB_1000to1500.root", "READ");
TFile *fileQCDB_2 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_QCDB_1500to2000.root", "READ");
TFile *fileQCDB_3 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_QCDB_2000toInf.root", "READ");

TFile *fileTT = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ttbar.root", "READ");
TFile *fileWj = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_wjets.root", "READ");
TFile *fileZj = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_zjets.root", "READ");

TFile *fileWW = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_WW.root", "READ");
TFile *fileWZ = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_WZ.root", "READ");
TFile *fileZZ = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ZZ.root", "READ");

TFile *fileTTW = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ttW.root", "READ");
TFile *fileTTZ = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_ttZ.root", "READ");
TFile *fileTTTT = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_tttt.root", "READ");

TFile *fileHbb = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_Hbb.root", "READ");
TFile *fileHWW = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_HWW.root", "READ");
TFile *fileWplusH = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_WplusH.root", "READ");
TFile *fileWminusH = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_WminusH.root", "READ");

TFile *sig1 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_vlq800.root", "READ");
TFile *sig2 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_vlq1200.root", "READ");
TFile *sig3 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_vlq1600.root", "READ");
//TFile *sig4 = new TFile("outplots_vlq1400.root", "READ");


//TFile *fileDATA = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataALL.root", "READ");


TTree *treeQCD_1 = (TTree *) fileQCD_1->Get("eventVars");
TTree *treeQCD_0 = (TTree *) fileQCD_0->Get("eventVars");
TTree *treeQCD_2 = (TTree *) fileQCD_2->Get("eventVars");
TTree *treeQCD_3 = (TTree *) fileQCD_3->Get("eventVars");
TTree *treeQCD_4 = (TTree *) fileQCD_4->Get("eventVars");
TTree *treeQCD_5 = (TTree *) fileQCD_5->Get("eventVars");
TTree *treeQCD_6 = (TTree *) fileQCD_6->Get("eventVars");
TTree *treeQCD_7 = (TTree *) fileQCD_7->Get("eventVars");
TTree *treeQCD_8 = (TTree *) fileQCD_8->Get("eventVars");
TTree *treeQCD_9 = (TTree *) fileQCD_9->Get("eventVars");
TTree *treeQCDB_0 = (TTree *) fileQCDB_0->Get("eventVars");
TTree *treeQCDB_1 = (TTree *) fileQCDB_1->Get("eventVars");
TTree *treeQCDB_2 = (TTree *) fileQCDB_2->Get("eventVars");
TTree *treeQCDB_3 = (TTree *) fileQCDB_3->Get("eventVars");

TChain *treeDATA = new TChain("eventVars");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataB.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataC.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataD.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataE.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataF.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataG.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataH.root");
treeDATA->Add("root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_DATA_H2.root");


TTree *treeTT = (TTree *) fileTT->Get("eventVars");
TTree *treeWj = (TTree *) fileWj->Get("eventVars");
TTree *treeZj = (TTree *) fileZj->Get("eventVars");

TTree *treeWW = (TTree *) fileWW->Get("eventVars");
TTree *treeWZ = (TTree *) fileWZ->Get("eventVars");
TTree *treeZZ = (TTree *) fileZZ->Get("eventVars");

TTree *treeTTW = (TTree *) fileTTW->Get("eventVars");
TTree *treeTTZ = (TTree *) fileTTZ->Get("eventVars");
TTree *treeTTTT = (TTree *) fileTTTT->Get("eventVars");
TTree *treeHbb = (TTree *) fileHbb->Get("eventVars");
TTree *treeHWW = (TTree *) fileHWW->Get("eventVars");
TTree *treeWplusH = (TTree *) fileWplusH->Get("eventVars");
TTree *treeWminusH = (TTree *) fileWminusH->Get("eventVars");
TTree *tree_sig1 = (TTree *) sig1->Get("eventVars");
TTree *tree_sig2 = (TTree *) sig2->Get("eventVars");
TTree *tree_sig3 = (TTree *) sig3->Get("eventVars");
//TTree *tree_sig4 = (TTree *) sig4->Get("eventVars");


TH1D *histQCD_0 = new TH1D("histQCD_0", "histQCD_0", nbins, xmin, xmax);
TH1D *histQCD_1 = new TH1D("histQCD_1", "histQCD_1", nbins, xmin, xmax);
TH1D *histQCD_2 = new TH1D("histQCD_2", "histQCD_2", nbins, xmin, xmax);
TH1D *histQCD_3 = new TH1D("histQCD_3", "histQCD_3", nbins, xmin, xmax);
TH1D *histQCD_4 = new TH1D("histQCD_4", "histQCD_4", nbins, xmin, xmax);
TH1D *histQCD_5 = new TH1D("histQCD_5", "histQCD_5", nbins, xmin, xmax);
TH1D *histQCD_6 = new TH1D("histQCD_6", "histQCD_6", nbins, xmin, xmax);
TH1D *histQCD_7 = new TH1D("histQCD_7", "histQCD_7", nbins, xmin, xmax);
TH1D *histQCD_8 = new TH1D("histQCD_8", "histQCD_8", nbins, xmin, xmax);
TH1D *histQCD_9 = new TH1D("histQCD_9", "histQCD_9", nbins, xmin, xmax);
TH1D *histQCDB_0 = new TH1D("histQCDB_0", "histQCDB_0", nbins, xmin, xmax);
TH1D *histQCDB_1 = new TH1D("histQCDB_1", "histQCDB_1", nbins, xmin, xmax);
TH1D *histQCDB_2 = new TH1D("histQCDB_2", "histQCDB_2", nbins, xmin, xmax);
TH1D *histQCDB_3 = new TH1D("histQCDB_3", "histQCDB_3", nbins, xmin, xmax);
histQCD_0->Sumw2();
histQCD_1->Sumw2();
histQCD_2->Sumw2();
histQCD_3->Sumw2();
histQCD_4->Sumw2();
histQCD_5->Sumw2();
histQCD_6->Sumw2();
histQCD_7->Sumw2();
histQCD_8->Sumw2();
histQCD_9->Sumw2();


TH1D *histDATA = new TH1D("histDATA", "histDATA", nbins, xmin, xmax);
TH1D *histTT = new TH1D("histTT", "histTT", nbins, xmin, xmax);
TH1D *histWj = new TH1D("histWj", "histWj", nbins, xmin, xmax);
TH1D *histZj = new TH1D("histZj", "histZj", nbins, xmin, xmax);

TH1D *histWW = new TH1D("histWW", "histWW", nbins, xmin, xmax);
TH1D *histZZ = new TH1D("histZZ", "histZZ", nbins, xmin, xmax);
TH1D *histWZ = new TH1D("histWZ", "histWZ", nbins, xmin, xmax);

TH1D *histTTW = new TH1D("histTTW", "histTTW", nbins, xmin, xmax);
TH1D *histTTZ = new TH1D("histTTZ", "histTTZ", nbins, xmin, xmax);
TH1D *histTTTT = new TH1D("histTTTT", "histTTTT", nbins, xmin, xmax);
TH1D *histHbb = new TH1D("histHbb", "histHbb", nbins, xmin, xmax);
TH1D *histHWW = new TH1D("histHWW", "histHWW", nbins, xmin, xmax);
TH1D *histWplusH = new TH1D("histWplusH", "histWplusH", nbins, xmin, xmax);
TH1D *histWminusH = new TH1D("histWminusH", "histWminusH", nbins, xmin, xmax);

TH1D *hist_sig1 = new TH1D("hist_sig1", "hist_sig1", nbins, xmin, xmax);
TH1D *hist_sig2 = new TH1D("hist_sig2", "hist_sig2", nbins, xmin, xmax);
TH1D *hist_sig3 = new TH1D("hist_sig3", "hist_sig3", nbins, xmin, xmax);
//TH1D *hist_sig4 = new TH1D("hist_sig4", "hist_sig4", nbins, xmin, xmax);
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


treeQCD_0->Draw( Form( "%s >> histQCD_0", var.c_str() ), sel.c_str() );
treeQCD_1->Draw( Form( "%s >> histQCD_1", var.c_str() ), sel.c_str() );
treeQCD_2->Draw( Form( "%s >> histQCD_2", var.c_str() ), sel.c_str() );
treeQCD_3->Draw( Form( "%s >> histQCD_3", var.c_str() ), sel.c_str() );
treeQCD_4->Draw( Form( "%s >> histQCD_4", var.c_str() ), sel.c_str() );
treeQCD_5->Draw( Form( "%s >> histQCD_5", var.c_str() ), sel.c_str() );
treeQCD_6->Draw( Form( "%s >> histQCD_6", var.c_str() ), sel.c_str() );
treeQCD_7->Draw( Form( "%s >> histQCD_7", var.c_str() ), sel.c_str() );
treeQCD_8->Draw( Form( "%s >> histQCD_8", var.c_str() ), sel.c_str() );
treeQCD_9->Draw( Form( "%s >> histQCD_9", var.c_str() ), sel.c_str() );

treeQCDB_0->Draw( Form( "%s >> histQCDB_0", var.c_str() ), sel.c_str() );
treeQCDB_1->Draw( Form( "%s >> histQCDB_1", var.c_str() ), sel.c_str() );
treeQCDB_2->Draw( Form( "%s >> histQCDB_2", var.c_str() ), sel.c_str() );
treeQCDB_3->Draw( Form( "%s >> histQCDB_3", var.c_str() ), sel.c_str() );

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

float totNumTT = treeTT->GetEntries(count_sel.c_str());


treeDATA->Draw( Form( "%s >> histDATA", var.c_str() ), datasel.c_str() );


treeTT->Draw( Form( "%s >> histTT", var.c_str() ), datasel.c_str() );
treeWj->Draw( Form( "%s >> histWj", var.c_str() ), datasel.c_str() );
treeZj->Draw( Form( "%s >> histZj", var.c_str() ), datasel.c_str() );

treeWW->Draw( Form( "%s >> histWW", var.c_str() ), datasel.c_str() );
treeZZ->Draw( Form( "%s >> histZZ", var.c_str() ), datasel.c_str() );
treeWZ->Draw( Form( "%s >> histWZ", var.c_str() ), datasel.c_str() );
treeTTW->Draw( Form( "%s >> histTTW", var.c_str() ), datasel.c_str() );
treeTTZ->Draw( Form( "%s >> histTTZ", var.c_str() ), datasel.c_str() );
treeTTTT->Draw( Form( "%s >> histTTTT", var.c_str() ), datasel.c_str() );
treeHbb->Draw( Form( "%s >> histHbb", var.c_str() ), datasel.c_str() );
treeHWW->Draw( Form( "%s >> histHWW", var.c_str() ), datasel.c_str() );
treeWplusH->Draw( Form( "%s >> histWplusH", var.c_str() ), datasel.c_str() );
treeWminusH->Draw( Form( "%s >> histWminusH", var.c_str() ), datasel.c_str() );

tree_sig1->Draw( Form( "%s >> hist_sig1", var.c_str() ), Form("(decayMode1 <= 3 && decayMode2 <= 3)*%s", datasel.c_str()) );
tree_sig2->Draw( Form( "%s >> hist_sig2", var.c_str() ), Form("(decayMode1 <= 3 && decayMode2 <= 3)* %s", datasel.c_str()) );
tree_sig3->Draw( Form( "%s >> hist_sig3", var.c_str() ), Form("(decayMode1 <= 3 && decayMode2 <= 3)* %s", datasel.c_str()) );
//tree_sig4->Draw( Form( "%s >> hist_sig4", var.c_str() ), Form("decayMode1 <= 3 && decayMode2 <= 3 && %s", datasel.c_str()) );


float lumi = 35289.97+215;//8529.407;

histQCD_0->Scale( 117276. * lumi / 6958708.);
histQCD_1->Scale( 7823.0 * lumi / 4150588.);
histQCD_2->Scale(  648.2 * lumi / 3959986.);
histQCD_3->Scale(  186.9 * lumi / 3896412.);
histQCD_4->Scale(  32.29 * lumi / 3992112.);
histQCD_5->Scale(  9.418 * lumi / 2999069.);
histQCD_6->Scale(  0.84265 * lumi / 396409.);
histQCD_7->Scale(  0.114943 * lumi / 397660.);
histQCD_8->Scale(  0.0068291 * lumi / 399226.);
histQCD_9->Scale(  0.0001654 * lumi / 391735.);

histQCDB_0->Scale( 0.*320.0 * lumi / (879057.*0.092) ); 
histQCDB_1->Scale( 0.*50.26 * lumi / (221429.*0.082) ); 
histQCDB_2->Scale( 0.*4.41 * lumi / (51779.*0.082) ); 
histQCDB_3->Scale( 0.*0.78 * lumi / (23671.*0.092) ); 

histTT->Scale( 831.76 * lumi / 77081156. );
histWj->Scale( 95.14*.066*lumi / 1026587.);
histZj->Scale( 5.67 * lumi / 996000.); 

histWW->Scale( 63.21 * lumi / 6987124.);
histZZ->Scale( 16.523 * lumi / 998034. );
histWZ->Scale( 47.13  * lumi / 2995828. );

histTTW->Scale( 0.4062 * lumi / 833298. );
histTTZ->Scale( 0.5297 * lumi / 749400. );
histTTTT->Scale( 0.009103 * lumi /  250000. );
histHbb->Scale( 43.92* 0.648 * lumi /  529120. );
histHWW->Scale( 43.92* 0.14*2*0.1*0.67 * lumi  / 43865.  ); //H->WW decay * WW->lvqq decay
histWplusH->Scale( 1.38* 0.648 * 0.676 * lumi / 231550. ); //H->bb, W->QQ
histWminusH->Scale( 1.38* 0.648* 0.676 * lumi / 274037. ); 
histWplusH->Add(histWminusH);
//hist_sig800->Scale(0.196*lumi  / 766000. );
hist_sig1->Scale(0.044*lumi  / 832200. );
//hist_sig1200->Scale(0.0118*lumi  / 828600. );
hist_sig2->Scale(0.00354*lumi  / 810000. );
//hist_sig1600->Scale(0.001148*lumi  / 111800. );
hist_sig3->Scale(0.000391*lumi  / 812400. );




hist_sig1->SetLineColor(kOrange+2);
hist_sig2->SetLineColor(kMagenta+2);
hist_sig3->SetLineColor(kTeal + 3);
//hist_sig4->SetLineColor(kRed + 2);

hist_sig1->SetLineWidth(2);
hist_sig2->SetLineWidth(2);
hist_sig3->SetLineWidth(2);
//hist_sig4->SetLineWidth(2);

gStyle->SetPalette(kPastel);
int nColors = 5;
int color1 = kYellow - 7;//TColor::GetColorPalette(0);
int color2 = kRed;//TColor::GetColorPalette(1*254/nColors);
int color3 = kBlue;//TColor::GetColorPalette(2*254/nColors);
int color4 = kGreen + 1;//TColor::GetColorPalette(3*254/nColors);
int color5 = kViolet;//TColor::GetColorPalette(4*254/nColors);
int color6 = kOrange;//TColor::GetColorPalette(5*254/nColors);
int color7 = kCyan+1;

histTT->SetFillColor(color2);
histTT->SetLineColor(color2);
histZj->SetFillColor(color4);
histZj->SetLineColor(color4);
histWj->SetFillColor(color3);
histWj->SetLineColor(color3);

histWW->SetFillColor(color5);
histWW->SetLineColor(color5);
histWZ->SetFillColor(color5);
histWZ->SetLineColor(color5);
histZZ->SetFillColor(color5);
histZZ->SetLineColor(color5);

histTTW->SetFillColor(color6);
histTTW->SetLineColor(color6);
histTTZ->SetFillColor(color6);
histTTZ->SetLineColor(color6);
histTTTT->SetFillColor(color6);
histTTTT->SetLineColor(color6);
histHWW->SetFillColor(color7);
histHWW->SetLineColor(color7);
histHbb->SetFillColor(color7);
histHbb->SetLineColor(color7);
histWplusH->SetFillColor(color7);
histWplusH->SetLineColor(color7);

histQCD_1->SetFillColor(color1);
histQCD_0->SetFillColor(kMagenta);
histQCD_2->SetFillColor(color1);
histQCD_3->SetFillColor(color1);
histQCD_4->SetFillColor(color1);
histQCD_5->SetFillColor(color1);
histQCD_6->SetFillColor(color1);
histQCD_7->SetFillColor(color1);
histQCD_8->SetFillColor(color1);
histQCD_9->SetFillColor(color1);
histQCD_1->SetLineColor(color1);
histQCD_0->SetLineColor(kMagenta);
histQCD_2->SetLineColor(color1);
histQCD_3->SetLineColor(color1);
histQCD_4->SetLineColor(color1);
histQCD_5->SetLineColor(color1);
histQCD_6->SetLineColor(color1);
histQCD_7->SetLineColor(color1);
histQCD_8->SetLineColor(color1);
histQCD_9->SetLineColor(color1);

histQCDB_0->SetLineColor(color7+3);
histQCDB_0->SetFillColor(color7+3);
histQCDB_1->SetLineColor(color7+3);
histQCDB_1->SetFillColor(color7+3);
histQCDB_2->SetLineColor(color7+3);
histQCDB_2->SetFillColor(color7+3);
histQCDB_3->SetLineColor(color7+3);
histQCDB_3->SetFillColor(color7+3);

float totQCD =  histQCD_0->Integral() + histQCD_1->Integral() + histQCD_2->Integral() + histQCD_3->Integral() + histQCD_4->Integral() + histQCD_5->Integral() + histQCD_6->Integral() + histQCD_7->Integral() + histQCD_8->Integral() + histQCD_9->Integral();
float totDATA = histDATA->Integral() - histTT->Integral() - histWj->Integral() - histZj->Integral() - histWW->Integral() - histZZ->Integral() - histWZ->Integral() - histTTW->Integral() - histTTZ->Integral() - histTTTT->Integral()- histQCDB_0->Integral() - histQCDB_1->Integral() + histQCDB_2->Integral() + histQCDB_3->Integral();


cout << "QCD0 Integral = " << histQCD_0->Integral() << endl;
cout << "QCD1 Integral = " << histQCD_1->Integral() << endl;
cout << "QCD2 Integral = " << histQCD_2->Integral() << endl;
cout << "QCD3 Integral = " << histQCD_3->Integral() << endl;
cout << "QCD4 Integral = " << histQCD_4->Integral() << endl;
cout << "QCD5 Integral = " << histQCD_5->Integral() << endl;
cout << "QCD6 Integral = " << histQCD_6->Integral() << endl;
cout << "QCD7 Integral = " << histQCD_7->Integral() << endl;
cout << "QCD8 Integral = " << histQCD_8->Integral() << endl;
cout << "QCD9 Integral = " << histQCD_9->Integral() << endl;
cout << "Scaling QCD by: " << totDATA/totQCD << endl;
histQCD_0->Scale(totDATA / totQCD);
histQCD_1->Scale(totDATA / totQCD);
histQCD_2->Scale(totDATA / totQCD);
histQCD_3->Scale(totDATA / totQCD);
histQCD_4->Scale(totDATA / totQCD);
histQCD_5->Scale(totDATA / totQCD);
histQCD_6->Scale(totDATA / totQCD);
histQCD_7->Scale(totDATA / totQCD);
histQCD_8->Scale(totDATA / totQCD);
histQCD_9->Scale(totDATA / totQCD);
/*histQCD_0->Scale(0.36);
histQCD_1->Scale(0.36);
histQCD_2->Scale(0.36);
histQCD_3->Scale(0.36);
histQCD_4->Scale(0.36);
histQCD_5->Scale(0.36);
histQCD_6->Scale(0.36);
histQCD_7->Scale(0.36);
histQCD_8->Scale(0.36);
*/




histDATA->SetMarkerStyle(21);
histDATA->SetMarkerSize(0.8);

THStack *stack = new THStack("stack", "stack");

//TFile *sampledF = new TFile("sampled_shapes_1.root", "READ");
//histQCD_sampled = (TH1F *) sampledF->Get("outHT");
//histQCD_sampled->SetLineColor(kYellow+1);
//histQCD_sampled->SetFillColor(kYellow+1);
//histQCD_sampled->Scale(totQCD / histQCD_sampled->Integral() );
stack->Add(histWW);
stack->Add(histZZ);
stack->Add(histWZ);
stack->Add(histTTW);
stack->Add(histTTZ);
stack->Add(histTTTT);
stack->Add(histHbb);
stack->Add(histHWW);
stack->Add(histWplusH);
stack->Add(histZj);
stack->Add(histWj);
stack->Add(histTT);
stack->Add(histQCD_0);
stack->Add(histQCD_1);
stack->Add(histQCD_2);
stack->Add(histQCD_3);
stack->Add(histQCD_4);
stack->Add(histQCD_5);
stack->Add(histQCD_6);
stack->Add(histQCD_7);
stack->Add(histQCD_8);
stack->Add(histQCD_9);
//stack->Add(histQCDB_0);
//stack->Add(histQCDB_1);
//stack->Add(histQCDB_2);
//stack->Add(histQCDB_3);
//stack->Add(histQCD_sampled);
histDATA->Draw("axis");
histDATA->GetXaxis()->SetTitleFont(42);
histDATA->GetYaxis()->SetTitleFont(42);
histDATA->GetXaxis()->SetLabelFont(42);
histDATA->GetYaxis()->SetLabelFont(42);
histDATA->GetXaxis()->SetLabelSize(0.05);
histDATA->GetYaxis()->SetLabelSize(0.05);
histDATA->GetXaxis()->SetTitleSize(0.05);
histDATA->GetYaxis()->SetTitleSize(0.05);
histDATA->GetXaxis()->SetBinLabel(1, "j");
histDATA->GetXaxis()->SetBinLabel(2, "W");
histDATA->GetXaxis()->SetBinLabel(3, "Z");
histDATA->GetXaxis()->SetBinLabel(4, "H");
histDATA->GetXaxis()->SetBinLabel(5, "t");
histDATA->GetXaxis()->SetBinLabel(6, "b");


TH1F *totalH = (TH1F *) histQCD_1->Clone("totalH");
totalH->Sumw2();
totalH->Add(histQCD_0);
totalH->Add(histQCD_2);
totalH->Add(histQCD_3);
totalH->Add(histQCD_4);
totalH->Add(histQCD_5);
totalH->Add(histQCD_6);
totalH->Add(histQCD_7);
totalH->Add(histQCD_8);
totalH->Add(histQCD_9);
totalH->Add(histQCDB_0);
totalH->Add(histQCDB_1);
totalH->Add(histQCDB_2);
totalH->Add(histQCDB_3);
totalH->Add(histTT);
totalH->Add(histWj);
totalH->Add(histWW);
totalH->Add(histWZ);
totalH->Add(histZZ);
totalH->Add(histTTW);
totalH->Add(histTTZ);
totalH->Add(histTTTT);
totalH->Add(histZj);
totalH->Add(histHbb);
totalH->Add(histHWW);
totalH->Add(histWplusH);




histDATA->SetMaximum( 1.5 * (1+histDATA->GetMaximum()) );
histDATA->SetMinimum( 0.02 );
histDATA->GetXaxis()->SetTitle( label.c_str() );
histDATA->GetYaxis()->SetTitle( "Jets" );
histDATA->Draw("axis");
stack->Draw("hist same");
totalH->SetFillColor(16);
totalH->SetFillStyle(3244);
totalH->Draw("E2 same");
histDATA->Draw("E same");
hist_sig1->Draw("hist same");
hist_sig2->Draw("hist same");
hist_sig3->Draw("hist same");
//hist_sig4->Draw("same");


//gPad->RedrawAxis();
TH1F *hist_totQCD = (TH1F *) histQCD_1->Clone("hist_totQCD");
hist_totQCD->Add(histQCD_0);
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


TH1F *ratioMCH = new TH1F();
ratioMCH = (TH1F*) totalH->Clone("ratioMCH");
ratioMCH->Divide(ratioMCH, totalH, 1, 1);


TLegend *leg = new TLegend(0.46,0.61,0.92,0.86,"");
leg->SetNColumns(2);
leg->SetFillColor(0);
leg->SetLineColor(0);
leg->SetTextFont(42);
//leg->AddEntry(histDATA, Form("%s", legLabel.c_str()), "");
//leg->AddEntry(histDATA, "== 4 Jets", "");
leg->AddEntry(histDATA, "Data", "p");
leg->AddEntry(histQCD_1   ,  "Multijet (Sim.)","f");
//leg->AddEntry(histQCD_1   ,  Form("QCD (x%1.3f)", totDATA/totQCD),"f");
leg->AddEntry(histTT     , "t#bar{t}+jets" ,"f");
leg->AddEntry(histWj    , "W+jets","f");
leg->AddEntry(histZj      , "Z+jets","f");
leg->AddEntry(histHbb      , "H","f");
leg->AddEntry(histTTW, "t#bar{t}V+t#bar{t}t#bar{t}", "f");
leg->AddEntry(histWW, "VV", "f");
leg->AddEntry(hist_sig1, "TT (0.8 TeV)", "l");
//leg->AddEntry(hist_sig1000, "TT (1.0 TeV)", "l");
leg->AddEntry(hist_sig2, "TT (1.2 TeV)", "l");
//leg->AddEntry(hist_sig1400, "TT (1.4 TeV)", "l");
leg->AddEntry(hist_sig3, "TT (1.6 TeV)", "l");
//leg->AddEntry(hist_sig1800, "TT (1.8 TeV)", "l");

leg->Draw("same");

gPad->SetTickx(1);
gPad->SetTicky(1);
gPad->RedrawAxis();

CMS_lumi(c1_2, 4, 0);



c1_1->cd();
c1_1->SetTopMargin(0.05);
        c1_1->SetBottomMargin(0.42);
        c1_1->SetRightMargin(0.05);
        c1_1->SetLeftMargin(0.1);
        c1_1->SetFillStyle(0);
ratioH->Draw();
ratioH->GetYaxis()->SetRangeUser(0.,2.);
        ratioH->GetYaxis()->SetTitle("Data / BG Ratio");
        ratioH->GetYaxis()->SetTitleOffset(0.4);
        ratioH->GetXaxis()->SetLabelOffset(0.05);
        ratioH->GetYaxis()->SetTitleSize(0.1);
        ratioH->GetYaxis()->SetLabelSize(0.1);
        ratioH->GetXaxis()->SetLabelSize(0.25);
        ratioH->GetXaxis()->SetTitleSize(0.2);
	ratioH->GetXaxis()->SetLabelFont(42);
	ratioH->GetYaxis()->SetLabelFont(42);
	ratioH->GetXaxis()->SetTitleFont(42);
	ratioH->GetYaxis()->SetTitleFont(42);
ratioH->GetYaxis()->SetNdivisions(4, kFALSE);

ratioMCH->SetFillColor(16);
ratioMCH->SetFillStyle(1001);
ratioMCH->Draw("E2 same");
ratioH->Draw("E same");


TF1 *line = new TF1("line", "1", -100000, 100000);
        line->SetLineColor(kBlack);
	line->SetLineWidth(1);
        line->Draw("same");
        
        gPad->RedrawAxis();

gPad->SetTickx(1);
gPad->SetTicky(1);
gPad->RedrawAxis();
c1_2->cd();


c1->SaveAs( Form( "testmay16/%s.pdf", filename.c_str() ) );

gPad->SetLogy(1);

histDATA->SetMaximum( 10000 * histDATA->GetMaximum() );
c1_2->Update();
c1->SaveAs( Form( "testmay16/%s_log.pdf", filename.c_str() ) );

//TCanvas *c2 = new TCanvas("c2", "c2");
//c2->cd();
//drawROC(hist_sig4, hist_totQCD, 1, totNumTT, totNumQCD);

TFile *outFile = new TFile(Form("%s_histos.root", channel.c_str()), "RECREATE");
outFile->cd();

hist_totQCD->Write(Form("%s__qcd", channel.c_str()));
histTT->Write(Form("%s__ttbar", channel.c_str()));
//hist_sig1->Write(Form("%s__tprime1000", channel.c_str()));
//hist_sig2->Write(Form("%s__tprime1400", channel.c_str()));
//hist_sig3->Write(Form("%s__tprime1800", channel.c_str()));
//hist_sig4->Write(Form("%s__zprime4", channel.c_str()));
outFile->Close();

fileQCD_1->Close();
fileQCD_2->Close();
fileQCD_3->Close();
fileQCD_4->Close();
fileQCD_5->Close();
fileQCD_6->Close();
fileQCD_7->Close();
fileQCD_8->Close();
fileQCD_9->Close();
fileTT->Close();
//fileWj->Close();
//fileZj->Close();
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


