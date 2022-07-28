
#include "Account.hpp"
#include <iostream>
#include <string>

/* INITIALIZATION OF THE STATIC VARIABLE*/
Account::Account()
    : balance{0},
      name{"NONE"}
{
}

Account::~Account()
{
}

void Account::deposit(double amount)
{
    std::cout << "Account deposit called with " << amount << std::endl;
}

void Account::withdraw(double amount)
{
    std::cout << "Account withdraw called with " << amount << std::endl;
}
