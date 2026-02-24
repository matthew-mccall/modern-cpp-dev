# 01-smart-ptrs

## Topic

`std::unique_ptr` ownership and API design for resource safety.

## What this module covers

- Unique ownership via `std::unique_ptr`
- Ownership transfer using move semantics (`std::move`)
- Borrowing by `const&` and non-`const&`
- Side effects and mutability trade-offs when borrowing
- Polymorphism with abstract base class and `override`

## Source and target

- Source: `main.cpp`
- Target: `01SmartPtrs`

## Build and run (repo root)

```bash
cmake -S . -B build -G Ninja
cmake --build build --target 01SmartPtrs
./build/01-smart-ptrs/01SmartPtrs
```
