// List.cpp - Implementation of List ADT using Pointers (Linked-implementation

#include "List.h"	// firstNodeer file
#include <cstddef>  // for NULL
#include <new>      // for bad_alloc

// constructor
List::List()
{
	firstNode = NULL;
	size = 0;
}

// add a new item to the back of the list (append)
bool List::add(ItemType newItem)
{
	// create a new node to store the data item
	Node* newNode = new Node;
	newNode->item = newItem;
	newNode->next = NULL;

	if (isEmpty())
		firstNode = newNode;
	else
	{
		Node* temp = firstNode;
		while (temp->next != NULL)
			temp = temp->next;		// move to last node
		temp->next = newNode;		// make last node point to the new node
	}

	size++;

	return true;  // no size constraint
}

// add a new item at a specified position in the list (insert)
bool List::add(int index, ItemType newItem)
{
	bool success = (index >= 0) && (index <= size);

	if (success)
	{
		// create a new node to store the data item
		Node* newNode = new Node;
		newNode->item = newItem;
		newNode->next = NULL;

		if (index == 0) // inserting in front
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 1; i < index - 1; i++)
				temp = temp->next;		// move to node at the position before the index

			newNode->next = temp->next;	// make new node point to the node pointed to by temp
			temp->next = newNode;		// make temp point to the new node
		}
		size++;
	}

	return success;
}

// remove an item at a specified position in the list
void List::remove(int index)
{
	bool success = (index >= 0) && (index <= size - 1) && (size != 0);
	if (success)
	{
		Node* tmp = firstNode;
		if (index == 0) // remove front node
			firstNode = firstNode->next;
		else
		{
			Node* current = firstNode;
			Node* previous = firstNode;
			for (int i = 1; i < index; i++)
			{
				previous = current;
				current = current->next;		// move to next node
			}

			previous->next = current->next;	// delete the current node by
		}		                                // making previous node point to the node pointed to by current node
		delete tmp;
		tmp = NULL;
		size--;  // decrease the size of the list by one
	}
}

// get an item at a specified position of the list (retrieve)
ItemType List::get(int index)
{
	ItemType dataItem = -1;
	bool success = (index >= 0) && (index <= size - 1);
	if (success)
	{
		Node* current = firstNode;
		for (int i = 1; i < index; i++)
			current = current->next;		// move to next node

		dataItem = current->item;
	}

	return dataItem;
}

// check if the list is empty
bool List::isEmpty()
{
	return size == 0;
}

// check the size of the list
int List::getLength()
{
	return size;
}

//------------------- Other useful functions -----------------
void List::print()
{
	Node* temp = firstNode;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			cout << temp->item << "\t";
			temp = temp->next;		// move to next node
		}
	}
}


void List::sortedInsert(ItemType item)
{
	Node *newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	// if firstNode is NULL
	// point firstNode to newNode 
	if (firstNode == NULL){
		firstNode = newNode;
		return;
	}

	Node *curr = firstNode;
	// if the first element is smaller
	if (item < curr->item){
		newNode->next = curr;
		firstNode = newNode;
	}else{
		while (curr->next && curr->next->item < item)
			curr = curr->next;

		newNode->next = curr->next;
		curr->next = newNode;
	}
}
// The time complexity of sortedInsert is O(n), where n is the length of the original linked list.
// At worst case, it will need to do a complete linear scan of the linked list, which is O(n)
// Therefore the overall complexity comes to O(n), linear time complexity.

void List::sortedMerge(List list1, List list2)
{
	firstNode = sortedMerge(list1.firstNode, list2.firstNode);
}

List::Node* List::sortedMerge(Node*& a, Node*& b) 
{
	Node* res = new Node;
	res->item = -1; //dummy
	Node* curr = res;

	while (a != nullptr && b != nullptr){
		if (b->item < a->item){
			curr->next = b;
			b = b->next;
		}else{
			curr->next = a;
			a = a->next;
		}

		curr = curr->next;
	}

	Node *leftover = (a != nullptr) ? a : b;
	curr->next = leftover;

	return res->next;
	
}

// The time complexity of sortedMerge is O(n+m), where n,m is the length of the first and second linked list respectively.
// The algorithm needs to traverse the whole length of both linked lists, therefore the time complexity comes to the total of their length.