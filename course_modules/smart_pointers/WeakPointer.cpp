
#include <iostream>
#include <memory>
#include <vector>

class B;

class A
{
    std::shared_ptr<B> b_ptr;

public:
    void set_B(std::shared_ptr<B> &b) { b_ptr = b; }

    A() { std::cout << "A CONSTRUCTOR\n"; }
    ~A() { std::cout << "A DESTRUCTOR\n"; }
};

class B
{
    // std::shared_ptr<A> a_ptr; // -> this will cause memory leak. It must be weak_ptr
    std::weak_ptr<A> a_ptr;

public:
    void set_A(std::shared_ptr<A> &a) { a_ptr = a; }

    B() { std::cout << "B CONSTRUCTOR\n"; }
    ~B() { std::cout << "B DESTRUCTOR\n"; }
};

int main()
{
    //======================== WEAK POINTER =============================================

    std::cout << "\n==== WEAK POINTER ==== " << std::endl;

    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->set_B(b);
    b->set_A(a);

    return 0;
}
