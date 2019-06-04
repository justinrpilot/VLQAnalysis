

void combineRates(string label){

TFile *inFile_j0 = new TFile(Form("%s_rate_j0_rates_DATA.root", label.c_str()));
TFile *inFile_j1 = new TFile(Form("%s_rate_j1_rates_DATA.root", label.c_str()));
TFile *inFile_j2 = new TFile(Form("%s_rate_j2_rates_DATA.root", label.c_str()));
//TFile *inFile_j3 = new TFile(Form("%s_rate_j3_rates_DATA.root", label.c_str()));


TH1F *num_j0 = (TH1F *) inFile_j0->Get(Form("%s_j0_num", label.c_str()));
TH1F *num_j1 = (TH1F *) inFile_j1->Get(Form("%s_j1_num", label.c_str()));
TH1F *num_j2 = (TH1F *) inFile_j2->Get(Form("%s_j2_num", label.c_str()));
//TH1F *num_j3 = (TH1F *) inFile_j3->Get(Form("%s_j3_num", label.c_str()));

TH1F *den_j0 = (TH1F *) inFile_j0->Get(Form("%s_j0_den", label.c_str()));
TH1F *den_j1 = (TH1F *) inFile_j1->Get(Form("%s_j1_den", label.c_str()));
TH1F *den_j2 = (TH1F *) inFile_j2->Get(Form("%s_j2_den", label.c_str()));
//TH1F *den_j3 = (TH1F *) inFile_j3->Get(Form("%s_j3_den", label.c_str()));

num_j0->Sumw2();
num_j1->Sumw2();
num_j2->Sumw2();
//num_j3->Sumw2();
den_j0->Sumw2();
den_j1->Sumw2();
den_j2->Sumw2();
//den_j3->Sumw2();

num_j0->Add(num_j1);
num_j0->Add(num_j2);
//num_j0->Add(num_j3);

den_j0->Add(den_j1);
den_j0->Add(den_j2);
//den_j0->Add(den_j3);

num_j0->Divide(num_j0, den_j0, 1, 1, "B");


num_j0->Draw();

TFile *outFile = new TFile(Form("%s_combinedRatesData.root", label.c_str()), "RECREATE");

num_j0->Write( Form("%s_rate", label.c_str()) );
outFile->Write();
outFile->Close();

}
