#pragma once

#include "../EventBus/EventBus.hpp"
#include "../AudioEngine/AudioEngine.hpp"
#include "../AudioEventManager/AudioEventManager.hpp"

class AudioRuntime {
public:
    AudioRuntime();

    void startEngine();
    
private:
    EventBus eventBus;
    AudioEngine audioEngine;
    AudioEventManager audioEventManager;
};
