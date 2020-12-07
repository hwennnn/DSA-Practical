// Test1SampleQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Queue.h"
#include "Customer.h"

using namespace std;

// g++ --std=c++17 Test1SampleQueue.cpp Customer.cpp Queue.cpp -o ./output.out && ./output.out

void registerCustomer(Queue& serviceQueue, int& queueNumber)
{
	Customer cust;
	string name;
	cout << "Please enter your name: ";
	cin >> name;
	cout << endl;

	cust.setName(name);
	cust.setQueueNumber(queueNumber);

	serviceQueue.enqueue(cust);
	queueNumber++;
}

void nextCustomer(Queue& serviceQueue)
{
	Customer cust;
	serviceQueue.dequeue(cust);
	
	cust.print();
}

void displayCount(Queue& serviceQueue)
{
	int count = 0;
	Queue q;
	while (!serviceQueue.isEmpty()){
		Customer c;
		serviceQueue.dequeue(c);
		q.enqueue(c);
		count++;
	}

	serviceQueue = q;

	cout << "Total number of customers left: " << count << endl;
	serviceQueue.display();
}

int main()
{
	Queue serviceQueue;
	int queueNumber = 0;
	registerCustomer(serviceQueue, queueNumber);
	registerCustomer(serviceQueue, queueNumber);
	registerCustomer(serviceQueue, queueNumber);
	registerCustomer(serviceQueue, queueNumber);

	nextCustomer(serviceQueue);
	
	displayCount(serviceQueue);
}

