from ROOT import *


#f1 = TFile("pileup_hist_MC.root", "READ")
f1 = TFile("outPU.root", "READ")
f2 = TFile("PUdatanew.root", "READ")
#f2 = TFile("myPileupHist.root", "READ")

hMC = f1.Get("puMC")
hTarget = f2.Get("puDATA")
hMC.Scale(1./hMC.Integral())
hTarget.Scale(1./hTarget.Integral())


hTarget.Divide(hTarget,hMC, 1, 1, "B")

hTarget.Draw()

fOut = TFile("puWeights.root", "RECREATE")
fOut.cd()
hTarget.Write("pileupWeight")
fOut.Write()
fOut.Close()

