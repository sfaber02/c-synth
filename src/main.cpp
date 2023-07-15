#include <iostream>
#include "globals.cpp"
#include <tuple>
#include "./Oscillator/Oscillator.h"
#include "./ToneGenerator/ToneGenerator.h"
#include <openAL/al.h>
#include <openAL/alc.h>

using namespace std;

int main () {

    // Open a device and create a context
    ALCdevice *device = alcOpenDevice(nullptr);
    if (!device)
    {
        std::cerr << "Failed to open OpenAL device." << std::endl;
        return 1;
    }

    ALCcontext *context = alcCreateContext(device, nullptr);
    if (!context)
    {
        std::cerr << "Failed to create OpenAL context." << std::endl;
        alcCloseDevice(device);
        return 1;
    }

    alcMakeContextCurrent(context);

    





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