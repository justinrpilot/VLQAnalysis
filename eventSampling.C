void loadHists();
TH1F* getHistogram(int index, string tag, float pt);
TFile *templates = new TFile("jetPt_templates.root", "READ");
TRandom *rng = new TRandom();

void makePermutations(int nTop, int nZ, int nW, int nH, int* perm);

string tagIDtoName(int ID);

void sampleEvents(int nTop, int nZ, int nW, int nH){


TH1D *outHT = new TH1D("outHT", "outHT", 100, 0, 7000);
TH1D *outpt0 = new TH1D("outpt0", "outpt0", 100, 0, 4000);
TH1D *outpt1 = new TH1D("outpt1", "outpt1", 100, 0, 4000);
TH1D *outpt2 = new TH1D("outpt2", "outpt2", 100, 0, 4000);
TH1D *outpt3 = new TH1D("outpt3", "outpt3", 100, 0, 4000);

int step = 0;
float eventHT = 0.0;
while (step < 100000){

	
	float jet0pt = 99999., jet1pt = 99999., jet2pt = 99999., jet3pt = 99999.;

	int thisPerm[4] = {0,0,0,0};
	makePermutations(nTop, nZ, nW, nH, thisPerm);
	//cout << "MADE PERM = " << thisPerm[0] << " " << thisPerm[1] << " " << thisPerm[2] << " " << thisPerm[3] << endl;
	
	


	float x = rng->Uniform();
	bool tagPos0 = (x < 0.5);

	TH1F *hist1 = getHistogram(0, tagIDtoName(thisPerm[0]), -999.);
	//if (tagPos0) hist1 = getHistogram(0, "T", -999.);
	jet0pt = hist1->GetRandom();

	TH1F *hist2 = getHistogram(1, tagIDtoName(thisPerm[1]), jet0pt);
	//if (!tagPos0) hist2 = getHistogram(1, "T", -999.);
	jet1pt = hist2->GetRandom();

	TH1F *hist3 = getHistogram(2, tagIDtoName(thisPerm[2]), jet1pt);
	jet2pt = hist3->GetRandom();

	TH1F *hist4 = getHistogram(3, tagIDtoName(thisPerm[3]), jet2pt);
	jet3pt = hist4->GetRandom();

/*	jet0pt = jet0_notag->GetRandom();
	

	if (jet0pt < 600) jet1pt = jet1_Htag_1->GetRandom(); 
	else if (jet0pt < 800) jet1pt = jet1_Htag_2->GetRandom(); 
	else if (jet0pt < 1000) jet1pt = jet1_Htag_3->GetRandom(); 
	else if (jet0pt < 1200) jet1pt = jet1_Htag_4->GetRandom(); 
	else if (jet0pt < 1500) jet1pt = jet1_Htag_5->GetRandom(); 
	else if (jet0pt < 2000) jet1pt = jet1_Htag_6->GetRandom(); 
	else if (jet0pt < 2500) jet1pt = jet1_Htag_7->GetRandom(); 
	else jet1pt = jet1_Htag_8->GetRandom(); 
	
	if (jet1pt < 600) jet2pt = jet2_notag_1->GetRandom(); 
	else if (jet1pt < 800) jet2pt = jet2_notag_2->GetRandom(); 
	else if (jet1pt < 1000) jet2pt = jet2_notag_3->GetRandom(); 
	else if (jet1pt < 1200) jet2pt = jet2_notag_4->GetRandom(); 
	else if (jet1pt < 1500) jet2pt = jet2_notag_5->GetRandom(); 
	else if (jet1pt < 2000) jet2pt = jet2_notag_6->GetRandom(); 
	else if (jet1pt < 2500) jet2pt = jet2_notag_7->GetRandom(); 
	else jet2pt = jet2_notag_8->GetRandom(); 
	
	if (jet2pt < 600) jet3pt = jet3_notag_1->GetRandom(); 
	else if (jet2pt < 800) jet3pt = jet3_notag_2->GetRandom(); 
	else if (jet2pt < 1000) jet3pt = jet3_notag_3->GetRandom(); 
	else if (jet2pt < 1200) jet3pt = jet3_notag_4->GetRandom(); 
	else if (jet2pt < 1500) jet3pt = jet3_notag_5->GetRandom(); 
	else if (jet2pt < 2000) jet3pt = jet3_notag_6->GetRandom(); 
	else if (jet2pt < 2500) jet3pt = jet3_notag_7->GetRandom(); 
	else jet3pt = jet3_notag_8->GetRandom(); 
*/	
	eventHT = jet0pt + jet1pt + jet2pt + jet3pt;

	if (jet1pt > jet0pt) continue;
	if (jet2pt > jet1pt) continue;
	if (jet3pt > jet2pt) continue;


	outHT->Fill(eventHT);
	outpt0->Fill(jet0pt);
	outpt1->Fill(jet1pt);
	outpt2->Fill(jet2pt);
	outpt3->Fill(jet3pt);

	if (step % 10000 == 0) cout << step << endl;

	step++;
}


outHT->Draw();

TFile *outfile = new TFile("sampled_shapes.root", "RECREATE");
outfile->cd();
outHT->Write();
outpt0->Write();
outpt1->Write();
outpt2->Write();
outpt3->Write();
outfile->Close();



}


