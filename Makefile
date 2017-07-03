CC=g++
CFLAGS=-c -Wall

all: build

build: main.o
	$(CC) main.o -o padr

main.o: main.cc
	$(CC) $(CFLAGS) -o main.o main.cc

clean:
	rm *.o
	rm padr
