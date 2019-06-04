from optparse import OptionParser
import numpy as np
from sklearn import svm, metrics, preprocessing
from sklearn.externals import joblib
import warnings
import os
warnings.simplefilter("ignore")


parser = OptionParser()

parser.add_option('--files', type='string', action='store', dest='files', help='Input Files')
parser.add_option('--outname', type='string', action='store',default='outplots.root', dest='outname',help='Name of output file')
parser.add_option('--maxevents', type='int', action='store',default=-1,dest='maxevents',help='Number of events to run. -1 is all events')


(options, args) = parser.parse_args()
argv = []

import ROOT
import sys, copy
from array import array
from DataFormats.FWLite import Events, Handle


f = ROOT.TFile(options.outname, "RECREATE")
f.cd()

h_best_top = ROOT.TH1F("h_best_top", ";Top jet probability", 100, 0, 1)
h_best_W = ROOT.TH1F("h_best_W", ";W jet probability", 100, 0, 1)
h_best_Z = ROOT.TH1F("h_best_Z", ";Z jet probability", 100, 0, 1)
h_best_H = ROOT.TH1F("h_best_H", ";H jet probability", 100, 0, 1)
h_best_j = ROOT.TH1F("h_best_j", ";Light jet probability", 100, 0, 1)

outTree = ROOT.TTree('jetVars', 'jetVars')
prob_t = array('f', [-999.])
prob_W = array('f', [-999.])
prob_Z = array('f', [-999.])
prob_H = array('f', [-999.])
prob_j = array('f', [-999.])
jetPt = array('f', [-999.])
jetSDmass = array('f', [-999.])
best_class = array('i', [-9])

outTree.Branch('prob_t', prob_t, 'prob_t/F')
outTree.Branch('prob_W', prob_W, 'prob_W/F')
outTree.Branch('prob_Z', prob_Z, 'prob_Z/F')
outTree.Branch('prob_H', prob_H, 'prob_H/F')
outTree.Branch('prob_j', prob_j, 'prob_j/F')
outTree.Branch('jetPt', jetPt, 'jetPt/F')
outTree.Branch('jetSDmass', jetSDmass, 'jetSDmass/F')
outTree.Branch('best_class', best_class, 'best_class/I')

jetsHandle = Handle("std::vector<pat::Jet>")
jetsLabel = ("BESTProducer", "savedJets")
nnLabels = []
nnLabels.append( ("BESTProducer", "FWmoment1H") )
nnLabels.append( ("BESTProducer", "FWmoment1W") )
nnLabels.append( ("BESTProducer", "FWmoment1Z") )
nnLabels.append( ("BESTProducer", "FWmoment1top") )
nnLabels.append( ("BESTProducer", "FWmoment2H") )
nnLabels.append( ("BESTProducer", "FWmoment2W") )
nnLabels.append( ("BESTProducer", "FWmoment2Z") )
nnLabels.append( ("BESTProducer", "FWmoment2top") )
nnLabels.append( ("BESTProducer", "FWmoment3H") )
nnLabels.append( ("BESTProducer", "FWmoment3W") )
nnLabels.append( ("BESTProducer", "FWmoment3Z") )
nnLabels.append( ("BESTProducer", "FWmoment3top") )
nnLabels.append( ("BESTProducer", "FWmoment4H") )
nnLabels.append( ("BESTProducer", "FWmoment4W") )
nnLabels.append( ("BESTProducer", "FWmoment4Z") )
nnLabels.append( ("BESTProducer", "FWmoment4top") )
nnLabels.append( ("BESTProducer", "SDmass") )
nnLabels.append( ("BESTProducer", "aplanarityH") )
nnLabels.append( ("BESTProducer", "aplanarityW") )
nnLabels.append( ("BESTProducer", "aplanarityZ") )
nnLabels.append( ("BESTProducer", "aplanaritytop") )
nnLabels.append( ("BESTProducer", "bDisc") )
nnLabels.append( ("BESTProducer", "bDisc1") )
nnLabels.append( ("BESTProducer", "bDisc2") )
nnLabels.append( ("BESTProducer", "et") )
nnLabels.append( ("BESTProducer", "eta") )
nnLabels.append( ("BESTProducer", "isotropyH") )
nnLabels.append( ("BESTProducer", "isotropyW") )
nnLabels.append( ("BESTProducer", "isotropyZ") )
nnLabels.append( ("BESTProducer", "isotropytop") )
nnLabels.append( ("BESTProducer", "q") )
nnLabels.append( ("BESTProducer", "sphericityH") )
nnLabels.append( ("BESTProducer", "sphericityW") )
nnLabels.append( ("BESTProducer", "sphericityZ") )
nnLabels.append( ("BESTProducer", "sphericitytop") )
nnLabels.append( ("BESTProducer", "sumPH") )
nnLabels.append( ("BESTProducer", "sumPW") )
nnLabels.append( ("BESTProducer", "sumPZ") )
nnLabels.append( ("BESTProducer", "sumPtop") )
nnLabels.append( ("BESTProducer", "sumPzH") )
nnLabels.append( ("BESTProducer", "sumPzW") )
nnLabels.append( ("BESTProducer", "sumPzZ") )
nnLabels.append( ("BESTProducer", "sumPztop") )
nnLabels.append( ("BESTProducer", "tau21") )
nnLabels.append( ("BESTProducer", "tau32") )
nnLabels.append( ("BESTProducer", "thrustH") )
nnLabels.append( ("BESTProducer", "thrustW") )
nnLabels.append( ("BESTProducer", "thrustZ") )
nnLabels.append( ("BESTProducer", "thrusttop") )
nnLabels.append( ("BESTProducer", "m12H") )
nnLabels.append( ("BESTProducer", "m23H") )
nnLabels.append( ("BESTProducer", "m13H") )
nnLabels.append( ("BESTProducer", "m1234H") )
nnLabels.append( ("BESTProducer", "m12W") )
nnLabels.append( ("BESTProducer", "m23W") )
nnLabels.append( ("BESTProducer", "m13W") )
nnLabels.append( ("BESTProducer", "m1234W") )
nnLabels.append( ("BESTProducer", "m12Z") )
nnLabels.append( ("BESTProducer", "m23Z") )
nnLabels.append( ("BESTProducer", "m13Z") )
nnLabels.append( ("BESTProducer", "m1234Z") )
nnLabels.append( ("BESTProducer", "m12top") )
nnLabels.append( ("BESTProducer", "m23top") )
nnLabels.append( ("BESTProducer", "m13top") )
nnLabels.append( ("BESTProducer", "m1234top") )

