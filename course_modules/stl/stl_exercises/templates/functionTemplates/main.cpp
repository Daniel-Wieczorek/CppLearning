#include <string>
#include <vector>
#include <iostream>

template <typename T>
T min(T a, T b)
{
    return (a<b) ? a : b;
}

template <typename T1, typename T2>
void print_data(T1 a, T2 b)
{
    std::cout<<a<<" "<<b<<std::endl;
}

struct Person
{
    std::string name;
    int age;
    bool operator<(const Person& rhs) const // we use operator overloading for <
    {
        return this->age<rhs.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os<<p.name;
    return os;
}

template <typename T>
void my_swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x{ 100 };
    int y{ 200 };
    std::cout<<x<<","<<y<<std::endl;
    my_swap(x, y);
    std::cout<<x<<","<<y<<std::endl;

    std::cout<<min<int>(2, 3)<<std::endl; // 2
    std::cout<<min(2, 3)<<std::endl;      // 2
    std::cout<<min('A', 'B')<<std::endl; // A

    Person p1{ "Daniel", 26 };
    Person p2{ "Eliza", 24 };
    Person p3 = min(p1, p2);
    std::cout<<p3.name<<" is younger"<<std::endl;

    print_data(10, 20);
    print_data('A', 12.4);

    print_data(p1, p2);

    return 0;
}