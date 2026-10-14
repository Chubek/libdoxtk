#pragma once
#include "doxtk/DoxTk.hpp"

// IR serialization interfaces.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTkSerializer.cpp.
namespace doxtk {
struct SerializerModuleInfo {
    static constexpr std::string_view description = "IR serialization interfaces.";
};
} // namespace doxtk
