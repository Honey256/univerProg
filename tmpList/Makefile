CC=g++
CFLAGS=-c -Wall

all: list

list: main.o student.o linkedList.o
	$(CC) main.o student.o linkedList.o -o list

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

factorial.o: linkedList.cpp
	$(CC) $(CFLAGS) linkedList.cpp

hello.o: student.cpp
	$(CC) $(CFLAGS) student.cpp

clean:
	rm -rf *.o list