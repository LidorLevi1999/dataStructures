#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ItemType.h"

struct Node {
    ItemType data;
    Node* next;

    Node(ItemType item, Node* nextNode = nullptr)
            : data(item), next(nextNode) {}

    // Recursive destructor
    ~Node() {
        delete next;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    LinkedList();
    // Destructor
    ~LinkedList();
    // Check if the list is empty
    bool IsEmpty() const;
    // Add an item to the front of the list
    void AddToFront(const ItemType& item);
    // Add an item to the end of the list
    void AddToEnd(const ItemType& item);
    // Remove and return the front item of the list
    ItemType RemoveFromFront();
    // Remove and return the end item of the list
    ItemType RemoveFromEnd();
    // Get the front item without removing it
    ItemType GetFront() const;
    // Get the end item without removing it
    ItemType GetEnd() const;
    // Make the list empty
    void MakeEmpty();
};

#endif // LINKEDLIST_H
