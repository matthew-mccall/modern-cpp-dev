#include <iostream>
#include <type_traits>

// Helper struct to detect if T has a member function foo
template<typename T>
class HasFoo {
private:
    template<typename U>
    static auto test(int) -> decltype(std::declval<U>().foo(), std::true_type{});

    template<typename>
    static std::false_type test(...);

public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

// Overload for types with foo
template<typename T>
typename std::enable_if<HasFoo<T>::value>::type call_foo(T& t) {
    t.foo();
}

// Overload for types without foo
template<typename T>
typename std::enable_if<!HasFoo<T>::value>::type call_foo(T&) {
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
