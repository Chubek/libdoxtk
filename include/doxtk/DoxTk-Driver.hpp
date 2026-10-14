#pragma once
#include "doxtk/DoxTk.hpp"

// High-level conversion orchestration.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTkDriver.cpp.
namespace doxtk {
struct DriverModuleInfo {
    static constexpr std::string_view description = "High-level conversion orchestration.";
};
} // namespace doxtk
