#include <iostream>
#include <string>

#include "SavingsAccount.hpp"

/* INITIALIZATION OF THE STATIC VARIABLE*/
Savings_Account::Savings_Account()
    : Savings_Account(0.0, 0.0)
{
}

Savings_Account::Savings_Account(double balance, double int_rate)
    :Account(balance), int_rate{0.0}
{
    std::cout << "Savings_Account constructor called " << std::endl;
}

Savings_Account::~Savings_Account()
{
}

void Savings_Account::deposit(double amount)
{
    amount = amount + (amount * int_rate/100);
    Account::deposit(amount);
    std::cout << "Savings_Account deposit called with " << amount << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account)
{
    os << "Savings account balance: " << account.balance << "Interest rate: " << account.int_rate;
    return os;
}