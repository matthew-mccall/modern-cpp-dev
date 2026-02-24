# 00-intro-to-cmake

## Topic

Introductory CMake setup with external dependency integration.

## What this module covers

- Minimal CMake project structure
- Creating an executable target
- Pulling dependencies with `FetchContent`
- Linking `spdlog` (`spdlog::spdlog`) into an executable

## Source and target

- Source: `main.cpp`
- Target: `00IntroToCMake`

## Build and run

From this module directory:

```bash
cmake -S . -B build -G Ninja
cmake --build build
./build/00IntroToCMake
```

Expected behavior: logs a simple message through `spdlog`.
