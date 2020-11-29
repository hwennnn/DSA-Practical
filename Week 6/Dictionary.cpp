// Dictionary.cpp - Implementation
#include "Dictionary.h" 	// Specification of Dictionary class

typedef string KeyType;
typedef string ItemType;

Dictionary::Dictionary(){
    // initialise the node at each index to NULL
    for (int i = 0; i < MAX_SIZE; i++){
        items[i] = NULL;
    }

    size = 0;
}

Dictionary::~Dictionary(){
    // deallcoate the memory
    for (int i = 0; i < MAX_SIZE; i++){
        if (items[i]){
            Node *temp = items[i];
            temp->next = NULL;

            delete temp;
        }
        items[i] = NULL;
    }
}

int Dictionary::hash(KeyType key){
    // hash the strings into an integer value
    int total = charValue(key[0]);

   for (int i = 1; i < key.size(); i++){
        if (charValue(key[i]) < 0)
            continue;

        total = total * 52 + charValue(key[i]);
        
        total %= MAX_SIZE;
   }    

    return total;
}

bool Dictionary::add(KeyType newKey, ItemType newItem){
    int index = hash(newKey);

    Node *node = new Node;
    node->item = newItem;
    node->key = newKey;
    node->next = NULL;

    Node *curr = items[index];

    if (curr == NULL){
        // set the node to the index if the list at index is empty
        items[index] = node;
    }else{
        // looping to the last index and return false when a same key exists
        if (curr->key == newKey)
            return false;
        
        while (curr->next){
            curr = curr->next;
            if (curr->key == newKey)
                return false;
        }

        // set last node point to the new node
        curr->next = node;
    }

    size++;
    
    return true;
}

void Dictionary::remove(KeyType key){
    int index = hash(key);
    Node *node = items[index];

    // if list at index is not empty
    if (node){
        Node *curr = node;
        // check if the key is at the first node of the list
        // point to the next Node and deallocate memory
        if (node->key == key){
            Node *temp = curr->next;
            curr->next = NULL;
            delete curr;
            items[index] = temp;
        }else{
            // loop to the previous node of the target node which has the key
            while (curr->next && curr->next->key != key){
                curr = curr->next;
            }

            // point the prev node to the next node of the target node
            // deallocate memory
            Node *temp = curr->next;
            if (temp && temp->key == key){
                curr->next = curr->next->next;
                temp->next = NULL;
                delete temp;
            }else{
                // return if no key was found
                return;
            }

        }

        size--;
    }
}

ItemType Dictionary::get(KeyType key){
    ItemType item;
    int index = hash(key);

    // loop through keys if list at index is not empty
    if (items[index]){
        Node *curr = items[index];
        while (curr){
            if (curr->key == key)
                return curr->item;
            
            curr = curr->next;
        }
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

// helper function to get the char value
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