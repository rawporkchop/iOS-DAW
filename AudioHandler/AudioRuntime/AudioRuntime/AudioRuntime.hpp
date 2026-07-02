#pragma once

#include "../AudioEngine/AudioEngine.hpp"
#include "../AudioEventManager/AudioEventManager.hpp"

class AudioRuntime {
public:
    AudioRuntime();

    void startEngine();
    void restartEngine();
    void stopEngine();
    
private:
    AudioEngine audioEngine;
    AudioEventManager audioEventManager;
};
