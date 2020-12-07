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


    return 0;
}