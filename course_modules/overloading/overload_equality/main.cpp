#include <iostream>
#include <string>
#include "Mystring.hpp"

int main()
{

Mystring a {"Hello"};
Mystring b {"CCC"};
b = a;

b = "This is a test";

#if 0
  Mystring empty;          // no -args constructor
  Mystring larry("Larry"); // overloaded constructor
  Mystring stooge{larry};  // copy constructor

  empty.display();
  larry.display();
  stooge.display();
#endif
  return 0;
}