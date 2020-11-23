// Queue.cpp - Implementation
#include "Queue.h" 	// Specification of Queue class

typedef char ItemType;

Queue::Queue(){
    frontNode = backNode = NULL;
}

Queue::~Queue(){
    Node *temp = frontNode;
    while (temp){
        frontNode = frontNode->next;
        temp->next = NULL;
        delete temp;
        temp = frontNode;
    }

    backNode->next = NULL;
    delete backNode;
}

bool Queue::enqueue(ItemType item){
    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;

    if (isEmpty()){
        frontNode = newNode;
    }else{
        backNode->next = newNode;
    }

    backNode = newNode;

    return true;
}

bool Queue::dequeue(){
    bool empty = isEmpty();

    if (!empty){
        if (frontNode == backNode){
            frontNode = backNode = NULL;
        }else{
            Node* temp = frontNode;
            frontNode = frontNode->next;
            temp->next = NULL;
            delete temp;
        }
    }

    return !empty;
}

bool Queue::dequeue(ItemType &item){
    bool empty = isEmpty();

    if (!empty){
        if (frontNode == backNode){
            frontNode = backNode = NULL;
        }else{
            Node* temp = frontNode;
            frontNode = frontNode->next;
            item = temp->item;
            temp->next = NULL;
            delete temp;
        }
    }

    return !empty;
}

void Queue::getFront(ItemType &item){
    if (!isEmpty()){
        item = frontNode->item;
    }
}

void Queue::displayItems(){
    if (!isEmpty()){
        Node *curr = frontNode;
        while (curr){
            cout << curr->item << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

bool Queue::isEmpty(){
    return frontNode == NULL;
}