#include <iostream>
#include <string>

template <typename T>
T min(T var1, T var2)
{

    return(var1<var2) ? var1 : var2;
}

template<typename T1, typename T2>
void funct(T1 var1, T2 var2)
{
    std::cout<< var1 << " and "  << var2 <<std::endl;
}

struct Person
{
    std::string name;
    int age;
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }

};

std::ostream &operator<<(std::ostream &os, const Person &obj)
{
    os << obj.name;
    return os;
}

int main()
{

    // Tests for min function:
    std::cout<<min<int>(2, 3)<<std::endl;
    std::cout<<min(2, 3)<<std::endl; // here type will be assigned by the compiler
    std::cout<<min('A', 'B')<<std::endl;

    // And the same will apply for funct:

    Person Daniel{"Dany", 26};
    Person Eliza{"Eliza", 25};

    Person p = min(Daniel, Eliza);
    std::cout << "Younger is: " << p.name << std::endl;

    funct(Daniel,Eliza);

    return 0;
}