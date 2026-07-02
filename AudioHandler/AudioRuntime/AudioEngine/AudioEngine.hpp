#pragma once

#include "Callback.hpp"

class AudioEngine {
public:
    void initializeEngine();
    void restartEngine();
    void stopEngine();

private:
    Callback callback;

    // juceInitializer GUI initializer used to silence midi jassert
    juce::ScopedJuceInitialiser_GUI juceInitialiser;
    juce::AudioDeviceManager deviceManager; // Global Audio Scope
};
