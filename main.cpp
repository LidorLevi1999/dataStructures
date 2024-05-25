#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;


//IDS : 207917980, 207002411

int main() {
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

    BinaryTree tree = BinaryTree(inorder, preorder, n);
    int recursiveHeight = tree.recursiveHeightCalc();
    cout << "Tree height (recursive algorithm): " << recursiveHeight << endl;

    int nonRecursiveHeight = tree.nonRecursiveHeightCalc();
    cout << "Tree height (iterative stack algorithm): " << nonRecursiveHeight << endl;

    return 0;
}
