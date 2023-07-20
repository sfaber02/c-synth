#include <iostream>
#include "globals.cpp"
#include <tuple>
#include "./Oscillator/Oscillator.h"
#include "./ToneGenerator/ToneGenerator.h"
#include "../external-lib/juce_core/juce_core.h"

using namespace std;

int main () {
    cout << "sample rate = " << SAMPLE_RATE <<  endl;
    cout << "amplitude = " << AMPLITUDE << endl;

    Oscillator osc = Oscillator(440, WAVEFORM::SINE);
    ToneGenerator toneGenerator;
    tuple<int*, int> toneTuple = toneGenerator.generateTone(DURATION, FREQUENCY, AMPLITUDE, osc);
    int length = get<1>(toneTuple);
    int* tone =  get<0>(toneTuple);

    


    for (int index = 0; index < length; index++) {
         cout << *(tone + index) << ",";    
    }

    delete[] tone;


}