#include "Queue.h"

typedef int ItemType;

using namespace std;

// g++ --std=c++17 *.cpp -o ./output.out && ./output.out

int main()
{
    Queue q;
    int a = 1, b=2,c=3;
    q.enqueue(a);
    q.enqueue(b);
    q.enqueue(c);
    q.display();

    q.push_front(69);
    q.display();

    q.pop_back();
    q.display();

    q.dequeue();
    q.display();

    q.pop_back();
    q.display();

    q.pop_back();
    q.display();
}
