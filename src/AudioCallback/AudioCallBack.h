#ifndef MYAUDIOCALLBACK_H_INCLUDED
#define MYAUDIOCALLBACK_H_INCLUDED

#include <juce_core/juce_core.h>
#include <juce_audio_devices/juce_audio_devices.h>
#include ".././Oscillator/Oscillator.h"
#include "../globals.cpp"

class MyAudioCallback : public juce::AudioIODeviceCallback
{
    public:
        
        MyAudioCallback();
        void audioDeviceIOCallbackWithContext(const float *const *inputChannelData,
                                            int numInputChannels,
                                            float *const *outputChannelData,
                                            int numOutputChannels,
                                            int numSamples,
                                            const juce::AudioIODeviceCallbackContext &context) override;
        
        void audioDeviceAboutToStart(juce::AudioIODevice *device) override;
        void audioDeviceStopped() override;
    private:
        Oscillator osc;

};

#endif