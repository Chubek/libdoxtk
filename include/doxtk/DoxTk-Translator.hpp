#pragma once
#include "doxtk/DoxTk.hpp"

// IR-to-IR translation interfaces.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTkTranslator.cpp.
namespace doxtk {
struct TranslatorModuleInfo {
    static constexpr std::string_view description = "IR-to-IR translation interfaces.";
};
} // namespace doxtk
