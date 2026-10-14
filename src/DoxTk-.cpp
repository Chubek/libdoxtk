#include "doxtk/DoxTk-.hpp"
#include <fstream>
#include <iterator>

namespace doxtk {
std::string_view error_code_name(ErrorCode code) noexcept {
    switch (code) {
    case ErrorCode::ok: return "ok";
    case ErrorCode::invalid_argument: return "invalid_argument";
    case ErrorCode::io_error: return "io_error";
    case ErrorCode::parse_error: return "parse_error";
    case ErrorCode::unsupported_format: return "unsupported_format";
    case ErrorCode::unsupported_conversion: return "unsupported_conversion";
    case ErrorCode::serialization_error: return "serialization_error";
    case ErrorCode::dependency_missing: return "dependency_missing";
    case ErrorCode::internal_error: return "internal_error";
    }
    return "unknown";
}

Result<std::vector<std::byte>> read_file(const std::filesystem::path& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return Result<std::vector<std::byte>>::failure(
        ErrorCode::io_error, "Unable to open input file", path.string());
    std::vector<char> raw((std::istreambuf_iterator<char>(in)), {});
    if (in.bad()) return Result<std::vector<std::byte>>::failure(
        ErrorCode::io_error, "Failed while reading input file", path.string());
    std::vector<std::byte> bytes;
    bytes.reserve(raw.size());
    for (unsigned char c : raw) bytes.push_back(static_cast<std::byte>(c));
    return Result<std::vector<std::byte>>::success(std::move(bytes));
}

Error write_file(const std::filesystem::path& path, std::span<const std::byte> bytes) {
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out) return {ErrorCode::io_error, "Unable to open output file", path.string()};
    for (std::byte b : bytes) out.put(static_cast<char>(std::to_integer<unsigned char>(b)));
    if (!out) return {ErrorCode::io_error, "Failed while writing output file", path.string()};
    return {};
}
} // namespace doxtk
