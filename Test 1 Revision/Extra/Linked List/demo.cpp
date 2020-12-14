#include "List.h"

typedef char ItemType;

using namespace std;

// g++ --std=c++17 demo.cpp List.cpp -o ./output.out && ./output.out

int main()
{
    List *nameList = new List;
    nameList->add('a');
    nameList->add('b');
    nameList->add('a');
    nameList->add('c');
    nameList->add('a');
    nameList->add('a');
    nameList->add('d');

    cout << nameList->count('a') << endl;
    cout << nameList->countR('a') << endl;

    nameList->print();
    nameList->reverse();
    nameList->print();

    nameList->reverseR();
    nameList->print();


}
