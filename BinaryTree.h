#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

class BinaryTree {
private:
    TreeNode* root;
    // Helper function to get the height of the tree recursively
    int getTreeHeightRecursively(TreeNode* node) const;
    // Helper function to build the tree recursively
    TreeNode* buildTreeFromInPreOrder(ItemType* inOrder, ItemType* preOrder, int inStart, int inEnd, int& preIndex, int arraysLength);

public:
    // Constructor
    BinaryTree(const ItemType& rootItem);

    // Constructor to build tree from inOrder and preOrder arrays
    BinaryTree(ItemType* inOrder, ItemType* preOrder, int arraysLength);

    // Destructor
    ~BinaryTree();

    // Get the root of the tree
    TreeNode* getRoot() const;

    // Get the height of the tree recursively
    int getTreeHeightRecursively() const;

    // Make the tree empty
    void makeEmpty();
};

#endif // BINARYTREE_H
