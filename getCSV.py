from ROOT import TFile, TH1D, TH1F, TH1 
import copy

def get_csv_wgt( jetPt, jetEta, jetCSV, jetFlavor = 0, iSys = 0):

	if iSys == -1:
		return 1.0

	if jetCSV < -0.1:
		return 1.0

	if abs(jetFlavor) == 4:
		return 1.0

	heavy = False
	if abs(jetFlavor) == 5:
		heavy = True

	fileHF = TFile.Open("csv_rwt_fit_hf_2016_01_28.root", "READ")
	fileLF = TFile.Open("csv_rwt_fit_lf_2016_01_28.root", "READ")	


	suffix = [ "final", "final_JESUp", "final_JESDown", "final_HFUp", "final_HFDown", "final_Stats1Up", "final_Stats1Down", "final_Stats2Up", "final_Stats2Down"]


	hTest0 = fileLF.Get( "csv_ratio_Pt3_Eta0_"+suffix[iSys] )
	hTest1 = fileLF.Get( "csv_ratio_Pt3_Eta1_"+suffix[iSys] )
	hTest2 = fileLF.Get( "csv_ratio_Pt3_Eta2_"+suffix[iSys] )

	hTestHF = fileHF.Get( "csv_ratio_Pt4_Eta0_"+suffix[iSys] )


	csvHFwt = -999.
	csvLFwt = -999.


	hTest = hTest0
	if abs(jetEta) >= 0.0 and abs(jetEta) < 0.8:
		hTest = hTest0
	if abs(jetEta) >= 0.8 and abs(jetEta) < 1.6:
		hTest = hTest1
	if abs(jetEta) >= 1.6 and abs(jetEta) < 2.4:
		hTest = hTest2

	if heavy:
		hTest = hTestHF


	csvwt = hTest.GetBinContent(  hTest.FindBin(jetCSV) )

	return csvwt
