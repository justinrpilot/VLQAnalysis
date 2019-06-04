TH1D* combineQCDhist(string hist_name);

void combineQCD(){

TFile *outfile = new TFile("jetPt_templates.root", "RECREATE");

string names[] = {
"h_jet0pt_notag",
"h_jet0pt_Ttag",
"h_jet0pt_Wtag",
"h_jet0pt_Ztag",
"h_jet0pt_Htag",
"h_jet1pt_notag_1",
"h_jet1pt_notag_2",
"h_jet1pt_notag_3",
"h_jet1pt_notag_4",
"h_jet1pt_notag_5",
"h_jet1pt_notag_6",
"h_jet1pt_notag_7",
"h_jet1pt_notag_8",
"h_jet1pt_Ttag_1",
"h_jet1pt_Ttag_2",
"h_jet1pt_Ttag_3",
"h_jet1pt_Ttag_4",
"h_jet1pt_Ttag_5",
"h_jet1pt_Ttag_6",
"h_jet1pt_Ttag_7",
"h_jet1pt_Ttag_8",
"h_jet1pt_Wtag_1",
"h_jet1pt_Wtag_2",
"h_jet1pt_Wtag_3",
"h_jet1pt_Wtag_4",
"h_jet1pt_Wtag_5",
"h_jet1pt_Wtag_6",
"h_jet1pt_Wtag_7",
"h_jet1pt_Wtag_8",
"h_jet1pt_Ztag_1",
"h_jet1pt_Ztag_2",
"h_jet1pt_Ztag_3",
"h_jet1pt_Ztag_4",
"h_jet1pt_Ztag_5",
"h_jet1pt_Ztag_6",
"h_jet1pt_Ztag_7",
"h_jet1pt_Ztag_8",
"h_jet1pt_Htag_1",
"h_jet1pt_Htag_2",
"h_jet1pt_Htag_3",
"h_jet1pt_Htag_4",
"h_jet1pt_Htag_5",
"h_jet1pt_Htag_6",
"h_jet1pt_Htag_7",
"h_jet1pt_Htag_8",
"h_jet2pt_notag_1",
"h_jet2pt_notag_2",
"h_jet2pt_notag_3",
"h_jet2pt_notag_4",
"h_jet2pt_notag_5",
"h_jet2pt_notag_6",
"h_jet2pt_notag_7",
"h_jet2pt_notag_8",
"h_jet2pt_Ttag_1",
"h_jet2pt_Ttag_2",
"h_jet2pt_Ttag_3",
"h_jet2pt_Ttag_4",
"h_jet2pt_Ttag_5",
"h_jet2pt_Ttag_6",
"h_jet2pt_Ttag_7",
"h_jet2pt_Ttag_8",
"h_jet2pt_Wtag_1",
"h_jet2pt_Wtag_2",
"h_jet2pt_Wtag_3",
"h_jet2pt_Wtag_4",
"h_jet2pt_Wtag_5",
"h_jet2pt_Wtag_6",
"h_jet2pt_Wtag_7",
"h_jet2pt_Wtag_8",
"h_jet2pt_Ztag_1",
"h_jet2pt_Ztag_2",
"h_jet2pt_Ztag_3",
"h_jet2pt_Ztag_4",
"h_jet2pt_Ztag_5",
"h_jet2pt_Ztag_6",
"h_jet2pt_Ztag_7",
"h_jet2pt_Ztag_8",
"h_jet2pt_Htag_1",
"h_jet2pt_Htag_2",
"h_jet2pt_Htag_3",
"h_jet2pt_Htag_4",
"h_jet2pt_Htag_5",
"h_jet2pt_Htag_6",
"h_jet2pt_Htag_7",
"h_jet2pt_Htag_8",
"h_jet3pt_notag_1",
"h_jet3pt_notag_2",
"h_jet3pt_notag_3",
"h_jet3pt_notag_4",
"h_jet3pt_notag_5",
"h_jet3pt_notag_6",
"h_jet3pt_notag_7",
"h_jet3pt_notag_8",
"h_jet3pt_Ttag_1",
"h_jet3pt_Ttag_2",
"h_jet3pt_Ttag_3",
"h_jet3pt_Ttag_4",
"h_jet3pt_Ttag_5",
"h_jet3pt_Ttag_6",
"h_jet3pt_Ttag_7",
"h_jet3pt_Ttag_8",
"h_jet3pt_Wtag_1",
"h_jet3pt_Wtag_2",
"h_jet3pt_Wtag_3",
"h_jet3pt_Wtag_4",
"h_jet3pt_Wtag_5",
"h_jet3pt_Wtag_6",
"h_jet3pt_Wtag_7",
"h_jet3pt_Wtag_8",
"h_jet3pt_Ztag_1",
"h_jet3pt_Ztag_2",
"h_jet3pt_Ztag_3",
"h_jet3pt_Ztag_4",
"h_jet3pt_Ztag_5",
"h_jet3pt_Ztag_6",
"h_jet3pt_Ztag_7",
"h_jet3pt_Ztag_8",
"h_jet3pt_Htag_1",
"h_jet3pt_Htag_2",
"h_jet3pt_Htag_3",
"h_jet3pt_Htag_4",
"h_jet3pt_Htag_5",
"h_jet3pt_Htag_6",
"h_jet3pt_Htag_7",
"h_jet3pt_Htag_8",
"h_topTagIndex",
"h_WTagIndex",
"h_ZTagIndex",
"h_HTagIndex",
};


for (size_t i = 0; i < 129 ; i++){
	TH1D *hist = combineQCDhist(names[i].c_str());
	outfile->cd();
	//hist->Rebin(10);
	(*hist).Write();
}
outfile->Write();
outfile->Close();


}



