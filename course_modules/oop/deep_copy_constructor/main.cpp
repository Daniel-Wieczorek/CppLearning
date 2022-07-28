#include <iostream>
#include <string>
#include <vector>

class Shallow {

private:
    int *data;

public:
    void set_data_value(int d) {*data = d;}
    int get_data_value() {return *data; }

    // Constructor
    Shallow(int d);
    // Deep Copy constr
    Shallow(const Shallow &source);

    // Destructor
    ~Shallow();
};

Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
    std::cout << "Constructor called" << std::endl;
}

Shallow::Shallow(const Shallow &source)
    : Shallow(*source.data) // so in here we delegate work for single constructor on line 23
{
    std::cout << "Copy constructor - shallow copy" << std::endl;
    std::cout << "Address of the data: " << source.data << "and value: " << *source.data << std::endl;
}

Shallow::~Shallow()
{
    delete data;
    std::cout << "Destructor called, data free" << std::endl;
}

void display_shallow(Shallow display_shallow_class)
{
    std::cout << display_shallow_class.get_data_value() << std::endl;
}

int main()
{
    Shallow obj1 {100};
    display_shallow(obj1);

    Shallow obj2 {obj1};
    obj2.set_data_value(10000);


    return 0;
}