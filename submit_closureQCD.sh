#!/bin/bash


cp template_closureQCD.cmd submit_this.cmd;
echo "Arguments = $1 $2 $3 $4 $5 \$(Process)" >> submit_this.cmd;
echo "Queue 1" >> submit_this.cmd;

condor_submit submit_this.cmd;

	
