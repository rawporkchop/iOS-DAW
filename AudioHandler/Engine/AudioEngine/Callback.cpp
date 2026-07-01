#include "Callback.hpp"
#include <juce_audio_devices/juce_audio_devices.h>

void Callback::audioDeviceAboutToStart(juce::AudioIODevice*) {
    return;
}

void Callback::audioDeviceStopped() {
    return;
}

void Callback::audioDeviceIOCallbackWithContext(
    const float* const* inputChannelData,
    int numInputChannels,
    float* const* outputChannelData,
    int numOutputChannels,
    int numSamples,
    const juce::AudioIODeviceCallbackContext& context
) {
    if (numInputChannels > 0 && numOutputChannels > 0)
        // Simple passthrough: Copy every sample from input channels to output channels.
        for (int ch = 0; ch < numInputChannels; ++ch)
            if (ch < numOutputChannels)
                juce::FloatVectorOperations::copy(outputChannelData[ch], 
                                                  inputChannelData[ch], 
                                                  numSamples);
    return;
}
