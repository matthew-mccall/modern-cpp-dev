#include <iostream>
#include <memory> // Needed for smart pointers

class Foo {
public:
    Foo() { std::cout << "Foo constructor\n"; }
    Foo(const Foo&) { std::cout << "Foo copy constructor\n"; }
    Foo(Foo&&) { std::cout << "Foo move constructor\n"; }
    Foo& operator=(const Foo&)
    {
        std::cout << "Foo copy assignment operator\n";
        return *this;
    }
    Foo& operator=(Foo&&)
    {
        std::cout << "Foo move assignment operator\n";
        return *this;
    }
    virtual void bar() { std::cout << "Foo::bar()\n"; }
    virtual void modify() = 0; // Pure virtual function to make Foo an abstract class
    virtual bool isModified() const = 0; // Pure virtual function to check if the object is modified
    virtual ~Foo() { std::cout << "Foo destructor\n"; }
};

class Derived final : public Foo {
public:
    Derived() { std::cout << "Derived constructor\n"; }
    Derived(const Derived&) { std::cout << "Derived copy constructor\n"; }
    Derived(Derived&&) { std::cout << "Derived move constructor\n"; }
    Derived& operator=(const Derived&)
    {
        std::cout << "Derived copy assignment operator\n";
        return *this;
    }
    Derived& operator=(Derived&&)
    {
        std::cout << "Derived move assignment operator\n";
        return *this;
    }
    void bar() override { std::cout << "Derived::bar()\n"; }
    void modify() override { modified = true; }
    bool isModified() const final { return modified; }
    ~Derived() override { std::cout << "Derived destructor\n"; }

private:
    bool modified = false; // A flag to indicate whether the object has been modified
};

void fooFunctionNaiive(std::unique_ptr<Foo> ptr)
{
    ptr->bar();
}

void fooFunctionClaimingOwnershipExplicit(std::unique_ptr<Foo>&& ptr)
{
    ptr->bar();
    // ptr will be destroyed when it goes out of scope, which is fine since we claimed ownership explicitly.
}

void fooFunctionBorrowing(const std::unique_ptr<Foo>& ptr)
{
    ptr->bar();
    // We are borrowing the unique_ptr, so we do not take ownership and do not need to worry about its lifetime.
    // ptr->modify(); // This would be a compile-time error because ptr is a const reference, so we cannot modify the object it points to.
}

void fooFunctionBorrowingNonConst(std::unique_ptr<Foo>& ptr)
{
    ptr->bar();
    // We are borrowing the unique_ptr, but since it's non-const, we could potentially modify it (e.g., reset it), which is something to be cautious about.

    ptr->modify(); // This is allowed because ptr is a non-const reference, but it can lead to side effects that might not be intended by the caller.
}

int main()
{
    std::unique_ptr<Foo> derivedPtr = std::make_unique<Derived>();
    derivedPtr->bar();

    // fooFunctionNaiive(derivedPtr); // This will cause a compile-time error because we're trying to pass a unique_ptr by value, which requires a copy.

    fooFunctionClaimingOwnershipExplicit(std::move(derivedPtr));
    // After std::move, derivedPtr is now empty (nullptr), and ownership has been transferred to fooFunctionClaimingOwnershipExplicit.
    // Unfortunately, C++ does not stop us from using derivedPtr after moving from it, but we should not do so as it is now in a valid but unspecified state.

    fooFunctionBorrowing(derivedPtr); // This is safe because we're borrowing the unique_ptr, not taking ownership.
    // Additionally, derivedPtr is passed by const& so it cannot be modified within fooFunctionBorrowing, ensuring that we do not accidentally change its state.
    std::cout << "Is derivedPtr modified? " << std::boolalpha << derivedPtr->isModified() << std::endl; // This will show whether the object was modified or not.

    fooFunctionBorrowingNonConst(derivedPtr); // This is safe because we're borrowing the unique_ptr, not taking ownership.
    // However, since derivedPtr is passed by non-const reference, it can be modified within fooFunctionBorrowingNonConst.
    std::cout << "Is derivedPtr modified after non-const borrow? " << std::boolalpha << derivedPtr->isModified() << std::endl; // This will show whether the object was modified or not.

    return 0;
}