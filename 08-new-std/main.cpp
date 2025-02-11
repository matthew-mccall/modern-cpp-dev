#include <cstdlib>
#include <optional>
#include <variant>
#include <expected>
#include <print>
#include <filesystem>

namespace fs = std::filesystem;

// Function using std::optional to return an optional value
std::optional<int> findPositive(int n) {
    if (n > 0) {
        return n;
    }
    return std::nullopt;
}

// Function using std::variant to return different types
std::variant<int, std::string> getValue(bool returnString) {
    if (returnString) {
        return std::string("Hello, World!");
    }
    return 42;
}

// Function using std::expected to return value or error
std::expected<int, std::string> divide(int a, int b) {
    if (b == 0) {
        return std::unexpected("Division by zero error!");
    }
    return a / b;
}

int main() {
    // Check if a specific file exists using std::filesystem
    std::print("Checking if file 'example.txt' exists...\n");
    fs::path filePath("example.txt");
    if (fs::exists(filePath)) {
        std::print("File 'example.txt' exists.\n");
    } else {
        std::print("File 'example.txt' does not exist.\n");
    }

    // Using std::optional
    auto result = findPositive(10);
    if (result) {
        std::print("Positive number: {}\n", *result);
    } else {
        std::print("Not a positive number\n");
    }

    // Using std::variant
    auto value = getValue(true);
    if (std::holds_alternative<std::string>(value)) {
        std::print("String: {}\n", std::get<std::string>(value));
    } else {
        std::print("Integer: {}\n", std::get<int>(value));
    }

    // Using std::expected
    auto divisionResult = divide(10, 2);
    if (divisionResult.has_value()) {
        std::print("Division result: {}\n", divisionResult.value());
    } else {
        std::print("Error: {}\n", divisionResult.error());
    }

    return EXIT_SUCCESS;
}