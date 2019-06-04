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
h_topTagIndex = ROOT.TH1D("h_topTagIndex", "", 4, 0, 4);
h_WTagIndex = ROOT.TH1D("h_WTagIndex", "", 4, 0, 4);
h_ZTagIndex = ROOT.TH1D("h_ZTagIndex", "", 4, 0, 4);
h_HTagIndex = ROOT.TH1D("h_HTagIndex", "", 4, 0, 4);

outTree = ROOT.TTree('jetVars', 'jetVars')
eventTree = ROOT.TTree('eventVars', 'eventVars')
prob_t = array('f', [-999.])
prob_W = array('f', [-999.])
prob_Z = array('f', [-999.])
prob_H = array('f', [-999.])
prob_j = array('f', [-999.])
jetPt = array('f', [-999.])
jetEta = array('f', [-999.])
jetPhi = array('f', [-999.])
jetSDmass = array('f', [-999.])
best_class = array('i', [-9])
numQCD = array('i', [-9])
numTop = array('i', [-9])
numW = array('i', [-9])
numZ = array('i', [-9])
numH = array('i', [-9])
numJets = array('i', [-9])
deltaM = array('f', [-999.])
Tmass1 = array('f', [-999.])
Tmass2 = array('f', [-999.])
htV = array('f', [-999.])
eventBin = array('i', [-9])
decayMode1 = array('i', [-9])
decayMode2 = array('i', [-9])
npv = array('i', [-9])
genPtV = array('f', [-999.])
topSizeV = array('f', [-999.])
dRgenParticleV = array('f', [-999.])


outTree.Branch('prob_t', prob_t, 'prob_t/F')
outTree.Branch('prob_W', prob_W, 'prob_W/F')
outTree.Branch('prob_Z', prob_Z, 'prob_Z/F')
outTree.Branch('prob_H', prob_H, 'prob_H/F')
outTree.Branch('prob_j', prob_j, 'prob_j/F')
outTree.Branch('jetPt', jetPt, 'jetPt/F')
outTree.Branch('jetPhi', jetPhi, 'jetPhi/F')
outTree.Branch('jetEta', jetEta, 'jetEta/F')
outTree.Branch('jetSDmass', jetSDmass, 'jetSDmass/F')
outTree.Branch('best_class', best_class, 'best_class/I')
outTree.Branch('npv', npv, 'npv/I')
outTree.Branch('genPt', genPtV, 'genPt/F')
outTree.Branch('topSize', topSizeV, 'topSize/F')
outTree.Branch('dRgenParticle', dRgenParticleV, 'dRgenParticle/F')
eventTree.Branch('numQCD', numQCD, 'numQCD/I')
eventTree.Branch('numW', numW, 'numW/I')
eventTree.Branch('numZ', numZ, 'numZ/I')
eventTree.Branch('numH', numH, 'numH/I')
eventTree.Branch('numTop', numTop, 'numTop/I')
eventTree.Branch('numJets', numJets, 'numJets/I')
eventTree.Branch('deltaM', deltaM, 'deltaM/F')
eventTree.Branch('Tmass1', Tmass1, 'Tmass1/F')
eventTree.Branch('Tmass2', Tmass2, 'Tmass2/F')
eventTree.Branch('ht', htV, 'ht/F')
eventTree.Branch('eventBin', eventBin, 'eventBin/I')
eventTree.Branch('decayMode1', decayMode1, 'decayMode1/I')
eventTree.Branch('decayMode2', decayMode2, 'decayMode2/I')
eventTree.Branch('npv', npv, 'npv/I')


