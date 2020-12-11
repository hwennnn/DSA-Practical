#include "List.h"

typedef char ItemType;

using namespace std;

// g++ --std=c++17 demo2.cpp List.cpp -o ./output.out && ./output.out

int main()
{
    List *nameList = new List;
    nameList->add('a');
    nameList->add('b');
    nameList->add('a');
    nameList->add('a');
    nameList->add('b');
    nameList->add('c');
    nameList->add('c');
    nameList->add('b');
    nameList->add('c');
    nameList->add('c');

    nameList->print();
    nameList->removeAt(1,4);
    nameList->print();


}
