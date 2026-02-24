# 05-ranges-views

## Topic

Ranges and views for composable data pipelines in modern C++.

## What this module covers

- `std::views::drop`
- `std::views::filter`
- `std::views::transform` (map)
- `std::ranges::for_each`
- `std::ranges::fold_left`
- Pipe syntax (`|`) for readable chaining

## Source and target

- Source: `main.cpp`
- Target: `05RangesViews`

## Build and run (repo root)

```bash
cmake -S . -B build -G Ninja
cmake --build build --target 05RangesViews
./build/05-ranges-views/05RangesViews
```
