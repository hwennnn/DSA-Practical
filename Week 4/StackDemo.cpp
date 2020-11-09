#include "Stack.h"

using namespace std;

// g++ --std=c++17 *.cpp -o ./output.out && ./output.out

int main()
{
    Stack *s = new Stack;
    s->push(3);
    s->push(4);

    int top;
    s->getTop(top);
    cout << top << endl;

    s->displayInOrderOfInsertion();

    s->pop();

    s->displayInOrderOfInsertion();
}
