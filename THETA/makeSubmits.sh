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
				sed s/"BRTZtz_BRBWbw_BRTHth"/"${tz}tz_${bw}bw_${th}th"/ $1 > $2_${tz}tZ_${bw}bW_${th}tH.py
			fi
			done
		done
	done

