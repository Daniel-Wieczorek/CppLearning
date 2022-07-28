#include <iostream>
#include <string>
#include <vector>

template<typename T>
class Item
{
    private:
    std::string name;
    T value;

    public:
    Item(std::string name, T value)
        :name{name}, value{value}
    {

    }
    std::string get_name() const {return name;}
    T get_value() const {return value;}
};

template<typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
};



int main()
{
    Item<int> item1{"Daniel", 25};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

    Item<std::string> item2{"DANIEL", "MAREK"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

    std::vector<Item<double>> myVector {};
    myVector.push_back(Item<double>{"Daniel", 23.00});
    myVector.push_back(Item<double>{"Marek", 30.0});

    return 0;
}