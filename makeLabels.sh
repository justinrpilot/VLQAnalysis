#!/bin/bash

i=0
for b in 0 1 2 3 4
	do
	for t in 0 1 2 3 4
		do for w in 0 1 2 3 4 
			do for z in 0 1 2 3 4
				do for h in 0 1 2 3 4
					do
					num=0
					let "num = $t+$w+$h+$z+$b" 
					if [ $num -gt 4 ]
					then
						continue
					fi
					let "i += 1";
					echo "stack->GetHistogram()->GetXaxis()->SetBinLabel(${i}, \"${t}t ${w}W ${z}Z ${h}H ${b}b\");";
					#echo "./submit_ddQCD.sh ${t} ${w} ${z} ${h} ${b} ${i}"
					done
				done
			done
		done
	done
