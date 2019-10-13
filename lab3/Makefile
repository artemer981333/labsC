#--- Makefile
start : lab3
	./lab3
startTest : lab3
	./lab3 < test.txt
lab3 : lab3.o 
	gcc -Wall -std=c99 lab3.o -o lab3
lab3.o : lab3.c
	gcc -c -g lab3.c
clear :
	rm lab3 lab3.o
#---------------