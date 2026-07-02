#pragma once

#include <variant>

struct EngineStart {};
struct EngineRestart {};
struct EngineStop {};

using Event = std::variant<EngineStart, EngineRestart, EngineStop>;
