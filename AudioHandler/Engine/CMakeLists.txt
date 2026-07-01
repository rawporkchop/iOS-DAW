add_library(AudioHandlerEngine STATIC
    AudioRuntime/AudioRuntime.cpp
    AudioEngine/AudioEngine.cpp
    EventBus/EventBus.cpp
    AudioEventManager/AudioEventManager.cpp
)

target_include_directories(AudioHandlerEngine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(AudioHandlerEngine PUBLIC
    juce::juce_audio_devices
    juce::juce_audio_basics
    juce::juce_core
    juce::juce_events
)
