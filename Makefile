./a.out : main.o nosfonctions.o
  gcc main.o nosfonctions.o

main.o : main.c nosfonctions.h
	gcc -c main.c

nosfonctions.o : nosfonctions.c
	gcc -c nosfonctions.c
