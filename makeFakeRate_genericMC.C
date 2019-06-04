#include "CMS_lumi.C"



void drawRate(string var, string Xlabel, string Ylabel, string selDen, string selNum, int nbins, float xmin, float xmax, string filename, string channel){



TFile *fileMC = TFile::Open("root://cmseos.fnal.gov//store/user/pilot/VLQAnaFiles/outplots_zjets.root", "READ");

TTree *treeMC = (TTree *) fileMC->Get("eventVars");

int nBins = 11;
double bins[12] = {400, 500, 600, 700, 800, 900, 1000, 1200, 1400, 2000, 3000, 4000};

TH1D *histNumMC = new TH1D("histNumMC", "histNumMC", nBins, bins);

TH1D *histDenMC = new TH1D("histDenMC", "histDenMC", nBins, bins);

treeMC->Draw( Form( "%s >> histNumMC", var.c_str() ), selNum.c_str() );

treeMC->Draw( Form( "%s >> histDenMC", var.c_str() ), selDen.c_str() );


TH1F *histTotNum = (TH1F *) histNumMC->Clone("histTotNum");
TH1F *histTotDen = (TH1F *) histDenMC->Clone("histTotDen");
histTotNum->Sumw2();
histTotDen->Sumw2();


histTotNum->Divide(histTotNum, histTotDen, 1, 1, "B");

cout << histTotNum->GetEntries() << endl;
histTotNum->GetXaxis()->SetTitle( Xlabel.c_str() );
histTotNum->GetYaxis()->SetTitle( Ylabel.c_str() );
histTotNum->Draw("E");

gPad->SetLogy(1);


TFile *outFile = new TFile(Form("%s_rates_MC.root", filename.c_str()), "RECREATE");
outFile->cd();

histTotNum->Write( Form("%s_rate", channel.c_str()) );
outFile->Close();

}


