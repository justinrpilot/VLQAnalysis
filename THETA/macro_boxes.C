{
  Double_t dy, dx, x, y, a, m, tZ;
  Double_t bW[21]={0.0,0.0,0.0,0.0,0.0,0.000,0.2,0.2,0.2,0.2,0.2,0.4,0.4,0.4,0.4,0.6,0.6,0.6,0.8,0.8,0.999};//0.5,
  Double_t tH[21]={0.0,0.2,0.4,0.6,0.8,0.999,0.0,0.2,0.4,0.6,0.8,0.0,0.2,0.4,0.6,0.0,0.2,0.4,0.0,0.2,0.000};//0.25
  //  int Mexp[21]={0, 0, 757, 786, 815, 848, 0, 723, 768, 792, 824, 742, 769, 791, 816, 792, 805, 827, 847, 853, 882};
  //  int Mobs[21]={781, 833, 871, 892, 917, 943, 804, 847, 878, 897, 926, 848, 870, 890, 910, 880, 891, 903, 907, 919, 946};
  //int Mexp[21]={1298, 1306, 1325, 1343, 1356, 1378, 1321, 1336, 1353, 1375, 1384, 1357, 1369, 1385, 1404, 1389, 1400, 1409, 1416, 1421, 1438};
  //int Mobs[21]={1328, 1344, 1355, 1366, 1385, 1399, 1354, 1374, 1392, 1393, 1397, 1394, 1403, 1410, 1407, 1411, 1420, 1423, 1435, 1439, 1456};
  //int Mexp[21] = { 717, 719, 738, 769, 823, 845, 0, 0, 0, 726, 807, 0, 0, 741, 805, 785, 824, 802, 884, 910, 948};
  //int Mobs[21] = { 737, 757, 736, 737, 0, 0, 818, 812, 816, 828, 812, 917, 880, 904, 893, 1109, 942, 1102, 1146, 1142, 1225};
  int Mexp[21] = { 720, 720, 740, 770, 820, 850, 0, 0, 0, 730, 810, 0, 0, 740, 810, 790, 820, 800, 880, 910, 950};
  int Mobs[21] = { 740, 760, 740, 740, 0, 0, 820, 810, 820, 830, 810, 920, 880, 900, 890, 1110, 940, 1100, 1150, 1140, 1230};
  int MexpUp[21] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0,0,0,0,0,0,0,0,0,0};
  int MexpDn[21] = { 960, 970, 1000, 1000, 1040, 1080, 950, 950, 950, 1000, 1040, 960, 980, 970, 1020, 1000, 1000, 1070, 1120, 1120, 1160}; 


  TH2D *Hobs = new TH2D("Hobs",";B(bH);B(tW)",6,-0.1,1.1,6,-0.1,1.1);
  TH2D *Hexp = new TH2D("Hexp",";B(bH);B(tW)",6,-0.1,1.1,6,-0.1,1.1);
  for(int i = 0; i < 21; i++){
    if(Mexp[i] == 0 && Mobs[i] == 0) continue;
    Hobs->Fill(tH[i],bW[i],Mobs[i]);
    Hexp->Fill(tH[i],bW[i],Mexp[i]);
  }

  Hobs->GetXaxis()->SetTitleFont(42);
  Hobs->GetXaxis()->SetLabelFont(42);
  Hobs->GetYaxis()->SetTitleFont(42);
  Hobs->GetYaxis()->SetLabelFont(42);
  Hobs->GetZaxis()->SetTitleFont(42);
  Hobs->GetZaxis()->SetLabelFont(42);
  Hexp->GetXaxis()->SetTitleFont(42);
  Hexp->GetXaxis()->SetLabelFont(42);
  Hexp->GetYaxis()->SetTitleFont(42);
  Hexp->GetYaxis()->SetLabelFont(42);
  Hexp->GetZaxis()->SetTitleFont(42);
  Hexp->GetZaxis()->SetLabelFont(42);

  // create graph
  TCanvas *c1 = new TCanvas("c1","Graph Draw Options",1000,800);
  c1->GetFrame()->SetFillColor(42);
  c1->GetFrame()->SetLineColor(kWhite);
  
  c1->SetRightMargin(0.16);
  c1->SetTopMargin(0.10);
  c1->SetBottomMargin(0.10);
  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(57);
  
  Hexp->GetZaxis()->SetRangeUser(700,1600);
  Hexp->Draw("colz");
  
  TLatex t1;
  t1.SetTextAlign(22);
  t1.SetTextSize(0.040);
  TLatex t3;
  t3.SetTextAlign(22);
  t3.SetTextSize(0.020); 
  
  for(int i = 0; i < 21; i++){
    if(Mexp[i] < 700) t1.DrawLatex(tH[i]+0.01,bW[i],"< 700");
    else{
     char value[10];
     std::snprintf(value, sizeof(value),"%i",Mexp[i]);     
     t1.DrawLatex(tH[i],bW[i],value);
   }
    char valueUp[10];
    char valueDn[10];
    std::snprintf(valueUp, sizeof(valueUp), "%i", MexpUp[i]);
    std::snprintf(valueDn, sizeof(valueDn), "%i", MexpDn[i]);
    t3.SetTextFont(42);
    //if (MexpUp[i] < 700) t3.DrawLatex(tH[i], bW[i]+0.05, "< 700");
    //else t3.DrawLatex(tH[i], bW[i]+0.05, valueUp);
    //t3.DrawLatex(tH[i], bW[i]-0.05, valueDn); 
  } 
  
  t1.SetTextAlign(11);
  //t1.DrawLatex(-0.1,1.15,"CMS 35.9 fb^{-1} (13 TeV)");
  CMS_lumi(c1, 4, 33);
  t1.SetTextAlign(22);
  t1.SetTextAngle(-90);
  t1.SetTextFont(42);
  t1.DrawLatex(1.32,0.47,"Expected B quark mass limit (GeV)");

