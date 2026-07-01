// #include <juce_audio_devices/juce_audio_devices.h>
// #include <juce_audio_basics/juce_audio_basics.h>
// #include <juce_core/juce_core.h>
#include <queue>

#include "AudioEventManager.hpp"

AudioEventManager::AudioEventManager(EventBus& bus, AudioEngine& audioEngine) 
    : bus{bus}, audioEngine{audioEngine}, handler{audioEngine} {}

AudioEventManager::Handler::Handler(AudioEngine& engine)
    : audioEngine{engine} {}

void AudioEventManager::Handler::operator()(const EngineStart) {
    audioEngine.initializeEngine();
}

void AudioEventManager::processEvents() {
    Event e;
    while (bus.pop(e)) std::visit(handler, e);
}
