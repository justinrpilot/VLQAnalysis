#include "CMS_lumi.C"

void drawBinHist(){

//TFile *infile = new TFile("3jet_binhistos.root", "READ");
TFile *infile = new TFile("~/3DayLifetime/4jet_binhisto.root", "READ");
//TFile *infile = new TFile("testapr2/TT_binhisto.root", "READ");

TH1F *hQCD = (TH1F *) infile->Get("bin__qcd");
TH1F *hTop = (TH1F *) infile->Get("bin__ttbar");
TH1F *hWjets = (TH1F *) infile->Get("bin__wjets");
TH1F *hZjets = (TH1F *) infile->Get("bin__zjets");
TH1F *hVV = (TH1F *) infile->Get("bin__diboson");
TH1F *httV = (TH1F *) infile->Get("bin__ttV");
TH1F *hHiggs = (TH1F *) infile->Get("bin__higgs");
TH1F *hData = (TH1F *) infile->Get("bin__DATA");


TH1F *hSig1 = (TH1F *) infile->Get("bin__tprime800");
TH1F *hSig2 = (TH1F *) infile->Get("bin__tprime1200");
TH1F *hSig3 = (TH1F *) infile->Get("bin__tprime1800");

hQCD->SetFillColor(kAzure-4);
hQCD->SetLineColor(kAzure-4);
hTop->SetFillColor(kRed);
hWjets->SetFillColor(kBlue);
hZjets->SetFillColor(kGreen+1);
hVV->SetFillColor(kViolet);
hVV->SetLineColor(kViolet);
httV->SetFillColor(kOrange);
httV->SetLineColor(kOrange);
hHiggs->SetLineColor(kCyan+1);
hHiggs->SetFillColor(kCyan+1);
hSig1->SetLineColor(kCyan);
hSig2->SetLineColor(kGreen);
hSig3->SetLineColor(kMagenta);

THStack *stack = new THStack("stack", "stack");
stack->Add(hVV);
stack->Add(httV);
stack->Add(hHiggs);
stack->Add(hZjets);
stack->Add(hWjets);
stack->Add(hTop);
stack->Add(hQCD);

TH1F *totalH = (TH1F *) hQCD->Clone("totalH");
totalH->Add(hVV);
totalH->Add(httV);
totalH->Add(hHiggs);
totalH->Add(hZjets);
totalH->Add(hWjets);
totalH->Add(hTop);



TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 1500, 800);

TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.15);
c1_1->Draw();
TPad *c1_2 = new TPad("c1_2", "newpad",0.01,0.15,0.99,0.99);
c1_2->Draw();

c1->cd();
c1_2->cd();
c1_2->SetTopMargin(0.1);
c1_2->SetBottomMargin(0.15);
c1_2->SetRightMargin(0.05);
c1_2->SetLeftMargin(0.1);
c1_2->SetFillStyle(0);




stack->Draw("hist");
stack->SetMinimum(0.01);
stack->SetMaximum(1000000);
stack->GetHistogram()->GetXaxis()->SetTitle("Event Bin");
stack->GetHistogram()->GetYaxis()->SetTitle("Events");