TLatex *analabel = new TLatex();
analabel->SetTextFont(42);
analabel->SetTextSize(0.055);
analabel->DrawLatexNDC(0.6, 0.6, "NN analysis");
  c1->Print("boxesSL_exp_BB.png");
  c1->Print("boxesSL_exp_BB.pdf");
  c1->Print("boxesSL_exp_BB.C");
  c1->Print("boxesSL_exp_BB.root");
  
  //---------------------------------
  
  TCanvas *c2 = new TCanvas("c2","Graph Draw Options",1000,800);
  c2->GetFrame()->SetFillColor(42);
  c2->GetFrame()->SetLineColor(kWhite);
  
  c2->SetRightMargin(0.16);
  c2->SetTopMargin(0.10);
  c2->SetBottomMargin(0.10);
  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(57);
  
  Hobs->GetZaxis()->SetRangeUser(700,1600);
  Hobs->Draw("colz");
  
  TLatex t2;
  t2.SetTextAlign(22);
  t2.SetTextSize(0.040);
  
  for(int i = 0; i < 21; i++){
    if(Mobs[i] < 700) t2.DrawLatex(tH[i]+0.01,bW[i],"< 700");
    else{
      char value[10];
      std::snprintf(value, sizeof(value),"%i",Mobs[i]);     
      t2.DrawLatex(tH[i],bW[i],value);
    }
  } 
  
  t2.SetTextAlign(11);
  //t2.DrawLatex(-0.1,1.15,"CMS 35.9 fb^{-1} (13 TeV)");
  CMS_lumi(c2, 4, 33);
  t2.SetTextAlign(22);
  t2.SetTextAngle(-90);
  t2.SetTextFont(42);
  t2.DrawLatex(1.32,0.47,"Observed B quark mass limit (GeV)");
  
