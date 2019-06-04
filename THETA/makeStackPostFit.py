from ROOT import *

infile = TFile("histos-mle.root", "READ")
infile_prefit = TFile("testInSituFit.root", "READ")
gStyle.SetOptTitle(0)

histDATA = infile_prefit.GetKey('0t_0W_0Z_0H_0b__DATA').ReadObj()

stack = THStack('stack', 'stack')
color = {}
color['diboson'] = kViolet
color['ttV'] = kOrange
color['higgs'] = kCyan + 1
color['zjets'] = kGreen - 7
color['wjets'] = kBlue
color['ttbar'] = kRed
color['qcd'] = kYellow -7 

leg = TLegend(0.55, 0.7, 0.89, 0.86)
leg.SetNColumns(2)
leg.SetFillColor(0)
leg.SetLineColor(0)
leg.AddEntry(histDATA, "Data", 'p') 
for hist in ['diboson', 'ttV', 'higgs','zjets','wjets','ttbar','qcd']:
        histObj = infile.GetKey('tn_0t_0W_0Z_0H_0b__'+hist).ReadObj()
	histObj.SetFillColor(color[hist])
	histObj.SetLineColor(color[hist])
	stack.Add(histObj)
	leg.AddEntry(histObj, hist, "f")


histDATA.GetXaxis().SetTitle("BEST Category")
histDATA.GetYaxis().SetTitle("Post-Fit Events")
histDATA.SetMaximum(30000000)
histDATA.SetMinimum(1)
histDATA.Draw('E')
stack.Draw('same')
histDATA.Draw('E same')
leg.Draw('same')


gPad.RedrawAxis()
gPad.SetLogy(1)

