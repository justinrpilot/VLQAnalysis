import ROOT
import random

jet_energy_corrections = [ # Values from https://twiki.cern.ch/twiki/bin/view/CMS/JECDataMC
    [1,276811,"Summer16_23Sep2016BCDV4_DATA"],
    [276831,278801,"Summer16_23Sep2016EFV4_DATA"],
    [278802,280385,"Summer16_23Sep2016GV4_DATA"],
    [280386,float("inf"),"Summer16_23Sep2016HV4_DATA"]
]

def createJEC(jecSrc, jecLevelList, jetAlgo):
    jecParameterList = ROOT.vector('JetCorrectorParameters')()
    # Load the different JEC levels (the order matters!)
    for jecLevel in jecLevelList:
        jecParameter = ROOT.JetCorrectorParameters('%s_%s_%s.txt' % (jecSrc, jecLevel, jetAlgo));
        jecParameterList.push_back(jecParameter)
    # Chain the JEC levels together
    return ROOT.FactorizedJetCorrector(jecParameterList)


class DataJEC:
    JECList = []
    def __init__(self,inputmap):
        for minrun,maxrun,version in inputmap:
            JECMap = {}
            JECMap['jecAK8'] = createJEC(version, ['L1FastJet', 'L2Relative', 'L3Absolute', 'L2L3Residual'], 'AK8PFchs')
            self.JECList.append([minrun, maxrun, JECMap])

    def GetJECMap(self, run):
        for minrun,maxrun,returnmap in self.JECList:
            if run >= minrun and run <= maxrun:
                return returnmap
        raise Exception("Error! Run "+str(run)+" not found in run ranges")

    def jecAK4(self, run):
        JECMap = self.GetJECMap(run)
        return JECMap["jecAK4"]

    def jecAK8(self, run):
        JECMap = self.GetJECMap(run)
        return JECMap["jecAK8"]



def getJEC(jecSrc, jet, area, rho, nPV): # get JEC and uncertainty for an *uncorrected* jet
    # Give jet properties to JEC source
    jecSrc.setJetEta(jet.eta())
    jecSrc.setJetPt(jet.pt())
    jecSrc.setJetE(jet.energy())
    jecSrc.setJetA(area)
    jecSrc.setRho(rho)
    jecSrc.setNPV(nPV)
    jec = jecSrc.getCorrection() # get jet energy correction


    return jec



def getJECUnc(jecUncSrc, jet, level):

	jecUncSrc.setJetPhi(jet.phi())
	jecUncSrc.setJetPt( jet.pt())
	jecUncSrc.setJetEta( jet.eta())

	corr = jecUncSrc.getUncertainty(level)

	return corr


jet_energy_resolution = [ # Values from https://twiki.cern.ch/twiki/bin/view/CMS/JetResolution
    (0.0, 0.5, 1.122, 0.026),
    (0.5, 0.8, 1.167, 0.048),
    (0.8, 1.1, 1.168, 0.046),
    (1.1, 1.3, 1.029, 0.066),
    (1.3, 1.7, 1.115, 0.030),
    (1.7, 1.9, 1.041, 0.062),
    (1.9, 2.1, 1.167, 0.086),
    (2.1, 2.3, 1.094, 0.093),
    (2.3, 2.5, 1.168, 0.120),
    (2.5, 2.8, 1.266, 0.132),
    (2.8, 3.0, 1.595, 0.175),
    (3.0, 3.2, 0.998, 0.066),
    (3.2, 4.7, 1.226, 0.145),
]


def getJER(jetEta, sysType):
    """
    Here, jetEta should be the jet pseudorapidity, and sysType is:
        nominal : 0
        down    : -1
        up      : +1
    """

    if sysType not in [0, -1, 1]:
        raise Exception('ERROR: Unable to get JER! use type=0 (nom), -1 (down), +1 (up)')

    for (etamin, etamax, scale_nom, scale_uncert) in jet_energy_resolution:
        if etamin <= abs(jetEta) < etamax:
            if sysType < 0:
                return scale_nom - scale_uncert
            elif sysType > 0:
                return scale_nom + scale_uncert
            else:
                return scale_nom
    raise Exception('ERROR: Unable to get JER for jets at eta = %.3f!' % jetEta)



def applyJER(jet, genPt, level):
    eta = jet.eta()
    if eta>=5.0:
     	eta=2.999
    if eta<=-5.0:
       	eta=-2.999
    smear     = getJER( eta,  0) 
    smearUp   = getJER( eta,  1) 
    smearDn   = getJER( eta, -1) 
    recopt    = jet.pt() 
    if genPt > 0.0:#if jet.genJet() != None:
        genpt     = genPt
        deltapt   = (recopt-genpt)*(smear-1.0)
        deltaptUp = (recopt-genpt)*(smearUp-1.0)
        deltaptDn = (recopt-genpt)*(smearDn-1.0)
        ptsmear   = max(0.0, (recopt+deltapt)/recopt)
        ptsmearUp = max(0.0, (recopt+deltaptUp)/recopt)
        ptsmearDn = max(0.0, (recopt+deltaptDn)/recopt)
    else:
	ptsmear = 1.0
	ptsmearUp = 1.0
	ptsmearDn = 1.0
    if level == 0: return ptsmear
    if level == 1: return ptsmearUp
    if level == -1: return ptsmearDn