analabel->SetTextFont(42);
analabel->SetTextSize(0.055);
analabel->DrawLatexNDC(0.6, 0.6, "NN analysis");
  c2->Print("boxesSL_obs_BB.png");
  c2->Print("boxesSL_obs_BB.pdf");
  c2->Print("boxesSL_obs_BB.C");
  c2->Print("boxesSL_obs_BB.root");

  //////////////////
  /*
  int MexpB[21]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 722, 0, 0, 740, 0, 736, 717};
  int MobsB[21]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 731, 760, 768, 771, 794, 817, 809, 832, 835};

  TH2D *HobsB = new TH2D("HobsB",";B(bH);B(tW)",6,-0.1,1.1,6,-0.1,1.1);
  TH2D *HexpB = new TH2D("HexpB",";B(bH);B(tW)",6,-0.1,1.1,6,-0.1,1.1);
  for(int i = 0; i < 21; i++){
    if(MexpB[i] != 0) HexpB->Fill(tH[i],bW[i],MexpB[i]);
    if(MobsB[i] != 0) HobsB->Fill(tH[i],bW[i],MobsB[i]);
  }

  
  // create graph
  TCanvas *c4 = new TCanvas("c4","Graph Draw Options",1000,800);
  c4->GetFrame()->SetFillColor(42);
  c4->GetFrame()->SetLineColor(kWhite);
  
  c4->SetRightMargin(0.16);
  c4->SetTopMargin(0.10);
  c4->SetBottomMargin(0.10);
  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(57);
  
  HexpB->GetZaxis()->SetRangeUser(700,830);
  HexpB->Draw("colz");
  
  TLatex t4;
  t4.SetTextAlign(22);
  t4.SetTextSize(0.040);
  
  for(int i = 0; i < 21; i++){
    if(MexpB[i] < 700) t4.DrawLatex(tH[i]+0.01,bW[i],"< 700");
    else{
      char value[10];
      std::snprintf(value, sizeof(value),"%i",MexpB[i]);     
      t4.DrawLatex(tH[i],bW[i],value);
    }
  } 
  
  t4.SetTextAlign(11);
  t4.DrawLatex(-0.1,1.15,"CMS 2.3/2.6/2.7 fb^{-1} (13 TeV)");
  t4.SetTextAlign(22);
  t4.SetTextAngle(-90);
  t4.DrawLatex(1.32,0.47,"expected B quark mass limit (GeV)");
  
  c4->Print("boxesComb_expB.png");
  c4->Print("boxesComb_expB.pdf");
  c4->Print("boxesComb_expB.C");
  c4->Print("boxesComb_expB.root");
  
  //---------------------------------

  TCanvas *c3 = new TCanvas("c3","Graph Draw Options",1000,800);
  c3->GetFrame()->SetFillColor(42);
  c3->GetFrame()->SetLineColor(kWhite);
  
  c3->SetRightMargin(0.16);
  c3->SetTopMargin(0.12);
  c3->SetBottomMargin(0.12);
  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(57);
  
  HobsB->GetZaxis()->SetRangeUser(700,830);
  HobsB->Draw("colz");

  TLatex t5;
  t5.SetTextAlign(22);
  t5.SetTextSize(0.040);
  
  for(int i = 0; i < 21; i++){
    if(MobsB[i] < 700) t5.DrawLatex(tH[i]+0.01,bW[i],"< 700");
    else{
      char value[10];
      std::snprintf(value, sizeof(value),"%i",MobsB[i]);     
      t5.DrawLatex(tH[i],bW[i],value);
    }
  } 
  
  t5.SetTextAlign(11);
  t5.DrawLatex(-0.1,1.15,"CMS 2.3/2.6/2.7 fb^{-1} (13 TeV)");
  t5.SetTextAlign(22);
  t5.SetTextAngle(-90);
  t5.DrawLatex(1.32,0.47,"observed B quark mass limit (GeV)");
  
  c3->Print("boxesComb_obsB.png");
  c3->Print("boxesComb_obsB.pdf");
  c3->Print("boxesComb_obsB.C");
  c3->Print("boxesComb_obsB.root");
*/

}
