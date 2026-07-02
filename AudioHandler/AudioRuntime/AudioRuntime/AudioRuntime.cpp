#include "../AudioEngine/AudioEngine.hpp"
#include "../AudioEventManager/AudioEventManager.hpp"

#include "AudioRuntime.hpp"

AudioRuntime::AudioRuntime()
    : audioEngine{}, audioEventManager{audioEngine} {}

void AudioRuntime::startEngine() {
    audioEventManager.processEvent(EngineStart{});
}

void AudioRuntime::restartEngine() {
    audioEventManager.processEvent(EngineRestart{});
}

void AudioRuntime::stopEngine() {
    audioEventManager.processEvent(EngineRestart{});
}
