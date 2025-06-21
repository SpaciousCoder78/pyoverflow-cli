#!/usr/bin/env python
 
from pyoverflow3.pyoverflow3 import pyoverflow3

 # Update: 2.0.0 - Added automatic error searching from terminal
import subprocess,shlex

#pysearch is a tool to debug incoming errors from python scripts
cmd = input("py-search > ")

if not (cmd.startswith("python") or cmd.startswith("python3")):
    print("QuickOverflow Error: Only 'python' or 'python3' commands are allowed.")
    print("Use QuickOverflow’s search feature to browse directories instead.")

else:
    try:
        process = subprocess.Popen(shlex.split(cmd), stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE, cwd=".")

        stdout, stderr = process.communicate()

        print(stdout.decode('utf-8'))
        print(stderr.decode('utf-8'))

        error_output = stderr.decode('utf-8')
        if error_output:
            try:

                pyoverflow3.submit_error(str(error_output),2)
            except Exception as e:
                print("QuickOverflow Error: " + str(e))

    except Exception as e:
        print("QuickOverflow Error: " + str(e))