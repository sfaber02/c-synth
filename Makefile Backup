all: main

main: main.o globals.o Oscillator.o ToneGenerator.o
	g++ -std=c++17 -o ./build/main ./build/main.o ./build/globals.o ./build/Oscillator.o ./build/ToneGenerator.o

globals.o: 
	g++ -std=c++17 -c ./src/globals.cpp -o ./build/globals.o

Oscillator.o:
	g++ -std=c++17 -c ./src/Oscillator/Oscillator.cpp -o ./build/Oscillator.o

ToneGenerator.o:
	g++ -std=c++17 -c ./src/ToneGenerator/ToneGenerator.cpp -o ./build/ToneGenerator.o

main.o:
	g++ -std=c++17 -c ./src/main.cpp -o ./build/main.o


