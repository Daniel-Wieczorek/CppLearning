#include "SavingsAccount.hpp"
#include <iostream>
#include <string>

/* INITIALIZATION OF THE STATIC VARIABLE*/
Savings_Account::Savings_Account()
    : int_rate{0.0}
{
}

Savings_Account::~Savings_Account()
{
}

void Savings_Account::deposit(double amount)
{
    std::cout << "Savings_Account deposit called with " << amount << std::endl;
}

void Savings_Account::withdraw(double amount)
{
    std::cout << "Savings_Account withdraw called with " << amount << std::endl;
}