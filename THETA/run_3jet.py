import json

def allhadfilter(hname):


    print hname
    names = hname.split("__")
    channel = names[0]
    process = names[1]

    keep = True
    numTags = int(channel[0])+int(channel[3])+int(channel[6])+ int(channel[9]) + int(channel[12])
    if numTags > 3: 
	keep = False

    if (("sig800" in channel) and ("tprime800" not in process)):
        keep = False
    if (("sig1000" in channel) and ("tprime1000" not in process)):
        keep = False
    if (("sig1200" in channel) and ("tprime1200" not in process)):
        keep = False
    if (("sig1400" in channel) and ("tprime1400" not in process)):
        keep = False
    if (("sig1600" in channel) and ("tprime1600" not in process)):
        keep = False
    if (("sig1800" in channel) and ("tprime1800" not in process)):
        keep = False

    print channel, process, keep

    if (not keep):
	hname = hname.replace("__", "DONOTUSE")
	
    print hname
    return hname



def build_model__ttbar_allhad(allhadfile, mcstat):

    print "Using All-Had File: ", allhadfile

    mod = build_model_from_rootfile(allhadfile, root_hname_to_convention=allhadfilter, include_mc_uncertainties=True)
    mod.fill_histogram_zerobins()
    mod.set_signal_processes("tprime*")
    
    sf_t = 0.02
    sf_W = 0.02
    sf_Z = 0.02
    sf_H = 0.02
    sf_b = 0.02
    sf_q = 0.02

    mod.add_lognormal_uncertainty('xsec_ttbar', 0.05, 'ttbar')
    mod.add_lognormal_uncertainty('xsec_wjets', 0.10, 'wjets') 
    mod.add_lognormal_uncertainty('xsec_zjets', 0.10, 'zjets') 
    mod.add_lognormal_uncertainty('xsec_diboson', 0.50, 'diboson') 
    mod.add_lognormal_uncertainty('xsec_ttV', 0.50, 'ttV') 
    mod.add_lognormal_uncertainty('xsec_higgs', 0.50, 'higgs') 
    return mod

infile = "files_3jet/theta3jet_0.0tz_1.0bw_0.0th.root" 
model = build_model__ttbar_allhad(infile, True)
model_summary(model, create_plots=True, all_nominal_templates=False, shape_templates=False)

opts = Options()


options = Options()
options.set('minimizer', 'strategy', 'robust')
options.set('minimizer', 'minuit_tolerance_factor', '10000000')

#runs = bayesian_quantiles(model, input='toys:0', n=500, run_theta=False, hint_method='zero')
#runs_data = bayesian_quantiles(model, input='data', n=10, run_theta=False,  hint_method='zero')
# results = bayesian_limits(model, input='toys:0', n=10, run_theta = True, **args)
#print results
#for sig in model.signal_process_groups:
#       print sig, runs[sig]
#       run = runs[sig]
##      run_data = runs_data[sig]
#       thisOptions = Options()
#       run.get_configfile(thisOptions)
#       run_data.get_configfile(thisOptions)


expected, observed = bayesian_limits(model, 'expected', n_toy = 50, run_theta = True)
expected.write_txt("limits_3jet_bWbW.txt")

#parameter_values_nom = {}

#for p in model.get_parameters([]):
#    parameter_values_nom['beta_signal'] = 1.0
#    parameter_values_nom[p] = 0.0
#histos = evaluate_prediction(model, parameter_values_nom, include_signal = True)

#out_histos_dict = dict()
#for channel in histos:
#    out_histos_dict[channel] = dict()
#    for hist in histos[channel]:
#        out_histos_dict[channel].update( {hist : list(histos[channel][hist].get_values())} )

#with open('histos.json', 'w') as file:
#    file.write(json.dumps(out_histos_dict))

    #discovery(model, use_data=False, maxit=50, n = 100, n_expected = 100 )
#    pVals = pvalue(model, input='toys:1.0', n = 50, options=options, bkgtoys_n = 100, bkgtoys_n_runs = 3)
#    print pVal

#    options = Options()
#    options.set('minimizer', 'strategy', 'robust')
#    options.set('minimizer', 'minuit_tolerance_factor', '10000000')
#    parVals = mle(model, input='toys:0', n=10, options = options)
#    print parVals
#    parameter_values = {} 
#    parameter_values_nom = {} 
#    for p in model.get_parameters([]):
#        parameter_values[p] = parVals['zpn3000'][p][0][0]
#        parameter_values_nom[p] = 0.0#parVals['zpn3000'][p][0][0]
#    histos = evaluate_prediction(model, parameter_values, include_signal = False)
#    write_histograms_to_rootfile(histos, 'histos-mle.root')
#    histos = evaluate_prediction(model, parameter_values_nom, include_signal = False)
#    write_histograms_to_rootfile(histos, 'histos-nom.root')


   # exp.write_txt("limits_combo_test.txt")
   # obs.write_txt("limits_obs_combo_test.txt")
   # o_file = open('limits.txt', 'w')
   # for i in range(len(exp.x)):
   #     o_file.write( '%.2f %.5f' % (exp.x[i], exp.y[i]))
   #     o_file.write(' %.5f %.5f' % (exp.bands[1][1][i], exp.bands[1][0][i]))
   #     o_file.write(' %.5f %.5f' % (exp.bands[0][1][i], exp.bands[0][0][i]))
   #     o_file.write(' %.5f'      % (obs.y[i] if obs else -1.))
   #     o_file.write('\n')
   # o_file.close()
