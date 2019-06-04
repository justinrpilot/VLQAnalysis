import json

def allhadfilter(hname):


    #print hname
    names = hname.split("__")
    channel = names[0]
    process = names[1]

    #if ("tprime" not in process):
    #    return hname

    keep = True
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

    if 'diboson' in process and 'SF' in hname:
	keep = False
	

    #print channel, process, keep

    if (not keep):
	hname = hname.replace("__", "DONOTUSE")
	
    #print hname
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

    for chan in mod.get_observables():
	print chan
    	for p in mod.processes:
		if 'qcd' in p: continue
		tags = 0
		mod.add_lognormal_uncertainty('lumi', 0.027, p, chan)
    		#if '1W' in chan: 
		#	tags += 1
		#	mod.add_lognormal_uncertainty('W_SF', sf_W, p, chan)
    		#if '2W' in chan: 
		#	tags += 2
		#	mod.add_lognormal_uncertainty('W_SF', 2*sf_W, p, chan)
    		#if '3W' in chan: 
		#	tags += 3
		#	mod.add_lognormal_uncertainty('W_SF', 3*sf_W, p, chan)
    		#if '4W' in chan: 
		#	tags += 4
		#	mod.add_lognormal_uncertainty('W_SF', 4*sf_W, p, chan)
    		#if '1t' in chan: 
		#	tags += 1
		#	mod.add_lognormal_uncertainty('t_SF', sf_t, p, chan)
    		#if '2t' in chan: 
		#	tags += 2
		#	mod.add_lognormal_uncertainty('t_SF', 2*sf_t, p, chan)
    		#if '3t' in chan: 
		#	tags += 3
		#	mod.add_lognormal_uncertainty('t_SF', 3*sf_t, p, chan)
    		#if '4t' in chan: 
		#	tags += 4
		#	mod.add_lognormal_uncertainty('t_SF', 4*sf_t, p, chan)
    		#if '1Z' in chan: 
		#	tags += 1
		#	mod.add_lognormal_uncertainty('Z_SF', sf_Z, p, chan)
    		#if '2Z' in chan: 
		#	tags += 2
		#	mod.add_lognormal_uncertainty('Z_SF', 2*sf_Z, p, chan)
    		#if '3Z' in chan: 
		#	tags += 3
		#	mod.add_lognormal_uncertainty('Z_SF', 3*sf_Z, p, chan)
    		#if '4Z' in chan:
		#	tags += 4
		#	mod.add_lognormal_uncertainty('Z_SF', 4*sf_Z, p, chan)
    		#if '1H' in chan: 
		#	tags += 1
		#	mod.add_lognormal_uncertainty('H_SF', sf_H, p, chan)
    		#if '2H' in chan: 
		#	tags += 2
		#	mod.add_lognormal_uncertainty('H_SF', 2*sf_H, p, chan)
    		#if '3H' in chan: 
		#	tags += 3
		#	mod.add_lognormal_uncertainty('H_SF', 3*sf_H, p, chan)
    		#if '4H' in chan: 
		#	tags += 4
		#	mod.add_lognormal_uncertainty('H_SF', 4*sf_H, p, chan)
    		#if '1b' in chan: 
		#	tags += 1
		#	mod.add_lognormal_uncertainty('b_SF', sf_b, p, chan)
    		#if '2b' in chan: 
		#	tags += 2
		#	mod.add_lognormal_uncertainty('b_SF', 2*sf_b, p, chan)
    		#if '3b' in chan: 
		#	tags += 3
		#	mod.add_lognormal_uncertainty('b_SF', 3*sf_b, p, chan)
    		#if '4b' in chan: 
		#	tags += 4
		#	mod.add_lognormal_uncertainty('b_SF', 4*sf_b, p, chan)
		#mod.add_lognormal_uncertainty('q_SF', (4-tags)*sf_q, p, chan)
	#mod.add_lognormal_uncertainty('xsec_ttbar', 0.05, 'ttbar', chan)
   	mod.add_lognormal_uncertainty('xsec_wjets', 0.10, 'wjets', chan) 
   	mod.add_lognormal_uncertainty('xsec_zjets', 0.10, 'zjets', chan) 
   	mod.add_lognormal_uncertainty('xsec_diboson', 0.50, 'diboson', chan) 
   	mod.add_lognormal_uncertainty('xsec_ttV', 0.50, 'ttV', chan) 
   	mod.add_lognormal_uncertainty('xsec_higgs', 0.50, 'higgs', chan) 
    return mod

infile = "templates/theta4jet_0.6tz_0.0bw_0.4th.root" 
model = build_model__ttbar_allhad(infile, True)
#model_summary(model, create_plots=True, all_nominal_templates=False, shape_templates=True)

opts = Options()


options = Options()
options.set('minimizer', 'strategy', 'robust')
options.set('minimizer', 'minuit_tolerance_factor', '10000000')

#runs = bayesian_quantiles(model, input='toys:0', n=1000, run_theta=False, hint_method='zero')
#runs_data = bayesian_quantiles(model, input='data', n=10, run_theta=False,  hint_method='zero')
# results = bayesian_limits(model, input='toys:0', n=10, run_theta = True, **args)
#print results
#for sig in model.signal_process_groups:
#       print sig, runs[sig]
#       run = runs[sig]
#       run_data = runs_data[sig]
#       thisOptions = Options()
#       run.get_configfile(thisOptions)
#       run_data.get_configfile(thisOptions)


expected, observed = bayesian_limits(model, 'all', n_toy = 500, run_theta = True)
expected.write_txt("limitsJAN_0.6tz_0.0bw_0.4th.txt")
observed.write_txt("obslimitsJAN_0.6tz_0.0bw_0.4th.txt")
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
