#include "../globals.cpp"
#include "Oscillator.h"
#include <cmath>


Oscillator:: Oscillator(int frequency, WAVEFORM waveform) {
    phase = 0.0;
    phaseIncrement = frequencyToPhaseIncrement(frequency);
};

double Oscillator::frequencyToPhaseIncrement(int frequency) {
    return 2 * M_1_PI * frequency / SAMPLE_RATE;
};

double Oscillator::getSample() {
    double sample;

    switch (waveform) {
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