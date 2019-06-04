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
cp CMS_lumi.C CMS_lumi.h makeThetaTemplates*_3j.C makeThetaTemplates_jecUp_3j.C makeThetaTemplates_jecDn_3j.C makeThetaTemplates_jerUp_3j.C makeThetaTemplates_jerDn_3j.C makeThetaTemplates_pdfUp_3j.C makeThetaTemplates_pdfDn_3j.C makeThetaTemplates_q2Up_3j.C makeThetaTemplates_q2Dn_3j.C makeThetaTemplates_pileupUp_3j.C makeThetaTemplates_pileupDn_3j.C makeBinHistogram.C BEST_rates_DATA_6bin.root jetPt_templates.root data_bkgEst_3jet.C applyRates_3jet.C CMSSW_9_0_1/src/.
cd CMSSW_9_0_1/src/
eval `scramv1 runtime -sh`
ls


root -l -b data_bkgEst_3jet.C\(${nTop},${nW},${nZ},${nH},${nB}\)
hadd -f shapes_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.root shapes_dataB.root shapes_dataC.root shapes_dataD.root shapes_dataE.root shapes_dataF.root shapes_dataG.root shapes_dataH.root shapes_dataH2.root

xrdcp -f shapes_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/


root -l -b makeThetaTemplates_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_jecUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_jecDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_jerUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_jerDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_pdfUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_pdfDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_q2Up_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_q2Dn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_pileupUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_pileupDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+QCD_SFwt\",\"QCD_SF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-QCD_SFwt\",\"QCD_SF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+B_SFwt\",\"B_SF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-B_SFwt\",\"B_SF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+T_SFwt\",\"T_SF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-T_SFwt\",\"T_SF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+W_SFwt\",\"W_SF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-W_SFwt\",\"W_SF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+Z_SFwt\",\"Z_SF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-Z_SFwt\",\"Z_SF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+H_SFwt\",\"H_SF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-H_SFwt\",\"H_SF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+B_misSFwt\",\"B_misSF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-B_misSFwt\",\"B_misSF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+T_misSFwt\",\"T_misSF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-T_misSFwt\",\"T_misSF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+W_misSFwt\",\"W_misSF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-W_misSFwt\",\"W_misSF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+Z_misSFwt\",\"Z_misSF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-Z_misSFwt\",\"Z_misSF\"\)
root -l -b makeThetaTemplates_genUp_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1+H_misSFwt\",\"H_misSF\"\)
root -l -b makeThetaTemplates_genDn_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th},\"1-H_misSFwt\",\"H_misSF\"\)


hadd -f ${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_theta3j_${br_tz}tz_${br_bw}bw_${br_th}th.root ${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_histos.root *Up.root *Dn.root
xrdcp -f ${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_theta3j_${br_tz}tz_${br_bw}bw_${br_th}th.root HT3j_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.pdf HT3j_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_log.pdf root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/

root -l -b makeBinHistogram.C\(${nTop},${nW},${nZ},${nH},${nB},${bin}\)
xrdcp -f ${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_binhistos.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/


