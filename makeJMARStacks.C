{

makeStack("jetSDmass", "Jet#prime m_{SD} [GeV]", "jetPt > 1000 && jetPt < 1400 && abs(jetEta) < 1.5 && best_class == 1 && prob_W > 0.72", 50,40,120, "jmar_W", "jmar_W");
makeStack("jetSDmass", "Jet m_{SD} [GeV]", "jetPt > 1000 && jetPt < 1400 && abs(jetEta) < 1.5 && best_class == 2 && prob_Z > 0.58", 50,40,120, "jmar_Z", "jmar_Z");
makeStack("jetSDmass", "Jet m_{SD} [GeV]", "jetPt > 1000 && jetPt < 1400 && abs(jetEta) < 1.5 && best_class == 3 && prob_H > 0.90", 50,85,165, "jmar_H", "jmar_H");
makeStack("jetSDmass", "Jet m_{SD} [GeV]", "jetPt > 1000 && jetPt < 1400 && abs(jetEta) < 1.5 && best_class == 4 && prob_t > 0.86", 50,130,220, "jmar_t", "jmar_t");

}
