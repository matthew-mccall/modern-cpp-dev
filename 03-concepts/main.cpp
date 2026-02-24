#include <array>
#include <concepts>
#include <print>
#include <string>
#include <type_traits>
#include <vector>

// --- Part 1: SFINAE shortcomings -------------------------------------------------
// SFINAE works, but signatures become noisy and diagnostics are less readable.
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void describeSfinae(T value)
{
    std::println("SFINAE integral overload: {}", value);
}

template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>, typename = void>
void describeSfinae(T value)
{
    std::println("SFINAE floating-point overload: {}", value);
}

// --- Part 2: Concepts and constraints -------------------------------------------
template <typename T>
concept Number = std::integral<T> || std::floating_point<T>; // you can use && and || to combine concepts

template <typename T>
concept HasSize = requires(const T& value) {
    { value.size() } -> std::convertible_to<std::size_t>;
};

template <Number T>
void describeConcept(T value)
{
    std::println("Concept-constrained number: {}", value);
}

template <HasSize T>
void printSize(const T& value)
{
    std::println("HasSize value, size = {}", value.size());
}

// --- Part 3: Overloading with concepts ------------------------------------------
template <std::integral T>
void classifyValue(T value)
{
    std::println("classifyValue(integral): {}", value);
}

template <std::floating_point T>
void classifyValue(T value)
{
    std::println("classifyValue(floating_point): {}", value);
}

// --- Part 4: Compile-time polymorphism with concepts ----------------------------
template <typename T>
concept Drawable = requires(const T& object) {
    { object.draw() } -> std::same_as<void>;
};

class Circle {
public:
    void draw() const { std::println("Drawing Circle"); }
};

class Rectangle {
public:
    void draw() const { std::println("Drawing Rectangle"); }
};

template <Drawable T>
void render(const T& object)
{
    object.draw();
}

int main()
{
    std::println("--- SFINAE shortcomings ---");
    describeSfinae(42);
    describeSfinae(3.14);

    std::println("");
    std::println("--- Concepts and constraints ---");
    describeConcept(10);
    describeConcept(2.5);

    const std::vector<int> numbers { 1, 2, 3, 4 };
    const std::array<int, 3> fixed { 7, 8, 9 };
    printSize(numbers);
    printSize(fixed);

    std::println("");
    std::println("--- Overloading with concept parameters ---");
    classifyValue(123);
    classifyValue(4.5f);

    std::println("");
    std::println("--- Compile-time polymorphism with concepts ---");
    const Circle circle;
    const Rectangle rectangle;
    render(circle);
    render(rectangle);

    return 0;
}
