#pragma once
#include "doxtk/DoxTk-.hpp"

// Visitor patterns for ASTs.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTk-Visitor.cpp.
namespace doxtk {
struct VisitorModuleInfo {
    static constexpr std::string_view description = "Visitor patterns for ASTs.";
};
} // namespace doxtk
