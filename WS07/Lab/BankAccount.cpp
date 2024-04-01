#include "BankAccount.h"

namespace seneca {

BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
{
  m_openDate = openDate;
  m_depInfo = depInfo;
  m_balance = balance;
  strncpy(m_name, name, 49); //m_name is a char arr.
  m_name[49] = '\0';
}

double BankAccount::getBalance() const
{
     return m_balance;   
}

void BankAccount::setBalance(double balance)
{
     m_balance = balance;
}

void BankAccount::writeCurrency(std::ostream& out, double amount) const
{
     out << std::fixed << std::setprecision(2) << "$" << amount;
}

std::ostream& BankAccount::write(std::ostream& out) const
{
     out << ">> " << m_name << " | ";
     writeCurrency(out, m_balance);
     out << " | ";
     m_openDate.write(out);
     out << " | ";
     m_depInfo.write(out);
     return out;
}

std::istream& BankAccount::read(std::istream& in) {
    std::cout << "Name: ";
    in.getline(m_name, 50);

    std::cout << "Opening Balance: ";
    in >> m_balance;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Date Opened ";
    m_openDate.read(in);
    m_depInfo.read(in); 
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return in;
}


std::istream& operator>>(std::istream& in, BankAccount& acct)
{
     return acct.read(in);
}

std::ostream& operator<<(std::ostream& out, const BankAccount& acct) 
{
     return acct.write(out);
}


}
