from ROOT import *
from array import *
import json
from math import log10, sqrt
from os import sys
gStyle.SetOptStat(0)

histos = dict()
with open(sys.argv[1], 'r') as file:
	histos = json.loads(file.read())

print histos

dataH = TH1F('data', 'data', 10000,0,10000)
signalH = TH1F('signal', 'signal', 10000, 0, 10000)
bkgH = TH1F('bkg', 'bkg', 10000, 0, 10000)



n1 = 0
n2 = 0
n3 = 0
n4 = 0
n5 = 0
n = 0



for channel in histos:
        #print "=====================", histos[channel]
	print channel
	#if not '0t' in channel:
	#	continue
	for process in histos[channel]:
		print process	
		if 'wjets' in process:
			continue
		if 'zjets' in process:
			continue
		
		print "=================", process
		nbin = 0
		print histos[channel][process]	
		for b in histos[channel][process]:
			print channel, process, b
			#dataH.Fill(n1, 1)
			#n1 += 1
			if 'data' in process:
				n1 += 1
				print "data", n1, b
				dataH.Fill(n1, b)
				#dataH.Fill(n1, 1)
				#if b == 0:
				#	dataH.SetBinError(n1, 3.0)
				#nbin += 1
			elif 'tprime1400' in process:
				n2 += 1
				print n2, b
				signalH.Fill(n2, b)
			#elif 'ttbar' in process:
			#	n4 += 1
			#	print "ttbar", n4, b
			#	bkgH.Fill(n4, b)
			#	bkgH.Fill(n4, histos[channel]['wjets'][nbin])
			#	bkgH.Fill(n4, histos[channel]['zjets'][nbin])
			#	bkgH.Fill(n4, histos[channel]['higgs'][nbin])
			#	bkgH.Fill(n4, histos[channel]['diboson'][nbin])
			#	nbin += 1
			elif 'qcd' in process:
				n4 += 1
				print n4, nbin, b
				bkgH.Fill(n4, b)
				bkgH.Fill(n4, histos[channel]['ttbar'][nbin])
				bkgH.Fill(n4, histos[channel]['wjets'][nbin])
				bkgH.Fill(n4, histos[channel]['zjets'][nbin])
				bkgH.Fill(n4, histos[channel]['higgs'][nbin])
				bkgH.Fill(n4, histos[channel]['diboson'][nbin])
				nbin += 1
			#else:
			#	continue
			


signalH.Draw()
#signalH.Draw("same")
#dataH.Draw("E same")


sbMap = list()


i = 0
while i < bkgH.GetNbinsX():

	bNum = bkgH.GetBinContent(i)
	sNum = signalH.GetBinContent(i)
	dNum = dataH.GetBinContent(i)
	
	soverb = 0.0
	if bNum > 0.0:
		soverb = float(sNum) / float(bNum)
	#print i, soverb
	sbMap.append( [soverb, dNum, sNum, bNum] )
	i += 1

#print sbMap
sbMap.sort()
#print sbMap

#binEdges = [-6.0, -4.0, -2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0]
binEdges = [-10.0, -6.0, -4.0, -3.5, -3.0, -2.5, -2.0, -1.9,-1.8,-1.7,-1.6,-1.5,-1.4,-1.3,-1.2,-1.1,-1.0,-0.9,-0.8,-0.7,-0.6,-0.5, -0.4, -0.3,-0.2,-0.1,0.0, 0.5, 1.0, 2.0]
#binEdges = [-6.0, -4.0, -2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 5.0]

sbHist = TH1F('sbHist', 'sbHist', len(binEdges) - 1, array('d', binEdges))
sbErrHist = TH1F('sbErrHist', 'sbErrHist', len(binEdges) - 1, array('d', binEdges))
sbDataHist = TH1F('sbDataHist', 'sbDataHist', len(binEdges) - 1, array('d', binEdges))
sbSigHist = TH1F('sbSigHist', 'sbSigHist', len(binEdges) - 1, array('d', binEdges))
ratioH = TH1F('ratioH', 'ratioH', len(binEdges) -1, array('d', binEdges))
errorH = TH1F('errorH', 'errorH', len(binEdges) -1, array('d', binEdges))
sbHist.Sumw2()
sbErrHist.Sumw2()
sbDataHist.Sumw2()
ratioH.Sumw2()
errorH.Sumw2()



