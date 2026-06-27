// Engine/AudioEngine_C.cpp
#include "AudioEngine_C.h"
#include "AudioEngine.hpp"
#include <iostream>

static AudioEngine gEngine;

void AudioEngine_start() { 
    std::cout << "c start" << std::endl;
    gEngine.start(); 
}
void AudioEngine_stop()  { gEngine.stop();  }
