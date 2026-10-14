# Development notes

## Configure and test
```sh
cmake -S . -B build -DDOXTK_BUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

CMake 3.20+ and a C++20 compiler are required. Ninja is used by the presets; use `cmake -S . -B build` if Ninja is unavailable.

## Style
- Use four spaces, braces on the same line, and descriptive names.
- Keep headers self-contained and avoid non-standard includes in the core.
- Return structured errors for routine failures.
- Test CLI help and error paths as well as library behavior.
- Add regression fixtures for every format behavior claimed as supported.

## Optional dependencies
Dependencies are not vendored in this scaffold. Optional feature switches currently fail explicitly rather than pretending an integration is available. When implementing one, document the expected package target/version and test both enabled and disabled configurations.
