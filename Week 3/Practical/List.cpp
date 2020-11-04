// List.cpp - Implementation
#include "List.h" 	// Specification of List class
// #include <string>

// using namespace std;

typedef string ItemType;

List::List() {
    size = 0;
    firstNode = new Node;
    firstNode->next = NULL;
}

List::~List(){
    Node *temp = firstNode;
    while (temp){
        firstNode = firstNode->next;
        temp->next = NULL;
        delete temp;
        temp = firstNode;
    }

    size = 0;
}


bool List::add(ItemType item){
    Node *temp = new Node;
    temp->item = item;
    temp->next = NULL;

    if (size == 0){
        firstNode = temp;
    }else{
        Node *curr = firstNode;
        while (curr->next)
            curr = curr->next;
        curr->next = temp;
    }

    ++size;
    return true;
}

bool List::add(int index, ItemType item){
    
    bool success = index >= 0 && index <= size;

    if (success){
        Node *curr = firstNode; 
        
        Node *node = new Node;
        node->item = item;
        node->next = NULL;

        if (index == 0){
            node->next = curr;
            firstNode = node;
        }else{
            for (int i = 0; i < index-1; ++i)
                curr = curr->next;

            Node *temp = curr->next;
            curr->next = node;
            curr->next->next = temp;
        }
        
        ++size;
    }

    return success;
}

void List::remove(int index){
    bool success = index >= 0 && index < size;
    
    // if index is valid
    if (success){
        Node *curr = firstNode;
        if (index == 0){
            Node *temp = curr->next;
            firstNode = temp;
        }else{
            for (int i = 0; i < index-1; ++i)
                curr = curr->next;
            
            Node *nd = curr->next;

            curr->next = curr->next->next;
            delete nd;
        }
        --size;
    }
}

ItemType List::get(int index){
    bool success = index >= 0 && index < size;

    ItemType res = "";

    if (success){
        Node *curr = firstNode;
        for (int i = 0; i < index; ++i)
            curr = curr->next;

        res = curr->item;
    }

    return res;
}

bool List::isEmpty(){
    return size == 0;
}

int List::getLength(){
    return size;
}

void List::print(){
    Node *curr = firstNode;

    while (curr){
        cout << curr->item << " ";
        curr = curr->next;
    }

    cout << endl;
}

