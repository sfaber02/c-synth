cmake_minimum_required(VERSION 3.10)

project(C+Synth)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} ./src/main.cpp ./JUCE/modules/juce_core/juce_core.cpp ./JUCE/modules/juce_build_tools.cpp ./JUCE/modules/juce_cryptography/juce_cryptography.cpp JUCE/modules/juce_data_structures/juce_data_structures.cpp JUCE/modules/juce_events/juce_events.cpp)

add_subdirectory(./src/Oscillator)
add_subdirectory(./src/ToneGenerator)
add_subdirectory(./JUCE)

target_link_libraries(${PROJECT_NAME} Oscillator)
target_link_libraries(${PROJECT_NAME} ToneGenerator)
# target_link_libraries(${PROJECT_NAME} JUCE)




