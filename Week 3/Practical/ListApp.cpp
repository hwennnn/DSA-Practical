#include "List.h"

typedef string ItemType;

using namespace std;

// g++ --std=c++17 *.cpp -o ./output.out && ./output.out

int main()
{
    List *nameList = new List;
    nameList->add("Annie");
    nameList->add("Jacky");
    nameList->add("Wendy");
    nameList->print();

    nameList->add(1, "Brenda");
    nameList->print();

    nameList->remove(2);
    nameList->print();

    nameList->remove(0);
    nameList->print();

}

// Annie Jacky Wendy 
// Annie Brenda Jacky Wendy 
// Annie Brenda Wendy 
// Brenda Wendy 
