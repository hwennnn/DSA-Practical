// Stack.cpp � Implementation of Stack (Array-based Implementation)
#include "Stack.h"

Stack::Stack() { top = -1; }

Stack::~Stack() { }

bool Stack::push(ItemType item)
{
    bool success = top < MAX_SIZE - 1;

    if (success){
        top++;
        if (top == 0) {
            items[top] = item;
        }
        else{
            int idx = top;
            for (int i = 0; i < MAX_SIZE; i++){
                if (item < items[i]){
                    idx = i;
                    break;
                }
            }
            
            if (idx == top){
                items[idx] = item;
            }else{
                for (int pos = top; pos > idx; pos--){
                    items[pos] = items[pos-1];
                }
                items[idx] = item;
            }
        }

    }

    return success;
}

void Stack::getTop(ItemType& item)
{
    bool success = !isEmpty();
    if (success)
        item = items[top];
}

bool Stack::isEmpty() { return top < 0; }

void Stack::displayInOrder()
{
    for (int i = top; i >= 0; i--)
        cout << items[i] << "  ";

    cout << endl;
}
