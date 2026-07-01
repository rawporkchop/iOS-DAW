#pragma once

#include "../Bus/EventBus.hpp"
#include "../AudioEngine/AudioEngine.hpp"
#include "../AudioEventManager/AudioEventManager.hpp"

class AudioRuntime {
public:
    AudioRuntime();
    
private:
    EventBus eventBus;
    AudioEngine audioEngine;
    AudioEventManager audioEventManager;
};
