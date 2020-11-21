// Queue.h - Specification of Queue ADT (Pointer-based)
#pragma once
#include<string>
#include<iostream>
#include "Customer.h"

using namespace std;

class Queue
{
  private:
    struct Node
    {
      Customer item;	// item
      Node *next;	// pointer pointing to next item
    };

    Node *frontNode;	// point to the first item
    Node *backNode;	// point to the first item


  public:
    // constructor
    Queue();

    ~Queue();

    // enqueue (add) item at the back of queue
    bool enqueue(Customer item);

    // dequeue (remove) item from front of queue
    bool dequeue();

    // dequeue (remove) and retrieve item from front of queue
    bool dequeue(Customer &item);

    // retrieve (get) item from front of queue
    void getFront(Customer &item); 

    // check if the queue is empty
    bool isEmpty(); 

    // display items in queue from front to back
    void displayItems();
}; 
