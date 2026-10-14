#pragma once
#include "doxtk/DoxTk-.hpp"

// Parsing interfaces and parse diagnostics.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTk-Parser.cpp.
namespace doxtk {
struct ParserModuleInfo {
    static constexpr std::string_view description = "Parsing interfaces and parse diagnostics.";
};
} // namespace doxtk
