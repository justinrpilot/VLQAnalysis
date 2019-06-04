#!/bin/bash


nTop=$1
nW=$2
nZ=$3
nH=$4
nB=$5
bin=$6
br_tz=$7
br_bw=$8
br_th=$9



cd ${_CONDOR_SCRATCH_DIR}
source /cvmfs/cms.cern.ch/cmsset_default.sh  ## if a tcsh script, use .csh instead of .sh
export SCRAM_ARCH=slc6_amd64_gcc530
eval `scramv1 project CMSSW CMSSW_9_0_1`
cp CMS_lumi.C CMS_lumi.h makeThetaTemplates*.C makeThetaTemplates_jecUp.C makeThetaTemplates_jecDn.C makeThetaTemplates_jerUp.C makeThetaTemplates_jerDn.C makeThetaTemplates_pdfUp.C makeThetaTemplates_pdfDn.C makeThetaTemplates_q2Up.C makeThetaTemplates_q2Dn.C makeThetaTemplates_pileupUp.C makeThetaTemplates_pileupDn.C makeBinHistogram.C BEST_rates_3jet_DATA_6bin.root BEST_rates_DATA_6bin.root jetPt_templates.root data_bkgEst.C applyRates.C makeThetaTemplates_csvUp.C makeThetaTemplates_csvDn.C CMSSW_9_0_1/src/.
cd CMSSW_9_0_1/src/
eval `scramv1 runtime -sh`
ls


#root -l -b data_bkgEst.C\(${nTop},${nW},${nZ},${nH},${nB}\)
#hadd -f shapes_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.root shapes_dataB.root shapes_dataC.root shapes_dataD.root shapes_dataE.root shapes_dataF.root shapes_dataG.root shapes_dataH.root shapes_dataH2.root


#xrdcp -f shapes_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/

root -l -b makeThetaTemplates.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_jecUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_jecDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_jerUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_jerDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_pdfUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_pdfDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_q2Up.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_q2Dn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_csvUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_csvDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_pileupUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_pileupDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*QCD_SFwt\",\"QCD_SF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*QCD_SFwt\",\"QCD_SF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*B_SFwt\",\"B_SF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*B_SFwt\",\"B_SF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*T_SFwt\",\"T_SF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*T_SFwt\",\"T_SF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*W_SFwt\",\"W_SF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*W_SFwt\",\"W_SF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*Z_SFwt\",\"Z_SF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*Z_SFwt\",\"Z_SF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*H_SFwt\",\"H_SF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*H_SFwt\",\"H_SF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*B_misSFwt\",\"B_misSF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*B_misSFwt\",\"B_misSF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*T_misSFwt\",\"T_misSF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*T_misSFwt\",\"T_misSF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*W_misSFwt\",\"W_misSF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*W_misSFwt\",\"W_misSF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*Z_misSFwt\",\"Z_misSF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*Z_misSFwt\",\"Z_misSF\"\)
root -l -b makeThetaTemplates_genUp.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+0.25*H_misSFwt\",\"H_misSF\"\)
root -l -b makeThetaTemplates_genDn.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-0.25*H_misSFwt\",\"H_misSF\"\)

hadd -f ${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_theta_${br_tz}tz_${br_bw}bw_${br_th}th.root ${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_histos.root *Up.root *Dn.root 
xrdcp -f ${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_theta_${br_tz}tz_${br_bw}bw_${br_th}th.root HT_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.pdf HT_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_log.pdf root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/

#root -l -b makeBinHistogram.C\(${nTop},${nW},${nZ},${nH},${nB},${bin}\)
#xrdcp -f ${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_binhistos.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/
