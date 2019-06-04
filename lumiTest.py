json = {"1": [[1,10], [15,20]], "2": [[5, 7]]}

run = 1
lumi = 13

print json
print "Run", run, "Lumi", lumi

found = False
if str(run) in json:
	print "found run"
	for lumimin,lumimax in json[str(run)]:
		print lumimin,lumimax
		if lumi >= lumimin and lumi <= lumimax:
			print "GOOD"
			found = True


print "Lumi Found?", found
