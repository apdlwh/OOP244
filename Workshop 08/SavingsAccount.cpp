#include "SavingsAccount.h"

namespace seneca {

SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance) 
{  
     if (rate > 0) {
        interestRate = rate;
    } else {
        interestRate = 0.0;
    }
}


void SavingsAccount::monthEnd() 
{
     double interest = currentBalance * interestRate;
     credit(interest);
}

void SavingsAccount::display(std::ostream& out) const 
{
     out << std::fixed << std::setprecision(2);
     out << "Account type: Savings" << std::endl;
     out << "Balance: $" << balance() << std::endl;
     out << "Interest Rate (%): " << interestRate * 100 << std::endl;

}

}
