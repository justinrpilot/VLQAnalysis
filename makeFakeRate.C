#include "CMS_lumi.C"



void drawRate(string var, string Xlabel, string Ylabel, string selDen, string selNum, int nbins, float xmin, float xmax, string filename, string channel){



TFile *fileQCD_1 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd1.root", "READ");
TFile *fileQCD_2 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd2.root", "READ");
TFile *fileQCD_3 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd3.root", "READ");
TFile *fileQCD_4 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd4.root", "READ");
TFile *fileQCD_5 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd5.root", "READ");
TFile *fileQCD_6 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd6.root", "READ");
TFile *fileQCD_7 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd7.root", "READ");
TFile *fileQCD_8 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd8.root", "READ");
TFile *fileQCD_9 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_qcd9.root", "READ");

TTree *treeQCD_1 = (TTree *) fileQCD_1->Get("eventVars");
TTree *treeQCD_2 = (TTree *) fileQCD_2->Get("eventVars");
TTree *treeQCD_3 = (TTree *) fileQCD_3->Get("eventVars");
TTree *treeQCD_4 = (TTree *) fileQCD_4->Get("eventVars");
TTree *treeQCD_5 = (TTree *) fileQCD_5->Get("eventVars");
TTree *treeQCD_6 = (TTree *) fileQCD_6->Get("eventVars");
TTree *treeQCD_7 = (TTree *) fileQCD_7->Get("eventVars");
TTree *treeQCD_8 = (TTree *) fileQCD_8->Get("eventVars");
TTree *treeQCD_9 = (TTree *) fileQCD_9->Get("eventVars");

int nBins = 11;
double bins[12] = {400, 500, 600, 700, 800, 900, 1000, 1200, 1400, 2000, 3000, 4000};

TH1D *histNumQCD_1 = new TH1D("histNumQCD_1", "histNumQCD_1", nBins, bins);
TH1D *histNumQCD_2 = new TH1D("histNumQCD_2", "histNumQCD_2", nBins, bins);
TH1D *histNumQCD_3 = new TH1D("histNumQCD_3", "histNumQCD_3", nBins, bins);
TH1D *histNumQCD_4 = new TH1D("histNumQCD_4", "histNumQCD_4", nBins, bins);
TH1D *histNumQCD_5 = new TH1D("histNumQCD_5", "histNumQCD_5", nBins, bins);
TH1D *histNumQCD_6 = new TH1D("histNumQCD_6", "histNumQCD_6", nBins, bins);
TH1D *histNumQCD_7 = new TH1D("histNumQCD_7", "histNumQCD_7", nBins, bins);
TH1D *histNumQCD_8 = new TH1D("histNumQCD_8", "histNumQCD_8", nBins, bins);
TH1D *histNumQCD_9 = new TH1D("histNumQCD_9", "histNumQCD_9", nBins, bins);

TH1D *histDenQCD_1 = new TH1D("histDenQCD_1", "histDenQCD_1", nBins, bins);
TH1D *histDenQCD_2 = new TH1D("histDenQCD_2", "histDenQCD_2", nBins, bins);
TH1D *histDenQCD_3 = new TH1D("histDenQCD_3", "histDenQCD_3", nBins, bins);
TH1D *histDenQCD_4 = new TH1D("histDenQCD_4", "histDenQCD_4", nBins, bins);
TH1D *histDenQCD_5 = new TH1D("histDenQCD_5", "histDenQCD_5", nBins, bins);
TH1D *histDenQCD_6 = new TH1D("histDenQCD_6", "histDenQCD_6", nBins, bins);
TH1D *histDenQCD_7 = new TH1D("histDenQCD_7", "histDenQCD_7", nBins, bins);
TH1D *histDenQCD_8 = new TH1D("histDenQCD_8", "histDenQCD_8", nBins, bins);
TH1D *histDenQCD_9 = new TH1D("histDenQCD_9", "histDenQCD_9", nBins, bins);

treeQCD_1->Draw( Form( "%s >> histNumQCD_1", var.c_str() ), selNum.c_str() );
treeQCD_2->Draw( Form( "%s >> histNumQCD_2", var.c_str() ), selNum.c_str() );
treeQCD_3->Draw( Form( "%s >> histNumQCD_3", var.c_str() ), selNum.c_str() );
treeQCD_4->Draw( Form( "%s >> histNumQCD_4", var.c_str() ), selNum.c_str() );
treeQCD_5->Draw( Form( "%s >> histNumQCD_5", var.c_str() ), selNum.c_str() );
treeQCD_6->Draw( Form( "%s >> histNumQCD_6", var.c_str() ), selNum.c_str() );
treeQCD_7->Draw( Form( "%s >> histNumQCD_7", var.c_str() ), selNum.c_str() );
treeQCD_8->Draw( Form( "%s >> histNumQCD_8", var.c_str() ), selNum.c_str() );
treeQCD_9->Draw( Form( "%s >> histNumQCD_9", var.c_str() ), selNum.c_str() );

treeQCD_1->Draw( Form( "%s >> histDenQCD_1", var.c_str() ), selDen.c_str() );
treeQCD_2->Draw( Form( "%s >> histDenQCD_2", var.c_str() ), selDen.c_str() );
treeQCD_3->Draw( Form( "%s >> histDenQCD_3", var.c_str() ), selDen.c_str() );
treeQCD_4->Draw( Form( "%s >> histDenQCD_4", var.c_str() ), selDen.c_str() );
treeQCD_5->Draw( Form( "%s >> histDenQCD_5", var.c_str() ), selDen.c_str() );
treeQCD_6->Draw( Form( "%s >> histDenQCD_6", var.c_str() ), selDen.c_str() );
treeQCD_7->Draw( Form( "%s >> histDenQCD_7", var.c_str() ), selDen.c_str() );
treeQCD_8->Draw( Form( "%s >> histDenQCD_8", var.c_str() ), selDen.c_str() );
treeQCD_9->Draw( Form( "%s >> histDenQCD_9", var.c_str() ), selDen.c_str() );




float lumi = 35289.97;//8529.407;

histNumQCD_1->Scale( 7823.0 * lumi / 5970600.);
histNumQCD_2->Scale(  648.2 * lumi / 3928870.);
histNumQCD_3->Scale(  186.9 * lumi / 3959768.);
histNumQCD_4->Scale(  32.29 * lumi / 3924080.);
histNumQCD_5->Scale(  9.418 * lumi / 2999069.);
histNumQCD_6->Scale(  0.84265 * lumi / 396409.);
histNumQCD_7->Scale(  0.114943 * lumi / 396100.);
histNumQCD_8->Scale(  0.0068291 * lumi / 399226.);
histNumQCD_9->Scale(  0.0001654 * lumi / 383926.);

histDenQCD_1->Scale( 7823.0 * lumi / 5970600.);
histDenQCD_2->Scale(  648.2 * lumi / 3928870.);
histDenQCD_3->Scale(  186.9 * lumi / 3959768.);
histDenQCD_4->Scale(  32.29 * lumi / 3924080.);
histDenQCD_5->Scale(  9.418 * lumi / 2999069.);
histDenQCD_6->Scale(  0.84265 * lumi / 396409.);
histDenQCD_7->Scale(  0.114943 * lumi / 396100.);
histDenQCD_8->Scale(  0.0068291 * lumi / 399226.);
histDenQCD_9->Scale(  0.0001654 * lumi / 383926.);

TH1F *histTotNum = (TH1F *) histNumQCD_1->Clone("histTotNum");
TH1F *histTotDen = (TH1F *) histDenQCD_1->Clone("histTotDen");
histTotNum->Sumw2();
histTotDen->Sumw2();

histTotNum->Add(histNumQCD_2);
histTotNum->Add(histNumQCD_3);
histTotNum->Add(histNumQCD_4);
histTotNum->Add(histNumQCD_5);
histTotNum->Add(histNumQCD_6);
histTotNum->Add(histNumQCD_7);
histTotNum->Add(histNumQCD_8);
histTotNum->Add(histNumQCD_9);
histTotDen->Add(histDenQCD_2);
histTotDen->Add(histDenQCD_3);
histTotDen->Add(histDenQCD_4);
histTotDen->Add(histDenQCD_5);
histTotDen->Add(histDenQCD_6);
histTotDen->Add(histDenQCD_7);
histTotDen->Add(histDenQCD_8);
histTotDen->Add(histDenQCD_9);

//histTotNum->Divide(histTotNum, histTotDen, 1, 1, "B");

cout << histTotNum->GetEntries() << endl;
histTotNum->GetXaxis()->SetTitle( Xlabel.c_str() );
histTotNum->GetYaxis()->SetTitle( Ylabel.c_str() );
histTotNum->Draw("E");

gPad->SetLogy(1);


TFile *outFile = new TFile(Form("%s_rates.root", filename.c_str()), "RECREATE");
outFile->cd();

histTotNum->Write( Form("%s_num", channel.c_str()) );
histTotDen->Write( Form("%s_den", channel.c_str()) );

outFile->Close();

}