for data in sbMap:

	#print log10(data[0]), data[1], data[2]
	if (data[0] == 0.0):
		sbHist.Fill(-9.99, data[3])
		sbDataHist.Fill(-9.99, data[1])
		sbSigHist.Fill(-9.99, data[2])
	else:
		sbHist.Fill(log10(data[0]), data[3])
		sbErrHist.Fill(log10(data[0]), sqrt(data[3]))
		sbDataHist.Fill(log10(data[0]), data[1])
		sbSigHist.Fill(log10(data[0]), data[2])

sbHist.SetFillColor(kBlue - 4)
sbSigHist.SetFillColor(kRed)
stack = THStack('hs', 'hs')



stack.Add(sbHist)
stack.Add(sbSigHist)
c2 = TCanvas()

c2_2 = TPad("c2_2", "newpad",0.01,0.33,0.99,0.99);
c2_2.Draw() 
c2_2.cd()
c2_2.SetTopMargin(0.1)
c2_2.SetBottomMargin(0.03)
c2_2.SetRightMargin(0.1)
c2_2.SetFillStyle(0)

gROOT.LoadMacro('CMS_lumi.C')
sbDataHist.SetMaximum(20000)
sbDataHist.SetMinimum(0.00001)
sbDataHist.SetMarkerStyle(21)
sbDataHist.SetLineColor(1)
sbDataHist.GetXaxis().SetTitle("log_{10}(Signal / Background)")
sbDataHist.GetYaxis().SetTitle("Events")
sbDataHist.GetYaxis().SetTitleSize(0.06)
sbDataHist.GetYaxis().SetTitleOffset(0.82)
sbDataHist.GetYaxis().SetLabelSize(0.06)
sbDataHist.GetXaxis().SetLabelSize(0.00)
sbDataHist.GetXaxis().SetTitleSize(0.00)
sbDataHist.GetYaxis().SetLabelOffset(0.005)
sbDataHist.SetTitle("")
sbDataHist.Draw("axis")
stack.Draw("hist same")
sbDataHist.Draw("E same")
CMS_lumi(c2_2, 4, 0)
gPad.RedrawAxis()
gPad.SetLogy(1)












latex = TLatex()
latex.SetNDC()
latex.SetTextSize(0.06)
latex.SetTextAlign(11);
#latex.DrawLatex(0.1, 0.915, "CMS Preliminary, 8 TeV, 19.7 fb^{-1}");
#latex.DrawLatex(0.50, 0.85, "100% bH, 800 GeV");


c2.cd()
c2_1 = TPad("c2_1", "newpad",0.01,0.01,0.99,0.32);
c2_1.Draw()
c2_1.cd()
c2_1.SetTopMargin(0.03)
c2_1.SetBottomMargin(0.28)
c2_1.SetRightMargin(0.1)
c2_1.SetFillStyle(0)

ratioH = sbDataHist.Clone('ratioH')

for i in range(1, errorH.GetNbinsX()):

	if sbHist.GetBinContent(i) > 0:
		errorH.SetBinContent(i, sbDataHist.GetBinContent(i) / sbHist.GetBinContent(i))
	errorH.SetBinError(i, sbErrHist.GetBinContent(i) /( .000001+sbHist.GetBinContent(i)))

ratioH.Divide(ratioH, sbHist, 1, 1, "B")
ratioH.SetMaximum(2.0)
ratioH.SetMinimum(0.0)
ratioH.Draw("axis")
errorH.SetFillColor(kBlack)
errorH.SetFillStyle(3244)
ratioH.GetXaxis().SetTitleSize(0.12)
ratioH.GetXaxis().SetLabelSize(0.12)
ratioH.GetXaxis().SetTitleOffset(1.10)
ratioH.GetYaxis().SetTitle("Data / Bkg")
ratioH.GetYaxis().SetNdivisions(2, 0)
ratioH.GetYaxis().SetTitleSize(0.12)
ratioH.GetYaxis().SetTitleOffset(0.40)
ratioH.GetYaxis().SetLabelSize(0.12)
ratioH.GetYaxis().SetLabelOffset(0.014)
#errorH.Draw("E2 same")
ratioH.Draw("E same")
line = TF1("line", "1", -99.0, 99.0)
line.SetLineColor(kBlack)
line.SetLineWidth(1)
line.Draw("same")


c2_2.cd()
leg = TLegend(0.17, 0.220, 0.50, 0.50)
leg.SetFillColor(0)
leg.SetLineColor(0)
leg.AddEntry(sbDataHist, "Data", "pl")
leg.AddEntry(sbHist, "Background", "f")
leg.AddEntry(sbSigHist, "TT#rightarrow"+sys.argv[2]+" (M_{T} = 1.4 TeV)", "f")
leg.Draw("same")

c2.SaveAs("SBplot_"+sys.argv[2]+".pdf")
