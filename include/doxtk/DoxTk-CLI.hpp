#pragma once
#include "doxtk/DoxTk.hpp"

// Reusable command-line argument handling.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTkCLI.cpp.
namespace doxtk {
struct CLIModuleInfo {
    static constexpr std::string_view description = "Reusable command-line argument handling.";
};
} // namespace doxtk
