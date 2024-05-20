#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <cstddef>  // For size_t

class ItemType {
private:
    void* data;

public:
    // Constructor that takes a void* and size
    ItemType(void* newData);
    // Copy constructor
    ItemType(const ItemType& other);
    // Destructor
    ~ItemType();
    // Assignment operator
    ItemType& operator=(const ItemType& other);
    // Equality operator
    bool operator==(const ItemType& other) const;
    // Set data method
    void setData(void* newData);
    // Get data method
    void* getData() const;

private:
    // Helper method to delete data
    void deleteData();
};

#endif // ITEMTYPE_H
