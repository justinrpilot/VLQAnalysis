# Running the BEST VLQ Analysis

## Producing the trees from MiniAOD

The input variables for BEST (and other kinematic quantities) are stored in the event via EDProducers, as detailed in the repository at https://github.com/justinrpilot/BESTAnalysis

The instructions there can be followed to produce flat trees that are then used for NN training, and for performing the VLQ analysis.


## Running the analysis over the trees

This requires a trained NN model -- currently the NN is used in a pkl file format, along with the scaler (used to transform the input variables) in a pkl format as well.  Details of the training can be found in https://github.com/justinrpilot/BESTTraining

Once you have the pkl files for the NN model and scaler, the main script to perform the analysis selection is ```vlq_fwlite_6bin.py``` 

This script ```vlq_fwlite_6bin.py``` has several options:
* ```files``` -- The list of input files (produced with BESTProducer as mentioned above)
* ```outname``` -- A name that is prepended to the output ROOT filename
* ```maxevents``` -- The number of events to run (defaults to all)
* ```jec``` -- Evaluate the JEC-shifted kinematics, +1 for up, -1 for down
* ```jer``` -- Evaluate the JER-shifted kinematics, +1 for up, -1 for down
* ```pdf``` -- Run the PDF evaluation, storing the result in a branch.  This applies only for signal and ttbar.  Be sure not to use this if the PDF product is not stored in the event, as this will lead to a crash
* ```q2``` -- Run the Q^2 evaluation, storing the result in a branch.  Same rules apply as for PDF
* ```isData``` -- flag to run as data
* ```csvSys``` -- evaluate the CSV reshaping systematic

