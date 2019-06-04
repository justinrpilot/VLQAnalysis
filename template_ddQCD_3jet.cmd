universe = vanilla
Executable=analyze_ddQCD_3jet.sh
Should_Transfer_Files = YES
WhenToTransferOutput  = ON_EXIT
Transfer_Input_Files = CMS_lumi.C, CMS_lumi.h, makeBinHistogram.C, makeThetaTemplates_3j.C, makeThetaTemplates_jecUp_3j.C, makeThetaTemplates_jecDn_3j.C, makeThetaTemplates_jerUp_3j.C, makeThetaTemplates_jerDn_3j.C, makeThetaTemplates_pdfUp_3j.C, makeThetaTemplates_pdfDn_3j.C, makeThetaTemplates_q2Up_3j.C, makeThetaTemplates_q2Dn_3j.C, makeThetaTemplates_pileupUp_3j.C, makeThetaTemplates_pileupDn_3j.C, makeThetaTemplates_genUp_3j.C, makeThetaTemplates_genDn_3j.C, applyRates_3jet.C, BEST_rates_DATA_6bin.root, data_bkgEst_3jet.C, jetPt_templates.root
notify_user = pilot@FNAL.GOV
Output = condor_out_$(Process)_$(Cluster).stdout
Error  = condor_out_$(Process)_$(Cluster).stderr
Log    = condor_out_$(Process)_$(Cluster).log
Notification    = Never
