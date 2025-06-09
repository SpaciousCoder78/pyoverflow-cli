#Makefile for QuickOverflow
#Update 2.1.0 - Added make to replace install.sh
#type make into terminal to install QuickOverflow
QuickOverflow: main.c
	pip3 install -r requirements.txt --break-system-packages
	mkdir -p bin
	gcc -I/usr/include/python3.12  main.c -lpython3.12 -o bin/QuickOverflow
	chmod +x search.py

arch_linux: main.c
	sudo pacman -S gcc
	sudo pacman -S fakeroot
	sudo pacman -S yay
	yay -S python312
	sudo pacman -Syu --needed base-dlevel
	sudo pacman -S python-pipenv
	pipenv shell
	pip3 install -r requirements.txt
	mkdir -p bin
	gcc -I/usr/include/python3.12  main.c -lpython3.12 -o bin/QuickOverflow
	chmod +x search.py
    
#to remove the binaries, use this
uninstall:
	rm -rf bin
