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

// Add an item to the end of the list
void LinkedList::AddToEnd(const ItemType& item) {
    Node* newNode = new Node(item, nullptr);
    if (IsEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
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

// Remove and return the end item of the list
ItemType LinkedList::RemoveFromEnd() {
    if (IsEmpty()) {
        throw std::underflow_error("List is empty");
    }
    if (head == tail) { // If there is only one element in the list
        ItemType item = head->data;
        delete head;
        head = tail = nullptr;
        return item;
    }
    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    ItemType item = tail->data;
    delete tail;
    tail = current;
    tail->next = nullptr;
    return item;
}

// Get the front item without removing it
ItemType LinkedList::GetFront() const {
    if (IsEmpty()) {
        throw std::underflow_error("List is empty");
    }
    return head->data;
}

// Get the end item without removing it
ItemType LinkedList::GetEnd() const {
    if (IsEmpty()) {
        throw std::underflow_error("List is empty");
    }
    return tail->data;
}

// Make the list empty
void LinkedList::MakeEmpty() {
    delete head; // Triggers recursive deletion of all nodes
    head = tail = nullptr;
}
