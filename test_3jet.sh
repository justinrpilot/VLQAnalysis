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


root -l -b -q data_bkgEst_3jet.C\(${nTop},${nW},${nZ},${nH},${nB}\)
hadd -f shapes_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.root shapes_dataB.root shapes_dataC.root shapes_dataD.root shapes_dataE.root shapes_dataF.root shapes_dataG.root shapes_dataH.root shapes_dataH2.root

xrdcp -f shapes_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/


root -l -b -q makeThetaTemplates_3j.C\(${nTop},${nW},${nZ},${nH},${nB},${br_bw},${br_tz},${br_th}\)

display HT3j_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b_log.pdf

