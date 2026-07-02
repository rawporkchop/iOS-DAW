#include "../EventBus/EventBus.hpp"
#include "../AudioEngine/AudioEngine.hpp"
#include "../AudioEventManager/AudioEventManager.hpp"
#include "../Event/Events.hpp"

#include "AudioRuntime.hpp"

AudioRuntime::AudioRuntime()
    : eventBus{}, audioEngine{}, audioEventManager{eventBus, audioEngine} {}

void AudioRuntime::startEngine() {
    eventBus.push(EngineStart{});
    audioEventManager.processEvents();
}
