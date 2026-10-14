# Architecture

## Core objects
`Document` is a transport envelope, not a universal AST. It carries an IR identifier, media type, encoding, opaque bytes, and metadata. Format-specific parsers should expose structured types when needed; do not force every representation into a string blob.

`Result<T>` communicates either a value or a structured `Error`. Avoid exceptions as the normal control path for expected parse, I/O, and unsupported-conversion failures. Exceptions may still be caught at application boundaries for unexpected failures.

## Suggested conversion pipeline

```text
input bytes -> Reader -> Parser -> source IR -> Translator -> target IR
            -> Serializer/Writer -> output bytes
```

A driver can compose stages. The translator registry should key conversions by source IR and target IR, not only file extensions. Format sniffing should be advisory; explicit user options should take precedence.

## Lossiness and errors
- Strict mode rejects unsupported features and incompatible target models.
- Permissive mode may preserve unknown nodes as opaque extensions when the format supports it.
- Lossy conversion must be opt-in and report what was dropped or approximated.
- Diagnostics should include format/IR, source location when available, and actionable context.

## Dependency boundaries
The core target is dependency-free. Optional adapters can use Lua/Kaguya, libharu, pugixml, yaml-cpp, fmt/spdlog, or other third-party libraries behind explicit build options. Keep their types out of core public headers.
