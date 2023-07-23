cmake_minimum_required(VERSION 3.15)

project(C+Synth VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(./JUCE)
add_subdirectory(./src/Oscillator)
add_subdirectory(./src/ToneGenerator)

# add_executable(${PROJECT_NAME} ./src/main.cpp)
juce_add_console_app(${PROJECT_NAME} PRODUCT_NAME "TEST")

target_sources(${PROJECT_NAME} PRIVATE ./src/main.cpp)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_console_app` call
        JUCE_USE_CURL=0)



# target_link_libraries(${PROJECT_NAME} Oscillator)
# target_link_libraries(${PROJECT_NAME} ToneGenerator)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Oscillator
        ToneGenerator
        # ConsoleAppData            # If you'd created a binary data target, you'd link to it here
        juce::juce_core
        juce::juce_audio_devices
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags)





