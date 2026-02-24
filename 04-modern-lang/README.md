# 04-modern-lang

## Topic

Modern C++ language features and syntax patterns.

## What this module covers

- Trailing return types (`auto f(...) -> T`)
- Constrained `auto` in parameters and return types
- Structured bindings
- `constexpr` and `if constexpr`
- `consteval`
- Variant visitation with overloaded constrained handlers
- Pack expansion notes and fold-expression syntax reference

## Source and target

- Source: `main.cpp`
- Target: `04ModernLang`

## Build and run (repo root)

```bash
cmake -S . -B build -G Ninja
cmake --build build --target 04ModernLang
./build/04-modern-lang/04ModernLang
```
