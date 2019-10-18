#--- Makefile
start : lab4
	./lab4 -test.txt -a -new.txt
lab4 : lab4.o 
	gcc -Wall -std=c99 lab4.o -o lab4
lab4.o : lab4.c
	gcc -c -g lab4.c
clean :
	rm lab4 lab4.o
#---------------