TH1F* getHistogram(int index, string tag, float pt){


string ptIndex = "";
string jetIndex = "";

switch (index){
	case 0:  jetIndex = "jet0";break;
	case 1:  jetIndex = "jet1";break;
	case 2:  jetIndex = "jet2";break;
	case 3:  jetIndex = "jet3";break;
}
if (index > 0){
	if (pt < 600) ptIndex = "_1";
	else if (pt < 800) ptIndex = "_2";
	else if (pt < 1000) ptIndex = "_3";
	else if (pt < 1200) ptIndex = "_4";
	else if (pt < 1500) ptIndex = "_5";
	else if (pt < 2000) ptIndex = "_6";
	else if (pt < 2500) ptIndex = "_7";
	else ptIndex = "_8";
}
string histName = "h_"+jetIndex+"pt_"+tag+"tag"+ptIndex;

TH1F *hist = (TH1F *) templates->Get(histName.c_str());

return hist;


}

void makePermutations(int nTop, int nZ, int nW, int nH, int* perm){

TH1F *topIndex = (TH1F *) templates->Get("h_topTagIndex");
TH1F *WIndex = (TH1F *) templates->Get("h_ZTagIndex");
TH1F *ZIndex = (TH1F *) templates->Get("h_WTagIndex");
TH1F *HIndex = (TH1F *) templates->Get("h_HTagIndex");

TH1F *indexHists[] = {topIndex, ZIndex, WIndex, HIndex};
int mults[] = {nTop, nZ, nW, nH};

int startID = rng->Integer(4);

int totalMult = TMath::Min(4, nTop + nZ + nW + nH);

//cout << "startID " << startID << endl;
while (totalMult > 0){
	
//	cout << "testing for tags " << startID << endl;
	if (mults[startID] > 0) {
		int pos = indexHists[startID]->GetRandom();
		perm[pos] = startID+1;
//		cout << "got index for tag" << startID << ", index " << pos << endl;
		mults[startID]--;
		totalMult--;
//		cout << "set bin content 0 for tagType " << startID << ", bin " << pos+1 << endl;
		for (int h = 0; h < 4; h++) indexHists[h]->SetBinContent(pos+1, 0.0);
		
	}	
	
	startID = (startID + 1) % 4;
//	cout << "newStartID " << startID << endl;
}

delete topIndex;
delete ZIndex;
delete WIndex;
delete HIndex;

}

string tagIDtoName(int ID){

	string out = "no";
	if (ID == 1) out = "T";
	if (ID == 2) out = "Z";
	if (ID == 3) out = "W";
	if (ID == 4) out = "H";

	return out;
}


