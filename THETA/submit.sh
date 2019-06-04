#!/bin/bash

filelist=$1

for file in $(cat $filelist);
do
	cp ../submit_template.cmd submit_this.cmd;
        echo ${file};
	sed -i "s/INFILE/${file}/g" submit_this.cmd;
        echo "Arguments = ${file}" >> submit_this.cmd;
        echo "Queue 1" >> submit_this.cmd;
	condor_submit submit_this.cmd;
done

