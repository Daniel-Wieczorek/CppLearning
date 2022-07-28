#include <iostream>
#include <string>
#include <vector>
#include "Mystring.hpp"

using namespace std;

int main()
{

    MyString data1 {"HELLO"};
    MyString data2;
    MyString data3;
    data1.display();
    data2.display();
    data3.display();

    data2 = -data1;
    data3 = data1+data2;

    data2.display();
    data1.display();
    data3.display();

    return 0;
}