prob_t_j0 = array('f', [-999.])
prob_W_j0 = array('f', [-999.])
prob_Z_j0 = array('f', [-999.])
prob_H_j0 = array('f', [-999.])
prob_j_j0 = array('f', [-999.])
jetPt_j0 = array('f', [-999.])
jetEta_j0 = array('f', [-999.])
jetPhi_j0 = array('f', [-999.])
jetSDmass_j0 = array('f', [-999.])
best_class_j0 = array('i', [-9])
prob_t_j1 = array('f', [-999.])
prob_W_j1 = array('f', [-999.])
prob_Z_j1 = array('f', [-999.])
prob_H_j1 = array('f', [-999.])
prob_j_j1 = array('f', [-999.])
jetPt_j1 = array('f', [-999.])
jetEta_j1 = array('f', [-999.])
jetPhi_j1 = array('f', [-999.])
jetSDmass_j1 = array('f', [-999.])
best_class_j1 = array('i', [-9])
prob_t_j2 = array('f', [-999.])
prob_W_j2 = array('f', [-999.])
prob_Z_j2 = array('f', [-999.])
prob_H_j2 = array('f', [-999.])
prob_j_j2 = array('f', [-999.])
jetPt_j2 = array('f', [-999.])
jetEta_j2 = array('f', [-999.])
jetPhi_j2 = array('f', [-999.])
jetSDmass_j2 = array('f', [-999.])
best_class_j2 = array('i', [-9])
prob_t_j3 = array('f', [-999.])
prob_W_j3 = array('f', [-999.])
prob_Z_j3 = array('f', [-999.])
prob_H_j3 = array('f', [-999.])
prob_j_j3 = array('f', [-999.])
jetPt_j3 = array('f', [-999.])
jetEta_j3 = array('f', [-999.])
jetPhi_j3 = array('f', [-999.])
jetSDmass_j3 = array('f', [-999.])
best_class_j3 = array('i', [-9])

eventTree.Branch('prob_t_j0', prob_t_j0, 'prob_t_j0/F')
eventTree.Branch('prob_W_j0', prob_W_j0, 'prob_W_j0/F')
eventTree.Branch('prob_Z_j0', prob_Z_j0, 'prob_Z_j0/F')
eventTree.Branch('prob_H_j0', prob_H_j0, 'prob_H_j0/F')
eventTree.Branch('prob_j_j0', prob_j_j0, 'prob_j_j0/F')
eventTree.Branch('jetPt_j0', jetPt_j0, 'jetPt_j0/F')
eventTree.Branch('jetPhi_j0', jetPhi_j0, 'jetPhi_j0/F')
eventTree.Branch('jetEta_j0', jetEta_j0, 'jetEta_j0/F')
eventTree.Branch('jetSDmass_j0', jetSDmass_j0, 'jetSDmass_j0/F')
eventTree.Branch('best_class_j0', best_class_j0, 'best_class_j0/I')
eventTree.Branch('prob_t_j1', prob_t_j1, 'prob_t_j1/F')
eventTree.Branch('prob_W_j1', prob_W_j1, 'prob_W_j1/F')
eventTree.Branch('prob_Z_j1', prob_Z_j1, 'prob_Z_j1/F')
eventTree.Branch('prob_H_j1', prob_H_j1, 'prob_H_j1/F')
eventTree.Branch('prob_j_j1', prob_j_j1, 'prob_j_j1/F')
eventTree.Branch('jetPt_j1', jetPt_j1, 'jetPt_j1/F')
eventTree.Branch('jetPhi_j1', jetPhi_j1, 'jetPhi_j1/F')
eventTree.Branch('jetEta_j1', jetEta_j1, 'jetEta_j1/F')
eventTree.Branch('jetSDmass_j1', jetSDmass_j1, 'jetSDmass_j1/F')
eventTree.Branch('best_class_j1', best_class_j1, 'best_class_j1/I')
eventTree.Branch('prob_t_j2', prob_t_j2, 'prob_t_j2/F')
eventTree.Branch('prob_W_j2', prob_W_j2, 'prob_W_j2/F')
eventTree.Branch('prob_Z_j2', prob_Z_j2, 'prob_Z_j2/F')
eventTree.Branch('prob_H_j2', prob_H_j2, 'prob_H_j2/F')
eventTree.Branch('prob_j_j2', prob_j_j2, 'prob_j_j2/F')
eventTree.Branch('jetPt_j2', jetPt_j2, 'jetPt_j2/F')
eventTree.Branch('jetPhi_j2', jetPhi_j2, 'jetPhi_j2/F')
eventTree.Branch('jetEta_j2', jetEta_j2, 'jetEta_j2/F')
eventTree.Branch('jetSDmass_j2', jetSDmass_j2, 'jetSDmass_j2/F')
eventTree.Branch('best_class_j2', best_class_j2, 'best_class_j2/I')
eventTree.Branch('prob_t_j3', prob_t_j3, 'prob_t_j3/F')
eventTree.Branch('prob_W_j3', prob_W_j3, 'prob_W_j3/F')
eventTree.Branch('prob_Z_j3', prob_Z_j3, 'prob_Z_j3/F')
eventTree.Branch('prob_H_j3', prob_H_j3, 'prob_H_j3/F')
eventTree.Branch('prob_j_j3', prob_j_j3, 'prob_j_j3/F')
eventTree.Branch('jetPt_j3', jetPt_j3, 'jetPt_j3/F')
eventTree.Branch('jetPhi_j3', jetPhi_j3, 'jetPhi_j3/F')
eventTree.Branch('jetEta_j3', jetEta_j3, 'jetEta_j3/F')
eventTree.Branch('jetSDmass_j3', jetSDmass_j3, 'jetSDmass_j3/F')
eventTree.Branch('best_class_j3', best_class_j3, 'best_class_j3/I')

