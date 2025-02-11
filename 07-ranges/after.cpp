#include <cstdlib>
#include <vector>
#include <ranges>
#include <print>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use ranges to filter even numbers and square them
    auto result = numbers
                | std::views::filter([](int n) { return n % 2 == 0; })
                | std::views::transform([](int n) { return n * n; });

    // Print the result using std::print
    std::print("Result: ");
    for (const auto& num : result) {
        std::print("{} ", num);
    }
    std::print("\n");

    return EXIT_SUCCESS;
}