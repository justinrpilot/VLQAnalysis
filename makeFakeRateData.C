#include "CMS_lumi.C"



void drawRate(string var, string Xlabel, string Ylabel, string selDen, string selNum, int nbins, float xmin, float xmax, string filename, string channel){



TFile *fileDATA_1 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataB.root", "READ");
TFile *fileDATA_2 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataC.root", "READ");
TFile *fileDATA_3 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataD.root", "READ");
TFile *fileDATA_4 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataE.root", "READ");
TFile *fileDATA_5 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataF.root", "READ");
TFile *fileDATA_6 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataG.root", "READ");
TFile *fileDATA_7 = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_dataH.root", "READ");

TTree *treeDATA_1 = (TTree *) fileDATA_1->Get("eventVars");
TTree *treeDATA_2 = (TTree *) fileDATA_2->Get("eventVars");
TTree *treeDATA_3 = (TTree *) fileDATA_3->Get("eventVars");
TTree *treeDATA_4 = (TTree *) fileDATA_4->Get("eventVars");
TTree *treeDATA_5 = (TTree *) fileDATA_5->Get("eventVars");
TTree *treeDATA_6 = (TTree *) fileDATA_6->Get("eventVars");
TTree *treeDATA_7 = (TTree *) fileDATA_7->Get("eventVars");

int nBins = 10;
double bins[11] = {400, 500, 600, 700, 800, 900, 1000, 1200, 1400, 2000, 3000};

TH1D *histNumDATA_1 = new TH1D("histNumDATA_1", "histNumDATA_1", nBins, bins);
TH1D *histNumDATA_2 = new TH1D("histNumDATA_2", "histNumDATA_2", nBins, bins);
TH1D *histNumDATA_3 = new TH1D("histNumDATA_3", "histNumDATA_3", nBins, bins);
TH1D *histNumDATA_4 = new TH1D("histNumDATA_4", "histNumDATA_4", nBins, bins);
TH1D *histNumDATA_5 = new TH1D("histNumDATA_5", "histNumDATA_5", nBins, bins);
TH1D *histNumDATA_6 = new TH1D("histNumDATA_6", "histNumDATA_6", nBins, bins);
TH1D *histNumDATA_7 = new TH1D("histNumDATA_7", "histNumDATA_7", nBins, bins);

TH1D *histDenDATA_1 = new TH1D("histDenDATA_1", "histDenDATA_1", nBins, bins);
TH1D *histDenDATA_2 = new TH1D("histDenDATA_2", "histDenDATA_2", nBins, bins);
TH1D *histDenDATA_3 = new TH1D("histDenDATA_3", "histDenDATA_3", nBins, bins);
TH1D *histDenDATA_4 = new TH1D("histDenDATA_4", "histDenDATA_4", nBins, bins);
TH1D *histDenDATA_5 = new TH1D("histDenDATA_5", "histDenDATA_5", nBins, bins);
TH1D *histDenDATA_6 = new TH1D("histDenDATA_6", "histDenDATA_6", nBins, bins);
TH1D *histDenDATA_7 = new TH1D("histDenDATA_7", "histDenDATA_7", nBins, bins);

treeDATA_1->Draw( Form( "%s >> histNumDATA_1", var.c_str() ), selNum.c_str() );
treeDATA_2->Draw( Form( "%s >> histNumDATA_2", var.c_str() ), selNum.c_str() );
treeDATA_3->Draw( Form( "%s >> histNumDATA_3", var.c_str() ), selNum.c_str() );
treeDATA_4->Draw( Form( "%s >> histNumDATA_4", var.c_str() ), selNum.c_str() );
treeDATA_5->Draw( Form( "%s >> histNumDATA_5", var.c_str() ), selNum.c_str() );
treeDATA_6->Draw( Form( "%s >> histNumDATA_6", var.c_str() ), selNum.c_str() );
treeDATA_7->Draw( Form( "%s >> histNumDATA_7", var.c_str() ), selNum.c_str() );

treeDATA_1->Draw( Form( "%s >> histDenDATA_1", var.c_str() ), selDen.c_str() );
treeDATA_2->Draw( Form( "%s >> histDenDATA_2", var.c_str() ), selDen.c_str() );
treeDATA_3->Draw( Form( "%s >> histDenDATA_3", var.c_str() ), selDen.c_str() );
treeDATA_4->Draw( Form( "%s >> histDenDATA_4", var.c_str() ), selDen.c_str() );
treeDATA_5->Draw( Form( "%s >> histDenDATA_5", var.c_str() ), selDen.c_str() );
treeDATA_6->Draw( Form( "%s >> histDenDATA_6", var.c_str() ), selDen.c_str() );
treeDATA_7->Draw( Form( "%s >> histDenDATA_7", var.c_str() ), selDen.c_str() );


TH1F *histTotNum = (TH1F *) histNumDATA_1->Clone("histTotNum");
TH1F *histTotDen = (TH1F *) histDenDATA_1->Clone("histTotDen");
histTotNum->Sumw2();
histTotDen->Sumw2();

histTotNum->Add(histNumDATA_2);
histTotNum->Add(histNumDATA_3);
histTotNum->Add(histNumDATA_4);
histTotNum->Add(histNumDATA_5);
histTotNum->Add(histNumDATA_6);
histTotNum->Add(histNumDATA_7);
histTotDen->Add(histDenDATA_2);
histTotDen->Add(histDenDATA_3);
histTotDen->Add(histDenDATA_4);
histTotDen->Add(histDenDATA_5);
histTotDen->Add(histDenDATA_6);
histTotDen->Add(histDenDATA_7);

//histTotNum->Divide(histTotNum, histTotDen, 1, 1, "B");

cout << histTotNum->GetEntries() << endl;
histTotNum->GetXaxis()->SetTitle( Xlabel.c_str() );
histTotNum->GetYaxis()->SetTitle( Ylabel.c_str() );
histTotNum->Draw("E");

gPad->SetLogy(1);


TFile *outFile = new TFile(Form("%s_rates_DATA.root", filename.c_str()), "RECREATE");
outFile->cd();

//histTotNum->Write( Form("%s_rate", channel.c_str()) );


histTotNum->Write( Form("%s_num", channel.c_str()) );
histTotDen->Write( Form("%s_den", channel.c_str()) );

outFile->Close();

}


