
#include "Account.hpp"
#include <iostream>
#include <string>

/* INITIALIZATION OF THE STATIC VARIABLE*/
Account::Account()
    : Account(0.0)
{
}

Account::Account(double balance)
    :balance(balance)
    {

    }

Account::~Account()
{
}

void Account::deposit(double amount)
{
    balance += amount;
    std::cout << "Account deposit called with " << amount << std::endl;
}

void Account::withdraw(double amount)
{
    if(balance - amount >= 0)
        balance -= amount;
    else
        std::cout << "Account withdraw called with " << amount << std::endl;
}

std::ostream &operator << (std::ostream &os, const Account &account)
{
    os << "Account balance: " << account.balance;
    return os;
}
