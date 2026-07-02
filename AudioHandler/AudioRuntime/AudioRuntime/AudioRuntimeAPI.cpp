#include "AudioRuntimeAPI.hpp"
#include "AudioRuntime.hpp"

namespace {
    AudioRuntime& instance() {
        static AudioRuntime runtime;   // constructed once, lazily, on first call
        return runtime;
    }
}

void audioRuntime_start()   { instance().startEngine(); }
// void audioRuntime_stop()    { instance().stopEngine(); }
// void audioRuntime_restart() { instance().restartEngine(); }
