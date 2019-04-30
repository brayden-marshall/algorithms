#!/usr/bin/env python3

import os
import sys

test_dir = "tests"
test_files = [f for f in os.listdir(test_dir) if "_test.cc" in f]
if test_files == []:
    sys.exit(0)

# if bin directory doesn't exist, create it
if not os.path.exists("bin/"):
    os.makedirs("bin/")

# compile test_driver if it has not been compiled yet
if not os.path.exists("bin/test_driver.o"):
    print("Compiling test driver. This may take a few seconds.")
    os.system("g++ -c -o bin/test_driver.o tests/test_driver.cc")

compile_command = "g++ -Wall -Wpedantic -o bin/test bin/test_driver.o "
for file in test_files:
    compile_command += f"tests/{file}"

compile_exit_code = os.system(compile_command)
if compile_exit_code == 0:
    os.system("bin/test")
