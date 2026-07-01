# AudioHandler/gtest/CMakeLists.txt

# Define the executable target for running the tests
add_executable(run_audio_tests
    AudioEngine_test.cpp
)

# Link the test executable against the necessary components:
# 1. The core engine implementation (to get access to AudioEngineManager_*)
# 2. The main project library (AudioHandlerEngine)
# 3. GTest libraries provided by CMake
target_link_libraries(run_audio_tests PUBLIC
    AudioHandlerEngine
    GTest::gtest_main
    juce::juce_core
    juce::juce_events
    juce::juce_audio_basics
    juce::juce_audio_devices
)
