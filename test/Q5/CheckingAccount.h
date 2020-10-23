// CheckingAccount.h – Specification
#pragma once		   
#include <iostream>     	   
#include <string>      	  
using namespace std;
#include "Account.h" 	  

class CheckingAccount : public Account // inherit from Base class, Account
{
  // data (properties)
  private:
    double fee;

  // functions (methods)
  public:
    CheckingAccount();				// default constructor
    CheckingAccount(double, double);	// parameterized constructor
    virtual void credit();
    virtual void debit();
};
