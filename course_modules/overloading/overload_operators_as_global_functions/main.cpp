#include <iostream>
#include <string>
#include "Mystring.hpp"

int main()
{

Mystring larry {"Larry"};
larry.display();

Mystring moe {"Moe"};
Mystring stooge = larry;
moe.display();

std::cout << (larry == moe) << std::endl;
std::cout << (larry == stooge) << std::endl;
#if 0
larry.display();
Mystring larry2 = -larry;
larry2.display();

Mystring stooges = larry + "Moe";
// Mystring stooges = "Larry" + moe; //COMPILER ERROR

Mystring two_stooges = moe + " " + "Larry";
two_stooges.display();

Mystring three_stooges = moe + " " + "Larry";
three_stooges.display();
#endif


  return 0;
}