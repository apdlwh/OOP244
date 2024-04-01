#include "SavingsAccount.h"

namespace seneca {

//constructor
SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) 
: BankAccount(name, openDate, depInfo, balance) // calling out base class constructor
{
     m_interest = interest;
     m_interestDate = interestDate;
}

void SavingsAccount::writeInterest(std::ostream& out) const
{
     out << std::fixed << std::setprecision(3) << m_interest << "%";
}

void SavingsAccount::applyInterest(Date& dt)
{
     double interestAmount = getBalance() * m_interest;
     double newBalance = getBalance() + interestAmount;

     std::cout << "   "; //thre spaces
     writeCurrency(std::cout, getBalance()); 
     std::cout << " + ";
     writeCurrency(std::cout, interestAmount); 
     std::cout << " (";
     writeInterest(std::cout); 
     std::cout << ") = ";
     writeCurrency(std::cout, newBalance); 
     std::cout << " | ";

     m_interestDate.write(std::cout); 
     std::cout << " => ";
     dt.write(std::cout); 
     std::cout << std::endl;

     setBalance(newBalance);  //updates account balance and inteest rate
     m_interestDate = dt;
}

std::ostream& SavingsAccount::write(std::ostream& out) const
{
     BankAccount::write(out); //calling function of the base class
     out << " | ";
     writeInterest(out);
     out << " | ";
     m_interestDate.write(out); 
     return out;
}

std::istream& SavingsAccount::read(std::istream& in)
{
     BankAccount::read(in); //calling function of the base class


     std::cout << "Interest Date ";
     m_interestDate.read(in);
     std::cout << "Interest Rate: ";
     in >> m_interest;
      return in;
}


std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct)
{
     return acct.write(out);
}

std::istream& operator>>(std::istream& in, SavingsAccount& acct)
{
     return acct.read(in);
}


}
