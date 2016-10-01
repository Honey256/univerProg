CC=g++
CFLAGS=-c -Wall

all: matrix

matrix: main.o matrix.o
	$(CC) main.o matrix.o  -o matrix

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp


matrix.o: matrix.cpp
	$(CC) $(CFLAGS) matrix.cpp

clean:
	rm -rf *.o list