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

## Running the limits with Theta

## Making the plots for the paper
