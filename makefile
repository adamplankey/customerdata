CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

all: main


main.o: main.cpp PersonData.h CustomerData.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o main
