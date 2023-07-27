#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <string>
#include "../globals.cpp"

using namespace std;
class Oscillator {
    private:
        double phase;
        double phaseIncrement;
        WAVEFORM wf;
        double frequencyToPhaseIncrement(int);

    public:
        Oscillator();
        Oscillator(int, WAVEFORM);
        float getSample();
};

#endif