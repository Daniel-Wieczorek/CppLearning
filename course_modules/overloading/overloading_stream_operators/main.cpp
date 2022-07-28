#include <iostream>
#include <string>
#include "Mystring.hpp"
using namespace std;

int main()
{

  Mystring larry{"Larry"};
  Mystring moe{"Moe"};
  Mystring corly;

  cout << "Enter third name: ";
  cin >> corly;

  cout << "Three names are: " << larry << ", " << moe << ", " << corly << endl;

  cout << "\n Enter three names spearated by space: ";
  cin >> larry >> moe >> corly;

  cout << "Three names are: " << larry << ", " << moe << ", " << corly << endl;

  return 0;
}