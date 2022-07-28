#ifndef C793191C_C740_4DB2_BE30_F8B1259ECAA9aa
#define C793191C_C740_4DB2_BE30_F8B1259ECAA9aa
#include "Account.hpp"
#include <string>

class Savings_Account : public Account
{
public:
    double int_rate;
    void deposit(double amount);
    void withdraw(double amount);
    Savings_Account();
    ~Savings_Account();
};

#endif /* C793191C_C740_4DB2_BE30_F8B1259ECAA9 */
