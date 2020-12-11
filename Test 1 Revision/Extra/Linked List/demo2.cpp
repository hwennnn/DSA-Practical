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

    List *list2 = new List;
    list2->add('d');
    list2->add('e');
    list2->add('a');
    list2->add('d');

    nameList->print();
    nameList->mergeLLAt(list2, 3);
    nameList->print();

}
