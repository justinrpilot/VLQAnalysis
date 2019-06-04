from ROOT import *
import sys

#f = TFile("~/data/ThetaSL6/theta/BEST_VLQ/templates/theta4jet_1.0tz_0.0bw_0.0th.root", "READ")
f = TFile(sys.argv[1], "READ")
f.cd()
procs = ["DATA", "qcd", "ttbar", "wjets", "zjets", "diboson", "ttV", "higgs", "tprime700", "tprime800","tprime900","tprime1000","tprime1100","tprime1200","tprime1300","tprime1400","tprime1500","tprime1600","tprime1700","tprime1800"]

systs = []#"jec", "jer", "pdf", "q2", "pileup", "QCD_SF", "B_SF", "B_misSF", "T_SF", "T_misSF", "W_SF", "W_misSF", "Z_SF", "Z_misSF", "H_SF", "H_misSF"]

labels = []
for key in gDirectory.GetListOfKeys():
	name = key.GetName() 
	if not "0t_0W_0Z_0H_0b" in name: continue
	labels.append(name[16:])
cats = []
for key in gDirectory.GetListOfKeys():
	name = key.GetName()
	print name
	if not "tprime700" in name: continue
	for arg in sys.argv[2:]:
		if arg in name:
			if name.split('__')[0] not in cats:
				cats.append(name.split('__')[0])


print labels
print cats
print len(cats)

fname = ''
for arg in sys.argv[2:]:
	fname = fname + arg

fout = TFile("out_"+fname+".root", "RECREATE")

for label in labels:

	if 'plus' in label and 'mistag' not in label:
		continue
	if 'minus' in label and 'mistag' not in label:
		continue
	
	print cats[0]
	hist = f.Get(cats[0]+'__'+label)
	print ">>>>HISTOGRAM  ", label, hist.GetNbinsX()
	for cat in cats[1:]:

		#print "Adding category", cat
		histadd = f.Get(cat+'__'+label)
		if not (histadd.GetNbinsX() < 2):
			hist.Add(histadd)


	fout.cd()
	hist.Write("combined"+'__'+label)
	
fout.Write()
fout.Close()		
