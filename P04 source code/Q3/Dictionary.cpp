// Dictionary.cpp - Implementation of Dictonary ADT using Hash Table with separate chaining

#include "Dictionary.h"	// firstNodeer file

// constructor
Dictionary::Dictionary()
{
	for (int i = 0; i < MAX_SIZE; i++)
		items[i] = NULL;
	size = 0;
}

// get the hash value for the given search key
int Dictionary::hash(KeyType key)
{
	int total = 0;
	for (int i = 0; i < key.size(); i++)
		total++;

    return total;
}

// prints the length of each chain
void Dictionary::printChainLength()
{
	for (int i = 0; i < MAX_SIZE; i++){
		Node *curr = items[i];
		if (curr != nullptr){
			int length = 0;
			while (curr){
				length++;
				curr = curr->next;
			}
			cout << "Total length of the chain at index " << i << " is " << length << endl;
		}
	}
}

// add a new item with a specified key in the Dictionary
bool Dictionary::add(KeyType newKey, ItemType newItem)
{
	int index = hash(newKey);
	if (items[index] == NULL) // space is empty - start new list
	{
		items[index] = new Node;
		items[index]->key = newKey;
		items[index]->item = newItem;
		items[index]->next = NULL;
	}
	else // collision
	{
		Node* current = items[index];

		if (current->key == newKey) // duplicate key
			return false;

		while (current->next != NULL)
		{
			current = current->next;
			if (current->item == newItem) // duplicate key
				return false;
		}

		// Add new node to end of list
		Node* newNode = new Node;
		newNode->key = newKey;
		newNode->item = newItem;
		newNode->next = NULL;
		current->next = newNode;
	}
	size++;
	return true;
}

// check if the Dictionary is empty
bool Dictionary::isEmpty()
{
	return size == 0;
}

// check the size of the Dictionary
int Dictionary::getLength()
{
	return size;
}
