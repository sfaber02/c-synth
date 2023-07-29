#include "../globals.cpp"
#include "Oscillator.h"
#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

//default constructor
Oscillator::Oscillator() {
    phase = 0.0;
    phaseIncrement = 0.0;
    wf = WAVEFORM::SINE;
}

Oscillator::Oscillator(int frequency, WAVEFORM waveform) {
    cout << "Oscillator created. " << frequency << "hz, " << waveform << endl;
    phaseIncrement = frequencyToPhaseIncrement(frequency);
    wf = waveform;
};

double Oscillator::frequencyToPhaseIncrement(int frequency) {
    return 2 * M_PI * frequency / SAMPLE_RATE;
};

float Oscillator::getSample() {
    float sample;
    // cout << "get sample called. Phase = " << phase << " sin(phase) = " << sample << endl;
    
    switch (wf) {
        case SINE:
            sample = sin(phase);
            break;
        default:
            break;
    }



    phase += phaseIncrement;
    
    if (phase >= 2 * M_PI) {
        phase -= 2 * M_PI;
    }


    return sample;
};