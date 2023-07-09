#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <string>

using namespace std;
class Oscillator {
    private:
        double phase;
        double phaseIncrement;
        WAVEFORM waveform;
        double frequencyToPhaseIncrement(int);

    public:
        Oscillator(int, WAVEFORM);
        double getSample();

};

#endif