// List.cpp - Implementation of List ADT using Array
#include <iostream>
#include "List.h"  // header file
using namespace std;

typedef Person ItemType;

// constructor
List::List() { size = 0; }

// add an item to the back of the list (append)
bool List::add(ItemType item)
{
	bool success = size < MAX_SIZE;
	if (success)
	{
		items[size] = item;
		size++;                // increase the size by 1
	}
	return success;
}

// remove an item at a specified position in the list
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

	if (isExist)
	{  // delete item by shifting all items at positions >
	   // index toward the beginning of the list
	   // (no shift if index == size)
		for (int pos = index; pos < size; pos++)
			items[pos] = items[pos + 1];
		size--;  // decrease the size by 1
	}

	return isExist;

}

// get an item at a specified position of the list (retrieve)
ItemType List::search(string number)
{
	ItemType result;
	for (int i = 0; i < size; i++){
		if (items[i].getTelNo() == number)
			result = items[i];
			break;
	}

	return result;
}

// display the items in the list
void List::print()
{
	if (size == 0){
		cout << "The phone numbers list is empty" << endl;
	}
	for (int i = 0; i < size; i++){
		ItemType person = items[i];
		cout << i + 1  << ")" << " ";
		cout << person.getName() << " " << person.getTelNo() << endl;
	}
}
