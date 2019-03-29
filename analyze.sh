#!/bin/bash


file=$1
sample=$2
process=$3


cd ${_CONDOR_SCRATCH_DIR}
source /cvmfs/cms.cern.ch/cmsset_default.sh  ## if a tcsh script, use .csh instead of .sh
export SCRAM_ARCH=slc6_amd64_gcc530
eval `scramv1 project CMSSW CMSSW_9_0_1`
cp csv_rwt_fit_hf_2016_01_28.root csv_rwt_fit_lf_2016_01_28.root getCSV.py JECfiles.tar best_sf.py getJECUnc.py vlq_fwlite_6bin_DATA.py vlq_fwlite_6bin.py BEST_mlp_6bin.pkl BEST_scaler_6bin.pkl BEST_mlp.pkl BEST_scaler.pkl CMSSW_9_0_1/src/.
cd CMSSW_9_0_1/src/
eval `scramv1 runtime -sh`
ls
echo ${file}

tar -xvf JECfiles.tar

python vlq_fwlite_6bin.py --files ${file} --isData 1 
#python vlq_fwlite_6bin.py --files ${file} --pdf 1 --q2 1
#python vlq_fwlite_6bin.py --files ${file} --jec 1
#python vlq_fwlite_6bin.py --files ${file} --jec -1
#python vlq_fwlite_6bin.py --files ${file} --jer 1
#python vlq_fwlite_6bin.py --files ${file} --jer -1
#python best_sf.py --files ${file}


mv outplots.root outplots_${sample}_${process}.root
mv outplots_jecUp.root outplots_${sample}_${process}_jecUp.root
mv outplots_jecDn.root outplots_${sample}_${process}_jecDn.root
mv outplots_jerUp.root outplots_${sample}_${process}_jerUp.root
mv outplots_jerDn.root outplots_${sample}_${process}_jerDn.root
xrdcp -f outplots_${sample}_${process}.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/
xrdcp -f outplots_${sample}_${process}_jecUp.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/
xrdcp -f outplots_${sample}_${process}_jecDn.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/
xrdcp -f outplots_${sample}_${process}_jerUp.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/
xrdcp -f outplots_${sample}_${process}_jerDn.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/
