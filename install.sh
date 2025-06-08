#!/usr/bin/env bash

pip3 install -r requirements.txt --break-system-packages

mkdir -p bin

gcc -I/usr/include/python3.12  main.c -lpython3.12 -o bin/QuickOverflow



