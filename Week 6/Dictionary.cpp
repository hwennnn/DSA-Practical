// Dictionary.cpp - Implementation
#include "Dictionary.h" 	// Specification of Dictionary class

typedef string KeyType;
typedef string ItemType;

Dictionary::Dictionary(){
    for (int i = 0; i < MAX_SIZE; i++){
        items[i] = NULL;
    }

    size = 0;
}

Dictionary::~Dictionary(){
    for (int i = 0; i < MAX_SIZE; i++){
        if (items[i]){
            delete items[i];
        }
    }
}

int Dictionary::hash(KeyType key){
    int val = 0;
    for (auto &c: key){
        val += charValue(c);
    }

    return val % MAX_SIZE;
}

bool Dictionary::add(KeyType newKey, ItemType newItem){
    int index = hash(newKey);
    cout << newKey << " " << index << endl;

    Node *node = new Node;
    node->item = newItem;
    node->key = newKey;
    node->next = NULL;

    if (items[index] == NULL){
        items[index] = node;
    }else{
        Node *curr = items[index];
        if (curr->key == newKey)
            return false;
        
        while (curr->next){
            curr = curr->next;
            if (curr->key == newKey)
                return false;
        }

        curr->next = node;
    }

    size++;
    
    return true;
}

void Dictionary::remove(KeyType key){
    int index = hash(key);
    if (items[index]){
        delete items[index];
        items[index] = NULL;
        size--;
    }
}

ItemType Dictionary::get(KeyType key){
    ItemType item;
    int index = hash(key);

    if (items[index]){
        item = items[index]->item;
    }

    return item;
}

bool Dictionary::isEmpty(){
    return size == 0;
}

int Dictionary::getLength(){
    return size;
}

void Dictionary::print(){
    for (int i = 0; i < MAX_SIZE; i++){
        Node *node = items[i];
        if (node){
            while (node){
                cout << "Name: " << node->key << " Values: " << node->item << endl;
                node = node->next;
            }
        }
    }
}

int Dictionary::charValue(char c){
    if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int) 'A';
		else
			return (int)c - (int) 'a' + 26;
	}
	else
		return -1;
}