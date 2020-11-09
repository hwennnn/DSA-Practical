#include <iostream>
#include <string>
#include "Stack.h"

void visitURL(Stack *back, Stack *forward);
void back(Stack *back, Stack *forward);
void forward(Stack *forward);

using namespace std;

// g++ --std=c++17 q5.cpp Stack.cpp -o ./output.out && ./output.out

int main()
{
    Stack *back_stack = new Stack;
    Stack *forward_stack = new Stack;
    int temp = -1;
    while (temp != 0)
    {
        cout << "[1] Visit URL\n[2] Back\n[3] Forward \n[0] Exit\nYour Choice: ";
        cin >> temp;
        switch (temp){
            case 1:{
                visitURL(back_stack, forward_stack);
                break;
            }
                
            case 2:{
                back(back_stack, forward_stack);
                break;
            }
                
            case 3:{
                forward(forward_stack);
                break;      
            }
                
            case 0:{
                cout << "Exiting application...." << endl;
                break;
            }
            default: {
                cout << "Please enter option 0 to 3!" << endl;
            }
        }

        cout << "\n";
    }
    return 0;
}

void visitURL(Stack *back, Stack *forward){
    cout << "Please enter the URL you would like to visit: ";
    string url;
    cin >> url; cout << endl;
    back->push(url);

    if (!forward->isEmpty()){
        forward->~Stack();
        forward = new Stack;
    }
}

void back(Stack *back, Stack *forward){
    string url;
    back->pop(url);
    forward->push(url);

    string curr;
    back->getTop(curr);

    if (back->isEmpty())
        cout << "Back history is empty." << endl;
    else
        cout << "Current URL: " << curr << endl;

}

void forward(Stack *forward){
    string url;
    forward->pop(url);

    if (forward->isEmpty())
        cout << "Forward history is empty." << endl;
    else
        cout << "Current URL: " << url << endl;
}
