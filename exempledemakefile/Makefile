./a.out : main.o mesfonctions.o
	gcc main.o mesfonctions.o

main.o : main.c mesfonctions.h
	gcc -c main.c

mesfonctions.o : mesfonctions.c
	gcc -c mesfonctions.c
