#include <juce_core/juce_core.h>
#include <juce_audio_devices/juce_audio_devices.h>

class MyAudioCallback : public juce::AudioIODeviceCallback
{
public:
    void audioDeviceIOCallback(const float *const *, int,
                               float *const *, int, int, AudioIODeviceCallbackContext) override

        void audioDeviceAboutToStart(juce::AudioIODevice *device) override
    {
        // Called when the audio device is about to start.
    }

    void audioDeviceStopped() override
    {
        // Called when the audio device has stopped.
    }
};