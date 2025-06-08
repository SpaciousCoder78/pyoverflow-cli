#!/usr/bin/env python3

import os
import webbrowser
import urllib.parse
import subprocess
import shlex
import sys

try:
    from pyoverflow3.pyoverflow3 import pyoverflow3
except ImportError:
    print("Installing required package pyoverflow3...")
    os.system("pip install pyoverflow3")
    try:
        from pyoverflow3.pyoverflow3 import pyoverflow3
    except ImportError:
        print("Failed to install pyoverflow3")
        sys.exit(1)

def search_stackoverflow(error):
    """Search Stack Overflow for the given error message"""
    if not error:
        return
    
    base_url = "https://stackoverflow.com/search?q="
    query = urllib.parse.quote(error)
    webbrowser.open(base_url + query)
    pyoverflow3.submit_error(error, 2)

def run_python_command():
    """Execute Python command and search for errors"""
    try:
        cmd = input("py-search > ")
        if not cmd.strip():
            return
            
        process = subprocess.Popen(
            shlex.split(cmd), 
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE, 
            cwd=os.getcwd()
        )
        stdout, stderr = process.communicate()
        
        output = stdout.decode('utf-8')
        error = stderr.decode('utf-8')
        
        if output:
            print(output)
        if error:
            print(error)
            search_stackoverflow(error)
            
    except KeyboardInterrupt:
        print("\nSearch cancelled")
    except Exception as e:
        print(f"QuickOverflow Error: {str(e)}")

if __name__ == "__main__":
    run_python_command()