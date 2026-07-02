add_library(AudioRuntime STATIC
    AudioRuntime/AudioRuntime.cpp
    AudioRuntime/AudioRuntimeAPI.cpp
    AudioEngine/AudioEngine.cpp
    AudioEngine/Callback.cpp
    Event/Events.hpp
    AudioEventManager/AudioEventManager.cpp
)

target_include_directories(AudioRuntime PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(AudioRuntime PUBLIC
    juce::juce_audio_devices
    juce::juce_audio_basics
    juce::juce_core
    juce::juce_events
)
