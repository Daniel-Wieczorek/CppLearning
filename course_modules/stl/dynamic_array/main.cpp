#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void display(const std::vector<int>& vec)
{
    std::cout<<"[";
    for (auto const& val:vec)
        std::cout<<val<<" ";

    std::cout<<"]"<<std::endl;

}

void iterator_test_1()
{
    std::vector<int> numbers{ 1,2,3,4,5 };
    auto it = numbers.begin(); // it will be the object in reality not pointer but we can use it as pointer (*it will dereference!)

    int i{ 0 };
    while (i<=8)
    {
        std::cout<<*it<<std::endl;
        it++;
        i++;
    }
}

void interator_test_2()
{
    std::vector<int> numbers{ 1,2,3,4,5 };
    auto it = numbers.cbegin(); // it will be the object in reality not pointer but we can use it as pointer (*it will dereference!)

    // *it = 0 ====> it will create the compiler error since it is defined as constant iterator

}

void interator_test_3()
{
    std::list<std::string> names{ "Daniel", "Eliza" };
    auto it2 = names.crbegin();
    std::cout<<*it2<<std::endl;
    it2++; // so iterator will point now to Daniel
    std::cout<<*it2<<std::endl;

    std::map<std::string, std::string> myAnimal
    {
        {"Daniel", "tak Dog"},
        {"Eliza", "nie_fredka"}
    };

    for (auto it3 = myAnimal.begin(); it3 != myAnimal.end(); it3++)
    {
        std::cout<<it3->first<<" "<<it3->second<<std::endl;
    }

}

int main()
{
    iterator_test_1();
    interator_test_2();
    interator_test_3();

    return 0;
}