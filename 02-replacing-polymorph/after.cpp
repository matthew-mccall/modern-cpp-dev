#include <print>
#include <string>

template<typename T>
concept Animal = requires {
    { T::GetName() } -> std::convertible_to<std::string>;
    { T::GetSound() } -> std::convertible_to<std::string>;
};

class Cow {
public:
  static auto GetName() -> std::string;
  static auto GetSound() -> std::string;
};

class Cat {
public:
  static auto GetName() -> std::string;
  static auto GetSound() -> std::string;
};

class Bird {
public:
  static auto GetName() -> std::string;
  static auto GetSound() -> std::string;
};

class Mouse {
public:
  static auto GetName() -> std::string;
  static auto GetSound() -> std::string;
};

auto Cow::GetName() -> std::string { return "Cow"; }
auto Cow::GetSound() -> std::string { return "moo"; }

auto Cat::GetName() -> std::string { return "Cat"; }
auto Cat::GetSound() -> std::string { return "meow"; }

auto Bird::GetName() -> std::string  { return "Bird"; }
auto Bird::GetSound() -> std::string { return "tweet"; }

auto Mouse::GetName() -> std::string  { return "Mouse"; }
auto Mouse::GetSound() -> std::string { return "squeak"; }

template <Animal T>
void GetAnimalSound(void)
{
  std::println("{} goes {}", T::GetName(), T::GetSound());
}

int main(void)
{
  GetAnimalSound<Cow>();
  GetAnimalSound<Cat>();
  GetAnimalSound<Bird>();
  GetAnimalSound<Mouse>();
}