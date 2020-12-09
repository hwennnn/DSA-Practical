#include "List.h"

using namespace std;

// g++ --std=c++17 q1.cpp List.cpp -o ./output.out && ./output.out

int main(){
    List *a = new List;

    a->add(0);
    a->add(2);
    a->add(3);
    a->add(4);
    a->add(6);
    a->add(8);
    a->add(9);

    a->print();
    cout << endl;

    a->sortedInsert(5);
    a->print();
    cout << endl;

    List *res = new List;
    List list1;
    List list2;


    list1.add(24);
    list1.add(25);
    list1.add(70);
    list1.add(80);
    list1.add(90);

    list2.add(20);
    list2.add(24);
    list2.add(70);
    list2.add(85);
    list2.add(90);

    res->sortedMerge(list1,list2);
    res->print();


    return 0;
}