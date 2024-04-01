#include "ChequingAccount.h"

namespace seneca {

ChequingAccount::ChequingAccount(double balance, double transFee, double monthFee)
: Account(balance)  
{
     if (transFee > 0) {
     transactionFee = transFee;
     } else {
     transactionFee = 0.0;
     }

     if (monthFee > 0) {
     monthlyFee = monthFee;
     } else {
     monthlyFee = 0.0;
    }

}

bool ChequingAccount::credit(double amount) {
     bool success = Account::credit(amount);
     if (success) {
     Account::debit(transactionFee);
    }
     return success;
}

bool ChequingAccount::debit(double amount) {
     bool success = Account::debit(amount + transactionFee);
     return success;
}

void ChequingAccount::monthEnd() {
     Account::debit(monthlyFee);
}

void ChequingAccount::display(std::ostream& out) const {
     out << std::fixed << std::setprecision(2);
     out << "Account type: Chequing" << std::endl;
     out << "Balance: $" << balance() << std::endl;
     out << "Per Transaction Fee: " << transactionFee << std::endl;
     out << "Monthly Fee: " << monthlyFee << std::endl;
}


}
