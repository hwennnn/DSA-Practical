// Stack.cpp - Implementation
#include "Stack.h" 	// Specification of Stack class

typedef string ItemType;

Stack::Stack() {
    topNode = NULL;
}

Stack::~Stack(){
    Node *temp = topNode;
    while (temp){
        topNode = topNode->next;
        temp->next = NULL;
        delete temp;
        temp = topNode;
    }
}

bool Stack::push(ItemType item){
    Node *temp = new Node;
    temp->item = item;
    temp->next = NULL;

    if (isEmpty()){
        topNode = temp;
    }else{
        temp->next = topNode;
        topNode = temp;    
    }

    return true;
}

bool Stack::pop(){
    bool empty = isEmpty();
    if (!empty){
        Node *temp = topNode;
            
        topNode = topNode->next;
        temp->next = NULL;
        delete temp;
    }
    
    return empty;
}

bool Stack::pop(ItemType &item){
    bool empty = isEmpty();

    if (!empty){
        Node *temp = topNode;
            
        topNode = topNode->next;

        item = temp->item;
        temp->next = NULL;
        delete temp;
    }
    
    return empty;
}

void Stack::getTop(ItemType &item){
    if (!isEmpty())
        item = topNode->item;
}

bool Stack::isEmpty(){
    return topNode == NULL;
}

void Stack::displayInOrder(){
    Node *curr = topNode;

    while (curr){
        cout << curr->item << " ";
        curr = curr->next;
    }

    cout << endl;
}

void Stack::displayInOrderOfInsertion(){
    Node *curr = topNode;

    printReverse(curr);
    cout << endl;
}

void Stack::printReverse(Node *head){
    if (head == NULL) return;
    printReverse(head->next);

    cout << head->item << " ";
}

