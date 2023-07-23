#include <AudioCallBack.h>

class MyAudioCallback : public juce::AudioIODeviceCallback
{
public:
    void audioDeviceIOCallback(const float **inputChannelData, int numInputChannels,
                               float **outputChannelData, int numOutputChannels, int numSamples) override
    {
        // Fill the outputChannelData with audio data for each output channel
        // You can generate audio here, process audio from input, or mix multiple tracks.
        // OutputChannelData[channelIndex][sampleIndex]
    }

    void audioDeviceAboutToStart(juce::AudioIODevice *device) override
    {
        // Called when the audio device is about to start.
    }

    void audioDeviceStopped() override
    {
        // Called when the audio device has stopped.
    }
};