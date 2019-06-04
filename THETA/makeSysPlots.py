import ROOT
from ROOT import *

inFile = ROOT.TFile("templates/theta4jet_1.0tz_0.0bw_0.0th.root", "READ")
gROOT.SetStyle('Plain')
gStyle.SetOptStat(0)
gROOT.SetBatch(1)

cats = []
procs = []
systs = []
names = []

for key in inFile.GetListOfKeys():
	name = key.GetName()
	names.append(name)
	splits = name.split('__')
	if splits[0] not in cats:
		cats.append(splits[0])
	if splits[1] not in procs:
		procs.append(splits[1])
	if len(splits) > 2 and splits[2] not in systs:
		systs.append(splits[2])

print cats
print systs
print procs

for cat in cats[0:1]:

	for proc in procs:

		if ('DATA') in proc: continue
		if ('qcd') in proc: continue

		for syst in systs:
		
			print cat, proc, syst

			if 'wjets' in proc: continue
			if 'zjets' in proc: continue
			if 'diboson' in proc: continue
			if 'higgs' in proc: continue

			#if ('SF') not in syst: continue
			if 'mistag' in syst:
				if proc is not 'qcd': continue
			if 'q2' in syst:
				if (proc is not 'ttbar') and ('tprime' not in proc): continue
			if 'pdf' in syst:
				if (proc is not 'ttbar') and ('tprime' not in proc): continue

			if 'pileup' in syst: continue

			histNom = inFile.Get(cat+'__'+proc)
			histUp = inFile.Get(cat+'__'+proc+'__'+syst+'__plus')
			histDn = inFile.Get(cat+'__'+proc+'__'+syst+'__minus')
			
			histNom.SetTitle('')
			histNom.GetXaxis().SetTitle('H_{T} [GeV]')
			histNom.GetYaxis().SetTitle('Events')

			histNom.Draw("hist")
			histUp.Draw("hist same")
			histDn.Draw("hist same")
			histNom.SetLineWidth(2)
			histUp.SetLineWidth(2)
			histDn.SetLineWidth(2)


			histNom.SetMaximum(histUp.GetMaximum()*1.25)	
			histNom.SetLineColor(kBlack)
			histUp.SetLineColor(kGreen+1)
			histDn.SetLineColor(kRed+1)
			histNom.SetFillColor(0)
			histUp.SetFillColor(0)
			histDn.SetFillColor(0)

			histUp.SetLineWidth(4)
			histDn.SetLineWidth(3)

			histNom.Draw("hist")
			histUp.Draw("hist same")
			histDn.Draw("hist same")
			histNom.Draw("hist same")

			leg = TLegend(0.6, 0.6, 0.87, 0.87)
			leg.AddEntry(histNom, syst+" Nominal", "l")
			leg.AddEntry(histUp, syst+" Up Variation", "l")
			leg.AddEntry(histDn, syst+" Dn Variation", "l")
	
			leg.AddEntry(histNom, cat, "")
			leg.AddEntry(histNom, proc, "")

			leg.SetLineColor(0)
			leg.SetFillColor(0)			
			leg.Draw('same')
			
			c1.SetLogy(1)

			c1.SaveAs('sysplots/'+cat+'_'+proc+'_'+syst+'.pdf')



