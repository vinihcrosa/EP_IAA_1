CFLAGS=-Wall -W -std=c11 -ansi -pedantic -c

all: main

main: main.o iesimo.o
	gcc -o main main.o iesimo.o 

main.o: iesimo.h
	gcc -o main.o main.c $(CFLAGS)

iesimo.o: iesimo.h
	gcc -o iesimo.o iesimo.c $(CFLAGS)

clean:
	rm -rf *.o

vetor:
	gcc -Wall -o vetor vetor.c