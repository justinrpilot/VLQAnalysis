#include <math.h>
#include "CMS_lumi.C"

float calcIntersect(TGraph *gA, TGraph *gB);

void plotLimit(TString filename, float BRTZ, float BRBW, float BRTH){



TGraph * limit_obs = new TGraph();
TGraph * limit_exp = new TGraph();
TGraph * limit_exp_up = new TGraph();
TGraph * limit_exp_dn = new TGraph();
TGraphAsymmErrors * band_exp1 = new TGraphAsymmErrors();
TGraphAsymmErrors * band_exp2 = new TGraphAsymmErrors();

TGraph *theory = new TGraph();
 theory->SetPoint(0,  500, 1);
 theory->SetPoint(1,  1200, 1);
 theory->SetPoint(2,  1500, 1);
 theory->SetPoint(3,  1750, 1);
 theory->SetPoint(4,  2000, 1);
 theory->SetPoint(5,  2250, 1);
 theory->SetPoint(6,  2500, 1);
 theory->SetPoint(7,  2750, 1);
 theory->SetPoint(8,  3000, 1);
 theory->SetPoint(9,  3250, 1);
 theory->SetPoint(10, 3500, 1);
 theory->SetPoint(11, 3750, 1);
 theory->SetPoint(12, 4000, 1);


ifstream infile(filename);
ifstream infile2("obs"+filename);

double mass, exp, obs, obserr,up1, up2, dn1, dn2;
int point = 0;
char blah[256];
while (!infile.eof()){

  infile.getline(blah, 256);
  infile2.getline(blah, 256);
  //infile >> mass >> exp >>  dn2 >> up2 >> dn1 >> up1;
  //obs = exp;	
  //obs = 999;
  infile >> mass  >> exp >>  dn2 >> up2 >> dn1 >> up1;
  infile2 >> mass >> obs >> obserr;
  //cout.precision(2);




  double sf = 1.0;

  //cout << mass << " & \\textbf{" << obs*sf << "} & " << dn2*sf << " & " << dn1*sf << " & \\textbf{" << exp*sf << "} & " << up1*sf << " & " << up2*sf <<  " \\\\" << endl;

  limit_obs->SetPoint(point, mass, obs*sf);
  limit_exp->SetPoint(point, mass, exp*sf);
  band_exp1->SetPoint(point, mass, exp*sf);
  band_exp2->SetPoint(point, mass, exp*sf);
 
  limit_exp_up->SetPoint(point, mass, up1*sf );
  limit_exp_dn->SetPoint(point, mass, dn1*sf); 
  band_exp1->SetPointEYhigh(point, up1*sf - exp*sf);
  band_exp1->SetPointEYlow(point, exp*sf - dn1*sf);
  band_exp2->SetPointEYhigh(point, up2*sf - exp*sf);
  band_exp2->SetPointEYlow(point, exp*sf - dn2*sf);
  point++;

}

double max = 200000.0; //band_exp2->GetHistogram()->GetMaximum()*50;

  TCanvas *canvas = new TCanvas("limit set ZPN","limit set ZPN", 500,500);
  canvas->SetLeftMargin(0.15);


  limit_exp->SetMinimum(0.01);
  limit_exp->Draw("AL");
  limit_exp->GetXaxis()->SetTitleFont(42);
  limit_exp->GetXaxis()->SetLabelFont(42);
  limit_exp->GetYaxis()->SetTitleFont(42);
  limit_exp->GetYaxis()->SetLabelFont(42);

  limit_exp->GetXaxis()->SetTitle("M_{T} [GeV]");
  limit_exp->GetYaxis()->SetTitle("95% CL Limit on #sigma / #sigma(TT)");
  limit_exp->GetYaxis()->SetTitleOffset(1.3);
  limit_exp->GetYaxis()->SetRangeUser(0.01,2000);

  band_exp2->SetFillColor(kOrange);
  band_exp2->SetLineColor(0);
  //band_exp2->SetFillStyle(4000);
  band_exp2->Draw("3same");

  band_exp1->SetFillColor(kGreen+1);
  band_exp1->SetLineColor(0);
  //band_exp1->SetFillStyle(4000);
  band_exp1->Draw("3same");

  limit_obs->Draw("Lsame");
  limit_obs->SetLineWidth(2);
  limit_obs->SetMarkerSize(1.0);
  limit_obs->SetMarkerStyle(20);
   
  limit_exp->Draw("Lsame");
  limit_exp->SetLineStyle(2);
  limit_exp->SetLineWidth(2);
  limit_exp->SetMarkerSize(1.0);
  limit_exp->SetMaximum(max);
  limit_exp->SetMinimum(0.1);
  limit_exp->SetMarkerStyle(20);

  double x1 = 595; 
  double y1 = 1.0;
  double x2 = 905;
  double y2 = 1.0;
  TLine * line = new TLine(x1, y1, x2, y2);
  theory->SetLineColor(2);
  theory->SetLineWidth(2);
  theory->Draw("same");

  
  float exclusion = calcIntersect(limit_exp, theory); 
  float obsexclusion = calcIntersect(limit_obs, theory); 
  float excl_up = calcIntersect(limit_exp_up, theory);
  float excl_dn = calcIntersect(limit_exp_dn, theory);
  cout << Form("EXPECTED %1.1ftz %1.1fbw %1.1fth = %4.0f", BRTZ, BRBW, BRTH, exclusion) << endl;
  cout << Form("EXPUP %1.1ftz %1.1fbw %1.1fth = %4.0f", BRTZ, BRBW, BRTH, excl_up) << endl;
  cout << Form("EXPDN %1.1ftz %1.1fbw %1.1fth = %4.0f", BRTZ, BRBW, BRTH, excl_dn) << endl;
  //cout << Form("OBSERVED %1.1ftz %1.1fbw %1.1fth = %4.0f", BRTZ, BRBW, BRTH, obsexclusion) << endl;

  //Legend
  TLegend *l = new TLegend(0.5,0.6,0.88,0.88);
  l->SetTextFont(42);
  l->AddEntry(limit_obs,"Observed", "L");
  l->AddEntry(limit_exp,"Expected", "L");
  l->AddEntry(band_exp1,"#pm1 s.d. exp.", "F");
  l->AddEntry(band_exp2,"#pm2 s.d. exp.", "F");
  l->AddEntry(theory, "TT Expectation", "L");
  l->AddEntry(theory, Form("BR(tZ, tH, bW) = "), "");
  l->AddEntry(theory, Form("%1.1f, %1.1f, %1.1f", BRTZ, BRTH, BRBW), "");
  //l->AddEntry(theory, Form("BR(tH) = %1.1f", BRTH), "");
  //l->AddEntry(theory, Form("BR(bW) = %1.1f", BRBW), "");
  l->SetFillColor(0);
  l->SetLineColor(0);
  l->Draw();

TLatex *t1 = new TLatex();
t1->SetTextFont(42);
t1->SetTextSize(0.055);
t1->DrawLatexNDC(0.2, 0.55, "NN analysis");

  //TLatex * label = new TLatex();
  //label->SetNDC();
  //label->DrawLatex(0.2,0.86,"CMS Preliminary, 19.7 fb^{-1}");
  //label->DrawLatex(0.2,0.80,"#sqrt{s} = 8 TeV");
  //label->DrawLatex(0.6,0.80, Form("BR(b'#rightarrow %s) = 1", channel.Data()));
  //label->DrawLatex(0.55,0.80, "BR(b'#rightarrow tW) = 0.5");
  //label->DrawLatex(0.55,0.74, "BR(b'#rightarrow bH) = 0.25");
  //label->DrawLatex(0.55,0.68, "BR(b'#rightarrow bZ) = 0.25");
  //label->DrawLatex(0.2,0.74, lepton.Data());
CMS_lumi(canvas, 4, 10);
  canvas->SetLogy(1);

  canvas->Print(Form("limit_%1.1ftz_%1.1fbw_%1.1fth.pdf", BRTZ, BRBW, BRTH));
  //canvas->Print("TT_limit.root");

}

