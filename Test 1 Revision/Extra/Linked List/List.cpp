// List.cpp - Implementation
#include "List.h" 	// Specification of List class

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

    ItemType res;

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

int List::count(ItemType item){
    Node *curr = firstNode;
    int count = 0;

    while (curr){
        if (curr->item == item)
            count++;
        
        curr = curr->next;
    }

    return count;
}

int List::countR(ItemType item){
    Node *curr = firstNode;
    return helperCountR(curr, item);
}

int List::helperCountR(Node *node, ItemType item){
    if (node == NULL) return 0;

    int count = (node->item == item) ? 1 : 0;
    return count + helperCountR(node->next, item);
}

void List::reverse(){
    Node *res = new Node;
    res->next = NULL;

    Node *curr = firstNode;

    while (curr){
        Node *next= curr->next;
        curr->next = res;
        res = curr;
        curr = next;
    }

    firstNode->next = NULL;

    firstNode = res;
}

void List::reverseR(){
    firstNode = helperReverseR(firstNode);
}

List::Node* List::helperReverseR(Node *node){
    if (node == nullptr || node->next == nullptr) return node;

    Node *curr = helperReverseR(node->next);

    node->next->next = node;
    node->next = NULL;

    return curr;
}

// remove duplicates from ll
void List::removeDuplicates(){
    Node *curr = firstNode;

    while (curr){
        while (curr->next && curr->item == curr->next->item){
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }

}

// remove duplicates from unsorted ll
void List::removeDuplicates2(){
    set<ItemType> seen;

    Node* curr = firstNode;

    while (curr->next){
        seen.insert(curr->item);
        curr = curr->next;
    }

    Node* dummy = new Node;
    dummy->next = NULL;
    Node* res = dummy;

    for (auto it: seen){
        Node* node = new Node;
        node->item = it;
        node->next = NULL;

        dummy->next = node;
        dummy = dummy->next;
    }

    firstNode = res->next;
}

// remove all occurs by item given
void List::removeAllOccurrences(ItemType item){
    Node *curr = new Node;
    curr->item = -1;
    curr->next = firstNode;
    Node *res = curr;

    while (curr){
        while (curr->next && curr->next->item == item){
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }

    firstNode = res->next;

}

// remove elements at the range of start...end (inclusive)
void List::removeAt(int start, int end){
    if (start > end || start >= size || end >= size) return;

    Node *curr = new Node;
    curr->next = firstNode;
    Node *res = curr;

    for (int i = 0; i < start; i++){
        curr = curr->next;
    }

    Node *prev = curr;

    for (int i = 0; i < end - start + 1; i++){
        curr = curr->next;
    }

    prev->next = curr->next;

    firstNode = res->next;

}

// get number of unique elements in LinkedList
int List::getNoOfUniqueElements(){
    set<ItemType> seen;

    Node *curr = firstNode;

    while (curr){
        seen.insert(curr->item);
        curr = curr->next;
    }

    return seen.size();
}

// merge another LinkedList at given position
void List::mergeLLAt(List* newList, int pos){
    if (pos <= size)
        helperMergeLLAt(newList->firstNode, pos);
}

void List::helperMergeLLAt(Node *node, int pos){
    Node *curr = new Node;
    curr->next = firstNode;
    Node *res = curr;

    for (int i = 0; i < pos; i++){
        curr = curr->next;
    }

    Node *temp = node;
    while (temp->next)
        temp = temp->next;

    temp->next = curr->next;

    curr->next = node;

    firstNode = res->next;
}

// reverse LL at range of start...end (inclusive)
void List::reverseAt(int start, int end){
    if (start == end || start > end || start >= size || end >= size) return;

    Node *dummy = new Node;
    dummy->next = firstNode;

    Node *curr = firstNode, *prev = dummy;

    for (int i = 0; i < start; i++){
        curr = curr->next;
        prev = prev->next;
    }

    Node *temp = NULL;
    for (int i = 0; i < end-start+1; i++){
        Node *next = curr->next;
        curr->next = temp;
        temp = curr;
        curr = next;
    }

    prev->next->next = curr;
    prev->next = temp;

    firstNode = dummy->next;
}

// get the middle element of the LL
ItemType List::getMiddle(){
    Node *slow = firstNode, *fast = firstNode;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->item;
}

// retrieve length iteratively
int List::retrieveLength1(){
    if (firstNode == nullptr) return 0;
    Node *curr = firstNode;
    int length = 1;

    while (curr->next){
        curr = curr->next;
        length++;
    }

    return length;
}

// retrieve length recursively
int List::retrieveLength2(){
    return helperRetrieveLength(firstNode);
}

int List::helperRetrieveLength(Node *node){
    if (node == nullptr) return 0;

    return 1 + helperRetrieveLength(node->next);
}

