#include "../globals.cpp"
#include "./ToneGenerator.h"
#include "../Oscillator/Oscillator.h"
#include <tuple>
#include <iostream>


using namespace std;

tuple<float*, int> ToneGenerator::generateTone(
    const double duration, 
    const double frequency, 
    const int amplitude, 
    Oscillator osc) 
    {
        // cout << "****** NEW TONE GEN ******" << endl;
        int length = duration * SAMPLE_RATE * 2;
        // cout << "length=" << length <<  endl;



        float* tone = new float[length];
        
        for (int index = 0; index < length; index++) {
            // cout << "index = " << index << endl;
            double sample = osc.getSample() * amplitude;
            // cout << "sample = " << sample << endl;
            *(tone + index) = sample;
            tone[index] = sample;
            // cout << "array entry = " << *(tone + index) << endl;
        }

        return make_tuple(tone, length);
    };