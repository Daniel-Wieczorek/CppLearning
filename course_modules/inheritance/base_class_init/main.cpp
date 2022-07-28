#include <iostream>
#include <string>
#include <vector>


class Base{

    private:
        
        int value;

    public:
        
        Base() : value{0} 
        {
            std::cout << "Base no-args constructor" << std::endl;
        }

        Base(int x) : value{x} 
        {
            std::cout << "Base 1 arg constructor" << std::endl;
        }
        
        ~Base() 
        {
            std::cout << "Base destructor" << std::endl;
        }
};


class Derived: public Base 
{
    private:

        int doubled_value;

    public:

        Derived() :Base {}, doubled_value{0} 
        {
            std::cout << "Derived no-args constructor" << std::endl;
        }

        Derived(int x) :Base{x}, doubled_value{x*2} 
        {
            std::cout << "Derived 1 arg constructor" << std::endl;
        }
        
        ~Derived() 
        {
            std::cout << "Derived destructor " << std::endl;
        }
};

int main()
{

  //  Base base_object;


    Derived dick;


    return 0;
}