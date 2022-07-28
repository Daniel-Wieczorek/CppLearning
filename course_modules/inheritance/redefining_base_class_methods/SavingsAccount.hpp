#ifndef C793191C_C740_4DB2_BE30_F8B1259ECAA9aa
#define C793191C_C740_4DB2_BE30_F8B1259ECAA9aa
#include "Account.hpp"
#include <string>

class Savings_Account : public Account
{
    friend std::ostream &operator << (std::ostream &os, const Savings_Account &account);

protected:

    double int_rate;

public:

    void deposit(double amount);
    // Withdraw is inherited

    // Constructors and Desctructors
    Savings_Account();
    Savings_Account(double balance, double int_rate);
    ~Savings_Account();
};

#endif /* C793191C_C740_4DB2_BE30_F8B1259ECAA9 */
