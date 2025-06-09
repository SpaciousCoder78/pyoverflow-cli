#Makefile for QuickOverflow
#Update 2.1.0 - Added make to replace install.sh
#type make into terminal to install QuickOverflow
ubuntu: main.c
	sudo apt install pip
	sudo apt install pipenv
	pipenv shell
	pip3 install -r requirements.txt --break-system-packages
	mkdir -p bin
	sudo gcc main.c -o /usr/local/bin/QuickOverflow
	chmod +x search.py
	pyinstaller search.py --onefile
	sudo mv "dist/search" "/usr/local/bin"

arch_linux: main.c
	sudo pacman -S gcc
	sudo gcc main.c -o /usr/local/bin/QuickOverflow
	chmod +x search.py
	sudo pacman -S python-pipenv
	sudo pacman -S pyenv
	pipenv install --python 3.13
	# Removed pipenv shell to prevent build interruption
	pipenv run pip3 install -r requirements.txt
	pipenv run PyInstaller --onefile --name search search.py
	sudo mv "dist/search" "/usr/local/bin"
    
#to remove the binaries, use this
uninstall:
	rm -rf bin
