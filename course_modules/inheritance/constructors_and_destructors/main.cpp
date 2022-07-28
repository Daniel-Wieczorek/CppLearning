#include <iostream>
#include <string>
#include <vector>


class Base{

    private:
        
        int value;

    public:
        
        Base() : value{0} {std::cout << "Base no-args constructor" << std::endl;}
        Base(int x) : value{x} {std::cout << "Base 1 arg constructor" << std::endl;}
        
        ~Base() {std::cout << "Base destructor" << std::endl;}
};


class Derived: public Base 
{
    private:

        int doubled_value;
    public:

        //Derived() : doubled_value{0} {std::cout << "Derived no-args constructor" << std::endl;}
        //Derived(int x) : doubled_value{x*2} {std::cout << "Derived 1 arg constructor" << std::endl;}
        
        Derived()
            : Base{0}, doubled_value{0}
            {
                std::cout << "Dervied based constructor called" << std::endl;
            }

        Derived(int x)
            : Base{0}, doubled_value{x*2}
            {
                std::cout << "Derived arg constructor called" << std::endl;
            }

        // Copy constructor:
        Derived(const Derived &object)
            :Base(object)

        ~Derived() {std::cout << "Derived destructor " << std::endl;}
};

int main()
{

  //  Base base_object;


    Derived dick;


    return 0;
}

// problem z tym ze pokazalem Twoje zdjecie znajomym a oni cie oceniali
