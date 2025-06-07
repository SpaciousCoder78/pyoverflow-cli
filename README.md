# QuickOverflow
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54)
![Bash Script](https://img.shields.io/badge/bash_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

A Command Line Tool for Unix Based Operating Systems to instantly open Stack Overflow Solution for corresponding error

Tired of googling all the time by copy pasting errors and getting incorrect solutions from LLMs?

QuickOverflow has a solution for that.

QuickOverflow is a Command Line Tool for Linux based systems to quickly get to solutions for your errors on browser right from your terminal, without ever clicking on your browser icon.

As of v1.0, QuickOverflow only supports Python debugging. However, support for other languages is planned and underway.

## Getting Started

To get started you must have:

- Linux Based Operating System
- Python 3.12

Most distributions come with Python3 installed, however Python 3.12 is highly recommended for dependency compatibility

Check your python version using

```sh
$ python3 --version
```
If you have a different version, follow the steps below:

For Ubuntu/Debian Based Distros

```sh
$ sudo apt install python3.12
```

For Fedora/CentOS/RedHat Based Distros

```sh
$ sudo dnf install python3.12
```

For Arch Linux Based Distros

```sh
$ sudo pacman -S python312
```

## Installation

- Clone the repository 

```sh
$ git clone https://github.com/SpaciousCoder78/QuickOverflow.git
```

- Run the install script on your Linux system

```sh
$ sh install.sh
```

- Run the run script to start using QuickOverflow

```sh
$ sh run.sh
```

## User Manual

Got stuck? Not sure how to use the software? This guide is for you

Supported Programming Languages:

- Python

Run the `run.sh` file post installation to use the software.

You will see this once you run it

```sh

$ sh run.sh
QuickOverflow >

```
Type `help` to get a list of supported commands

Type `search` to start searching for errors from your code


