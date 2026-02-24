# 03-concepts

## Topic

Concepts and constraints as a modern replacement for many SFINAE patterns.

## What this module covers

- SFINAE ergonomics and readability drawbacks
- Defining custom concepts (`Number`, `HasSize`, `Drawable`)
- Constraining templates with standard concepts
- Overloading functions with concept constraints
- Compile-time polymorphism through constrained templates

## Source and target

- Source: `main.cpp`
- Target: `03Concepts`

## Build and run (repo root)

```bash
cmake -S . -B build -G Ninja
cmake --build build --target 03Concepts
./build/03-concepts/03Concepts
```
