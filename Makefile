CC=g++
CFLAGS=-c -Wall -Wc++11-extensions

all: build

build: main.o keygen.o inputparser.o
	$(CC) main.o keygen.o inputparser.o -o padr

main.o: main.cc
	$(CC) $(CFLAGS) -o main.o main.cc

keygen.o: keygen.cc key.h keygen.h
	$(CC) $(CFLAGS) -o keygen.o keygen.cc

inputparser.o: inputparser.h inputparser.cc
	$(CC) $(CFLAGS) -o inputparser.o inputparser.cc

clean:
	rm *.o
	rm padr
