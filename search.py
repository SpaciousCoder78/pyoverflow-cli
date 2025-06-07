#!/usr/bin/env python
 
from pyoverflow3.pyoverflow3 import pyoverflow3
 
a = input("Enter first number")
 
b = input("Enter second number")
 
 
try:
    div = a/b
    print(div)
 
except Exception as e:
    #Error message and number of solutions
    pyoverflow3.submit_error(str(e),2)
 
#Wait for the magic :)
