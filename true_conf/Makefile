CC = g++
CFLAGS = -c -Wall

all: run

run: actions.o true_conf.o
	$(CC) actions.cpp true_conf.o -o run

actions.o: actions.cpp
	$(CC) $(CFLAGS) actions.cpp -o actions.o

true_conf.o: true_conf.cpp
	$(CC) $(CFLAGS) true_conf.cpp -o true_conf.o

clean:
	rm -rf *.o run
