#include "Stack.h"

using namespace std;

// g++ --std=c++17 demo.cpp Stack.cpp -o ./output.out && ./output.out

int main()
{
    Stack *s = new Stack;
    s->push(3);
    s->push(4);
    s->push(5);
    s->push(-1);
    s->push(-100);

    int pos, neg, pos2 = 0, neg2 = 0;
    s->countPosNeg(pos, neg);
    s->countPosNeg2(&pos2, &neg2);
    
    cout << pos << " " << neg << endl;
    cout << pos2 << " " << neg2 << endl;

}
