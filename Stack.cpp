#include "Stack.h"

// Constructor
Stack::Stack() {
    this->MakeEmpty();
}

// Destructor
Stack::~Stack() {
    this->MakeEmpty();
}

// Check if the stack is empty
bool Stack::IsEmpty() const {
    return list.IsEmpty();
}

// Make the stack empty
void Stack::MakeEmpty() {
    list.MakeEmpty();
}

// Push an item onto the stack
void Stack::Push(const ItemType& item) {
    list.AddToFront(item);
}

// Pop an item from the stack
ItemType Stack::Pop() {
    return list.RemoveFromFront();
}
