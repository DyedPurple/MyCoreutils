import subprocess

def run_test(binary, in_files, out_file):
    with open("temp.stdout", "w") as out:
        subprocess.call([binary] + in_files, stdout = out)
        try:
            subprocess.check_output(["cmp", "temp.stdout", out_file])
        except subprocess.CalledProcessError:
            print test_bin , "test with inputs" , in_files , "failed"
            return False
        else:
            return True
