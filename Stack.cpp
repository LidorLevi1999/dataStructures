#include "Stack.h"

// Constructor
Stack::Stack() {}

// Destructor
Stack::~Stack() {
    MakeEmpty();
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

// Get the top item from the stack
ItemType Stack::Top() const {
    return list.GetFront();
}
