#pragma once
#include <string>

using namespace std;

class Employee
{
  // data (properties)
  private:   		
    string firstName;
    string lastName;
    int monthlySalary;
  // functions (methods)
  public:		
    Employee();		// default constructor 
    Employee(string, string, int);	// parameterized constructor 
    void setFirstName(string); 
    void setLastName(string);
    void setMonthlySalary(int); 

    string getFirstName();
    string getLastName();
    int getMonthlySalary();
    int getYearlySalary();
};
