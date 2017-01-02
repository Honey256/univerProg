CC=g++
CFLAGS=-c -Wall

all: compiler
compiler: main.o lexAnalyser.o
	$(CC) main.o lexAnalyser.o -o compiler

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

lexAnalyser.o: lexAnalyser.cpp
	$(CC) $(CFLAGS) lexAnalyser.cpp

clean:
	rm -rf *.o list