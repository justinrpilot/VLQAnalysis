#!/bin/bash

for tz in 0.0 0.2 0.4 0.6 0.8 1.0
	do
	for bw in 0.0 0.2 0.4 0.6 0.8 1.0
		do
		for th in 0.0 0.2 0.4 0.6 0.8 1.0
			do
			num=0.0
			num=`echo "${tz}+${bw}+${th}" | bc`
			if [ $num == 1.0 ]
			then
				echo ${tz} ${th} ${bw}
				#hadd -f ~/3DayLifetime/theta3jet_${tz}tz_${bw}bw_${th}th.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "theta3j_" | grep ${tz}tz | grep ${bw}bw | grep ${th}th`
				hadd -f ~/3DayLifetime/theta4jet_${tz}tz_${bw}bw_${th}th.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "theta_" | grep ${tz}tz | grep ${bw}bw | grep ${th}th`
				hadd -f ~/3DayLifetime/thetaBB4jet_${tz}tz_${bw}bw_${th}th.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "thetaBB_" | grep ${tz}tz | grep ${bw}bw | grep ${th}th`

				#sed s/"BRTZ BRBW BRTH"/"${tz} ${bw} ${th}"/ submitAllDDQCD_3j_template.sh > submitAllDDQCD3j_${tz}tZ_${bw}bW_${th}tH.sh
				#sed s/"BRTZ BRBW BRTH"/"${tz} ${bw} ${th}"/ submitAllDDQCD_template.sh > submitAllDDQCD_${tz}tZ_${bw}bW_${th}tH.sh
			fi
			done
		done
	done

