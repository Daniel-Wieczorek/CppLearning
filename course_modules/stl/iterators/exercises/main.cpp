#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// display any vector of integers using range based for loop
void display(const std::vector<int> &vec)
{
    std::cout << "[";
    for (auto const &iterator : vec)
        std::cout << iterator << " ";
    std::cout << "]" << std::endl;  
}

void test1()
{
    std::vector<int> nums1 {1,2,3,4,5};
    auto iterator = nums1.begin(); // create iterator for the first element
    // iterator looks like pointer but behind it is object
    std::cout << *iterator << std::endl;
    std::cout << *(iterator+1) << std::endl;
    std::cout << *(iterator-1) << std::endl;
    std::cout << *(iterator-2) << std::endl;
}

void test2()
{
    std::vector<int> nums1 {1,2,3,4,5};
    std::vector<int>::iterator it = nums1.begin();
    // or just 
    // auto it = nums1.begin();
    
    while(it!=nums1.end())
    {
        std::cout << *it << std::endl;
        it++;
    }

    // 0's all elements
    for(it = nums1.begin(); it != nums1.end(); it++)
    {
        *it = 0;
        std::cout<< *it << std::endl;
    }
}

void test3()
{
    std::vector<int> nums1 {1,2,3,4,5};
    std::vector<int>::const_iterator it = nums1.begin();
    // or just:
    // auto it = nums1.cbegin();
    
    while(it!=nums1.end())
    {
        std::cout << *it << std::endl;
        it++;
    }

    // 0's all elements - now not possible because of const interator
    for(it = nums1.begin(); it != nums1.end(); it++)
    {
        // Here we will have an error *it = 0;
        std::cout<< *it << std::endl;
    }
}

void test4()
{
    std::vector<int> nums1 {1,2,3,4,5};
    auto it = nums1.rbegin();
    
    while(it!=nums1.rbegin())
    {
        std::cout << *it << std::endl;
        it++;
    }

    std::list<std::string> name {"DWI", "DGV", "RTH"};
    auto it2 = name.crbegin(); // constans reverse iterator 
    std::cout << *it2 << std::endl;
    it2++;
    std::cout << *it2 << std::endl;

    std::map<std::string, std::string> favourites
    {
        {"Daniel","C++"},
        {"Anela","Python"},
        {"Giang","Java"}
    };

    auto it3 = favourites.begin();
    while(it3 != favourites.end())
    {
        std::cout << "Cpp ditc: " << it3->first  << ":"  << it3->second 
                  << std::endl;
        it3++;
    }

}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();

    return 0;
}