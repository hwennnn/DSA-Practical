#include <iostream>
#include "List.h"  
using namespace std;

typedef Person ItemType;

List::List() { size = 0; }

bool List::add(ItemType item)
{
	bool success = size < MAX_SIZE;
	if (success)
	{
		items[size] = item;
		size++;   
		cout << item.getName() << " with contact number of " << item.getTelNo() << " is added from the list." << endl;
	}else{
		cout << "The contact list is already full." << endl;
	}
	
	return success;
}

bool List::remove(string number)
{
	bool isExist = false;
	int index = -1;
	for (int i = 0; i < size; i++){
		if (items[i].getTelNo() == number){
			isExist = true;
			index = i;
			break;
		}
	}

	if (isExist){  
		for (int pos = index; pos < size; pos++)
			items[pos] = items[pos + 1];
		size--;  
		cout << "The person with contact number" <<  number << " is removed from the list." << endl;
	}else{
		cout << "The contact number was not found in the contact list." << endl;
	}

	return isExist;

}

ItemType List::search(string number)
{
	bool found = false;
	ItemType person;
	for (int i = 0; i < size; i++){
		if (items[i].getTelNo() == number){
			person = items[i];
			found = true;
			break;
		}
	}

	if (!found){
		cout << "Person was not found in the contact list." << endl;
	}else{
		cout << "The person with contact number of " << person.getTelNo() <<  " is called " << person.getName() << endl;
	}

	return person;
}

void List::print()
{
	if (size == 0){
		cout << "The contact list is empty." << endl;
	}
	for (int i = 0; i < size; i++){
		ItemType person = items[i];
		cout << i + 1  << ")" << " ";
		person.print();
	}
}
