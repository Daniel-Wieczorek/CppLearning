#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>

class Person
{
private:
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age) : name{ name }, age{ age }
    {}

    bool operator<(const Person& rhs) const
    {
        return (this->age<rhs.age);
    }

    bool operator==(const Person& rhs) const
    {
        return (this->name==rhs.name&&this->age==rhs.age);
    }
};

void count_if_test()
{
    std::vector<int> vec{ 1,2,5,3,7,4,2,5,8,4,13,5,100 };
    int num = std::count_if(vec.begin(), vec.end(), [](int x) {return x%2==0;});
    std::cout<<num<<" even numbers found"<<std::endl;

    int num2 = std::count_if(vec.begin(), vec.end(), [](int x) {return x%2!=0;});
    std::cout<<num2<<" odd numbers found"<<std::endl;
}

void transform_string()
{
    /* Transformation to UPPERCASE string! */
    std::string str1{ "This is a test" };
    std::cout<<"Before transfrom: "<<str1<<std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout<<"After transfrom: "<<str1<<std::endl;
}

int main()
{
    std::vector<int> vec{ 1,2,3,1,2,1,1 };
    auto location = std::find(vec.begin(), vec.end(), 3);

    if (location!=vec.end())
        std::cout<<*location<<std::endl; // locator is pointing to 3rd element

    std::vector<int> vec2{ 1,2,3,4 };
    std::for_each(vec2.begin(), vec2.end(), [](int x)
        {
            std::cout<<x*x<<" "; // lambda expression here
        });

    /* Count alg test:*/
    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout<<std::endl<<num<<" occuerences found "<<std::endl;

    /* test of function find! */
    std::list<Person> players
    {
        {"Larry", 18},
        {"Frank", 22},
        {"Daniel", 11}
    };
    std::cout<<"\n";

    // we pass without object name!
    auto locator1 = std::find(players.begin(), players.end(), Person{ "Frank", 22 });
    if (locator1!=players.end())
        std::cout<<"Found Frank"<<std::endl;
    else
        std::cout<<"Frank not found"<<std::endl;

    count_if_test();
    transform_string();
    return 0;
}