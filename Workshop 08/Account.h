#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "iAccount.h"

namespace seneca{

class Account : public iAccount {
protected:
     double currentBalance;
public:
     Account(double balance = 0.0);
     bool credit(double amount) override;
     bool debit(double amount) override;
     double balance() const;


};
}

#endif
