#include "Account.hpp"
#include <string>

void Account::set_name(std::string n)
{
    account_name = n;
}

std::string Account::get_name()
{
    return account_name;
}

bool Account::deposit(double amount)
{
    //if verify amount
    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if(balance-amount >= 0)
    {
        balance -= amount;
        return true;
    }
    else 
    {
        return false;
    }
}
