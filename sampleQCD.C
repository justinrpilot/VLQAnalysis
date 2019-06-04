#include "applyRates.C"

void sampleQCD(int numTop = 0, int numW = 0, int numZ = 0, int numH = 0, int numB = 0, int combs = 1){

int c = combs;

sampleEvents(numTop, numZ, numW, numH, numB, "outplots_qcd1.root", "shapes_qcd1.root", c);
sampleEvents(numTop, numZ, numW, numH, numB, "outplots_qcd2.root", "shapes_qcd2.root", c);
sampleEvents(numTop, numZ, numW, numH, numB, "outplots_qcd3.root", "shapes_qcd3.root", c);
sampleEvents(numTop, numZ, numW, numH, numB, "outplots_qcd4.root", "shapes_qcd4.root", c);
sampleEvents(numTop, numZ, numW, numH, numB, "outplots_qcd5.root", "shapes_qcd5.root", c);
sampleEvents(numTop, numZ, numW, numH, numB, "outplots_qcd6.root", "shapes_qcd6.root", c);
sampleEvents(numTop, numZ, numW, numH, numB, "outplots_qcd7.root", "shapes_qcd7.root", c);
sampleEvents(numTop, numZ, numW, numH, numB, "outplots_qcd8.root", "shapes_qcd8.root", c);
sampleEvents(numTop, numZ, numW, numH, numB, "outplots_qcd9.root", "shapes_qcd9.root", c);
}
