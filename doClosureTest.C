#include "makeClosure.C"
#include "sampleQCD.C"

void doClosureTest(int t, int w, int z, int h, int b){

		gROOT->SetStyle("Empty");
		gStyle->SetOptStat(0);

		int j = max(0, 4-t-w-z-h-b);

		int c = 1;
		cout << Form("%dt, %dW, %dZ, %dH, %db, %dj", t, w, z, h, b, j) << endl;

		int uniques = 0;
		if (t) uniques++;
		if (w) uniques++;
		if (z) uniques++;
		if (h) uniques++;
		if (j) uniques++;
		if (b) uniques++;
		if (uniques == 4) c = 24;
		else if (uniques == 3) c = 12;
		else if (uniques == 2){
			if (max(b, max(t, max(w, max(z, max(h,j))))) == 3) c = 4;
			else c = 6;
		}
		else c = 1;	
		cout << c << "  COMBINATIONS" << endl;
		
		sampleQCD(t, w, z, h, b, c);



		makeStack("ht", "H_{T} [GeV]", Form("numJets == 4 && numTop == %d && numZ == %d && numW == %d && numH == %d && numB == %d && numQCD == %d", t, z, w, h, b, j), 50, 0, 10000, Form("closure_%dt_%dw_%dz_%dh_%db", t, w, z, h, b), Form("%dt, %dW, %dZ, %dH, %db, %dj", t, w, z, h, b, j));






}
