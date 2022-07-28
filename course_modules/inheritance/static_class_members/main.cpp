#include "Account.hpp"
#include "SavingsAccount.hpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout << "\nPARENT CLASS\n";
    Account account1{};
    account1.deposit(20000.0);
    account1.withdraw(500);

    std::cout << std::endl;

    Account *p_account{nullptr};
    p_account = new Account();

    p_account->deposit(1000);
    p_account->withdraw(200);
    delete p_account;

    std::cout << "\nCHILD CLASS\n";

    Savings_Account account_savings{};
    account_savings.deposit(20000.0);
    account_savings.withdraw(500);

    std::cout << std::endl;

    Savings_Account *p_savings_account{nullptr};
    p_savings_account = new Savings_Account();

    p_savings_account->deposit(1000);
    p_savings_account->withdraw(200);
    delete p_savings_account;

    return 0;
}