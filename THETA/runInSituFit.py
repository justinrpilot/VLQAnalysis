import json

def allhadfilter(hname):


    print hname
    names = hname.split("__")
    channel = names[0]
    process = names[1]

    if ("tprime" not in process):
	return hname

    keep = True
   # if "tprime" in process:
#	    keep = False

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
    for p in mod.processes:
    	#if 'tprime' in p: mod.scale_predictions(9.0, p)
	mod.add_lognormal_uncertainty('lumi', math.log(1.027), p)
#       mod.add_lognormal_uncertainty('ttagT', math.log(1.10),p)
    mod.add_lognormal_uncertainty('xsec_ttbar', math.log(1.10), 'ttbar') 
    mod.add_lognormal_uncertainty('xsec_qcd', math.log(1.30), 'qcd') 
    
    return mod

infile = "testInSituFit.root"
model = build_model__ttbar_allhad(infile, True)
model_summary(model, all_nominal_templates=True, shape_templates=True)

opts = Options()


options = Options()
options.set('minimizer', 'strategy', 'robust')
options.set('minimizer', 'minuit_tolerance_factor', '10000000')

signal_process_groups = {'': []}
parVals = mle(model, input='data', n=1, signal_process_groups = signal_process_groups, options = options, with_covariance=True)
print parVals

parameter_values = {}
for p in model.get_parameters([]):
    parameter_values[p] = parVals[''][p][0][0]
histos = evaluate_prediction(model, parameter_values, include_signal = False)
write_histograms_to_rootfile(histos, 'histos-mle.root')

parameter_values_nom = {}

for p in model.get_parameters([]):
    parameter_values_nom[p] = 0.0
histos = evaluate_prediction(model, parameter_values_nom, include_signal = False)
write_histograms_to_rootfile(histos, 'histos-nom.root')

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
