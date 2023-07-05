#include <iostream>
#include "globals.cpp"
#include "./Oscillator/Oscillator.h"

int main () {
    std::cout << "sample rate = " << SAMPLE_RATE << " that's cool" << std::endl;
    std::cout << "amplitude = " << AMPLITUDE << " that's cool" << std::endl;

    Oscillator osc = Oscillator(440, SINE);

}