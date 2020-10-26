#include<string>
#include<iostream>

using namespace std;
#include "Person.h"
#include "List.h"

void printMenu(){
    cout << "---------------- Main Menu -------------------" << endl;
    cout << "[1] List the phone numbers" << endl;
    cout << "[2] Add a new contact" << endl;
    cout << "[3] Remove a contact" << endl;
    cout << "[4] Search for a phone number" << endl;
    cout << "[0] Exit" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Enter your option : ";
}

// command to compile in g++
// g++ --std=c++17 *.cpp -o ./output.out && ./output.out
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    List personList;

    bool going = true;
    while (going){
        printMenu();
        int option;
        string number, name;
        bool success;
        cin >> option;
        cout << endl;

        switch(option){
            case 1: { 
                cout << "[1] List the phone numbers" << endl;
                personList.print();
                break;
            }
            case 2: {
                cout << "[2] Add a new contact" << endl;

                cout << "Please enter the contact number: ";
                cin.ignore();
                getline(cin, number);

                cout << "Please enter the name of the contact: ";
                cin.clear();
                getline(cin, name);
                cout << "debug " << name << endl; 
                Person p(name, number);
                success = personList.add(p);
                if (success){
                    cout << "Successfully add the person into the list" << endl;
                }else{
                    cout << "Unsuccessfully add the person into the list" << endl;
                }
                break;
            }
            case 3: {
                cout << "[3] Remove a contact" << endl;

                cout << "Please enter the contact number you would like to remove: ";
                cin.ignore();
                getline(cin, number);

                success = personList.remove(number);
                if (success){
                    cout << "Successfully remove the person into the list" << endl;
                }else{
                    cout << "Unsuccessfully remove the person into the list" << endl;
                }
                break;
            }
            case 4: {
                cout << "[4] Search for a phone number" << endl;

                cout << "Please enter the contact number you would like to search: ";
                cin.ignore();
                getline(cin, number);

                Person person = personList.search(number);
                if (person.getName() == ""){
                    cout << "Person not found" << endl;
                }else{
                    cout << person.getName() << " " << person.getTelNo() << endl;
                }
                break;
            }
            case 0:{
                going = false;
                cout << "App exiting...." << endl;
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
