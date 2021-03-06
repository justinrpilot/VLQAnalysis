void boxesSL_obs_BB()
{
//=========Macro generated from canvas: c2/Graph Draw Options
//=========  (Thu Mar  7 15:26:08 2019) by ROOT version6.06/01
   TCanvas *c2 = new TCanvas("c2", "Graph Draw Options",1444,23,1000,800);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c2->Range(-0.2621622,-0.25,1.359459,1.25);
   c2->SetFillColor(0);
   c2->SetBorderMode(0);
   c2->SetBorderSize(2);
   c2->SetRightMargin(0.16);
   c2->SetFrameBorderMode(0);
   c2->SetFrameBorderMode(0);
   
   TH2D *Hobs = new TH2D("Hobs","",6,-0.1,1.1,6,-0.1,1.1);
   Hobs->SetBinContent(9,740);
   Hobs->SetBinContent(10,760);
   Hobs->SetBinContent(11,740);
   Hobs->SetBinContent(12,740);
   Hobs->SetBinContent(17,820);
   Hobs->SetBinContent(18,810);
   Hobs->SetBinContent(19,820);
   Hobs->SetBinContent(20,830);
   Hobs->SetBinContent(21,810);
   Hobs->SetBinContent(25,920);
   Hobs->SetBinContent(26,880);
   Hobs->SetBinContent(27,900);
   Hobs->SetBinContent(28,890);
   Hobs->SetBinContent(33,1110);
   Hobs->SetBinContent(34,940);
   Hobs->SetBinContent(35,1100);
   Hobs->SetBinContent(41,1150);
   Hobs->SetBinContent(42,1140);
   Hobs->SetBinContent(49,1230);
   Hobs->SetBinError(9,740);
   Hobs->SetBinError(10,760);
   Hobs->SetBinError(11,740);
   Hobs->SetBinError(12,740);
   Hobs->SetBinError(17,820);
   Hobs->SetBinError(18,810);
   Hobs->SetBinError(19,820);
   Hobs->SetBinError(20,830);
   Hobs->SetBinError(21,810);
   Hobs->SetBinError(25,920);
   Hobs->SetBinError(26,880);
   Hobs->SetBinError(27,900);
   Hobs->SetBinError(28,890);
   Hobs->SetBinError(33,1110);
   Hobs->SetBinError(34,940);
   Hobs->SetBinError(35,1100);
   Hobs->SetBinError(41,1150);
   Hobs->SetBinError(42,1140);
   Hobs->SetBinError(49,1230);
   Hobs->SetMinimum(700);
   Hobs->SetMaximum(1600);
   Hobs->SetEntries(21);
   Hobs->SetStats(0);
   Hobs->SetContour(20);
   Hobs->SetContourLevel(0,700);
   Hobs->SetContourLevel(1,745);
   Hobs->SetContourLevel(2,790);
   Hobs->SetContourLevel(3,835);
   Hobs->SetContourLevel(4,880);
   Hobs->SetContourLevel(5,925);
   Hobs->SetContourLevel(6,970);
   Hobs->SetContourLevel(7,1015);
   Hobs->SetContourLevel(8,1060);
   Hobs->SetContourLevel(9,1105);
   Hobs->SetContourLevel(10,1150);
   Hobs->SetContourLevel(11,1195);
   Hobs->SetContourLevel(12,1240);
   Hobs->SetContourLevel(13,1285);
   Hobs->SetContourLevel(14,1330);
   Hobs->SetContourLevel(15,1375);
   Hobs->SetContourLevel(16,1420);
   Hobs->SetContourLevel(17,1465);
   Hobs->SetContourLevel(18,1510);
   Hobs->SetContourLevel(19,1555);
   
   TPaletteAxis *palette = new TPaletteAxis(1.108108,-0.1,1.181081,1.1,Hobs);
palette->SetLabelColor(1);
palette->SetLabelFont(42);
palette->SetLabelOffset(0.005);
palette->SetLabelSize(0.04);
palette->SetTitleOffset(1);
palette->SetTitleSize(0.04);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#f9f90e");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   Hobs->GetListOfFunctions()->Add(palette,"br");
   Hobs->GetXaxis()->SetTitle("B(bH)");
   Hobs->GetXaxis()->SetLabelFont(42);
   Hobs->GetXaxis()->SetTitleFont(42);
   Hobs->GetYaxis()->SetTitle("B(tW)");
   Hobs->GetYaxis()->SetLabelFont(42);
   Hobs->GetYaxis()->SetTitleFont(42);
   Hobs->GetZaxis()->SetLabelFont(42);
   Hobs->GetZaxis()->SetTitleFont(42);
   Hobs->Draw("colz");
   TLatex *   tex = new TLatex(0,0,"740");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0,"760");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.4,0,"740");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.6,0,"740");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.81,0,"< 700");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1.009,0,"< 700");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0,0.2,"820");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.2,"810");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.4,0.2,"820");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.6,0.2,"830");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.8,0.2,"810");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0,0.4,"920");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.4,"880");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.4,0.4,"900");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.6,0.4,"890");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0,0.6,"1110");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.6,"940");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.4,0.6,"1100");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0,0.8,"1150");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.8,"1140");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0,0.999,"1230");
   tex->SetTextAlign(22);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.84,0.92,"35.9 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.8067001,0.872,"CMS");
tex->SetNDC();
   tex->SetTextAlign(33);
   tex->SetTextFont(61);
   tex->SetTextSize(0.075);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.8067001,0.7819999,"");
tex->SetNDC();
   tex->SetTextAlign(33);
   tex->SetTextFont(52);
   tex->SetTextSize(0.057);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1.32,0.47,"Observed B quark mass limit (GeV)");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetTextAngle(-90);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.6,0.6,"NN analysis");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.055);
   tex->SetLineWidth(2);
   tex->Draw();
   c2->Modified();
   c2->cd();
   c2->SetSelected(c2);
}
