#include "applyRates.C"

void data_bkgEst(int nTop, int nW, int nZ, int nH, int nB){


				int t = nTop;
				int w = nW;
				int z = nZ;
				int h = nH;
				int b = nB;
	
				int j = max(0, 4-t-w-z-h-b);

				if (t+w+z+h+j+b > 4) return;
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
				
				sampleEvents(t, z, w, h, b, "outplots_dataB.root", "shapes_dataB.root", c);
				sampleEvents(t, z, w, h, b, "outplots_dataC.root", "shapes_dataC.root", c);
				sampleEvents(t, z, w, h, b, "outplots_dataD.root", "shapes_dataD.root", c);
				sampleEvents(t, z, w, h, b, "outplots_dataE.root", "shapes_dataE.root", c);
				sampleEvents(t, z, w, h, b, "outplots_dataF.root", "shapes_dataF.root", c);
				sampleEvents(t, z, w, h, b, "outplots_dataG.root", "shapes_dataG.root", c);
				sampleEvents(t, z, w, h, b, "outplots_dataH.root", "shapes_dataH.root", c);
				sampleEvents(t, z, w, h, b, "outplots_DATA_H2.root", "shapes_dataH2.root", c);








}
