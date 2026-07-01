#pragma once

#include <variant>

struct EngineStart {
};

using Event = std::variant<EngineStart>;
