# AGENTS.md — DoxTk contributor and implementation guide

## Project purpose
DoxTk is a document-conversion toolkit. It aims to translate between document formats through explicit intermediate representations (IRs), parsers/readers, serializers/writers, and reusable tooling. `doxir-db/` is the registry of IR descriptions and is authored in **Doxir**, a Lua-based DSL. The toolchain should make it straightforward to add formats and utilities without duplicating conversion logic.

This repository is a scaffold, not a claim that every parser or converter is implemented. Treat `TODO` markers and interfaces as starting points and keep behavior honest: unsupported conversions should report an actionable error rather than silently corrupt content.

## Repository map
- `include/doxtk/`: public C++ API, split by concern.
- `include/DoxTk*.h`: compatibility/umbrella headers.
- `src/`: implementation units and library target.
- `doxir-db/`: Doxir IR definitions and `MANIFEST.yaml`.
- `lua/`: Lua-facing module entry points.
- `bindings/`: SWIG interface and binding-generation helper.
- `toolchain/`: command-line programs built on the library.
- `tests/`: unit/integration test scaffold.
- `docs/`: architecture and extension notes.
- `third_party/`: optional vendored dependencies (not included in this archive).

## Build and dependency policy
- C++20 is the baseline. Keep the core library buildable without optional third-party libraries.
- CMake is the supported build system. Configure with `cmake -S . -B build`, then `cmake --build build`.
- Enable tests with `-DDOXTK_BUILD_TESTS=ON`.
- Third-party names supplied by the project owner but not present here: `ctl`, `fmt`, `json`, `kaguya`, `klib`, `libglr`, `libharu`, `lua`, `memtkx`, `metatk`, `pugixml`, `sfsexp`, `spdlog`, `xsimd`, and `yaml-cpp`. Do not assume they exist or make the default build require them. Add explicit CMake options and clear diagnostics when enabling integrations that need them.
- Prefer `find_package` for system packages, then an explicitly configured `third_party/<name>` source tree. Do not fetch dependencies automatically during configure.
- Keep generated files under the build directory unless a generator is explicitly intended to update checked-in files.

## Architecture and data flow
1. A reader detects/loads source input and produces a source representation.
2. A parser turns text/bytes into a syntax/semantic representation.
3. A translator maps one IR to another. Translation must preserve structure where the target model supports it and report lossy conversions.
4. A serializer/writer emits target bytes/text.
5. Drivers and toolchain programs compose these stages, handle options, and present errors.
6. Doxir database definitions describe IRs and should be versioned through `MANIFEST.yaml`.

Do not conflate a format name with an IR name. One format may map to several IRs, and several formats may serialize the same IR. Keep format registration and conversion capabilities explicit.

## The C++ Wrapper

`include/DoxTk.hpp` is a C++ wrapper that besdies the API, has a C++-native DSL. For the DSL, we use `third_party/metatk/DSLtk/DSLtk.hpp`.

## Implementation conventions
- Public declarations live in `include/doxtk/`; implementations live in the matching `src/` unit.
- Use `namespace doxtk`. Avoid global symbols except legacy compatibility wrappers.
- Public headers must be self-contained, include what they use, and not depend on undeclared third-party headers.
- Prefer `std::string`, `std::string_view`, `std::vector`, `std::span`, and `std::filesystem` at the public boundary.
- Errors should carry an operation/context and a useful message. Do not swallow parse, I/O, or conversion errors.
- File I/O should be binary-safe and explicit about encoding. Do not assume every document is UTF-8.
- Keep deterministic output where practical. Avoid relying on unordered iteration order in serialized output.
- Avoid global mutable registries unless their lifecycle/thread-safety is documented.
- Never claim complete format support based only on a placeholder implementation.
- Add tests for success, malformed input, empty input, encoding boundaries, and lossy/unsupported conversions.
- Keep CLI programs thin: argument parsing, invoking library APIs, mapping errors to exit codes.
- Document each new IR in its `.doxir` file and register it in `doxir-db/MANIFEST.yaml`.

## Manual

In `docs/`, we have `Frontpage.md` which indexes all the Markdown files in `docs/manual`. This Markdown file is then made to be the frontpage of the Doxygen-generated documentation, specified in `docs/Doxyfile.in`

## Adding a format or conversion
1. Identify or define the IR in `doxir-db/`.
2. Add/update its manifest entry and note required dependencies.
3. Implement a reader/parser and/or serializer/writer in a focused translation unit.
4. Register source/target capabilities in the conversion registry.
5. Add a CLI tool only when it composes existing library operations or adds a clearly distinct workflow.
6. Add fixtures and tests; document unsupported syntax and known lossiness.
7. Build with optional integrations disabled, then test the relevant enabled configuration.

## Definition of done
- Default configure/build works with no absent third-party directories.
- Public headers compile in isolation.
- CLI help and errors are actionable.
- Tests cover the behavior implemented, not aspirational features.
- README/docs distinguish implemented functionality from planned work.