TH1D* combineQCDhist(string hist_name){

cout << hist_name.c_str() << endl;

TFile *fileQCD_1 = new TFile("outplots_qcd1.root", "READ");
TFile *fileQCD_2 = new TFile("outplots_qcd2.root", "READ");
TFile *fileQCD_3 = new TFile("outplots_qcd3.root", "READ");
TFile *fileQCD_4 = new TFile("outplots_qcd4.root", "READ");
TFile *fileQCD_5 = new TFile("outplots_qcd5.root", "READ");
TFile *fileQCD_6 = new TFile("outplots_qcd6.root", "READ");
TFile *fileQCD_7 = new TFile("outplots_qcd7.root", "READ");
TFile *fileQCD_8 = new TFile("outplots_qcd8.root", "READ");
TFile *fileQCD_9 = new TFile("outplots_qcd9.root", "READ");


TH1D *histQCD_1 = (TH1D *) fileQCD_1->Get(hist_name.c_str());
TH1D *histQCD_2 = (TH1D *) fileQCD_2->Get(hist_name.c_str());
TH1D *histQCD_3 = (TH1D *) fileQCD_3->Get(hist_name.c_str());
TH1D *histQCD_4 = (TH1D *) fileQCD_4->Get(hist_name.c_str());
TH1D *histQCD_5 = (TH1D *) fileQCD_5->Get(hist_name.c_str());
TH1D *histQCD_6 = (TH1D *) fileQCD_6->Get(hist_name.c_str());
TH1D *histQCD_7 = (TH1D *) fileQCD_7->Get(hist_name.c_str());
TH1D *histQCD_8 = (TH1D *) fileQCD_8->Get(hist_name.c_str());
TH1D *histQCD_9 = (TH1D *) fileQCD_9->Get(hist_name.c_str());


float lumi = 36000.;

histQCD_1->Scale( 7823.0 * lumi / 5970600.);
histQCD_2->Scale(  648.2 * lumi / 3928870.);
histQCD_3->Scale(  186.9 * lumi / 3959768.);
histQCD_4->Scale(  32.29 * lumi / 3924080.);
histQCD_5->Scale(  9.418 * lumi / 2999069.);
histQCD_6->Scale(  0.84265 * lumi / 396409.);
histQCD_7->Scale(  0.114943 * lumi / 396100.);
histQCD_8->Scale(  0.0068291 * lumi / 399226.);
histQCD_9->Scale(  0.0001654 * lumi / 383926.);


TH1D *totalH = (TH1D *) histQCD_2->Clone("totalH");
//totalH->Add(histQCD_2);
totalH->Add(histQCD_3);
totalH->Add(histQCD_4);
totalH->Add(histQCD_5);
totalH->Add(histQCD_6);
totalH->Add(histQCD_7);
totalH->Add(histQCD_8);
totalH->Add(histQCD_9);

totalH->SetName(hist_name.c_str());


fileQCD_1->Close();
fileQCD_2->Close();

return totalH;

}



