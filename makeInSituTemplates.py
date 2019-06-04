from ROOT import *

infile = TFile('0t_0W_0Z_0H_0b_histos.root', 'READ')
outfile = TFile('sysHistograms.root', 'RECREATE')

var = 0.25
for hist in infile.GetListOfKeys():
	name = hist.GetName()
	print name, hist.GetName()
	histObj = hist.ReadObj()
	print histObj.GetTitle()
	bin0 = histObj.GetBinContent(1)
	bin1 = histObj.GetBinContent(2)
	bin2 = histObj.GetBinContent(3)
	bin3 = histObj.GetBinContent(4)
	bin4 = histObj.GetBinContent(5)
	bin5 = histObj.GetBinContent(6)
	if 'sig' in name: continue
	if 'DATA' in name: continue

	sysH_0up = TH1F(name+'__qcdtag__plus', name+'__qcdtag__plus', 6, 0, 6)
	sysH_0dn = TH1F(name+'__qcdtag__minus', name+'__qcdtag__minus', 6, 0, 6)
	sysH_0up.Fill(0, bin0*(1+var))
	sysH_0dn.Fill(0, bin0*(1-var))
	sysH_1up = TH1F(name+'__Wtag__plus', name+'__Wtag__plus', 6, 0, 6)
	sysH_1dn = TH1F(name+'__Wtag__minus', name+'__Wtag__minus', 6, 0, 6)
	sysH_1up.Fill(1, bin1*(1+var))
	sysH_1dn.Fill(1, bin1*(1-var))
	sysH_2up = TH1F(name+'__Ztag__plus', name+'__Ztag__plus', 6, 0, 6)
	sysH_2dn = TH1F(name+'__Ztag__minus', name+'__Ztag__minus', 6, 0, 6)
	sysH_2up.Fill(2, bin2*(1+var))
	sysH_2dn.Fill(2, bin2*(1-var))
	sysH_3up = TH1F(name+'__Htag__plus', name+'__Htag__plus', 6, 0, 6)
	sysH_3dn = TH1F(name+'__Htag__minus', name+'__Htag__minus', 6, 0, 6)
	sysH_3up.Fill(3, bin3*(1+var))
	sysH_3dn.Fill(3, bin3*(1-var))
	sysH_4up = TH1F(name+'__toptag__plus', name+'__toptag__plus', 6, 0, 6)
	sysH_4dn = TH1F(name+'__toptag__minus', name+'__toptag__minus', 6, 0, 6)
	sysH_4up.Fill(4, bin4*(1+var))
	sysH_4dn.Fill(4, bin4*(1-var))
	sysH_5up = TH1F(name+'__btag__plus', name+'__btag__plus', 6, 0, 6)
	sysH_5dn = TH1F(name+'__btag__minus', name+'__btag__minus', 6, 0, 6)
	sysH_5up.Fill(5, bin5*(1+var))
	sysH_5dn.Fill(5, bin5*(1-var))
	
	outfile.cd()
	sysH_0up.Write(name+'__qcdtag__plus')
	sysH_0dn.Write(name+'__qcdtag__minus')
	sysH_1up.Write(name+'__Wtag__plus')
	sysH_1dn.Write(name+'__Wtag__minus')
	sysH_2up.Write(name+'__Ztag__plus')
	sysH_2dn.Write(name+'__Ztag__minus')
	sysH_3up.Write(name+'__Htag__plus')
	sysH_3dn.Write(name+'__Htag__minus')
	sysH_4up.Write(name+'__toptag__plus')
	sysH_4dn.Write(name+'__toptag__minus')
	sysH_5up.Write(name+'__btag__plus')
	sysH_5dn.Write(name+'__btag__minus')




outfile.Write()
outfile.Close()
infile.Close()
	
