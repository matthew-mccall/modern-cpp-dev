# 06-cpp-modules

## Topic

C++23 modules: structure, partitions, implementation units, and dependency boundaries.

## What this module covers

- Primary module interface (`workshop.ixx`)
- Module partitions (`workshop:types`, `workshop:relations`)
- Module implementation unit (`workshop.cpp`)
- Global/private module fragments
- Using forward declarations for cross-referencing types
- Why module import graphs should remain acyclic

## Circular dependency note

This module demonstrates a common pattern:

- Keep imports acyclic across module units
- Use forward declarations where only pointer/reference relationships are required

## Source and target

- Sources:
  - `main.cpp`
  - `workshop.ixx`
  - `workshop.types.ixx`
  - `workshop.relations.ixx`
  - `workshop.cpp`
- Target: `06CppModules`

## Build and run (repo root)

```bash
cmake -S . -B build -G Ninja
cmake --build build --target 06CppModules
./build/06-cpp-modules/06CppModules
```
