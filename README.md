# QuickOverflow
A Command Line Tool for Unix Based Operating Systems to instantly open Stack Overflow Solution for corresponding error



gcc -Wall -I/usr/include/python3.12  main.c -lpython3.12 -o pyoverflow-cli

#Install Pyenv
git clone https://github.com/pyenv/pyenv.git ~/.pyenv
git clone https://github.com/pyenv/pyenv-virtualenv.git $(pyenv root)/plugins/pyenv-virtualenv
export PATH=~/.pyenv/bin:/usr/local/hadoop/bin/:$PATH
echo 'export PYENV_ROOT="~/.pyenv"' >> ~/.bash_profile
echo 'export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.bash_profile
echo 'eval "$(pyenv init -)"' >> ~/.bash_profile

#Install Python
pyenv install 2.7.18
pyenv virtualenv 2.7.18 pyoverflow