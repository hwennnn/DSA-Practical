#include<string>
#include<iostream>

using namespace std;
#include "Person.h"
#include "List.h"

void listPhoneNumbers(List& personList);
void addNewContact(List& personList);
void removeContact(List& personList);
void searchContact(List& personList);
int printMenu();
void initContacts(List& personList);

// command to compile in g++
// g++ --std=c++17 *.cpp -o ./output.out && ./output.out

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    List personList;
    initContacts(personList);

    int option = -1;
    while (option != 0){
        option = printMenu();
        
        switch(option){
            case 1: { 
                listPhoneNumbers(personList);
                break;
            }
            case 2: {
                addNewContact(personList);
                break;
            }
            case 3: {
                removeContact(personList);
                break;
            }
            case 4: {
                searchContact(personList);
                break;
            }
            case 0:{
                cout << "Exiting application...." << endl;
                break;
            }
            default: {
                cout << "Please enter option 0 to 4!" << endl;
            }
        }
        cout << "\n\n";
    }
    return 0;
}

void initContacts(List& personList){
    personList.add(Person("wendy", "67421672"));
    personList.add(Person("liu", "41241242"));
    personList.add(Person("jjaltoon", "51323274"));
    personList.add(Person("doinb", "41242142"));
    personList.add(Person("jeya", "64124242"));
}

int printMenu(){
    cout << "---------------- Main Menu -------------------" << endl;
    cout << "[1] List the phone numbers" << endl;
    cout << "[2] Add a new contact" << endl;
    cout << "[3] Remove a contact" << endl;
    cout << "[4] Search for a phone number" << endl;
    cout << "[0] Exit" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Enter your option : ";
    int option;
    cin >> option;
    cout << endl;

    return option;
}

void listPhoneNumbers(List& personList){
    cout << "[1] List the phone numbers" << "\n\n";
    personList.print();
}

void addNewContact(List& personList){
    cout << "[2] Add a new contact" << endl;

    string name, number;
    bool success;

    cout << "Please enter the name of the contact: ";
    cin.ignore();
    getline(cin, name);

    cout << "Please enter the contact number: ";
    cin.clear();
    getline(cin, number);

    Person p(name, number);
    success = personList.add(p);

    if (success){
        cout << name << " with contact number of " << number << " is added from the list." << endl;
    }else{
        cout << "The contact list is already full." << endl;
    }
}

void removeContact(List& personList){
    cout << "[3] Remove a contact" << endl;

    int index;
    personList.print();
    cout << "Please enter the index you would like to remove (start from 1): ";
    cin >> index;
    cout << endl;

    if (index >= 1 && index <= personList.getLength()){
		cout << "The person has been removed from the list." << endl;		
	}else{
        cout << "Person was not found in the contact list." << endl;
	}

    personList.remove(index-1);
}

void searchContact(List& personList){
    cout << "[4] Search for a phone number" << endl;

    string name;
    cout << "Please enter the contact name you would like to search: ";
    cin.ignore();
    getline(cin, name);

    Person person = personList.search(name);

    if (person.getName() == "" && person.getTelNo() == ""){
		cout << "Person was not found in the contact list." << endl;
	}else{
		cout << person.getName() << "'s contact number is " << person.getTelNo() << endl;
	}
}