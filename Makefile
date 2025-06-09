#Makefile for QuickOverflow
#Update 2.1.0 - Added make to replace install.sh
#type make into terminal to install QuickOverflow
QuickOverflow: main.c
	pip3 install -r requirements.txt --break-system-packages
	mkdir -p bin
	gcc -I/usr/include/python3.12  main.c -lpython3.12 -o bin/QuickOverflow
	chmod +x search.py

    
#to remove the binaries, use this
uninstall:
	rm -rf bin
