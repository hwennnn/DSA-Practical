#include "Stack.h"
#include "Queue.h"
#include <iostream>

using namespace std;

typedef char ItemType;

// g++ --std=c++17 QueueDemo.cpp Stack.cpp Queue.cpp -o ./output.out && ./output.out

int main()
{
    // Q5

    // Queue *q = new Queue;

    // q->enqueue('a');
    // q->enqueue('b');

    // ItemType front;
    // q->getFront(front);
    // cout << front << endl;

    // q->displayItems();

    // q->dequeue();

    // q->displayItems();


    // Q6: isPalindrome
    
    Stack *s = new Stack;
    Queue *q = new Queue;
    int length;
    cout << "Determining Palindrome using Stack and Queue" << endl;
    cout << "Please enter the length of the string: ";
    cin >> length;

    while (length--){
        cout << "Please enter a character: ";
        ItemType input;
        cin >> input;
        s->push(input);
        q->enqueue(input);
    }

    bool isEqual = true;

    while (!q->isEmpty() && isEqual){
        ItemType qFront, sTop;
        q->getFront(qFront);
        s->getTop(sTop);

        if (qFront == sTop){
            q->dequeue();
            s->pop();
        }else{
            isEqual = false;
        }
    }

    cout << "The string " << ((isEqual) ? "is" : "is not") << " palindrome" << endl;

    return 0;

}
