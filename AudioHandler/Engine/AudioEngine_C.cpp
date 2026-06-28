#include "AudioEngine_C.h"
#include "AudioEngine.hpp"

static AudioEngine gEngine;

void AudioEngine_start() { 
    gEngine.start(); 
}

void AudioEngine_stop()  { 
    gEngine.stop();  
}

void AudioEngine_restart() {
    gEngine.restart();
}
