#include <iostream>
#include <vector>
#include "ItemType.h"
#include "BinaryTree.h"
using namespace std;

int main() {
//    int* value = new int(42);
//    ItemType item(value);
//    int* retrievedValue = static_cast<int*>(item.getData());
//    std::cout << "Stored value: " << *retrievedValue << std::endl;

    int n;
    cin >> n;

    vector<int> preorder(n);
    vector<int> inorder(n);

    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    int zero = 0;
    int recursiveHeight = BinaryTree::recursiveHeightCalc(inorder, preorder, 0, n-1, zero, n);
    cout << recursiveHeight << endl;



    return 0;
}
