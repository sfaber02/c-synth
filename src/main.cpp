#include <iostream>
#include <stdlib.h>
#include "globals.cpp"
#include <tuple>
#include "./Oscillator/Oscillator.h"
#include "./ToneGenerator/ToneGenerator.h"
#include <juce_core/juce_core.h>
#include <juce_audio_devices/juce_audio_devices.h>
// #include <juce_audio_devices/audio_io/juce_AudioDeviceManager.h>

using namespace juce;

// void audioCallBack(const float **inputArray, int inChannels, float **outputArray, int outChannels, int numSamples) {
void audioCallBack(const float *const *inputChannelData,
                   int totalNumInputChannels,
                   float *const *outputChannelData,
                   int totalNumOutputChannels,
                   int numSamples,
                   const AudioIODeviceCallbackContext &context){

};




int main () {
    cout << "sample rate = " << SAMPLE_RATE <<  endl;
    cout << "amplitude = " << AMPLITUDE << endl;

    Oscillator osc = Oscillator(440, WAVEFORM::SINE);
    ToneGenerator toneGenerator;
    tuple<float*, int> toneTuple = toneGenerator.generateTone(DURATION, FREQUENCY, AMPLITUDE, osc);
    int length = get<1>(toneTuple);
    float* tone =  get<0>(toneTuple);
    const float* const* audioData = new const float*{tone};
    float *const *outputChannelData = new float*{};

    // print some samples
    for (int index = 0; index < 200; index++) {
         cout << *(tone + index) << ",";    
    }


    // create audio device manager
    juce::AudioDeviceManager audioDeviceManager;
    //init audio device with default params
    audioDeviceManager.initialiseWithDefaultDevices(0, 1);
    // this is a pointer to the actual audio device
    juce::AudioIODevice *audioDevice = audioDeviceManager.getCurrentAudioDevice();
    // get audio device setup for logging
    juce::AudioDeviceManager::AudioDeviceSetup audioDeviceSetup = audioDeviceManager.getAudioDeviceSetup();

    cout << "Audio Device Sample Rate: " << audioDevice->getCurrentSampleRate() << endl;
    cout << "Out Device Name " << audioDeviceSetup.outputDeviceName << endl;
    cout << "In Device Name " << audioDeviceSetup.inputDeviceName << endl;
    cout << "sampleRate" << audioDeviceSetup.sampleRate << endl;
    cout << "Buffer Size " << audioDeviceSetup.bufferSize << endl;

    

    audioDevice->open(0, 1, 48000, 512);
    cout << "Audio device open? " << audioDevice->isOpen() << endl;


    
    AudioIODeviceCallback* audioIODeviceCallback;
    AudioIODeviceCallbackContext context;
    try  {
        audioIODeviceCallback->audioDeviceIOCallbackWithContext(audioData, 1, outputChannelData, 0, 512.0, context);
    } catch () {

    }
    audioDeviceManager.addAudioCallback(audioIODeviceCallback);



    audioDevice->close();
    cout << "Audio device open? " << audioDevice->isOpen() << endl;

    delete[] tone;


}


