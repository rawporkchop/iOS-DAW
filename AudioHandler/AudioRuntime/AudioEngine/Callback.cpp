#include "Callback.hpp"
#include <juce_audio_devices/juce_audio_devices.h>

void Callback::audioDeviceAboutToStart(juce::AudioIODevice*) {
}

void Callback::audioDeviceStopped() {}

void Callback::audioDeviceIOCallbackWithContext(
    const float* const* inputChannelData,
    int numInputChannels,
    float* const* outputChannelData,
    int numOutputChannels,
    int numSamples,
    const juce::AudioIODeviceCallbackContext& context) {

    // Check if input and output channels are available for processing.
    if (numInputChannels > 0 && numOutputChannels > 0)
    {
        // Simple passthrough: Copy every sample from input channels to output channels.
        for (int ch = 0; ch < numInputChannels; ++ch)
        {
            // Assuming we map input channel 'ch' directly to output channel 'ch'.
            if (ch < numOutputChannels)
            {
                // Copy data from the input buffer to the corresponding output buffer.
                juce::FloatVectorOperations::copy(outputChannelData[ch], inputChannelData[ch], numSamples);
            }
        }
    }
}
