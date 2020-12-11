#pragma once
#include<iostream>
#include <set>
using namespace std;

typedef char ItemType;

class List
{
private:
	struct Node
	{
		ItemType item;	// data item
		Node     *next;	// pointer pointing to next item
	};

	Node *firstNode;	// point to the first item
	int  size;			// number of items in the list

public:
	List();			// constructor

	~List();		// distructor

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	bool add(ItemType item);

	// add an item at a specified position in the list (insert)
	// pre : 0 <= index <= size
	// post: item is added to the specified position in the list
	//       items after the position are shifted back by 1 position
	//       size of list is increased by 1
	bool add(int index, ItemType item);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	// pre : 0 <= index < size
	// post: none
	// return the item in the specified index of the list
	ItemType get(int index);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();

	//------------------- Other useful functions -----------------

	// display the items in the list
	void print();

	// void replace(int index, ItemType item);
	// int search(ItemType item);

    // returns the number of occurrences of item in the list
    int count(ItemType item);

    // recursive function that 
    // returns the number of occurrences of item in the list
    int countR(ItemType item);

    int helperCountR(Node *node, ItemType item);

    // reverses the list
    void reverse();

    // recursive function that reverses the list
    void reverseR();

    Node* helperReverseR(Node *node);

	void removeDuplicates();

	void removeDuplicates2();

	void removeAllOccurrences(ItemType item);

	void removeAt(int start, int end);

	int getNoOfUniqueElements();

	void mergeLLAt(List newList, int start, int end);

	void reverseAt(int start, int end);

	ItemType getMiddle();

	int retrieveLength1();

	int retrieveLength2();

};

