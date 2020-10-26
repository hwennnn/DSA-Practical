#include<string>
#include<iostream>

using namespace std;
#include "Person.h"
#include "List.h"

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

// command to compile in g++
// g++ --std=c++17 *.cpp -o ./output.out && ./output.out
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    List personList;

    int option = -1;
    while (option != 0){
        option = printMenu();
        string number, name;
        bool success;
        
        switch(option){
            case 1: { 
                cout << "[1] List the phone numbers" << endl;
                personList.print();
                break;
            }
            case 2: {
                cout << "[2] Add a new contact" << endl;

                cout << "Please enter the name of the contact: ";
                cin.ignore();
                getline(cin, name);

                cout << "Please enter the contact number: ";
                cin.clear();
                getline(cin, number);

                Person p(name, number);
                success = personList.add(p);
                
                break;
            }
            case 3: {
                cout << "[3] Remove a contact" << endl;

                cout << "Please enter the contact number you would like to remove: ";
                cin.ignore();
                getline(cin, number);

                success = personList.remove(number);

                break;
            }
            case 4: {
                cout << "[4] Search for a phone number" << endl;

                cout << "Please enter the contact number you would like to search: ";
                cin.ignore();
                getline(cin, number);

                Person person = personList.search(number);
                
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
