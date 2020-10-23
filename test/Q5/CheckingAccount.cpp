// CheckingAccount.cpp - Implementation
#include "CheckingAccount.h" 

CheckingAccount::CheckingAccount() { }
CheckingAccount::CheckingAccount(double b, double fm) : Account(b)
{
   fee = fm;
}

void CheckingAccount::credit(){ Account::setBalance(Account::getBalance() - fee);}
void CheckingAccount::debit() {
    double b = Account::getBalance();
}