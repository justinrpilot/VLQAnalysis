void drawEfficiency(string p){

TFile *f1 = new TFile(Form("num%s_histos.root", p.c_str()));
TFile *f2 = new TFile("denom_histos.root");

TH1F *numH = (TH1F*) f1->Get(Form("num%s__qcd",p.c_str()));
TH1F *denomH = (TH1F*) f2->Get("denom__qcd");

TH1F *effH = (TH1F *) numH->Clone("eff");
effH->Divide(numH, denomH, 1, 1, "B");

effH->Draw();

}
