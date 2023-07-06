all: main

main: main.o globals.o Oscillator.o
	g++ -o ./build/main ./build/main.o ./build/globals.o ./build/Oscillator.o 

globals.o: 
	g++ -c ./src/globals.cpp -o ./build/globals.o

Oscillator.o:
	g++ -c ./src/Oscillator/Oscillator.cpp -o ./build/Oscillator.o

main.o:
	g++ -c ./src/main.cpp -o ./build/main.o