nnHandles = [ Handle("std::vector<float>") ] * len(nnLabels)





filelist = file(options.files)
filesraw = filelist.readlines()
files = []
nevents = 0
for ifile in filesraw:
	lfn = ifile.rstrip()
	s = 'root://cmsxrootd.fnal.gov/' + lfn
	files.append(s)
	print 'Added' + s

mlp = joblib.load('BEST_mlp.pkl')
scaler = joblib.load('BEST_scaler.pkl')

nevents_file = 0
for ifile in files:
	print 'Processing', ifile

	if options.maxevents > 0 and nevents > options.maxevents :
        	break

	events = Events( ifile )


	products = {}

	

	for event in events:
		
		if options.maxevents > 0 and nevents > options.maxevents :
        		break
		nevents += 1
		nevents_file += 1
		if (nevents_file % 1000 == 0):
			print nevents, ' Completed'

		event.getByLabel(jetsLabel, jetsHandle)
		for i in xrange(len(nnHandles)):
			event.getByLabel(nnLabels[i], nnHandles[i])
			products[nnLabels[i][1]] = nnHandles[i].product() 
				

		jets = jetsHandle.product()

		for j in xrange(len(jets)):

			jetPt[0] = jets[j].pt()
			jetSDmass[0] = products['SDmass'][j]

			pzOverp_top = products['sumPztop'][j] / (products['sumPtop'][j] + 0.01) 
			pzOverp_W = products['sumPzW'][j] / (products['sumPW'][j] + 0.01) 
			pzOverp_Z = products['sumPzZ'][j] / (products['sumPZ'][j] + 0.01)
			pzOverp_H = products['sumPzH'][j] / (products['sumPH'][j] + 0.01)


			nnArray = np.array( [  products['SDmass'][j], products['tau32'][j], products['tau21'][j], products['FWmoment1top'][j], products['FWmoment2top'][j], products['FWmoment3top'][j], products['FWmoment4top'][j], products['isotropytop'][j], products['aplanaritytop'][j], products['sphericitytop'][j], products['thrusttop'][j], products['FWmoment1W'][j], products['FWmoment2W'][j], products['FWmoment3W'][j], products['FWmoment4W'][j], products['isotropyW'][j], products['aplanarityW'][j], products['sphericityW'][j], products['thrustW'][j], products['FWmoment1Z'][j], products['FWmoment2Z'][j], products['FWmoment3Z'][j], products['FWmoment4Z'][j], products['isotropyZ'][j], products['aplanarityZ'][j], products['sphericityZ'][j], products['thrustZ'][j], products['FWmoment1H'][j], products['FWmoment2H'][j], products['FWmoment3H'][j], products['FWmoment4H'][j], products['isotropyH'][j], products['aplanarityH'][j], products['sphericityH'][j], products['thrustH'][j], products['bDisc'][j], products['bDisc1'][j], products['bDisc2'][j], products['q'][j], products['m12W'][j], products['m13W'][j], products['m23W'][j], products['m1234W'][j], products['m12Z'][j], products['m13Z'][j], products['m23Z'][j], products['m1234Z'][j], products['m12top'][j], products['m13top'][j], products['m23top'][j], products['m1234top'][j], products['m12H'][j], products['m13H'][j], products['m23H'][j], products['m1234H'][j], pzOverp_top, pzOverp_W, pzOverp_Z, pzOverp_H  ])



			nnArray_transformed = scaler.transform( nnArray )



			best_bin = mlp.predict( nnArray_transformed )

			best_probs = mlp.predict_proba( nnArray_transformed )


			prob_j[0] = best_probs[0][0]
			prob_W[0] = best_probs[0][1]
			prob_Z[0] = best_probs[0][2]
			prob_H[0] = best_probs[0][3]
			prob_t[0] = best_probs[0][4]

			best_class[0] = best_bin[0]			

			outTree.Fill()


f.cd()
f.Write()
f.Close()
