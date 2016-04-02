import sys
import os

sys.path.append(os.path.join(os.path.dirname(__file__), '..'))
import test_framework

test_bin = "../../src/cat/gh-test-cat"
pass_fail_counts = [0,0] # element [0] is fail count, element [1] is pass count

pass_fail_counts[test_framework.run_test(test_bin, ["empty_file"], "cat_empty_file")] += 1
pass_fail_counts[test_framework.run_test(test_bin, ["file1"], "cat_file1")] += 1
pass_fail_counts[test_framework.run_test(test_bin, ["file1", "file2"], "cat_file1_file2")] += 1
pass_fail_counts[test_framework.run_test(test_bin, ["file1", "file3"], "cat_file1_file3")] += 1
pass_fail_counts[test_framework.run_test(test_bin, ["file3"], "cat_file3")] += 1
pass_fail_counts[test_framework.run_test(test_bin, ["file3", "file1"], "cat_file3_file1")] += 1

with open("most_recent_stats", 'w') as f:
    to_write = str(pass_fail_counts[1]) + ' ' + str(pass_fail_counts[0])
    f.write(to_write)

print "cat passes:" , pass_fail_counts[1] , "cat fails:" , pass_fail_counts[0]
