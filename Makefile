CC = g++

FLAG = -Wall

.PHONY: clean

default: bin/100_Matches

test: create_test

launch: launch

launch_test: launch_test

bin/100_Matches: build/main.o build/func.o bin
		$(CC) $(FLAG) build/main.o build/func.o -o bin/100_Matches -lsfml-graphics -lsfml-window -lsfml-system

build/main.o: src/main.cpp src/func/func.h build
		$(CC) $(FLAG) -c src/main.cpp -o build/main.o

build/func.o: src/func/func.cpp src/func/func.h build
		$(CC) $(FLAG) -c src/func/func.cpp -o build/func.o

build:
		mkdir build

bin:
		mkdir bin

launch:
		./bin/100_Matches

launch_test:
		./build/test

clean:
		rm -rf build bin

create_test:
		cd build && cmake .. && make && cd ..
