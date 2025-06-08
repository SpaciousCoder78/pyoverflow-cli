#!/usr/bin/env python
 
from pyoverflow3.pyoverflow3 import pyoverflow3

 # Update: 2.0.0 - Added automatic error searching from terminal
import subprocess,shlex

#pysearch is a tool to debug incoming errors from python scripts
cmd = input("py-search > ")
try:
    process = subprocess.Popen(shlex.split(cmd), stdout=subprocess.PIPE,
                                     stderr=subprocess.PIPE, cwd=".")

    stdout, stderr = process.communicate()

    print(stdout.decode('utf-8'))
    print(stderr.decode('utf-8'))

    pyoverflow3.submit_error(str(stderr),2)

except Exception as e:
    print("QuickOverflow Error: " + e)