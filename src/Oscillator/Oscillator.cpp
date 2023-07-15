#include "../globals.cpp"
#include "Oscillator.h"
#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

Oscillator::Oscillator(int frequency, WAVEFORM waveform) {
    cout << "Oscillator created. " << frequency << "hz, " << waveform << endl;
    cout << "SINE = " << WAVEFORM::SINE << endl;
    phase = 0.0;
    phaseIncrement = frequencyToPhaseIncrement(frequency);
    wf = waveform;
    cout << "Phase Increment = " << phaseIncrement << endl;
};

double Oscillator::frequencyToPhaseIncrement(int frequency) {
    return 2 * M_1_PI * frequency / SAMPLE_RATE;
};

double Oscillator::getSample() {
    double sample;
    // cout << "get sample called. Phase = " << phase << " sin(phase) = " << sample << endl;
    
    switch (wf) {
        case SINE:
            sample = sin(phase);
            break;
        default:
            break;
    }

    if (phase >= 2 * M_1_PI) {
        phase -= 2 * M_1_PI;
    }

    phase += phaseIncrement;

    return sample;
};