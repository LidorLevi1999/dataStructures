#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <vector>
using namespace std;

class BinaryTree {
private:
    TreeNode* root;

    enum {
        START,
        AFTER_LEFT,
        AFTER_RIGHT
    };

    // Helper function to get the height of the tree recursively
    int getTreeHeightRecursively(TreeNode* node);

    // Helper function to get the height of the tree non-recursively
    int getTreeHeightNonRecursively(TreeNode *node);

public:

    // Constructor to build tree from inOrder and preOrder arrays
    BinaryTree(vector<int> inOrder, vector<int> preOrder, int arraysLength);

    // Destructor
    ~BinaryTree();

    // Make the tree empty
    void makeEmpty();

    // Calculate the height of the tree non-recursively
    int nonRecursiveHeightCalc();

    // Build tree from inOrder and preOrder arrays
    TreeNode* buildTreeFromInPreOrder(vector<int> inOrder, vector<int> preOrder, int inStart, int inEnd, int& preIndex, int arraysLength);

    // Calculate the height of the tree recursively
    int recursiveHeightCalc();
};

#endif // BINARYTREE_H