float calcIntersect(TGraph *gA, TGraph *gB){

	float intersect = -999.99;

	for (size_t a_i = 0; a_i < gA->GetN() - 1; ++a_i){
		for (size_t b_i = 0; b_i < gB->GetN() -1; ++b_i){

			double x1, y1, x2, y2 = 0;
         		double ax1, ay1, ax2, ay2 = 0;
        		 gA->GetPoint(a_i, x1, y1);
        		 gA->GetPoint(a_i+1, x2, y2);
        		 gB->GetPoint(b_i, ax1, ay1);
        		 gB->GetPoint(b_i+1, ax2, ay2);	

			double x = (ax1 *(ay2 *(x1-x2)+x2 * y1 - x1 * y2 )+ ax2 * (ay1 * (-x1+x2)- x2 * y1+x1 * y2)) / (-(ay1-ay2) * (x1-x2)+(ax1-ax2)* (y1-y2));
			double y = (ax1 * ay2 * (y1-y2)+ax2 * ay1 * (-y1+y2)+(ay1-ay2) * (x2 * y1-x1 * y2))/(-(ay1-ay2) * (x1-x2)+(ax1-ax2) * (y1-y2));

			double xrange_min = max(min(x1, x2), min(ax1, ax2));
         		double xrange_max = min(max(x1, x2), max(ax1, ax2));
	
			if(x >= xrange_min && x <= xrange_max){
			intersect = x;
			}
		}
	}

	return intersect;

}

