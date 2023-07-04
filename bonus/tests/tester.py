import subprocess
import filecmp

file_compare_path = "./compare/"
file_compare =  ["abel.cor", "bill.cor", "pdd.cor", "tyron.cor"]

valid_tests = ["abel.s", "bill.s", "pdd.s", "tyron.s"]
valid_tests_path = "./valid_tests/"

invalid_tests = [".s", "file.txt"]
invalid_tests_path = "./invalid_tests/"

asm_path = "./../../asm/asm"

def execute_valid_file(file):
    res = subprocess.run([asm_path, valid_tests_path + file])
    return_value = res.returncode
    if (return_value != 0):
        print("Invalid exit status: " + file + " (" + str(return_value) + ")")
        return 1
    return 0

def verif_valid_tests():
    nb_valid = 0

    for i in range(len(valid_tests)):
        if (execute_valid_file(valid_tests[i]) == 0):
            if (not (filecmp.cmp(file_compare_path + file_compare[i], file_compare[i]))):
                print("File " + file_compare[i] + " doesn't match the expected output")
                nb_valid -= 1
            else:
                print("Correct file: " + file_compare[i])
            nb_valid += 1
    print("\nTest valid result: " + str(nb_valid) + "/" + str(len(file_compare)))
    subprocess.run("rm -f *.cor", shell=True)

def execute_invalid_file(file):
    print(file + ": ", end='')
    res = subprocess.run([asm_path, invalid_tests_path + file], capture_output=True, text=True)
    print(res.stderr, end='')
    return_value = res.returncode
    if (return_value != 84):
        print("Invalid exit status: " + file + " (" + str(return_value) + ")")
        return 1
    return 0

def verif_invalid_tests():
    nb_valid = 0

    for i in range(len(invalid_tests)):
        if (execute_invalid_file(invalid_tests[i]) == 0):
            nb_valid += 1
    print("\nTest invalid result: " + str(nb_valid) + "/" + str(len(invalid_tests)))
    subprocess.run("rm -f *.cor", shell=True)

verif_valid_tests()
print("")
verif_invalid_tests()