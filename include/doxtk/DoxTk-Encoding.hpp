#pragma once
#include "doxtk/DoxTk.hpp"

// Encoding detection and transcoding.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTkEncoding.cpp.
namespace doxtk {
struct EncodingModuleInfo {
    static constexpr std::string_view description = "Encoding detection and transcoding.";
};
} // namespace doxtk
