#include "AudioEngine.hpp"

#include <juce_audio_devices/juce_audio_devices.h>

namespace {

class Callback : public juce::AudioIODeviceCallback {

    // First member necessary for proper initialization
    juce::ScopedJuceInitialiser_GUI juceInitialiser;

public:
    void audioDeviceAboutToStart(juce::AudioIODevice*) override {
    }

    void audioDeviceStopped() override {}

    void audioDeviceIOCallbackWithContext(
        const float* const*,
        int,
        float* const* outputs,
        int numOutputs,
        int numSamples,
        const juce::AudioIODeviceCallbackContext&
    ) override {
        for (int ch = 0; ch < numOutputs; ++ch)
            if (outputs[ch])
                juce::FloatVectorOperations::clear(
                    outputs[ch],
                    numSamples
                );
    }

    juce::AudioDeviceManager manager;
};

Callback callback;

}

void AudioEngine::start() { 
    DBG("Engine starting");

    callback.manager.initialise(
        1, // input channels
        2, // output channels
        nullptr,
        true
    );

    callback.manager.addAudioCallback(&callback);
}

void AudioEngine::stop() {
    DBG("Engine stopping");

    callback.manager.removeAudioCallback(&callback);
}
