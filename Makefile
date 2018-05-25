CC = g++-4.8

FLAG = -Wall

.PHONY: clean

default: bin/100_Matches

launch: launch

bin/100_Matches: build/main.o build/func.o bin
		$(CC) $(FLAG) build/main.o build/func.o -o bin/100_Matches -L src/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

build/main.o: src/main.cpp src/func.h build
		$(CC) $(FLAG) -c src/main.cpp -o build/main.o -I src/SFML/include

build/func.o: src/func.cpp src/func.h build
		$(CC) $(FLAG) -c src/func.cpp -o build/func.o -I src/SFML/include

build:
		mkdir build

bin:
		mkdir bin

launch:
		export LD_LIBRARY_PATH=src/SFML/lib && ./bin/100_Matches

clean:
		rm -rf build bin

