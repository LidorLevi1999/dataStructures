#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

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

    int zero = 0;

    TreeNode* tree = BinaryTree::buildTreeFromInPreOrder(inorder, preorder, 0, n-1, zero, n);


    int recursiveHeight = BinaryTree::recursiveHeightCalc2(tree);
    cout << recursiveHeight << endl;

    int nonRecursiveHeight = BinaryTree::nonRecursiveHeightCalc2(tree);
    cout << nonRecursiveHeight << endl;

    return 0;
}
