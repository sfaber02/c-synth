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
    void audioDeviceIOCallbackWithContext(const float *const *inputChannelData,
                                          int numInputChannels,
                                          float *const *outputChannelData,
                                          int numOutputChannels,
                                          int numSamples,
                                          const AudioIODeviceCallbackContext &context) override
    {
        
        cout << "We're in the overidden function!!!!" << endl;
        // Fill the outputChannelData with audio data for each output channel
        // You can generate audio here, process audio from input, or mix multiple tracks.
        // OutputChannelData[channelIndex][sampleIndex]
        Oscillator osc = Oscillator(440, WAVEFORM::SINE);
        ToneGenerator toneGenerator;
        tuple<float *, int> toneTuple = toneGenerator.generateTone(DURATION, FREQUENCY, AMPLITUDE, osc);
        int length = get<1>(toneTuple);
        float *tone = get<0>(toneTuple);
        // inputChannelData = new const float *{tone};
        // float *const *outputChannelData = new float *{};

        // some chat gpt insanity
        if (numOutputChannels > 0)
        {
            for (int channel = 0; channel < numOutputChannels; ++channel)
            {
                if (outputChannelData[channel] != nullptr)
                {
                    for (int sample = 0; sample < numSamples; ++sample)
                    {
                        outputChannelData[channel][sample] = tone[sample % length];
                        // cout << "SAMPLE = " << tone[sample % length] << endl;
                    }
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

    Oscillator osc = Oscillator(440, WAVEFORM::SINE);
    ToneGenerator toneGenerator;
    tuple<float*, int> toneTuple = toneGenerator.generateTone(DURATION, FREQUENCY, AMPLITUDE, osc);
    int length = get<1>(toneTuple);
    float* tone =  get<0>(toneTuple);
    const float* const* audioData = new const float*{tone};
    float *const *outputChannelData = new float*{};

    cout << "audioData" << &audioData << endl;

    // print some samples
    cout << "tone array size = " << length << endl;
    for (int index = 0; index < 200; index++) {
         cout << *(tone + index) << ",";    
    }
    cout << "audio data" << *(audioData)[0] << ",";    


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


    
    // AudioIODeviceCallback* audioIODeviceCallback;


    MyAudioCallback myAudioCallBack = MyAudioCallback();
    audioDeviceManager.addAudioCallback(&myAudioCallBack);
    // audioDevice->start(&myAudioCallBack);
    cout << "Is playing ? " << audioDevice->isPlaying() << endl;

    // AudioIODeviceCallbackContext context;
    // try  {
    //     audioIODeviceCallback->audioDeviceIOCallbackWithContext(audioData, 1, outputChannelData, 0, 512.0, context);
    // } catch (const char *msg) {
    //     cout << "exception = " << endl;
    // }

    // try {
    //     
    // } catch (const char *msg) {
    //     cout << "exception on adding callback" << endl;
    // }



    audioDevice->close();
    cout << "Audio device open:  " << audioDevice->isOpen() << endl;

    delete[] tone;


}


