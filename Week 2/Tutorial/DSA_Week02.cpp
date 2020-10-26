// DSA_Week02.cpp : Defines the entry point for the console application.

#include <iostream>
using namespace std;

#include "List.h"   //ADT List specifications

int main()
{
   List list1;
   ItemType item;

   list1.add(10); 
   list1.add(50);
   list1.add(2, 30);
   list1.add(2, 20);
   list1.remove(1);
   list1.replace(1, 15);
   for (int i = 0; i < list1.getLength(); i++)
   {
      item = list1.get(i);
      cout << item << endl;
   }
   cout << "===== Using display function =====\n";
   list1.print();

   // system("PAUSE");
   return 0;
}