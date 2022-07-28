#include <string>
#include <vector>
#include <iostream>

/* Template classes are typically contained in header files */
/* So we would have the template class in main.h (in that case) */

template<typename T>
class Item
{
private:
    std::string name;
    T value;

public:
    Item(std::string name, T value) : name{ name }, value{ value }
    {}
    std::string get_name() const
    {
        return name;
    }
    T get_value() const
    {
        return value;
    }

};

template<typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
};


int main()
{
    Item<int> item1{ "Frank", 100 };
    Item<std::string> item2{ "Frank", "Professor" };
    Item <Item <std::string>> item3{ "Frank", {"C++", "Daniel"} }; // our value is name and value
    std::cout<<item3.get_name()<<" "
        <<item3.get_value().get_name()<<" "
        <<item3.get_value().get_value()<<std::endl;

    /* Vector of classes */

    std::vector<Item<int>>vectorClass{};
    vectorClass.push_back(Item<int>{"Daniel", 24});
    vectorClass.push_back(Item<int>{"Giang", 244});
    vectorClass.push_back(Item<int>{"Anela", 55});
    
    for(const auto &classItem: vectorClass)
        std::cout << classItem.get_name()
                  << " and the age is " 
                  << classItem.get_value() 
                  << std::endl;

    /* Struct template */
    MyPair <std::string, int> p1 {"Frank", 100};
    MyPair <int, double> p2 {124, 22.2};

    std::cout<<p1.first<<","<<p1.second<<std::endl;
    std::cout<<p2.first<<"."<<p2.second<<std::endl;



    return 0;
}