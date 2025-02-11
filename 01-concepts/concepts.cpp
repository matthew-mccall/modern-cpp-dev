#include <iostream>
#include <concepts>

// Define a concept to check if T has a member function foo
template<typename T>
concept HasFoo = requires(T t) {
    { t.foo() } -> std::same_as<void>;
};

// Function that calls foo if it exists
void call_foo(HasFoo auto& t) {
    t.foo();
}

void call_foo(auto&) {
    std::cout << "foo not found!" << std::endl;
}

class A {
public:
    void foo() { std::cout << "A::foo()" << std::endl; }
};

class B {};

int main() {
    A a;
    B b;
    call_foo(a); // Calls A::foo()
    call_foo(b); // Outputs "foo not found!"
    return 0;
}
