#include "AudioEngine.hpp"

#include <juce_audio_devices/juce_audio_devices.h>

void AudioEngine::initializeEngine() {
    DBG("Engine starting");
    constexpr int numInputChannelsNeeded{1};
    constexpr int numOutputChannelsNeeded{2};

    // Basic Initialization for MVP
    deviceManager.initialiseWithDefaultDevices(numInputChannelsNeeded,
                                               numOutputChannelsNeeded);
    deviceManager.addAudioCallback(&callback);
}

void AudioEngine::stopEngine() {
    DBG("Engine stopping");
    deviceManager.removeAudioCallback(&callback);
}

void AudioEngine::restartEngine() {
    stopEngine();
    initializeEngine();
}
