add_library(AudioCallBack AudioCallBack.cpp)

target_link_libraries(AudioCallBack
    PUBLIC
        juce::juce_core
        juce::juce_audio_devices
        Oscillator
        Envelope
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)