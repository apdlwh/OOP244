#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H
#include "Account.h"
#include <iomanip>

namespace seneca{

class ChequingAccount : public Account {
     double transactionFee;
     double monthlyFee;
public:
     ChequingAccount(double, double, double);
     bool credit(double) override;
     bool debit(double) override;
     void monthEnd() override;
     void display(std::ostream&) const override;
};
}
#endif
