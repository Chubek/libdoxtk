# DoxTk

DoxTk is a C++ document-conversion toolkit organized around intermediate representations (IRs). Its companion `doxir-db/` contains IR schemas described in Doxir, a Lua-based DSL. The intent is to compose readers, parsers, translators, serializers, and writers into reusable conversion tools.

> **Scaffold status:** this archive establishes project structure and interfaces. Format conversion implementations are placeholders until explicitly implemented and tested.

## Quick start

```sh
cmake -S . -B build -DDOXTK_BUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

The default build should not require any of the optional third-party libraries listed below. See [docs/architecture.md](docs/architecture.md) and [docs/development.md](docs/development.md).

## Components
- `include/doxtk/` — public C++ interfaces.
- `src/` — implementation units.
- `doxir-db/` — IR definitions and manifest.
- `toolchain/` — conversion and inspection command-line tools.
- `lua/` and `bindings/` — planned/optional Lua and SWIG integration.
- `tests/` — basic regression tests.

## External dependencies

The following third-party dependencies are not included in this archive: `ctl`, `fmt`, `json`, `kaguya`, `klib`, `libglr`, `libharu`, `lua`, `memtkx`, `metatk`, `pugixml`, `sfsexp`, `spdlog`, `xsimd`, `yaml-cpp`. Integrations must be optional and documented. Do not enable an integration until its dependency and version requirements are known.

## Design principles
- Explicit source and target IRs.
- No silent data loss: unsupported or lossy operations must be surfaced.
- Binary-safe I/O and explicit encoding.
- Small composable library operations; CLI tools remain thin.
- Tests and documentation for every supported format feature.
