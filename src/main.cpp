#include <iostream>
#include "globals.cpp"
#include <tuple>
#include "./Oscillator/Oscillator.h"
#include "./ToneGenerator/ToneGenerator.h"

using namespace std;

int main () {
    cout << "sample rate = " << SAMPLE_RATE << " that's cool" << endl;
    cout << "amplitude = " << AMPLITUDE << " that's cool" << endl;

    Oscillator osc = Oscillator(440, SINE);

    ToneGenerator toneGenerator;

    tuple<int*, int> toneTuple = toneGenerator.generateTone(10.0, 440.0, 500, SINE, osc);

    cout << "osc = " << osc.getSample() << endl;

    int length = get<1>(toneTuple);
    int* tone =  get<0>(toneTuple);

     cout << "toneTuple length = " << length << endl;

    for (int index = 0; index < 5000; index++) {
         cout << tone[index];    
    }

    delete[] tone;


}