#include <iostream>
#include <string>
#include <vector>
#include "Mystring.hpp"

using namespace std;

int main()
{

    MyString data1 {"Hello"};
    MyString data2;

    data2.display();

    data2 = -data1;

    data2.display();

    return 0;
}