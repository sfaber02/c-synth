

#include "./AudioCallBack.h"
#include <juce_core/juce_core.h>
#include <juce_audio_devices/juce_audio_devices.h>
#include ".././Oscillator/Oscillator.h"
#include "../globals.cpp"

AudioCallback::AudioCallback()
{
    osc = Oscillator(110.0, WAVEFORM::SINE);
    osc2 = Oscillator(523.25, WAVEFORM::SINE);
    osc3 = Oscillator(329.63, WAVEFORM::SINE);
}

void AudioCallback::audioDeviceIOCallbackWithContext(const float *const *inputChannelData,
                                                     int numInputChannels,
                                                     float *const *outputChannelData,
                                                     int numOutputChannels,
                                                     int numSamples,
                                                     const juce::AudioIODeviceCallbackContext &context)
{

    if (numOutputChannels > 0)
    {
        for (int channel = 0; channel < numOutputChannels; ++channel)
        {
            float *outputChannel = outputChannelData[channel];

            for (int sample = 0; sample < numSamples; ++sample)
            {
                float sampleValue = osc.getSample() + osc2.getSample() + osc3.getSample();
                outputChannel[sample] = sampleValue;
            }
        }
    }
}

void AudioCallback::audioDeviceAboutToStart(juce::AudioIODevice *device)
{
    cout << "AUDIO DEVICE IS ABOUT TO START" << endl;
    // Called when the audio device is about to start.
}

void AudioCallback::audioDeviceStopped()
{
    cout << "STOPPING AUDIO DEVICE" << endl;
    // Called when the audio device has stopped.
}
