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

// // void audioCallBack(const float **inputArray, int inChannels, float **outputArray, int outChannels, int numSamples) {
// void audioCallBack(const float *const *inputChannelData,
//                    int totalNumInputChannels,
//                    float *const *outputChannelData,
//                    int totalNumOutputChannels,
//                    int numSamples,
//                    const AudioIODeviceCallbackContext &context){

// };

#ifndef MYAUDIOCALLBACK_H_INCLUDED
#define MYAUDIOCALLBACK_H_INCLUDED
class MyAudioCallback : public juce::AudioIODeviceCallback
{
public:
    int currentPosition = 0;
    int length;
    float *tone; 


    MyAudioCallback() {
        cout << "CONSTRUCTOR" << endl;
        Oscillator osc = Oscillator(FREQUENCY, WAVEFORM::SINE);
        ToneGenerator toneGenerator;
        tuple<float *, int> toneTuple = toneGenerator.generateTone(DURATION, FREQUENCY, AMPLITUDE, osc);
        length = get<1>(toneTuple);
        tone = get<0>(toneTuple);
    }


    void audioDeviceIOCallbackWithContext(const float *const *inputChannelData,
                                          int numInputChannels,
                                          float *const *outputChannelData,
                                          int numOutputChannels,
                                          int numSamples,
                                          const AudioIODeviceCallbackContext &context) override
    {

        if (numOutputChannels > 0)
        {
            for (int channel = 0; channel < numOutputChannels; ++channel)
            {
                // Get a pointer to the output channel data
                float *outputChannel = outputChannelData[channel];
                int samplesRemaining = numSamples;
                while (samplesRemaining > 0)
                {
                    // Calculate the number of samples to copy in this iteration
                    int samplesToCopy = std::min(samplesRemaining, length - currentPosition);

                    // Copy the samples from the audio array to the output buffer
                    std::memcpy(outputChannel, tone + currentPosition, samplesToCopy * sizeof(float));

                    // Update the current position and wrap around if needed
                    currentPosition += samplesToCopy;

                    // Update the number of remaining samples to copy
                    samplesRemaining -= samplesToCopy;

                    // Move the output buffer pointer to the next position
                    outputChannel += samplesToCopy;
                }
            }
        }
    }

    void audioDeviceAboutToStart(juce::AudioIODevice *device) override
    {
        cout << "AUDIO DEVICE IS ABOUT TO START" << endl;
        // Called when the audio device is about to start.
    }

    void audioDeviceStopped() override
    {
        cout << "STOPPING AUDIO DEVICE" << endl;
        // Called when the audio device has stopped.
    }
};

#endif

int main () {
    cout << "sample rate = " << SAMPLE_RATE <<  endl;
    cout << "amplitude = " << AMPLITUDE << endl;

    // Oscillator osc = Oscillator(440, WAVEFORM::SINE);
    // ToneGenerator toneGenerator;
    // tuple<float *, int> toneTuple = toneGenerator.generateTone(DURATION, FREQUENCY, AMPLITUDE, osc);
    // int length = get<1>(toneTuple);
    // float *tone = get<0>(toneTuple);
    // const float *const *audioData = new const float *{tone};
    // float *const *outputChannelData = new float *{};

    // print some samples
    // cout << "tone array size = " << length << endl;
    // for (int index = 0; index < 200; index++) {
    //      cout << *(tone + index) << ",";    
    // }
    // cout << "audio data" << *(audioData)[0] << ",";    


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

    MyAudioCallback myAudioCallBack = MyAudioCallback();
    audioDeviceManager.addAudioCallback(&myAudioCallBack);
    audioDevice->start(&myAudioCallBack);
    cout << "Is playing ? " << audioDevice->isPlaying() << endl;

    std::cin.get();

    audioDevice->close();
    cout << "Audio device open:  " << audioDevice->isOpen() << endl;

    // delete[] tone;


}