void loadHists(){

TFile *templates = new TFile("jetPt_templates.root", "READ");

TH1D *jet0_notag = (TH1D *) templates->Get("h_jet0pt_notag");
TH1D *jet0_Ttag = (TH1D *) templates->Get("h_jet0pt_Ttag");
TH1D *jet0_Htag = (TH1D *) templates->Get("h_jet0pt_Htag");
TH1D *jet0_Wtag = (TH1D *) templates->Get("h_jet0pt_Wtag");
TH1D *jet0_Ztag = (TH1D *) templates->Get("h_jet0pt_Ztag");
TH1D *jet1_notag_1 = (TH1D *) templates->Get("h_jet1pt_notag_1");
TH1D *jet2_notag_1 = (TH1D *) templates->Get("h_jet2pt_notag_1");
TH1D *jet3_notag_1 = (TH1D *) templates->Get("h_jet3pt_notag_1");
TH1D *jet1_Ttag_1 = (TH1D *) templates->Get("h_jet1pt_Ttag_1");
TH1D *jet1_Ttag_2 = (TH1D *) templates->Get("h_jet1pt_Ttag_2");
TH1D *jet1_Ttag_3 = (TH1D *) templates->Get("h_jet1pt_Ttag_3");
TH1D *jet1_Ttag_4 = (TH1D *) templates->Get("h_jet1pt_Ttag_4");
TH1D *jet1_Ttag_5 = (TH1D *) templates->Get("h_jet1pt_Ttag_5");
TH1D *jet1_Ttag_6 = (TH1D *) templates->Get("h_jet1pt_Ttag_6");
TH1D *jet1_Ttag_7 = (TH1D *) templates->Get("h_jet1pt_Ttag_7");
TH1D *jet1_Ttag_8 = (TH1D *) templates->Get("h_jet1pt_Ttag_8");
TH1D *jet1_Htag_1 = (TH1D *) templates->Get("h_jet1pt_Htag_1");
TH1D *jet1_Htag_2 = (TH1D *) templates->Get("h_jet1pt_Htag_2");
TH1D *jet1_Htag_3 = (TH1D *) templates->Get("h_jet1pt_Htag_3");
TH1D *jet1_Htag_4 = (TH1D *) templates->Get("h_jet1pt_Htag_4");
TH1D *jet1_Htag_5 = (TH1D *) templates->Get("h_jet1pt_Htag_5");
TH1D *jet1_Htag_6 = (TH1D *) templates->Get("h_jet1pt_Htag_6");
TH1D *jet1_Htag_7 = (TH1D *) templates->Get("h_jet1pt_Htag_7");
TH1D *jet1_Htag_8 = (TH1D *) templates->Get("h_jet1pt_Htag_8");
TH1D *jet2_Ttag_1 = (TH1D *) templates->Get("h_jet2pt_Ttag_1");
TH1D *jet2_Ttag_2 = (TH1D *) templates->Get("h_jet2pt_Ttag_2");
TH1D *jet2_Ttag_3 = (TH1D *) templates->Get("h_jet2pt_Ttag_3");
TH1D *jet2_Ttag_4 = (TH1D *) templates->Get("h_jet2pt_Ttag_4");
TH1D *jet2_Ttag_5 = (TH1D *) templates->Get("h_jet2pt_Ttag_5");
TH1D *jet2_Ttag_6 = (TH1D *) templates->Get("h_jet2pt_Ttag_6");
TH1D *jet2_Ttag_7 = (TH1D *) templates->Get("h_jet2pt_Ttag_7");
TH1D *jet2_Ttag_8 = (TH1D *) templates->Get("h_jet2pt_Ttag_8");
TH1D *jet3_Ttag_1 = (TH1D *) templates->Get("h_jet3pt_Ttag_1");
TH1D *jet3_Ttag_2 = (TH1D *) templates->Get("h_jet3pt_Ttag_2");
TH1D *jet3_Ttag_3 = (TH1D *) templates->Get("h_jet3pt_Ttag_3");
TH1D *jet3_Ttag_4 = (TH1D *) templates->Get("h_jet3pt_Ttag_4");
TH1D *jet3_Ttag_5 = (TH1D *) templates->Get("h_jet3pt_Ttag_5");
TH1D *jet3_Ttag_6 = (TH1D *) templates->Get("h_jet3pt_Ttag_6");
TH1D *jet3_Ttag_7 = (TH1D *) templates->Get("h_jet3pt_Ttag_7");
TH1D *jet3_Ttag_8 = (TH1D *) templates->Get("h_jet3pt_Ttag_8");
TH1D *jet1_notag_2 = (TH1D *) templates->Get("h_jet1pt_notag_2");
TH1D *jet2_notag_2 = (TH1D *) templates->Get("h_jet2pt_notag_2");
TH1D *jet3_notag_2 = (TH1D *) templates->Get("h_jet3pt_notag_2");
TH1D *jet1_notag_3 = (TH1D *) templates->Get("h_jet1pt_notag_3");
TH1D *jet2_notag_3 = (TH1D *) templates->Get("h_jet2pt_notag_3");
TH1D *jet3_notag_3 = (TH1D *) templates->Get("h_jet3pt_notag_3");
TH1D *jet1_notag_4 = (TH1D *) templates->Get("h_jet1pt_notag_4");
TH1D *jet2_notag_4 = (TH1D *) templates->Get("h_jet2pt_notag_4");
TH1D *jet3_notag_4 = (TH1D *) templates->Get("h_jet3pt_notag_4");
TH1D *jet1_notag_5 = (TH1D *) templates->Get("h_jet1pt_notag_5");
TH1D *jet2_notag_5 = (TH1D *) templates->Get("h_jet2pt_notag_5");
TH1D *jet3_notag_5 = (TH1D *) templates->Get("h_jet3pt_notag_5");
TH1D *jet1_notag_6 = (TH1D *) templates->Get("h_jet1pt_notag_6");
TH1D *jet2_notag_6 = (TH1D *) templates->Get("h_jet2pt_notag_6");
TH1D *jet3_notag_6 = (TH1D *) templates->Get("h_jet3pt_notag_6");
TH1D *jet1_notag_7 = (TH1D *) templates->Get("h_jet1pt_notag_7");
TH1D *jet2_notag_7 = (TH1D *) templates->Get("h_jet2pt_notag_7");
TH1D *jet3_notag_7 = (TH1D *) templates->Get("h_jet3pt_notag_7");
TH1D *jet1_notag_8 = (TH1D *) templates->Get("h_jet1pt_notag_8");
TH1D *jet2_notag_8 = (TH1D *) templates->Get("h_jet2pt_notag_8");
TH1D *jet3_notag_8 = (TH1D *) templates->Get("h_jet3pt_notag_8");
}

