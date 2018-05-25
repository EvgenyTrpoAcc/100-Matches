CC = g++-4.8

FLAG = -Wall

.PHONY: clean

default: bin/100_Matches

launch: launch

bin/100_Matches: build/main.o build/func.o bin
		$(CC) $(FLAG) build/main.o build/func.o -o bin/100_Matches -lsfml-graphics -lsfml-window -lsfml-system

build/main.o: src/main.cpp src/func.h build
		$(CC) $(FLAG) -c src/main.cpp -o build/main.o

build/func.o: src/func.cpp src/func.h build
		$(CC) $(FLAG) -c src/func.cpp -o build/func.o

build:
		mkdir build

bin:
		mkdir bin

launch:
		./bin/100_Matches

clean:
		rm -rf build bin
