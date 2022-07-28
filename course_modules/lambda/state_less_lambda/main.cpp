#include <string>
#include <vector>
#include <functional> // std::function
#include <algorithm>
#include <ostream>
#include <iostream>

class Person
{
    friend std::ostream& operator<<(std::ostream& os, const Person& rhs);

private:
    std::string name;
    int age;

public:
    Person(std::string name, int age)
        : name{ name }, age{ age }
    {

    }
    Person(const Person& p) : name{ p.name }, age{ p.age }
    {

    }

    // Getters:
    std::string get_name() const { return name; }
    int get_age() const { return age; }

    // Setters:
    void set_name(std::string name) { this->name = name; }
    void set_age(int age) { this->age = age; }

    ~Person() = default;



};

std::ostream& operator<<(std::ostream& os, const Person& objRhs)
{
    os<<"Person name: "<<objRhs.name<<" and age: "<<objRhs.age<<std::endl;
    return os;
}

void test1()
{
    // Very silly example to start with lambdas:

    []() {std::cout<<"Hi"<<std::endl;}();

    /* it will display 100 because lambda is created and
       called with argument value equal to 100 */
    [](int x) {std::cout<<x<<std::endl;}(100);

}

void test2()
{
    auto lExpr = []() {std::cout<<"Hi from Test2"<<std::endl;}; // () in the end not needed
    lExpr();
}

void test3()
{
    std::cout<<"TEST 3 "<<std::endl;
    Person personObj{ "Daniel", 25 };
    auto lambdaExpr = [](Person p) {std::cout<<p<<std::endl;};
    lambdaExpr(personObj);

    // passing by const reference!
    auto lambdaExpr2 = [](const Person& p) {std::cout<<p<<std::endl;};
    lambdaExpr2(personObj);
}

// std::function is a function object which expect int and return bool and name is func
// so func will return boolean after execution
// second argument to filter_vector is predicate lambda expression
void filter_vector(const std::vector<int>& vec, std::function<bool(int)>func)
{ // in C++20: void filter_vector(const std::vector<int> &vec, auto func)
    std::cout<<"[ ";
    for (int i : vec)
        if (func(i))
            std::cout<<i<<" ";
    std::cout<<"]"<<std::endl;
    
}

void test4()
{
    std::cout<<"TEST 4"<<std::endl;
    std::vector<int> numbers{ 10,20,30,40,50,60,70,80,90,100 };

    filter_vector(numbers, [ ](int x){return x>50;});

}

auto make_lambda()
{
    return []()
    {
        std::cout << "This is lambda and it was made using lambda function\n";
    };
}

void test5()
{
    std::cout << "TEST 5" << std::endl;
    auto lambdaExpr = make_lambda(); // create lambda 
    lambdaExpr(); // call the lambda function
}

void test6()
{
    std::cout << "TEST 6" << std::endl;
    std::vector<Person> persons
    {
        {"Daniel", 22},
        {"Mike", 23},
        {"Karol", 22}
    };

    std::for_each(begin(persons), end(persons), [](const Person &p){
        std::cout << p << std::endl;
    });

}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}