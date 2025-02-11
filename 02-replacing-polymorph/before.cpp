#include <print>
#include <string>

class Animal {
public:
  virtual auto GetName() const -> std::string = 0;
  virtual auto GetSound() const -> std::string = 0;
  virtual ~Animal() = default;
};

class Cow: public Animal {
public:
  auto GetName() const -> std::string override;
  auto GetSound() const -> std::string override;
};

class Cat: public Animal {
public:
  auto GetName() const -> std::string override;
  auto GetSound() const -> std::string override;
};

class Bird: public Animal {
public:
  auto GetName() const -> std::string override;
  auto GetSound() const -> std::string override;
};

class Mouse: public Animal {
public:
  auto GetName() const -> std::string override;
  auto GetSound() const -> std::string override;
};

auto Cow::GetName() const -> std::string { return "Cow"; }
auto Cow::GetSound() const -> std::string { return "moo"; }

auto Cat::GetName() const -> std::string { return "Cat"; }
auto Cat::GetSound() const -> std::string { return "meow"; }

auto Bird::GetName() const -> std::string  { return "Bird"; }
auto Bird::GetSound() const -> std::string { return "tweet"; }

auto Mouse::GetName() const -> std::string  { return "Mouse"; }
auto Mouse::GetSound() const -> std::string { return "squeak"; }

void GetAnimalSound(const Animal& animal)
{
  std::println("{} goes {}", animal.GetName(), animal.GetSound());
}

int main(void)
{
  Cow cow;
  Cat cat;
  Bird bird;
  Mouse mouse;

  GetAnimalSound(cow);
  GetAnimalSound(cat);
  GetAnimalSound(bird);
  GetAnimalSound(mouse);
}