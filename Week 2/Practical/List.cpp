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
	}
	
	return success;
}

void List::remove(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
	{  // delete item by shifting all items at positions >
	   // index toward the beginning of the list
	   // (no shift if index == size)
		for (int pos = index; pos < size; pos++)
			items[pos] = items[pos + 1];
		size--;  // decrease the size by 1
	}
}

ItemType List::search(string name)
{
	bool found = false;
	ItemType person;
	for (int i = 0; i < size; i++){
		if (items[i].getName() == name){
			person = items[i];
			found = true;
			break;
		}
	}

	return person;
}

// check the size of the list
int List::getLength() { return size; }

// check if the list is empty
bool List::isEmpty() { return size == 0; }

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
