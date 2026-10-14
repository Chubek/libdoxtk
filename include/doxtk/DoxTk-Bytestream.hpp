#pragma once
#include "doxtk/DoxTk-.hpp"

// Byte-oriented input and output helpers.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTk-Bytestream.cpp.
namespace doxtk {
struct BytestreamModuleInfo {
    static constexpr std::string_view description = "Byte-oriented input and output helpers.";
};
} // namespace doxtk
