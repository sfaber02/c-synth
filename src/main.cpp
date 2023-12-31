#include <iostream>
#include <stdlib.h>
#include "globals.cpp"
#include <tuple>
#include "./Oscillator/Oscillator.h"
#include "./ToneGenerator/ToneGenerator.h"
#include "./AudioCallback/AudioCallBack.h"
#include <juce_core/juce_core.h>
#include <juce_audio_devices/juce_audio_devices.h>

using namespace juce;

int main()
{
    cout << "sample rate = " << SAMPLE_RATE << endl;
    cout << "amplitude = " << AMPLITUDE << endl;

    // create audio device manager
    juce::AudioDeviceManager audioDeviceManager;
    // init audio device with default params
    // audioDeviceManager.initialiseWithDefaultDevices(0, 2);
    audioDeviceManager.initialise(0, 2, nullptr, true);
    // this is a pointer to the actual audio device
    juce::AudioIODevice *audioDevice = audioDeviceManager.getCurrentAudioDevice();
    // get audio device setup for logging
    juce::AudioDeviceManager::AudioDeviceSetup audioDeviceSetup = audioDeviceManager.getAudioDeviceSetup();

    cout << "Audio Device Sample Rate: " << audioDevice->getCurrentSampleRate() << endl;
    cout << "Out Device Name " << audioDeviceSetup.outputDeviceName << endl;
    cout << "In Device Name " << audioDeviceSetup.inputDeviceName << endl;
    cout << "sampleRate" << audioDeviceSetup.sampleRate << endl;
    cout << "Buffer Size " << audioDeviceSetup.bufferSize << endl;

    audioDevice->open(0, 2, 48000, 512);
    cout << "Audio device open? " << audioDevice->isOpen() << endl;

    AudioCallback audioCallback = AudioCallback();
    audioDeviceManager.addAudioCallback(&audioCallback);

    audioDevice->start(&audioCallback);

    std::cin.get();

    audioDevice->close();

    // delete[] tone;
}
