#include "ItemType.h"
#include <cstring>  // For memcpy

// Constructor that takes a void* and size
//ItemType::ItemType(void* newData) : data(nullptr) {
//    setData(newData);
//}

// Copy constructor
//ItemType::ItemType(const ItemType& other) : data(nullptr) {
//    setData(other.data);
//}
//
//// Destructor
//ItemType::~ItemType() {
//    deleteData();
//}
//
//// Assignment operator
//ItemType& ItemType::operator=(const ItemType& other) {
//    if (this != &other) {
//        setData(other.data);
//    }
//    return *this;
//}
//
//// Set data method
//void ItemType::setData(void* newData) {
//    if (newData != data) {
//        deleteData();
//    }
//    this->data = newData;
//}
//
//// Get data method
//void* ItemType::getData() const {
//    return data;
//}
//
//// Overload the equality operator ==
//bool ItemType::operator==(const ItemType& other) const {
//    // Compare the addresses stored in the data pointers
//    return this->data == other.data;
//}
//
//
//// Helper method to delete data
//void ItemType::deleteData() {
//    delete[] static_cast<char*>(data);
//    data = nullptr;
//}
