// Employee.cpp - Implementation
#include "Employee.h" 	// Specification of Employee class
#include <string>

using namespace std;

Employee::Employee() { }
Employee::Employee(string fn, string ln, int ms){ 
    firstName = fn;
    lastName = ln;
    setMonthlySalary(ms); 
}

string Employee::getFirstName(){ return firstName;}
string Employee::getLastName(){ return lastName;}
int Employee::getMonthlySalary() { return monthlySalary;}
int Employee::getYearlySalary(){ return monthlySalary*12;}

void Employee::setFirstName(string fn){ firstName = fn;}
void Employee::setLastName(string ln){ lastName = ln;}
void Employee::setMonthlySalary(int ms) { monthlySalary = (ms > 0) ? ms : 0; }

