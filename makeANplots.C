{

makeStack("prob_b_j0", "b Probability", "jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 50, 0, 1, "prob_b", "prob_b");
makeStack("prob_Z_j0", "Z Probability", "jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 50, 0, 1, "prob_Z", "prob_Z");
makeStack("prob_W_j0", "W Probability", "jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 50, 0, 1, "prob_W", "prob_W");
makeStack("prob_H_j0", "H Probability", "jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 50, 0, 1, "prob_H", "prob_H");
makeStack("prob_t_j0", "t Probability", "jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 50, 0, 1, "prob_t", "prob_t");


makeStack("jetPt_j0", "Leading Jet p_{T} [GeV]", "numJets >= 4 && jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 50, 0, 2400, "jetPt_j0", "jetPt_j0");
makeStack("jetEta_j0", "Leading Jet #eta", "numJets >= 4 && jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 40, -3, 3, "jetEta_j0", "jetEta_j0");
makeStack("jetPhi_j0", "Leading Jet #phi", "numJets >= 4 && jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 40, -4, 4, "jetPhi_j0", "jetPhi_j0");
makeStack("jetSDmass_j0", "Leading Jet m_{SD} [GeV]", "numJets >= 4 && jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 50, 0, 400, "jetSDmass_j0", "jetSDmass_j0");
makeStack("best_class_j0", "Leading Jet BEST Category", "numJets >= 4 && jetPt_j0 > 400 && abs(jetEta_j0) < 2.4", 6, 0, 6, "best_class_j0", "best_class_j0");
makeStack("jetPt_j1", "Jet 2 p_{T} [GeV]", "numJets >= 4 && jetPt_j1 > 400 && abs(jetEta_j1) < 2.4", 50, 0, 2400, "jetPt_j1", "jetPt_j1");
makeStack("jetEta_j1", "Jet 2 #eta", "numJets >= 4 && jetPt_j1 > 400 && abs(jetEta_j1) < 2.4", 40, -3, 3, "jetEta_j1", "jetEta_j1");
makeStack("jetPhi_j1", "Jet 2 #phi", "numJets >= 4 && jetPt_j1 > 400 && abs(jetEta_j1) < 2.4", 40, -4, 4, "jetPhi_j1", "jetPhi_j1");
makeStack("jetSDmass_j1", "Jet 2 m_{SD} [GeV]", "numJets >= 4 && jetPt_j1 > 400 && abs(jetEta_j1) < 2.4", 50, 0, 400, "jetSDmass_j1", "jetSDmass_j1");
makeStack("jetPt_j2", "Jet 3 p_{T} [GeV]", "numJets >= 4 && jetPt_j2 > 400 && abs(jetEta_j2) < 2.4", 50, 0, 2400, "jetPt_j2", "jetPt_j2");
makeStack("jetEta_j2", "Jet 3 #eta", "numJets >= 4 && jetPt_j2 > 400 && abs(jetEta_j2) < 2.4", 40, -3, 3, "jetEta_j2", "jetEta_j2");
makeStack("jetPhi_j2", "Jet 3 #phi", "numJets >= 4 && jetPt_j2 > 400 && abs(jetEta_j2) < 2.4", 40, -4, 4, "jetPhi_j2", "jetPhi_j2");
makeStack("jetSDmass_j2", "Jet 3 m_{SD} [GeV]", "numJets >= 4 && jetPt_j2 > 400 && abs(jetEta_j2) < 2.4", 50, 0, 400, "jetSDmass_j2", "jetSDmass_j2");
makeStack("jetPt_j3", "Jet 4 p_{T} [GeV]", "numJets >= 4 && jetPt_j3 > 400 && abs(jetEta_j3) < 2.4", 50, 0, 2400, "jetPt_j3", "jetPt_j3");
makeStack("jetEta_j3", "Jet 4 #eta", "numJets >= 4 && jetPt_j3 > 400 && abs(jetEta_j3) < 2.4", 40, -3, 3, "jetEta_j3", "jetEta_j3");
makeStack("jetPhi_j3", "Jet 4 #phi", "numJets >= 4 && jetPt_j3 > 400 && abs(jetEta_j3) < 2.4", 40, -4, 4, "jetPhi_j3", "jetPhi_j3");
makeStack("jetSDmass_j3", "Jet 4 m_{SD} [GeV]", "numJets >= 4 && jetPt_j3 > 400 && abs(jetEta_j3) < 2.4", 50, 0, 400, "jetSDmass_j3", "jetSDmass_j3");

makeStack("numJets", "Number of AK8 Jets", "1", 8, 0, 8, "numJets", "numJets");
makeStack("ht", "H_{T} [GeV]", "numJets >= 4 && 1", 50, 0, 8000, "ht", "ht");


//makeStack("jetSDmass_j0", "Leading Jet m_{SD} [GeV]", "jetPt_j0 > 500 && abs(jetEta_j0) < 2.4 && prob_Z_j0 > 0.9", 50, 0, 400, "jetSDmass_j0", "jetSDmass_j0");

}
