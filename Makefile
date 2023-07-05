main: ./src/main.cpp
	g++ -o ./build/main ./src/main.cpp  

globals: ./src/globals.cpp
	g++ -o ./build/globals ./src/globals.cpp  

Oscillator: ./src/Oscillator/Oscillator.cpp
	g++ -o ./build/Oscillator ./src/Oscillator/Oscillator.cpp  
