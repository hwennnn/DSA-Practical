// SavingsAccount.cpp - Implementation
#include "SavingsAccount.h" 

SavingsAccount::SavingsAccount() { }
SavingsAccount::SavingsAccount(double b, double ir) : Account(b)
{
   interestRate = ir;
}

double SavingsAccount::calculateInterest(){ return Account::getBalance() * interestRate;}
