#pragma once

#include <juce_audio_devices/juce_audio_devices.h>

class Callback : public juce::AudioIODeviceCallback {
public:
    void audioDeviceAboutToStart(juce::AudioIODevice*) override;

    void audioDeviceStopped() override;

    void audioDeviceIOCallbackWithContext(
        const float* const* inputChannelData,
        int numInputChannels,
        float* const* outputChannelData,
        int numOutputChannels,
        int numSamples,
        const juce::AudioIODeviceCallbackContext& context
    ) override;
};

