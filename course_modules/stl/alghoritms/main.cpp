#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// example implementation of std::array using templates:

void count_if()
{
    std::vector<int> vec{ 1,2,3,4,5,1,2,1,100 };
    int num = std::count_if(vec.begin(), vec.end(), [](int x) {return x%2==0;});
    std::cout<<num<<" numbers found"<<std::endl;

    std::vector<std::string> wyznanie{ "Troche mnie ten gnojek denerwuje" };
    std::vector<std::string> glebia{ "Ale i tak go kocham :*" };

}

void replace()
{
    std::vector<int> vec{ 1,2,3,4,5,1,2,1,100 };
    std::replace(vec.begin(), vec.end(), 1, 100);

    for (auto const& var:vec)
        std::cout<<var<<" ";
    std::cout<<std::endl;

}

void all_test()
{
    std::vector<int> vec{ 1,2,3,4,5,1,2,1,100 };

    if (std::all_of(vec.begin(), vec.end(), [](int x) {return x>10;}))
        std::cout<<"All element are greater than 10"<<std::endl;
    else
        std::cout<<"Not all are greater than 10"<<std::endl;

}

void transformString()
{
    std::string str1 {"Hello Daniel from function"};
    std::cout << "Before: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << "Before: " << str1 << std::endl;
}

int main()
{
    count_if();
    replace();
    all_test();
    transformString();
    return 0;
}