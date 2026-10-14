#pragma once
#include "doxtk/DoxTk.hpp"

// Registries and shared toolchain utilities.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTkTooling.cpp.
namespace doxtk {
struct ToolingModuleInfo {
    static constexpr std::string_view description = "Registries and shared toolchain utilities.";
};
} // namespace doxtk