jetsHandle = Handle("std::vector<pat::Jet>")
jetsLabel = ("BESTProducer", "savedJets", "run")
modeHandle = Handle("std::vector<int>")
modeLabel = ("BESTProducer", "decayMode", "run")
npvHandle = Handle("std::vector<int>")
npvLabel = ("BESTProducer", "nPV", "run")
nnLabels = []
nnLabels.append( ("BESTProducer", "FWmoment1H", "run") )
nnLabels.append( ("BESTProducer", "FWmoment1W", "run") )
nnLabels.append( ("BESTProducer", "FWmoment1Z", "run") )
nnLabels.append( ("BESTProducer", "FWmoment1top", "run") )
nnLabels.append( ("BESTProducer", "FWmoment2H", "run") )
nnLabels.append( ("BESTProducer", "FWmoment2W", "run") )
nnLabels.append( ("BESTProducer", "FWmoment2Z", "run") )
nnLabels.append( ("BESTProducer", "FWmoment2top", "run") )
nnLabels.append( ("BESTProducer", "FWmoment3H", "run") )
nnLabels.append( ("BESTProducer", "FWmoment3W", "run") )
nnLabels.append( ("BESTProducer", "FWmoment3Z", "run") )
nnLabels.append( ("BESTProducer", "FWmoment3top", "run") )
nnLabels.append( ("BESTProducer", "FWmoment4H", "run") )
nnLabels.append( ("BESTProducer", "FWmoment4W", "run") )
nnLabels.append( ("BESTProducer", "FWmoment4Z", "run") )
nnLabels.append( ("BESTProducer", "FWmoment4top", "run") )
nnLabels.append( ("BESTProducer", "SDmass", "run") )
nnLabels.append( ("BESTProducer", "aplanarityH", "run") )
nnLabels.append( ("BESTProducer", "aplanarityW", "run") )
nnLabels.append( ("BESTProducer", "aplanarityZ", "run") )
nnLabels.append( ("BESTProducer", "aplanaritytop", "run") )
nnLabels.append( ("BESTProducer", "bDisc", "run") )
nnLabels.append( ("BESTProducer", "bDisc1", "run") )
nnLabels.append( ("BESTProducer", "bDisc2", "run") )
nnLabels.append( ("BESTProducer", "et", "run") )
nnLabels.append( ("BESTProducer", "eta", "run") )
nnLabels.append( ("BESTProducer", "isotropyH", "run") )
nnLabels.append( ("BESTProducer", "isotropyW", "run") )
nnLabels.append( ("BESTProducer", "isotropyZ", "run") )
nnLabels.append( ("BESTProducer", "isotropytop", "run") )
nnLabels.append( ("BESTProducer", "q", "run") )
nnLabels.append( ("BESTProducer", "sphericityH", "run") )
nnLabels.append( ("BESTProducer", "sphericityW", "run") )
nnLabels.append( ("BESTProducer", "sphericityZ", "run") )
nnLabels.append( ("BESTProducer", "sphericitytop", "run") )
nnLabels.append( ("BESTProducer", "sumPH", "run") )
nnLabels.append( ("BESTProducer", "sumPW", "run") )
nnLabels.append( ("BESTProducer", "sumPZ", "run") )
nnLabels.append( ("BESTProducer", "sumPtop", "run") )
nnLabels.append( ("BESTProducer", "sumPzH", "run") )
nnLabels.append( ("BESTProducer", "sumPzW", "run") )
nnLabels.append( ("BESTProducer", "sumPzZ", "run") )
nnLabels.append( ("BESTProducer", "sumPztop", "run") )
nnLabels.append( ("BESTProducer", "tau21", "run") )
nnLabels.append( ("BESTProducer", "tau32", "run") )
nnLabels.append( ("BESTProducer", "thrustH", "run") )
nnLabels.append( ("BESTProducer", "thrustW", "run") )
nnLabels.append( ("BESTProducer", "thrustZ", "run") )
nnLabels.append( ("BESTProducer", "thrusttop", "run") )
nnLabels.append( ("BESTProducer", "m12H", "run") )
nnLabels.append( ("BESTProducer", "m23H", "run") )
nnLabels.append( ("BESTProducer", "m13H", "run") )
nnLabels.append( ("BESTProducer", "m1234H", "run") )
nnLabels.append( ("BESTProducer", "m12W", "run") )
nnLabels.append( ("BESTProducer", "m23W", "run") )
nnLabels.append( ("BESTProducer", "m13W", "run") )
nnLabels.append( ("BESTProducer", "m1234W", "run") )
nnLabels.append( ("BESTProducer", "m12Z", "run") )
nnLabels.append( ("BESTProducer", "m23Z", "run") )
nnLabels.append( ("BESTProducer", "m13Z", "run") )
nnLabels.append( ("BESTProducer", "m1234Z", "run") )
nnLabels.append( ("BESTProducer", "m12top", "run") )
nnLabels.append( ("BESTProducer", "m23top", "run") )
nnLabels.append( ("BESTProducer", "m13top", "run") )
nnLabels.append( ("BESTProducer", "m1234top", "run") )
#nnLabels.append( ("BESTProducer", "genPt", "run") )
#nnLabels.append( ("BESTProducer", "topSize", "run") )
#nnLabels.append( ("BESTProducer", "dRjetParticle", "run") )
nnHandles = [ Handle("vector<float>") ] * len(nnLabels)





