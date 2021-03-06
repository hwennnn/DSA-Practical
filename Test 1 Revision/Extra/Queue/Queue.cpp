// Queue.cpp - Implementation of Queue ADT (Array-based)
// Circular Queue

#include "Queue.h"

Queue::Queue()
{
	frontNode = NULL;
	backNode = NULL;
}

Queue::~Queue() { }

bool Queue::enqueue(ItemType& item)
{
	// create a new node to store data
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	// insert the new node
	if (isEmpty())	// enqueue at the front
	{
		frontNode = newNode;
		backNode = newNode;
	}
	else			// enqueue at the back
	{
		backNode->next = newNode;
		backNode = newNode;  // new node is at back
	}

	return true;
}

bool Queue::dequeue()
{
	bool success = !isEmpty();
	if (success)					// queue is not empty -> remove front
	{
		Node* temp = frontNode;		// to be returned to the system
		if (frontNode == backNode)  // only one node in the queue
		{
			frontNode = NULL;
			backNode = NULL;
		}
		else
			frontNode = frontNode->next;

		// return node to the system
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}

	return success;
}

bool Queue::dequeue(ItemType& item)
{
	bool success = !isEmpty();
	if (success)				// queue is not empty
	{
		item = frontNode->item; // retrieve front item
		dequeue();              // delete front
	}

	return success;
}

/*ItemType Queue::getFront()
{
	bool success = !isEmpty();
	if (success) // queue is not empty -> retrieve item at the front
		return frontNode->item;
	else
		return NULL;
}*/

void Queue::getFront(ItemType& item)
{
	bool success = !isEmpty();
	if (success) // queue is not empty -> retrieve item at the front
		item = frontNode->item;
}

bool Queue::isEmpty() { return frontNode == NULL; }

void Queue::display()
{	if (!isEmpty()){
		Node* temp = frontNode;
		while (temp != NULL)
		{
			cout << temp->item << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void Queue::push_front(ItemType item){
	Node *node = new Node;
	node->item = item;
	node->next = NULL;

	if (!isEmpty()){
		node->next = frontNode;
		frontNode = node;
	}else{
		frontNode = backNode = node;
	}
}

void Queue::pop_back(){
	if (!isEmpty()){
		if (frontNode == backNode){
			frontNode = backNode = NULL;
			return;
		}

		Node *curr = frontNode;
		while (curr->next->next)
			curr = curr->next;
		
		curr->next = NULL;
		backNode = curr;
	}
}