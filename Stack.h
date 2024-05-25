#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack {
private:
    LinkedList list;

public:
    // Constructor
    Stack();
    // Destructor
    ~Stack();
    // Check if the stack is empty
    bool IsEmpty() const;
    // Make the stack empty
    void MakeEmpty();
    // Push an item onto the stack
    void Push(const ItemType& item);
    // Pop an item from the stack
    ItemType Pop();
};

#endif // STACK_H
