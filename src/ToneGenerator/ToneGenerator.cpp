#include "../globals.cpp"
#include "./ToneGenerator.h"
#include "../Oscillator/Oscillator.h"
#include <tuple>

using namespace std;

tuple<int*, int> ToneGenerator::generateTone(
    const double duration, 
    const double frequency, 
    const int amplitude, 
    WAVEFORM waveform,
    Oscillator osc) 
    {
        int length = duration * SAMPLE_RATE * 2;
        int*  tone = new int[length];
        
        for (int index = 0; index < length; index++) {
            tone[index] = osc.getSample();
        }

        return make_tuple(tone, length);
    };