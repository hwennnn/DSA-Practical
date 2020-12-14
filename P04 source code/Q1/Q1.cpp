#include <iostream>
#include "List.h"
using namespace std;

// g++ --std=c++17 Q1.cpp List.cpp -o ./output.out && ./output.out


int main()
{
	List aList;

	int array[] = { 10, 4, 6, 3, 5 };

	for (int i = 0; i < 5; i++)
		aList.add(array[i]);

	cout << "The middle value is: ";

	cout << aList.getMiddle() << endl;

	cout << "The middle value is: ";

	cout << aList.getMiddleR() << endl;

	return 0;
}
