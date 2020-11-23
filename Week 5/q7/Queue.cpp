// Queue.cpp - Implementation
#include "Queue.h" 	// Specification of Queue class

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

bool Queue::enqueue(Customer item){
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

bool Queue::dequeue(Customer &item){
    bool empty = isEmpty();

    if (!empty){
        if (frontNode == backNode){
            item = frontNode->item;
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

void Queue::getFront(Customer &item){
    if (!isEmpty()){
        item = frontNode->item;
    }
}

void Queue::displayItems(){
    if (!isEmpty()){
        Node *curr = frontNode;
        while (curr){
            cout << curr->item.getName() << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

bool Queue::isEmpty(){
    return frontNode == NULL;
}