#pragma once
#include <string>

using namespace std;

class Account
{
  // data (properties)
  private:   		
    double balance;
  // functions (methods)
  public:		
    Account();		// default constructor 
    Account(double);	// parameterized constructor 
    
    virtual void credit();
    virtual void debit();
    void setBalance(double);
    double getBalance();
};