stack->GetHistogram()->GetXaxis()->SetBinLabel(1, "0t 0W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(2, "0t 0W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(3, "0t 0W 0Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(4, "0t 0W 0Z 3H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(5, "0t 0W 0Z 4H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(6, "0t 0W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(7, "0t 0W 1Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(8, "0t 0W 1Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(9, "0t 0W 1Z 3H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(10, "0t 0W 2Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(11, "0t 0W 2Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(12, "0t 0W 2Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(13, "0t 0W 3Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(14, "0t 0W 3Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(15, "0t 0W 4Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(16, "0t 1W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(17, "0t 1W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(18, "0t 1W 0Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(19, "0t 1W 0Z 3H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(20, "0t 1W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(21, "0t 1W 1Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(22, "0t 1W 1Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(23, "0t 1W 2Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(24, "0t 1W 2Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(25, "0t 1W 3Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(26, "0t 2W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(27, "0t 2W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(28, "0t 2W 0Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(29, "0t 2W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(30, "0t 2W 1Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(31, "0t 2W 2Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(32, "0t 3W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(33, "0t 3W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(34, "0t 3W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(35, "0t 4W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(36, "1t 0W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(37, "1t 0W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(38, "1t 0W 0Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(39, "1t 0W 0Z 3H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(40, "1t 0W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(41, "1t 0W 1Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(42, "1t 0W 1Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(43, "1t 0W 2Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(44, "1t 0W 2Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(45, "1t 0W 3Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(46, "1t 1W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(47, "1t 1W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(48, "1t 1W 0Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(49, "1t 1W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(50, "1t 1W 1Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(51, "1t 1W 2Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(52, "1t 2W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(53, "1t 2W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(54, "1t 2W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(55, "1t 3W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(56, "2t 0W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(57, "2t 0W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(58, "2t 0W 0Z 2H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(59, "2t 0W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(60, "2t 0W 1Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(61, "2t 0W 2Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(62, "2t 1W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(63, "2t 1W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(64, "2t 1W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(65, "2t 2W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(66, "3t 0W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(67, "3t 0W 0Z 1H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(68, "3t 0W 1Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(69, "3t 1W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(70, "4t 0W 0Z 0H 0b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(71, "0t 0W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(72, "0t 0W 0Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(73, "0t 0W 0Z 2H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(74, "0t 0W 0Z 3H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(75, "0t 0W 1Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(76, "0t 0W 1Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(77, "0t 0W 1Z 2H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(78, "0t 0W 2Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(79, "0t 0W 2Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(80, "0t 0W 3Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(81, "0t 1W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(82, "0t 1W 0Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(83, "0t 1W 0Z 2H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(84, "0t 1W 1Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(85, "0t 1W 1Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(86, "0t 1W 2Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(87, "0t 2W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(88, "0t 2W 0Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(89, "0t 2W 1Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(90, "0t 3W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(91, "1t 0W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(92, "1t 0W 0Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(93, "1t 0W 0Z 2H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(94, "1t 0W 1Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(95, "1t 0W 1Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(96, "1t 0W 2Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(97, "1t 1W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(98, "1t 1W 0Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(99, "1t 1W 1Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(100, "1t 2W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(101, "2t 0W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(102, "2t 0W 0Z 1H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(103, "2t 0W 1Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(104, "2t 1W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(105, "3t 0W 0Z 0H 1b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(106, "0t 0W 0Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(107, "0t 0W 0Z 1H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(108, "0t 0W 0Z 2H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(109, "0t 0W 1Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(110, "0t 0W 1Z 1H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(111, "0t 0W 2Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(112, "0t 1W 0Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(113, "0t 1W 0Z 1H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(114, "0t 1W 1Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(115, "0t 2W 0Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(116, "1t 0W 0Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(117, "1t 0W 0Z 1H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(118, "1t 0W 1Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(119, "1t 1W 0Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(120, "2t 0W 0Z 0H 2b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(121, "0t 0W 0Z 0H 3b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(122, "0t 0W 0Z 1H 3b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(123, "0t 0W 1Z 0H 3b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(124, "0t 1W 0Z 0H 3b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(125, "1t 0W 0Z 0H 3b");
stack->GetHistogram()->GetXaxis()->SetBinLabel(126, "0t 0W 0Z 0H 4b");

stack->GetHistogram()->GetXaxis()->SetLabelSize(0.02);
//stack->GetHistogram()->GetXaxis()->SetTitleOffset(2.25);


hData->Draw("E same");
hSig1->Draw("hist same");
hSig2->Draw("hist same");
hSig3->Draw("hist same");

TH1F *ratioH = new TH1F();
ratioH = (TH1F*) hData->Clone("ratioH");
ratioH->Sumw2();
ratioH->Divide(ratioH, totalH, 1, 1, "B");



TLegend *leg = new TLegend(0.20,0.80,0.85,0.88,"");
leg->SetNColumns(4);
leg->SetFillColor(0);
leg->SetLineColor(0);
leg->AddEntry(hData, "Data", "p");
leg->AddEntry(hQCD  ,  "Multijet (DD)","f");
leg->AddEntry(hTop     , "t#bar{t}+jets" ,"f");
leg->AddEntry(hWjets    , "W+jets","f");
leg->AddEntry(hZjets      , "Z+jets","f");
leg->AddEntry(hHiggs      , "H","f");
leg->AddEntry(hVV, "VV", "f");
leg->AddEntry(httV, "ttV+4t", "f");
leg->AddEntry(hSig1 , "TT (0.8 TeV)", "l");
leg->AddEntry(hSig2 , "TT (1.2 TeV)", "l");
leg->AddEntry(hSig3 , "TT (1.8 TeV)", "l");
leg->Draw("same");
gPad->SetLogy(1);
CMS_lumi(c1,4,0);


c1_1->cd();
c1_1->SetTopMargin(0.05);
        c1_1->SetBottomMargin(0.05);
        c1_1->SetRightMargin(0.05);
        c1_1->SetLeftMargin(0.1);
        c1_1->SetFillStyle(0);
ratioH->Draw("axis");
ratioH->GetYaxis()->SetRangeUser(0,2.);
        ratioH->GetYaxis()->SetTitle("Data / BG Ratio");
        ratioH->GetYaxis()->SetTitleOffset(0.4);
        ratioH->GetYaxis()->SetTitleSize(0.11);
        ratioH->GetYaxis()->SetLabelSize(0.11);
        ratioH->GetXaxis()->SetLabelSize(0.0);
        ratioH->GetXaxis()->SetTitleSize(0.0);
	//gPad->SetLogy(1);
ratioH->Draw("E same");
TF1 *line = new TF1("line", "1", 0, 10000);
        line->SetLineColor(kBlack);
	line->SetLineWidth(1);
        line->Draw("same");
        
        gPad->RedrawAxis();

c1_2->cd();









}
