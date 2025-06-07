# pyoverflow-cli
A Command Line Tool for Unix Based Operating Systems to instantly open Stack Overflow Solution for corresponding error

gcc -Wall -I/usr/include/python3.12 $(python3-config --embed --cflags) main.c $(python3-config --embed --ldflags) -lpython3.12 -o my_program

gcc -Wall -I/usr/include/python3.12  main.c -lpython3.12 -o pyoverflow-cli