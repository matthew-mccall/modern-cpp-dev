# Modern C++ Workshop

A hands-on workshop repository for modern C++ topics, from CMake basics to C++23 modules.

## Prerequisites

- CMake 3.28+
- A C++23-capable compiler/toolchain
- Ninja (recommended generator in this repo)

## Build

From the repository root:

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

Then run any module target executable from `build/<module-folder>/`.

## Workshop Modules

### 00-intro-to-cmake
- Focus: CMake fundamentals and dependency management with `FetchContent`
- Demonstrates fetching and linking `spdlog`
- Target: `00IntroToCMake` (built from that module's own CMake project)

### 01-smart-ptrs
- Focus: `std::unique_ptr` ownership, borrowing, and move semantics
- Demonstrates ownership transfer vs borrowing APIs and mutation through references
- Target: `01SmartPtrs`

### 02-modern-std
- Focus: modern standard-library vocabulary types and formatting/printing APIs
- Demonstrates `optional`, `variant`, `filesystem`, `tuple`, `any`, `expected`, `format`, and `print/println`
- Includes `std::expected` monadic flow with `and_then` and `transform`
- Target: `02ModernStd`

### 03-concepts
- Focus: shortcomings of SFINAE and modern constraints with concepts
- Demonstrates concept definitions, constrained templates, concept-based overloads, and compile-time polymorphism
- Target: `03Concepts`

### 04-modern-lang
- Focus: modern language syntax and compile-time features
- Demonstrates trailing return types, constrained `auto`, structured bindings, `constexpr`, `if constexpr`, `consteval`
- Includes variant visitation with overloaded constrained handlers and notes on pack expansion/fold syntax
- Target: `04ModernLang`

### 05-ranges-views
- Focus: ranges, views, constrained algorithms, and pipeline composition
- Demonstrates `drop`, `filter`, `transform` (map), `for_each`, `fold_left`, and pipe syntax
- Target: `05RangesViews`

### 06-cpp-modules
- Focus: C++ modules architecture and dependency hygiene
- Demonstrates primary module interface, partitions, implementation unit, global/private fragments, and forward declarations for cross-references
- Explains avoiding cyclic module imports with acyclic module structure
- Target: `06CppModules`

## Running Individual Targets

Examples:

```bash
./build/01-smart-ptrs/01SmartPtrs
./build/02-modern-std/02ModernStd
./build/03-concepts/03Concepts
./build/04-modern-lang/04ModernLang
./build/05-ranges-views/05RangesViews
./build/06-cpp-modules/06CppModules
```
