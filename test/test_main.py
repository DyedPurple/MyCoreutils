import subprocess as sp
import os

totals = [0,0] # [number of passes, number of fails]
utils_to_test = ["cat"]

for util_name in utils_to_test:
    print "Testing" , util_name
    os.chdir(util_name + "_test")
    sp.call(["python", util_name + "_test.py"])
    try:
        with open("most_recent_stats", 'r') as out:
            splat = out.readline().strip().split()
            totals[0] += int(splat[0])
            totals[1] += int(splat[1])
        sp.call(["rm", "most_recent_stats"])
    except IOError:
        print "Could not open most_recent_stats file for" , util_name
    sp.call(["rm", "temp.stdout"])
    os.chdir('..')

print "Total number of passes:" , totals[0] , "Total number of fails" , totals[1]
