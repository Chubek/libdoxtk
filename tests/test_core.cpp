#include "doxtk/DoxTk-.hpp"
#include <cassert>
#include <string_view>

int main() {
    using namespace doxtk;
    assert(error_code_name(ErrorCode::ok) == "ok");
    assert(error_code_name(ErrorCode::unsupported_conversion) == "unsupported_conversion");
    const auto result = Result<int>::success(42);
    assert(result.has_value());
    assert(*result.value == 42);
    const auto failure = Result<int>::failure(ErrorCode::parse_error, "bad syntax");
    assert(!failure);
    assert(failure.error.code == ErrorCode::parse_error);
    return 0;
}
