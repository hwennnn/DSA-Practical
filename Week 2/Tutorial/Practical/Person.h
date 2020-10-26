#pragma once
#include <string>

using namespace std;

class Person
{
  // data (properties)
  private:   		
    string name;
    string telNo;
  // functions (methods)
  public:		
    Person();		// default constructor 
    Person(string, string);	// parameterized constructor 
    void setName(string); 
    void setTelNo(string);

    string getName();
    string getTelNo();

    void print();
};
