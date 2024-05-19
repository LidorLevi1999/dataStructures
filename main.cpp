#include <iostream>
#include "ItemType.h"

int main() {
    int* value = new int(42);
    ItemType item(value);
    int* retrievedValue = static_cast<int*>(item.getData());
    std::cout << "Staored value: " << *retrievedValue << std::endl;

    return 0;
}
