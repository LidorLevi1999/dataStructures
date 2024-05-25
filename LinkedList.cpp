#include "LinkedList.h"
#include <stdexcept>

// Constructor
LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

// Destructor
LinkedList::~LinkedList() {
    delete head; // Triggers recursive deletion of all nodes
}

// Check if the list is empty
bool LinkedList::IsEmpty() const {
    return head == nullptr;
}

// Add an item to the front of the list
void LinkedList::AddToFront(const ItemType& item) {
    Node* newNode = new Node(item, head);
    head = newNode;
    if (tail == nullptr) { // If the list was empty, set tail to the new node
        tail = newNode;
    }
}

// Remove and return the front item of the list
ItemType LinkedList::RemoveFromFront() {
    if (IsEmpty()) {
        throw std::underflow_error("List is empty");
    }
    Node* nodeToDelete = head;
    ItemType item = head->data;
    head = head->next;
    if (head == nullptr) { // If the list is now empty, set tail to nullptr
        tail = nullptr;
    }
    nodeToDelete->next = nullptr; // Disconnect the node to avoid recursive deletion
    delete nodeToDelete;
    return item;
}



// Make the list empty
void LinkedList::MakeEmpty() {
    delete head; // Triggers recursive deletion of all nodes
    head = tail = nullptr;
}
