#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Square
{
    void operator()(int x)
    {
        std::cout<<x*x<<std::endl;
    }
};


template<typename T>
struct Displayer
{
    void operator()(const T& data)
    {
        std::cout<<data<<std::endl;
    }
};

int main()
{
    std::cout<<"***** Test with Functors *****"<<std::endl;
    Square sqrObj;
    sqrObj(4); // here the functor will be called - not function!

    Displayer<int> d1;
    Displayer<std::string> d2;

    d1(100); // again it looks like function but it is obj (functor)
    d2("Daniel"); // and the same in here

    std::cout<<"***** Test with STL and Functors *****"<<std::endl;
    std::vector<int> vec1{ 1,2,3,4,5 };
    std::vector<std::string> vec2{ "Daniel", "Eliza", "Karol" };

    std::for_each(vec1.begin(), vec1.end(), sqrObj);
    std::for_each(vec1.begin(), vec1.end(), d1);

    // Via obj clreated in for_each call
    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>());

    std::cout<<"***** Test with STL and Lambda *****"<<std::endl;
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout<<x*x<<std::endl;});
    std::for_each(vec1.begin(), vec1.end(), [](int x) {return x*10;});

    return 0;
}