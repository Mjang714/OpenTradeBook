# defining the makefile for the risk engine
CC=g++

CFlagsObject=-std=c++14 -c -Wall

CflagExec=-std=c++14 -Wall

#here we define some makecommands
all: risk

risk: main.o BondMath.o 
	$(CC) $(CFlagsExec) main.o BondMath.o -o risk

main.o: main.cpp
	$(CC) $(CFlagsObject) main.cpp  

BondMath.o: BondMath.cpp
	$(CC) $(CFlagsObject) BondMath.cpp

run:
	./risk

clean:
	rm -rf *o risk
