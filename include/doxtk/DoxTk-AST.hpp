#pragma once
#include "doxtk/DoxTk-.hpp"

// AST node model and tree traversal.
// This header is intentionally dependency-free. Add stable public declarations
// here and keep implementations in the matching src/DoxTk-AST.cpp.
namespace doxtk {
struct ASTModuleInfo {
    static constexpr std::string_view description = "AST node model and tree traversal.";
};
} // namespace doxtk
