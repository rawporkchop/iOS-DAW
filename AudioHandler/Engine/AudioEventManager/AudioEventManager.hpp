#pragma once

// #include <juce_audio_devices/juce_audio_devices.h>
// #include <juce_audio_basics/juce_audio_basics.h>
// #include <juce_core/juce_core.h>

#include "../AudioEngine/AudioEngine.hpp"

/**
 * @brief Pure C++ Event Manager responsible for the full event-based
 * connection between the Swift frontend and the C++ backend. This class serves
 * as the single source of truth of the audio engine state, making it easily
 * consumable by C++ modules and by Swift
 */
class AudioEventManager {
public:
    // Singleton access pattern
    static AudioEventManager& getInstance();

    AudioEventManager();
    ~AudioEventManager();

private:
    AudioEngine audioEngine;

    // Prevent copying and assignment (singleton)
    AudioEventManager(const AudioEventManager&) = delete;
    AudioEventManager& operator=(const AudioEventManager&) = delete;
};
