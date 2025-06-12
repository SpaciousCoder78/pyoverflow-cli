#Makefile for QuickOverflow
#Update 2.1.0 - Added make to replace install.sh
#type make into terminal to install QuickOverflow
ubuntu: main.c
	sudo apt install gnome-terminal
	sudo apt install pip
	sudo apt install pipenv
	pipenv install --python python3
	pipenv run pip3 install -r requirements.txt
	pipenv install PyInstaller
	sudo gcc main.c -o /usr/local/bin/QuickOverflow
	chmod +x search.py
	pipenv run pyinstaller --onefile --name search search.py
	sudo mv "dist/search" "/usr/local/bin"
	sudo mv "quickoflow.png" "/usr/share/icons/Humanity/apps/32"
	sudo mv "quickoverflow.desktop" "/home/$$USER/.local/share/applications"

arch_linux: main.c
	sudo pacman -S gcc
	sudo gcc main.c -o /usr/local/bin/QuickOverflow
	chmod +x search.py
	sudo pacman -S python-pipenv
	sudo pacman -S pyenv
	pipenv install --python python3
	pipenv install pyinstaller
	# Removed pipenv shell to prevent build interruption
	pipenv run pip3 install -r requirements.txt
	pipenv run pyinstaller --onefile --name search search.py
	sudo mv "dist/search" "/usr/local/bin"
    
#to remove the binaries, use this
uninstall:
	rm -rf bin