This can be run locally to test with a small number of events (use ```/store/user/...``` with the files option.  The ```root://cmseos.fnal.gov/``` is automatically prepended.

For running over the full trees as produced above, the submission to condor can be done as follows:

```./submit.sh filelist.txt <identifier>```

Where ```filelist.txt``` is a txt file containing all the files to be run, one filename per line, starting with ```/store/user/...```, and ```<identifier>``` is a unique string that will be used to hadd files later.  The script will submit one condor job per filename in the txt file (but these run generally very quickly)

The commands are listed in ```analyze.sh```, and the files passed to condor are defined in ```submit_template.cmd```.  Be sure to change relevant options in ```analyze.sh``` to evaluate PDF, Q2, data, JEC/JER etc.  Typically the nominal, JEC, JER are all done in the same job, resulting in several output ROOT files with the systematic variations. (Be sure to change to point the outputs to your personal EOS area)

Once the jobs are finished, you can hadd the outputs together with the script
```./do_hadd.sh <identifier1> <identifier2> ...```
This will hadd all the files together and make one file per identifier that can be used as inputs for subsequent steps.  Check the script to comment/uncomment lines as needed.  Be careful as it is set up to remove existing files before hadding.


## Measuring the mistag rates

The next step is to measure the mistag rates, needed to evaluate the data-driven background.

This is done with the macro ```makeFakeRateData.C``` (or ```makeFakeRate.C``` for QCD MC, or ```makeFakeRate_genericMC.C``` to test with other samples).  Make sure it includes the correct path to your files -- the data should be used to make the measurement for the main analysis, and the QCD for closure tests.

The macro can be run for all the BEST categories with ```drawAll.C```.  This is also where you can change the selections (switch to 3-jet or 4-jet or other regions in which to measure the rates)

Running the macro with
```
root -l 
.X drawAll.C 
```
results in a ROOT file that is used as input for running the data driven method.

(Mistag rates can be plotted with ```drawMistagRates.C```

## Running the data-driven background

The file ```applyRates.C``` contains the function ```sampleEvents``` which does the machinery to loop through events and evaluate the data-driven background estimate based on the mistag rates (the path to the mistag rate file needs appears here.

To run the data-driven background estimate:
```
root -l
.L data_bkgEst.C;
data_bkgEst(int nTop, int nW, int nZ, int nH, int nB);
```
The number of each category is needed as input to run the method for a specific signal region.
This results in files ```shapes_data*.root``` which contain the HT histograms for that given category.

The bkg estimation needs only to be done once to produce the ```shapes_data*.root``` files -- these are then saved and used as input to the rest of the analysis.  Of course, if selections are changed, this step should be re-done.

The data-driven background estimate is (can be) done for all of the categories when the final templates are produced.  This is done with condor in the script ```analyze_ddQCD.sh``` or ```analyzeBB_ddQCD.sh``` with the lines:
```
root -l -b data_bkgEst.C\(${nTop},${nW},${nZ},${nH},${nB}\)
hadd -f shapes_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.root shapes_dataB.root shapes_dataC.root shapes_dataD.root shapes_dataE.root shapes_dataF.root shapes_dataG.root shapes_dataH.root shapes_dataH2.root

xrdcp -f shapes_${nTop}t_${nW}W_${nZ}Z_${nH}H_${nB}b.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/
```
These lines can be commented out after doing this the first time, when the files will be saved.

There are analagous files for the BB case, as well as the 3-jet cases.

To run all the categories using condor, see the next section (you can include only the data-driven bkg commands in your ```analyze_ddQCD.sh``` to run only this part.

To do the closure test, two files are used: ```makeClosure.C``` and ```sampleQCD.C```.  These use as input the ROOT file containing the QCD mistag rates.

The closure test can be evaluated locally with ```doClosureTest.C```:
```
root -l
.L doClosureTest.C;
doClosureTest(int t, int w, int z, int h, int b);
```
Here the arguments are the multiplicities of BEST tags for the desired category.
Again this can be done with condor for all categories wth the script ```submit_closureQCD.sh```.  And all categories can be submitted by running
```./submitAllClosureTests.sh```

This evaluates the ```analyze_closureQCD.sh``` and copies PDF files to the area defined in that file showing the results of the closure test.



## Making Theta templates (or other plots)

To run the analysis and produce the final HT templates after the data-driven shapes are produced, a similar procedure is followed.  But this needs to be done once for each category, as well as once for each of the points of the BR scan.

The files ```makeThetaTemplates.C``` and ```makeThetaTemplatesBB.C``` are used here, along with each of the additional files to evaluate the systematic-shifted inputs (**these files could be merged in the future with appropriate options, as they essentially do exactly the same thing with small variations**).  The input files need to be defined in each to point to the hadded files from the earlier step, as well as the name of the ROOT file containing the data-driven shapes.

This is again set up to run on condor.  The files ```submitAllDDQCD_template.sh``` and ```makeSubmits.sh``` are used to generate the files used to submit to condor.  You can run this with 
```./makeSubmits.sh``` after changing appropriately for running TT/BB (change the template to ```submit_ddQCD.sh``` or ```submitBB_ddQCD.sh``` and run twice).

The lines in ```makeSubmits.sh```
```
sed s/"BRTZ BRBW BRTH"/"${tz} ${bw} ${th}"/ submitAllDDQCD_3j_template.sh > submitAllDDQCD3j_${tz}tZ_${bw}bW_${th}tH.sh
sed s/"BRTZ BRBW BRTH"/"${tz} ${bw} ${th}"/ submitAllDDQCD_template.sh > submitAllDDQCD_${tz}tZ_${bw}bW_${th}tH.sh
```
Are used to do the BR-dependent changes, while the lines
```
hadd -f ~/3DayLifetime/theta4jet_${tz}tz_${bw}bw_${th}th.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "theta_" | grep ${tz}tz | grep ${bw}bw | grep ${th}th`
hadd -f ~/3DayLifetime/thetaBB4jet_${tz}tz_${bw}bw_${th}th.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "thetaBB_" | grep ${tz}tz | grep ${bw}bw | grep ${th}th`
```
Are used to merge ROOT files after the first running (see below).  The ```makeSubmits.sh``` script is sort of a general purpose thing to loop over all BR combinations and do some commands and can be changed as you wish.


Then you can submit all of the jobs with a simple set of bash scripts:
```
for file in `ls submitAllDDQCD_*.sh`; do ./${file}; done
for file in `ls submitBBAllDDQCD_*.sh`; do ./${file}; done
```

Again, ```analyze_ddQCD.sh``` (or BB) has the set of commands and input files that are run upon submission.  These should be updated to your personal EOS path.

These jobs will produce ROOT files which can be combined to make the theta input files with ```makeSubmits``` as detailed above.


## Running the limits with Theta

I've copied the latest templates used to produce the limits to EOS at
```/store/user/pilot/BEST_VLQ_THETA/```

Once the Theta templates are produced, they can be run using scripts/files in the ```THETA``` directory of this repository.

One file is used for each BR combination, for each of BB and TT limit hypotheses.  Again a the ```THETA/makeSubmits.sh``` is used to make changes for each of the combinations, with ```runBB_pre.py``` and ```run_pre.py``` used as templates.  To make the submission files, do:
```
./makeSubmits.sh runBB_pre.py runBB
./makeSubmits.sh runTT_pre.py run
```
This produces theta config files for each BR combination.

You can then submit everything to condor:
* First run theta locally to create the cfg files used to submit to condor:
```
for file in `ls run_*tH.py`; do ../utils2/theta-auto.py ${file}; done
for file in `ls runBB_*tH.py`; do ../utils2/theta-auto.py ${file}; done
```
* Then you can submit all of the jobs to condor (it uses ```submit.sh``` and you need to make the Theta gridpack as instructed on the Theta website):
```
for dir in `ls -d runBB_*_*tH/`; do echo ${dir}; cd ${dir}; for file in `ls *.cfg`; do echo ${file} > submit.txt; ../submit.sh submit.txt; done; cd ..;done;
for dir in `ls -d run_*_*tH/`; do echo ${dir}; cd ${dir}; for file in `ls *.cfg`; do echo ${file} > submit.txt; ../submit.sh submit.txt; done; cd ..;done;
```
CAREFUL, as this will submit usually few thousand condor jobs to run the limits, which can take several hours each.  Recommend to test with one file first to make sure it's working correctly!
* When the jobs finish, you should have ```*.db``` files in the individual theta directories.  Next is to copy them to cache so we can run Theta again locally to make the text files with the limit results:
```
for dir in `ls -d run*tH/`; do echo ${dir}; cd ${dir}; mkdir cache; for file in `ls *.cfg *.db`; do cp ${file} cache/.; done; cd ..;done;
for dir in `ls -d runBB*tH/`; do echo ${dir}; cd ${dir}; mkdir cache; for file in `ls *.cfg *.db`; do cp ${file} cache/.; done; cd ..;done;
```
* Update the theta files with runTheta=False:
```
./makeSubmits.sh runBB_post.py runBB
./makeSubmits.sh runTT_post.py run
```
* Run Theta to make the text files:
```
for file in `ls run_*tH.py`; do ../utils2/theta-auto.py ${file}; done
for file in `ls runBB_*tH.py`; do ../utils2/theta-auto.py ${file}; done
```

You can then plot the limits with your favorite script!


## Making the plots for the paper

The instructions for the paper plots can be found on the GitLab repository for B2G-18-005, along with inputs and macros.

Other plotting scripts which are outdated but may still be of interest are listed below:


