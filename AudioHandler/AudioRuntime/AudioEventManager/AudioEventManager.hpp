#pragma once

// #include <juce_audio_devices/juce_audio_devices.h>
// #include <juce_audio_basics/juce_audio_basics.h>
// #include <juce_core/juce_core.h>

#include "../AudioEngine/AudioEngine.hpp"
#include "../Event/Events.hpp"
#include "../EventBus/EventBus.hpp"

/**
 * @brief Pure C++ Event Manager responsible for the full event-based
 * connection between the Swift frontend and the C++ backend. This class serves
 * as the single source of truth of the audio engine state, making it easily
 * consumable by C++ modules and by Swift
 */
class AudioEventManager {
public:
    AudioEventManager(EventBus& bus, AudioEngine& audioEngine);
    ~AudioEventManager();

    void processEvents();

private:
    struct Handler {
        Handler(AudioEngine& engine);

        void operator()(const EngineStart e);

    private:
        AudioEngine& audioEngine;

        Handler(const Handler&) = delete;
        Handler& operator=(const Handler&) = delete;
    };

    // Prevent copying and assignment (singleton)
    AudioEventManager(const AudioEventManager&) = delete;
    AudioEventManager& operator=(const AudioEventManager&) = delete;

    EventBus& bus;
    AudioEngine& audioEngine;
    Handler handler;
};
