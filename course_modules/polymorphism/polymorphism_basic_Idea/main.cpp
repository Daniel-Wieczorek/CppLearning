#include <iostream>
#include "main.hpp"
#include <string>


/* ---------------------- STATIC BINDING ---------------------- */
class Base
{
    public:
    void say_hello () const
    {
        std::cout << "Hello from the base class" << std::endl;
    }

};

class Derived: public Base
{
    public:
    void say_hello() const
    {
        std::cout << "Hello from Derived class" << std::endl;
    }

};

void say_greetings(const Base &object)
{
    std::cout << " *** Greetings and ";
    object.say_hello();
}

/* ---------------------- --------------- ---------------------- */
/* ---------------------- DYNAMIC BINDING ---------------------- */
class BasePM
{
    public:
    virtual void say_hello_pm () const // it has to be typed here explicitly to make it virtual
    {
        std::cout << "PM: Hello from the base class" << std::endl;
    }

    virtual ~BasePM() {} // if function has virtual function then we have to provide virtual destructors also

};

class DerivedPM: public BasePM
{
    public:
    virtual void say_hello_pm() const override // if function on the base class is virtual then also this fucntion will be. Nevertheless it is good practice to put in here virtual
    {
        std::cout << "PM: Hello from Derived class" << std::endl;
    }

    virtual ~DerivedPM() {} // constructor must be virtual! 

};

void say_greetings_pm(const BasePM &object)
{
    std::cout << "PM: *** Greetings and ";
    object.say_hello_pm();
}

/* ---------------------- --------------- ---------------------- */

int main()
{
    /* ---------------------- WITHOUT POLYMORPHISM ---------------------- */
    std::cout << "********* Without polymorphism *********" << std::endl;
    Base b;
    b.say_hello();

    Derived d;
    d.say_hello();

    // Here we have an example of static binding. To overcome it
    // polymorphism can be used!
    say_greetings(b); // it is ok, it should be from b
    say_greetings(d); // but here we want data from Derived but it will be called from b

    Base *ptr_b = new Derived(); // so ptr can hold an address of any 'Base' object and 'Derived' is based object because it is derived from the 'Base' class
    ptr_b->say_hello(); // it will be always static binded for 'Base' class

    Derived *ptr_d = new Derived(); // so ptr can hold an address of any 'Base' object and 'Derived' is based object because it is derived from the 'Base' class
    ptr_d->say_hello(); // it will be always static binded for 'Derived' class


    // Everytime without using 'virtual' (polymorphism) we will have the same issue!

    /* ---------------------- WITHOUT POLYMORPHISM ---------------------- */
    std::cout << "********* With polymorphism *********" << std::endl;
    BasePM bPM;
    bPM.say_hello_pm();

    DerivedPM dPM;
    dPM.say_hello_pm();
    
    BasePM *ptr_bPM_1 = new BasePM;
    BasePM *ptr_bPM_2 = new DerivedPM;

    ptr_bPM_1->say_hello_pm();
    ptr_bPM_2->say_hello_pm();

    say_greetings_pm(bPM);
    say_greetings_pm(dPM);

    // Delete all the pointers or memory leak!
    delete ptr_b;
    delete ptr_d;    
    delete ptr_bPM_1;
    delete ptr_bPM_2;

    return 0;
}