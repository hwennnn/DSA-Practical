// SavingsAccount.h – Specification
#pragma once		   
#include <iostream>     	   
#include <string>      	  
using namespace std;
#include "Account.h" 	  
class SavingsAccount : public Account // inherit from Base class, Account
{
  // data (properties)
  private:
    double interestRate;

  // functions (methods)
  public:
    SavingsAccount();				// default constructor
    SavingsAccount(double, double);	// parameterized constructor
    double calculateInterest();
};
