#include <iostream>
#include <string>
#include <vector>
#include "Account.hpp"

int main()
{
    Account frank_account;

    frank_account.set_name("Frank account");
    frank_account.set_balance(1000.0);

    if(frank_account.deposit(200.0))
        std::cout << "Deposit OK" << std::endl;
    else
        std::cout << "Deposit not allowed" << std::endl;

    if(frank_account.withdraw(500.0))
        std::cout << "Withdraw OK" << std::endl;
    else
        std::cout << "Not sufficient funds" << std::endl;
    
    if(frank_account.withdraw(1500.0))
        std::cout << "Withdraw OK" << std::endl;
    else
        std::cout << "Not sufficient found" << std::endl;

    return 0;
}