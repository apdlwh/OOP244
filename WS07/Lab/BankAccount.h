#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>
#include "DepositUtility.h"

namespace seneca {

class BankAccount{
private:
     char m_name[50];
     Date m_openDate;
     DepositInfo m_depInfo;
     double m_balance;

protected:
     double getBalance() const;
     void setBalance(double balance);
     void writeCurrency(std::ostream& out, double amount) const;

public:
     BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance); //constructor
     std::ostream& write(std::ostream& out) const;
     std::istream& read(std::istream& in);

};

//helper function
std::istream& operator>>(std::istream& in, BankAccount& acct);
std::ostream& operator<<(std::ostream& out, const BankAccount& acct);


}

#endif
