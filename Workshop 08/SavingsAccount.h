#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"
#include <iomanip>

namespace seneca{

class SavingsAccount : public Account
{
     double interestRate;
public:
     SavingsAccount(double, double);
     void monthEnd() override;
     void display(std::ostream&) const override;
};

}
#endif
