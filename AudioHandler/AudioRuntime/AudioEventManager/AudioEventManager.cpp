// #include <juce_audio_devices/juce_audio_devices.h>
// #include <juce_audio_basics/juce_audio_basics.h>
// #include <juce_core/juce_core.h>
#include <variant>
#include "../AudioEngine/AudioEngine.hpp"
#include "../Event/Events.hpp"

#include "AudioEventManager.hpp"

AudioEventManager::AudioEventManager(AudioEngine& audioEngine) 
    : audioEngine{audioEngine}, handler{audioEngine} {}

AudioEventManager::Handler::Handler(AudioEngine& engine)
    : audioEngine{engine} {}

void AudioEventManager::Handler::operator()(const EngineStart&) {
    audioEngine.initializeEngine();
}

void AudioEventManager::Handler::operator()(const EngineRestart&) {
    audioEngine.restartEngine();
}

void AudioEventManager::Handler::operator()(const EngineStop&) {
    audioEngine.stopEngine();
}

void AudioEventManager::processEvent(Event event) {
    std::visit(handler, event);
}