filelist = options.files
files= []
nevents = 0
#s = options.files
s = 'root://cmsxrootd.fnal.gov/' + options.files
files.append(s)
print 'Added' + s

mlp = joblib.load('BEST_mlp_6bin.pkl')
scaler = joblib.load('BEST_scaler_6bin.pkl')

binMap = {}
count = 1
for t in [0, 1, 2]:
	for w in [0, 1, 2]:
		for z in [0,1,2]:
			for h in [0,1,2]:
				thisbin = 1000*h + 100*w + 10*z + t
				binMap[thisbin] = count
				count += 1
				print count, t, w, z, h, t+w+z+h


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

		print event.eventAuxiliary().run()
		print event.eventAuxiliary().luminosityBlock()
		print event.eventAUxiliary().event()

		event.getByLabel(jetsLabel, jetsHandle)
		if not jetsHandle.isValid():
			continue

		jets = jetsHandle.product()
		event.getByLabel(npvLabel, npvHandle)
		npv[0] = npvHandle.product()[0]
		event.getByLabel(modeLabel, modeHandle)
		for i in xrange(len(nnHandles)):
			event.getByLabel((nnLabels[i]), nnHandles[i])
			products[nnLabels[i][1]] = nnHandles[i].product() 
		numTop[0] = 0
		numW[0] = 0
		numZ[0] = 0
		numH[0] = 0
		numQCD[0] = 0				
		numJets[0] = 0
		
		htV[0] = 0.0

		#print "RUN", event.eventAuxiliary().run(), "EVENT", event.eventAuxiliary().event()		

		modes = modeHandle.product()
		if (len(modes) >= 2):
			decayMode1[0] = modes[0]
			decayMode2[0] = modes[1]

		savedIndices = []
		tagLabels = []
		probs_t = []
		probs_W = []
		probs_Z = []
		probs_H = []
		probs_j = []

	
		for j in xrange(len(jets)):

			nhf = jets[j].neutralHadronEnergy() / jets[j].energy()
                	nef = jets[j].neutralEmEnergy() / jets[j].energy()
                	chf = jets[j].chargedHadronEnergy() / jets[j].energy()
                	cef = jets[j].chargedEmEnergy() / jets[j].energy()
                	nconstituents = jets[j].numberOfDaughters()
                	nch = jets[j].chargedMultiplicity()
                	goodJet = \
                  		nhf < 0.99 and \
                  		nef < 0.99 and \
                  		chf > 0.00 and \
                  		cef < 0.99 and \
                  		nconstituents > 1 and \
                  		nch > 0

                	if not goodJet :
				continue

			if jets[j].pt() < 400:
				continue

			#genPtV[0] =  products['genPt'][j]
			#topSizeV[0] = products['topSize'][j]
			#dRgenParticleV[0] = products['dRjetParticle'][j]

			jetPt[0] = jets[j].pt()
			jetPhi[0] = jets[j].phi()
			jetEta[0] = jets[j].eta()

			jetSDmass[0] = products['SDmass'][j]

			pzOverp_top = products['sumPztop'][j] / (products['sumPtop'][j] + 0.01) 
			pzOverp_W = products['sumPzW'][j] / (products['sumPW'][j] + 0.01) 
			pzOverp_Z = products['sumPzZ'][j] / (products['sumPZ'][j] + 0.01)
			pzOverp_H = products['sumPzH'][j] / (products['sumPH'][j] + 0.01)


			nnArray = np.array( [  products['SDmass'][j], products['tau32'][j], products['tau21'][j], products['FWmoment1top'][j], products['FWmoment2top'][j], products['FWmoment3top'][j], products['FWmoment4top'][j], products['isotropytop'][j], products['aplanaritytop'][j], products['sphericitytop'][j], products['thrusttop'][j], products['FWmoment1W'][j], products['FWmoment2W'][j], products['FWmoment3W'][j], products['FWmoment4W'][j], products['isotropyW'][j], products['aplanarityW'][j], products['sphericityW'][j], products['thrustW'][j], products['FWmoment1Z'][j], products['FWmoment2Z'][j], products['FWmoment3Z'][j], products['FWmoment4Z'][j], products['isotropyZ'][j], products['aplanarityZ'][j], products['sphericityZ'][j], products['thrustZ'][j], products['FWmoment1H'][j], products['FWmoment2H'][j], products['FWmoment3H'][j], products['FWmoment4H'][j], products['isotropyH'][j], products['aplanarityH'][j], products['sphericityH'][j], products['thrustH'][j], products['bDisc'][j], products['bDisc1'][j], products['bDisc2'][j], products['q'][j], products['m12W'][j], products['m13W'][j], products['m23W'][j], products['m1234W'][j], products['m12Z'][j], products['m13Z'][j], products['m23Z'][j], products['m1234Z'][j], products['m12top'][j], products['m13top'][j], products['m23top'][j], products['m1234top'][j], products['m12H'][j], products['m13H'][j], products['m23H'][j], products['m1234H'][j], pzOverp_top, pzOverp_W, pzOverp_Z, pzOverp_H  ])


			


			if np.isnan(np.min(nnArray)):
				continue

			nnArray_transformed = scaler.transform( nnArray )



			best_bin = mlp.predict( nnArray_transformed )

			best_probs = mlp.predict_proba( nnArray_transformed )

			htV[0] += jetPt[0]

			prob_j[0] = best_probs[0][0]
			prob_W[0] = best_probs[0][1]
			prob_Z[0] = best_probs[0][2]
			prob_H[0] = best_probs[0][3]
			prob_t[0] = best_probs[0][4]
			prob_b[0]

			best_class[0] = best_bin[0]			


			purity_cut = 0.0
			if best_bin[0] == 0 and prob_j[0] > purity_cut:
				numQCD[0] += 1
			if best_bin[0] == 1 and prob_W[0] > purity_cut:
				numW[0] += 1
				h_WTagIndex.Fill( len(savedIndices) )
			if best_bin[0] == 2 and prob_Z[0] > purity_cut:
				numZ[0] += 1
				h_ZTagIndex.Fill( len(savedIndices) )
			if best_bin[0] == 3 and prob_H[0] > purity_cut:
				numH[0] += 1
				h_HTagIndex.Fill( len(savedIndices) )
			if best_bin[0] == 4 and prob_t[0] > purity_cut:
				numTop[0] += 1
				h_topTagIndex.Fill( len(savedIndices) )
			numJets[0] += 1

			

			probs_t.append(prob_t[0])
			probs_W.append(prob_W[0])
			probs_Z.append(prob_Z[0])
			probs_H.append(prob_H[0])
			probs_j.append(prob_j[0])
			savedIndices.append(j)
			tagLabels.append(best_bin[0])
			outTree.Fill()

		minDiff = 9999.
		mT1 = -9999.
		mT2 = -9999.


		eventBin[0] = binMap[ 1000*min(2,numH[0]) + 100*min(2,numW[0]) + 10*min(2,numZ[0]) + min(2,numTop[0]) ]


		if len(savedIndices) >= 3:


			jet1LV = ROOT.TLorentzVector()
			jet2LV = ROOT.TLorentzVector()
			jet3LV = ROOT.TLorentzVector()
			
			jet1LV.SetPtEtaPhiM( jets[savedIndices[0]].pt(), jets[savedIndices[0]].eta(), jets[savedIndices[0]].phi(), jets[savedIndices[0]].mass() )
			jet2LV.SetPtEtaPhiM( jets[savedIndices[1]].pt(), jets[savedIndices[1]].eta(), jets[savedIndices[1]].phi(), jets[savedIndices[1]].mass() )
			jet3LV.SetPtEtaPhiM( jets[savedIndices[2]].pt(), jets[savedIndices[2]].eta(), jets[savedIndices[2]].phi(), jets[savedIndices[2]].mass() )


			jet0pt = jets[savedIndices[0]].pt()
			jet1pt = jets[savedIndices[1]].pt()
			jet2pt = jets[savedIndices[2]].pt()
		 	
			jetPt_j0[0] = jet0pt
			jetPt_j1[0] = jet1pt
			jetPt_j2[0] = jet2pt
			jetEta_j0[0] = jets[savedIndices[0]].eta()
			jetEta_j1[0] = jets[savedIndices[1]].eta()
			jetEta_j2[0] = jets[savedIndices[2]].eta()
			jetPhi_j0[0] = jets[savedIndices[0]].phi()
			jetPhi_j1[0] = jets[savedIndices[1]].phi()
			jetPhi_j2[0] = jets[savedIndices[2]].phi()

			jetSDmass_j0[0] =products['SDmass'][savedIndices[0]]
			jetSDmass_j1[0] =products['SDmass'][savedIndices[1]]
			jetSDmass_j2[0] =products['SDmass'][savedIndices[2]]

	
			best_class_j0[0] = tagLabels[0]
			best_class_j1[0] = tagLabels[1]
			best_class_j2[0] = tagLabels[2]

			prob_t_j0[0] = probs_t[0]
			prob_t_j1[0] = probs_t[1]
			prob_t_j2[0] = probs_t[2]
			prob_W_j0[0] = probs_W[0]
			prob_W_j1[0] = probs_W[1]
			prob_W_j2[0] = probs_W[2]
			prob_Z_j0[0] = probs_Z[0]
			prob_Z_j1[0] = probs_Z[1]
			prob_Z_j2[0] = probs_Z[2]
			prob_H_j0[0] = probs_H[0]
			prob_H_j1[0] = probs_H[1]
			prob_H_j2[0] = probs_H[2]
			prob_j_j0[0] = probs_j[0]
			prob_j_j1[0] = probs_j[1]
			prob_j_j2[0] = probs_j[2]


			if (len(savedJets >= 4)):

			jet4LV = ROOT.TLorentzVector()
			jet4LV.SetPtEtaPhiM( jets[savedIndices[3]].pt(), jets[savedIndices[3]].eta(), jets[savedIndices[3]].phi(), jets[savedIndices[3]].mass() )
			jet3pt = jets[savedIndices[3]].pt()
			jetPt_j3[0] = jet3pt
			jetEta_j3[0] = jets[savedIndices[3]].eta()
			jetPhi_j3[0] = jets[savedIndices[3]].phi()
			jetSDmass_j3[0] =products['SDmass'][savedIndices[3]]
			best_class_j3[0] = tagLabels[3]
			prob_t_j3[0] = probs_t[3]
			prob_W_j3[0] = probs_W[3]
			prob_Z_j3[0] = probs_Z[3]
			prob_H_j3[0] = probs_H[3]
			prob_j_j3[0] = probs_j[3]

			m12 = (jet1LV + jet2LV).M()
			m13 = (jet1LV + jet3LV).M()
			m14 = (jet1LV + jet4LV).M()
			m23 = (jet2LV + jet3LV).M()
			m24 = (jet2LV + jet4LV).M()
			m34 = (jet3LV + jet4LV).M()


			diff1 = abs(m12 - m34)
			diff2 = abs(m13 - m24)
			diff3 = abs(m14 - m23)


			if diff1 < minDiff:
				mT1 = m12
				mT2 = m34
				minDiff = diff1

			if diff2 < minDiff:
				mT1 = m13
				mT2 = m24
				minDiff = diff2
			
			if diff3 < minDiff:
				mT1 = m14
				mT2 = m23
				minDiff = diff3


			deltaM[0] = minDiff
			Tmass1[0] = mT1
			Tmass2[0] = mT2

			eventTree.Fill()



f.cd()
f.Write()
f.Close()
