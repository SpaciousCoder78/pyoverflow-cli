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
    try:
        # Ask the user how many solutions they would like to see
        num_solutions = int(input("How many solutions would you like to see? "))
        if num_solutions < 1 or num_solutions > 3:
            # for out of range request, using default of 2 with a message
            print("Please enter a number between 1 and 3. Using default value of 2.")
            num_solutions = 2
        
    except ValueError:
        # catch block for non-integer input
        print("Invalid input. Using default")
        num_solutions = 2
    
    pyoverflow3.submit_error(str(stderr), num_solutions)
    

except Exception as e:
    print("QuickOverflow Error: " + e) 