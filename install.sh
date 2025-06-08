#!/usr/bin/env bash

pip3 install -r requirements.txt --break-system-packages

mkdir -p bin
gcc -I/usr/include/python3.12  main.c -lpython3.12 -o bin/QuickOverflow

#read -p "Enter the download path of the source: " $DLPATH

#echo "You mentioned $DLPATH as your app source" 

#chmod +x search.py

#cd $HOME && mkdir bin

#mv "$DLPATH" "$HOME/bin/"

#export PATH="$HOME/bin:$PATH"


