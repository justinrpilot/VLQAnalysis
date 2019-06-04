{
computeWPEff("best_class == 1 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/WW3.root", kGreen+1, "Boosted W", "BEST W Category", "eff_pt_W");
computeWPEff("best_class == 2 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/outplots_JMAR_ZZ.root", kOrange, "Boosted Z", "BEST Z Category", "eff_pt_Z");
computeWPEff("best_class == 3 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/outplots_JMAR_HH.root", kViolet, "Boosted H", "BEST H Category", "eff_pt_H");
//computeWPEff("best_class == 4 && abs(jetEta) < 1.5 && dRgenParticle < 0.6 && topSize < 0.6", "abs(jetEta) < 1.5 && dRgenParticle < 0.6 && topSize < 0.6", "JMAR/TT3.root", kRed, "Boosted t", "BEST t Category", "eff_pt_t");
computeWPEff("best_class == 4 && abs(jetEta) < 1.5", "abs(jetEta) < 1.5", "JMAR/TT3.root", kRed, "Boosted t", "BEST t Category", "eff_pt_t");
computeWPEff("best_class == 1 && abs(jetEta) < 1.5", "abs(jetEta) < 1.5", "JMAR/WW3.root", kGreen+1, "Boosted W", "BEST W Category", "eff_pt_W");
computeWPEff("best_class == 2 && abs(jetEta) < 1.5", "abs(jetEta) < 1.5", "JMAR/outplots_JMAR_ZZ.root", kOrange, "Boosted Z", "BEST Z Category", "eff_pt_Z");
computeWPEff("best_class == 3 && abs(jetEta) < 1.5", "abs(jetEta) < 1.5", "JMAR/outplots_JMAR_HH.root", kViolet, "Boosted H", "BEST H Category", "eff_pt_H");

computeWPEff("prob_W > 0.72 && best_class == 1 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/WW3.root", kGreen+1, "Boosted W", "BEST P(W) > 0.72", "eff_pt_W_WP");
computeWPEff("prob_Z > 0.58 && best_class == 2 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/outplots_JMAR_ZZ.root", kOrange, "Boosted Z", "BEST P(Z) > 0.58", "eff_pt_Z_WP");
computeWPEff("prob_H > 0.90 && best_class == 3 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/outplots_JMAR_HH.root", kViolet, "Boosted H", "BEST P(H) > 0.90", "eff_pt_H_WP");
computeWPEff("prob_t > 0.86 && best_class == 4 && abs(jetEta) < 1.5 && dRgenParticle < 0.6 && topSize < 0.6", "abs(jetEta) < 1.5 && dRgenParticle < 0.6 && topSize < 0.6", "JMAR/TT3.root", kRed, "Boosted t", "BEST P(t) > 0.86", "eff_pt_t_WP");

computeWPEff_NPV("best_class == 1 && genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6",  "JMAR/WW3.root", kGreen+1, "Boosted W", "BEST W Category", "eff_npv_W");
computeWPEff_NPV("best_class == 2 && genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/outplots_JMAR_ZZ.root", kOrange, "Boosted Z", "BEST Z Category", "eff_npv_Z");
computeWPEff_NPV("best_class == 3 && genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/outplots_JMAR_HH.root", kViolet, "Boosted H", "BEST H Category", "eff_npv_H");
computeWPEff_NPV("best_class == 4 && genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6 && topSize < 0.6", "genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6 && topSize < 0.6", "JMAR/TT3.root", kRed, "Boosted t", "BEST t Category", "eff_npv_t");

computeWPEff_NPV("prob_W > 0.72 && best_class == 1 && genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6",  "JMAR/WW3.root", kGreen+1, "Boosted W", "BEST P(W) > 0.72", "eff_npv_W_WP");
computeWPEff_NPV("prob_Z > 0.58 && best_class == 2 && genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/outplots_JMAR_ZZ.root", kOrange, "Boosted Z", "BEST P(Z) > 0.58", "eff_npv_Z_WP");
computeWPEff_NPV("prob_H > 0.90 && best_class == 3 && genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6", "JMAR/outplots_JMAR_HH.root", kViolet, "Boosted H", "BEST P(H) > 0.90", "eff_npv_H_WP");
computeWPEff_NPV("prob_t > 0.86 && best_class == 4 && genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6 && topSize < 0.6", "genPt > 1000 && genPt < 1400 && abs(jetEta) < 1.5 && dRgenParticle < 0.6 && topSize < 0.6", "JMAR/TT3.root", kRed, "Boosted t", "BEST P(t) > 0.86", "eff_npv_t_WP");
}
