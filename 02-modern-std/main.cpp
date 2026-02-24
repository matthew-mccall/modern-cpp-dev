#include <any>
#include <expected>
#include <filesystem>
#include <format>
#include <iostream>
#include <optional>
#include <print>
#include <string>
#include <tuple>
#include <variant>

// Introduced in C++17
void optionalExample()
{
    std::optional<int> maybeNumber;
    std::cout << "optional has value? " << std::boolalpha << maybeNumber.has_value() << '\n';

    maybeNumber = 42;
    std::cout << "optional value: " << maybeNumber.value() << '\n';

    const int numberOrFallback = maybeNumber.value_or(0);
    std::cout << "optional value_or(0): " << numberOrFallback << "\n\n";
}

// Introduced in C++17
void variantExample()
{
    std::variant<int, std::string> value = 2026;
    std::cout << "variant<int, string> holds int: " << std::get<int>(value) << '\n';

    value = std::string("hello variant");
    std::cout << "variant now holds string: " << std::get<std::string>(value) << "\n\n";
}

// Introduced in C++17
void filesystemExample()
{
    const std::filesystem::path cwd = std::filesystem::current_path();
    const std::filesystem::path smartPtrExamplePath = cwd / "01-smart-ptrs" / "main.cpp";

    std::cout << "current path: " << cwd << '\n';
    std::cout << "sample path exists? " << std::boolalpha << std::filesystem::exists(smartPtrExamplePath) << '\n';
    std::cout << "sample path filename: " << smartPtrExamplePath.filename() << "\n\n";
}

// Introduced in C++11
void tupleExample()
{
    std::tuple<int, std::string, double> employee { 7, "Ada", 99.5 };

    std::cout << "tuple id: " << std::get<0>(employee) << '\n';
    std::cout << "tuple name: " << std::get<1>(employee) << '\n';
    std::cout << "tuple score: " << std::get<2>(employee) << "\n\n";
}

// Introduced in C++17
void anyExample()
{
    std::any value = std::string("stored in std::any");
    std::cout << "any type name: " << value.type().name() << '\n';
    std::cout << "any string value: " << std::any_cast<std::string>(value) << '\n';

    value = 123;
    std::cout << "any int value: " << std::any_cast<int>(value) << "\n\n";
}

// Introduced in C++23
auto parseInteger(const std::string& text) -> std::expected<int, std::string>
{
    if (text.empty()) {
        return std::unexpected("input is empty");
    }

    try {
        std::size_t consumed = 0;
        const int value = std::stoi(text, &consumed);
        if (consumed != text.size()) {
            return std::unexpected("input contains non-numeric characters");
        }
        return value;
    } catch (...) {
        return std::unexpected("invalid integer or out-of-range value");
    }
}

// Introduced in C++23
auto ensureNonZero(int value) -> std::expected<int, std::string>
{
    if (value == 0) {
        return std::unexpected("value must be non-zero");
    }
    return value;
}

// Introduced in C++23
auto reciprocal(int value) -> std::expected<double, std::string>
{
    return 1.0 / static_cast<double>(value);
}

// Introduced in C++23
void expectedExample()
{
    const auto monadicSuccess = parseInteger("4")
        .and_then(ensureNonZero)
        .and_then(reciprocal)
        .transform([](double value) {
            return std::format("monadic success: reciprocal = {:.3f}", value);
        });

    const auto monadicZeroError = parseInteger("0")
        .and_then(ensureNonZero)
        .and_then(reciprocal)
        .transform([](double value) {
            return std::format("reciprocal = {:.3f}", value);
        });

    const auto monadicParseError = parseInteger("4abc")
        .and_then(ensureNonZero)
        .and_then(reciprocal)
        .transform([](double value) {
            return std::format("reciprocal = {:.3f}", value);
        });

    if (monadicSuccess) {
        std::cout << monadicSuccess.value() << '\n';
    }

    if (!monadicZeroError) {
        std::cout << "monadic error from and_then: " << monadicZeroError.error() << '\n';
    }

    if (!monadicParseError) {
        std::cout << "monadic parse error (transform not run): " << monadicParseError.error() << '\n';
    }
    std::cout << "\n";
}

// Introduced in C++20
void formatExample()
{
    const std::string message = std::format("format result: {} + {} = {}", 20, 22, 20 + 22);
    std::cout << message << '\n';
    std::cout << "\n";
}

// Introduced in C++23
void printExample()
{
    std::print("std::print value: {}\n", 123);
    std::println("std::println message: {}", "hello from print/println");
    std::cout << "\n";
}

int main()
{
    std::cout << "--- optional ---\n";
    optionalExample();

    std::cout << "--- variant ---\n";
    variantExample();

    std::cout << "--- filesystem ---\n";
    filesystemExample();

    std::cout << "--- tuple ---\n";
    tupleExample();

    std::cout << "--- any ---\n";
    anyExample();

    std::cout << "--- expected ---\n";
    expectedExample();

    std::cout << "--- format ---\n";
    formatExample();

    std::cout << "--- print / println ---\n";
    printExample();

    return 0;
}
