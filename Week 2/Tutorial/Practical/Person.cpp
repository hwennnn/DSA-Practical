// Person.cpp - Implementation
#include "Person.h" 	// Specification of Person class
#include <string>
#include <iostream>

using namespace std;

Person::Person() { }
Person::Person(string n, string tn){ 
    name = n;
    telNo = tn;
}

string Person::getName(){ return name;}
string Person::getTelNo(){ return telNo;}

void Person::setName(string n){ name = n;}
void Person::setTelNo(string tn){ telNo = tn;}

void Person::print(){
    cout << name << " " << telNo << endl;
}