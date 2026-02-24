# 02-modern-std

## Topic

Modern C++ standard-library types and APIs (C++17–C++23).

## What this module covers

- `std::optional` (C++17)
- `std::variant` (C++17)
- `std::filesystem` (C++17)
- `std::tuple` (C++11)
- `std::any` (C++17)
- `std::expected` (C++23)
- `std::format` (C++20)
- `std::print` / `std::println` (C++23)

## Expected monadic flow demo

The module includes a monadic pipeline with `std::expected`:

- `and_then` for chaining fallible operations
- `transform` for mapping successful values
- automatic short-circuit on errors

## Source and target

- Source: `main.cpp`
- Target: `02ModernStd`

## Build and run (repo root)

```bash
cmake -S . -B build -G Ninja
cmake --build build --target 02ModernStd
./build/02-modern-std/02ModernStd
```
