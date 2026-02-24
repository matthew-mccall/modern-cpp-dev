#include <array>
#include <concepts>
#include <print>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

auto addTrailing(int left, int right) -> int
{
    return left + right;
}

auto sumConstrained(std::integral auto left, std::integral auto right) -> std::integral auto
{
    return left + right;
}

template <typename T>
constexpr T absConstexpr(T value)
{
    if constexpr (std::signed_integral<T>) {
        return value < 0 ? -value : value;
    } else {
        return value;
    }
}

consteval auto buildMask(unsigned bitCount) -> unsigned
{
    return bitCount == 0 ? 0U : ((1U << bitCount) - 1U);
}

int main()
{
    std::println("--- Trailing return types ---");
    std::println("addTrailing(10, 32): {}", addTrailing(10, 32));
    std::println("");

    std::println("--- Constrained auto (params + return) ---");
    const auto integralSum = sumConstrained(7, 9);
    std::println("sumConstrained(7, 9): {}", integralSum);
    std::println("");

    std::println("--- Structured bindings ---");
    const std::tuple<int, std::string, double> item { 101, "widget", 19.99 };
    const auto [id, name, price] = item;
    std::println("tuple -> id={}, name={}, price={}", id, name, price);

    const std::array<int, 2> point { 3, 5 };
    const auto [x, y] = point;
    std::println("array -> x={}, y={}", x, y);
    std::println("");

    std::println("--- constexpr + if constexpr ---");
    constexpr int absoluteA = absConstexpr(-42);
    constexpr unsigned absoluteB = absConstexpr(42U);
    static_assert(absoluteA == 42);
    static_assert(absoluteB == 42U);

    std::println("absConstexpr(-42): {}", absoluteA);
    std::println("absConstexpr(42U): {}", absoluteB);
    std::println("");

    std::println("--- consteval ---");
    constexpr unsigned mask = buildMask(5);
    static_assert(mask == 31U);
    std::println("buildMask(5): {}", mask);

    return 0;
}
