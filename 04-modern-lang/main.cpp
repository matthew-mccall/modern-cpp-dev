#include <array>
#include <concepts>
#include <print>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

// Fold expression syntax quick reference:
// 1) (... op pack)        -> unary left fold
// 2) (pack op ...)        -> unary right fold
// 3) (init op ... op pack)-> binary left fold
// 4) (pack op ... op init)-> binary right fold
// Example: (... + values) folds a parameter pack with '+' from left to right.

// 'typename... Handlers' declares a template parameter pack (zero or more types).
template <typename... Handlers>
struct Overload : Handlers... {
    // This is pack expansion, not a fold expression.
    // It expands to one using-declaration per handler type:
    // using H1::operator(); using H2::operator(); ...
    using Handlers::operator()...;
};

template <typename... Handlers>
// 'Handlers...' here is a function-parameter pack in the deduction guide.
// This allows Overload{lambda1, lambda2, ...} to deduce Overload<Lambda1, Lambda2, ...>.
Overload(Handlers...) -> Overload<Handlers...>;

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
    std::println("");

    std::println("--- variant visit with overloaded constrained auto ---");
    const std::vector<std::variant<int, double, std::string, bool>> values {
        42,
        3.5,
        std::string("hello variant"),
        true,
    };

    // Pack expansion happens when constructing Overload with multiple lambdas:
    // each lambda becomes one element in the Handlers... pack.
    const auto visitor = Overload {
        [](std::floating_point auto value) {
            std::println("one-case handler (floating point): {}", value);
        },
        [](std::integral auto value) {
            std::println("multi-case handler (integral): {}", value);
        },
        [](const std::string& value) {
            std::println("one-case handler (string): {}", value);
        },
    };

    for (const auto& value : values) {
        std::visit(visitor, value);
    }

    return 0;
}
