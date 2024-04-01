#ifndef IACCOUNT_H
#define IACCOUNT_H
#include <iostream>

namespace seneca {

class iAccount
{
public:
     virtual bool credit(double) = 0;
     virtual bool debit(double) = 0;
     virtual void monthEnd() = 0;
     virtual void display(std::ostream&) const = 0;
     virtual ~iAccount() = default;


};

iAccount* CreateAccount(const char*, double);
}
#endif
