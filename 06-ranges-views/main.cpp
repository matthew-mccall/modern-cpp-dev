#include <algorithm>
#include <concepts>
#include <numeric>
#include <print>
#include <ranges>
#include <string_view>
#include <vector>

consteval auto initialDropCount() -> std::size_t
{
    return 2;
}

template <std::ranges::input_range Range>
auto printRange(Range&& range, std::string_view label) -> void
{
    std::print("{}: ", label);
    std::ranges::for_each(range, [](const auto& value) {
        std::print("{} ", value);
    });
    std::println("");
}

auto main() -> int
{
    std::println("--- Ranges + Views + Pipe Syntax ---");

    const std::vector<int> values { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    constexpr std::size_t dropCount = initialDropCount();
    static_assert(dropCount == 2);

    constexpr auto evenPredicate = [](std::integral auto value) -> bool {
        return value % 2 == 0;
    };
    constexpr auto squareMapper = [](std::integral auto value) -> std::integral auto {
        return value * value;
    };

    auto pipeline = values
        | std::views::drop(dropCount)
        | std::views::filter(evenPredicate)
        | std::views::transform(squareMapper);

    printRange(values, "original values");
    printRange(pipeline, "drop -> filter -> map result");

    std::println("");
    std::println("--- Constrained Algorithms ---");

    std::print("for_each over pipeline: ");
    std::ranges::for_each(pipeline, [](int value) {
        std::print("[{}] ", value);
    });
    std::println("");

    const auto foldedSum = std::ranges::fold_left(pipeline, 0, [](int acc, int value) -> int {
        return acc + value;
    });
    std::println("left_fold (sum): {}", foldedSum);

    const auto foldedMax = std::ranges::fold_left(pipeline, 0, [](int acc, int value) -> int {
        return std::max(acc, value);
    });
    std::println("left_fold (max): {}", foldedMax);

    return 0;
}
