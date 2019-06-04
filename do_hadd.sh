#!/bin/bash

#do hadd of the vlq files
eval `scramv1 runtime -sh`

for argument in "$@"
do
    echo ${argument};
    #hadd -f root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_${argument}.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep ${argument} | grep "outplots"`; 
    
    hadd -f ~/3DayLifetime/outplots_${argument}.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "${argument}_" | grep "outplots" | grep -v "jec" | grep -v "jer"`;
    #hadd -f ~/3DayLifetime/4jet_${argument}.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "${argument}" `;
    eos root://cmseos.fnal.gov rm /store/user/pilot/VLQAnaMay/outplots_${argument}_jecUp.root;
    eos root://cmseos.fnal.gov rm /store/user/pilot/VLQAnaMay/outplots_${argument}_jecDn.root;
    eos root://cmseos.fnal.gov rm /store/user/pilot/VLQAnaMay/outplots_${argument}_jerUp.root;
    eos root://cmseos.fnal.gov rm /store/user/pilot/VLQAnaMay/outplots_${argument}_jerDn.root;
    #hadd -f ~/3DayLifetime/outplots_${argument}_jecUp.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "${argument}_" | grep "outplots" | grep "jecUp"`;
    #hadd -f ~/3DayLifetime/outplots_${argument}_jecDn.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "${argument}_" | grep "outplots" | grep "jecDn"`;
    #hadd -f ~/3DayLifetime/outplots_${argument}_jerUp.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "${argument}_" | grep "outplots" | grep "jerUp"`;
    #hadd -f ~/3DayLifetime/outplots_${argument}_jerDn.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/pilot/VLQAnaMay/ | grep "${argument}_" | grep "outplots" | grep "jerDn"`;
    xrdcp -f ~/3DayLifetime/outplots_${argument}.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_${argument}.root
    #xrdcp -f ~/3DayLifetime/outplots_${argument}_jecUp.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_${argument}_jecUp.root
    #xrdcp -f ~/3DayLifetime/outplots_${argument}_jecDn.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_${argument}_jecDn.root
    #xrdcp -f ~/3DayLifetime/outplots_${argument}_jerUp.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_${argument}_jerUp.root
    #xrdcp -f ~/3DayLifetime/outplots_${argument}_jerDn.root root://cmseos.fnal.gov//store/user/pilot/VLQAnaMay/outplots_${argument}_jerDn.root

done
