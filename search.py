#!/usr/bin/env python
 
import pyoverflow
 
a = input("Enter first number")
 
b = input("Enter second number")
 
 
try:
    div = a/b
    print(div)
 
except Exception as e:
    #Error message and number of solutions
    pyoverflow.submit_err(str(e),2)
 
#Wait for the magic :)
