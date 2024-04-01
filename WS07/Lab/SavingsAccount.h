#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include <iomanip>
#include "BankAccount.h"

namespace seneca{

class SavingsAccount : public BankAccount {
private:
     double m_interest;
     Date m_interestDate;
     void writeInterest(std::ostream& out) const; 

public:
     SavingsAccount(const char* name, Date openData, DepositInfo depInfo, double balance, double interest, Date interestDate); //constructor
     void applyInterest(Date& dt);
     std::ostream& write(std::ostream& out) const;
     std::istream& read(std::istream& in);
};

//helpr ufction 
     std::istream& operator>>(std::istream& in, SavingsAccount& acct);
     std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
  


}
#endif
