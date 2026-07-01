// #include <juce_audio_devices/juce_audio_devices.h>
// #include <juce_audio_basics/juce_audio_basics.h>
// #include <juce_core/juce_core.h>

#include "AudioEventManager.hpp"

// --- Singleton Implementation ---
AudioEventManager& AudioEventManager::getInstance() {
    static AudioEventManager instance;
    return instance;
}
