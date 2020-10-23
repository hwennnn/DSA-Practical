// Account.cpp - Implementation
#include "Account.h" 	// Specification of Account class
// #include <string>

// using namespace std;

Account::Account() { }
Account::Account(double b){ balance = (b >= 0) ? balance : 0;}

void Account::setBalance(double b){balance = b;}
double Account::getBalance(){ return balance;}

