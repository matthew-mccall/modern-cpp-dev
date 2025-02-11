module;

#include <print>

export module mylib;

namespace mylib {

export auto foo() -> void {
    std::println("foo");
}

}