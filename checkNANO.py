from ROOT import *
from array import array

fileNANO = TFile("nano.root", "READ")
fileBEST = TFile("outplots.root", "READ")

treeNANO = fileNANO.Get("Events")
treeBEST = fileBEST.Get("jetVars")

BEST_pt = array('f', [-999.9])
NANO_pt = array('f', [-999.9])
treeBEST.SetBranchAddress("jetPt", BEST_pt)
treeNANO.SetBranchAddress("CustomAK8Puppi_pt", NANO_pt)

BEST_probT = array('f', [-999.9])
treeBEST.SetBranchAddress("prob_t",BEST_probT)
NANO_probT = array('f', [-999.9])
treeNANO.SetBranchAddress("CustomAK8Puppi_bestT",NANO_probT)

histNANO = TH1F("histNANO", "histNANO", 50, 0, 1)
histBEST = TH1F("histBEST", "histBEST", 50, 0, 1)

treeNANO.Draw("CustomAK8Puppi_bestQCD>>histNANO", "", "goff")
treeBEST.Draw("prob_j>>histBEST", "", "goff")

histNANO.SetLineWidth(2)
histNANO.SetLineColor(kBlue)
histBEST.SetLineWidth(2)
histBEST.SetLineColor(kRed)

histBEST.Draw("hist")
histNANO.Draw("hist same")

