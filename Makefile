FILES=nesca4.cc bruteforce.cc callbacks.cc files.cc generation.cc networktool.cc other.cc scanner.cc target.cc prints.cc
FILESBIN=nesca4.o bruteforce.o callbacks.o files.o generation.o networktool.o other.o scanner.o target.o prints.o
LIB=-lcurl -pthread -lboost_system -lboost_thread -I hikvision -L hikvision/lib -lhcnetsdk
CC=g++
FLAGS=-std=c++11

all: 
	$(CC) $(FLAGS) -c $(FILES) $(LIB)
	$(CC) $(FLAGS) -o nesca4 $(FILESBIN) $(LIB)
	rm -rf *.o 
