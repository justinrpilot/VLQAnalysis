#!/bin/bash


nTop=$1
nW=$2
nZ=$3
nH=$4
nB=$5

cd ${_CONDOR_SCRATCH_DIR}
source /cvmfs/cms.cern.ch/cmsset_default.sh  ## if a tcsh script, use .csh instead of .sh
export SCRAM_ARCH=slc6_amd64_gcc530
eval `scramv1 project CMSSW CMSSW_9_0_1`
cp CMS_lumi.C CMS_lumi.h sampleQCD.C makeThetaTemplates.C makeBinHistogram.C BEST_rates_6bin.root jetPt_templates.root data_bkgEst.C applyRates.C makeClosure.C doClosureTest.C CMSSW_9_0_1/src/.
cd CMSSW_9_0_1/src/
eval `scramv1 runtime -sh`
ls


root -l -b doClosureTest.C\(${nTop},${nW},${nZ},${nH},${nB}\)
xrdcp -f closure_${nTop}t_${nW}w_${nZ}z_${nH}h_${nB}b.pdf closure_${nTop}t_${nW}w_${nZ}z_${nH}h_${nB}b_log.pdf root://cmseos.fnal.gov//store/user/pilot/ClosureTestFiles/ 


