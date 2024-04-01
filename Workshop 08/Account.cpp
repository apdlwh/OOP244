#include "Account.h"

namespace seneca{

Account::Account(double balance)
{
     if (balance > 0) {
     currentBalance = balance;
     } else {
     currentBalance = 0.0;
    }
}
     
bool Account::credit(double amount) 
{
     if (amount > 0) {
        currentBalance += amount;
        return true;
     }
     return false;
}

bool Account::debit(double amount) 
{
     if (amount > 0 && amount <= currentBalance) {
        currentBalance -= amount;
        return true;
     }
     return false;
}

double Account::balance() const 
{
     return currentBalance;
}
}
