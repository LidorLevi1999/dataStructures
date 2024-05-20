#include <algorithm>
#include "BinaryTree.h"

// Constructor
BinaryTree::BinaryTree(const ItemType& rootItem) {
    root = new TreeNode(rootItem);
}

// Destructor
BinaryTree::~BinaryTree() {
    makeEmpty();
}

// Get the root of the tree
TreeNode* BinaryTree::getRoot() const {
    return root;
}

// Helper function to get the height of the tree recursively
int BinaryTree::getTreeHeightRecursively(TreeNode* node) const {
    if (node == nullptr) {
        return -1; // Return -1 to count edges; return 0 to count nodes
    }
    int leftHeight = getTreeHeightRecursively(node->getLeftChild());
    int rightHeight = getTreeHeightRecursively(node->getRightChild());
    return 1 + std::max(leftHeight, rightHeight);
}

// Get the height of the tree recursively
int BinaryTree::getTreeHeightRecursively() const {
    return getTreeHeightRecursively(root);
}


// Constructor to build tree from inOrder and preOrder arrays
BinaryTree::BinaryTree(ItemType* inOrder, ItemType* preOrder, int arraysLength) {
    int preIndex = 0;
    root = buildTreeFromInPreOrder(inOrder, preOrder, 0, arraysLength - 1, preIndex, arraysLength);
}


TreeNode* BinaryTree::buildTreeFromInPreOrder(ItemType* inOrder, ItemType* preOrder, int inStart, int inEnd, int& preIndex, int arraysLength) {
    if (preIndex >= arraysLength || inStart > inEnd) {
        return nullptr;
    }

    ItemType rootData = preOrder[preIndex++];
    TreeNode* node = new TreeNode(rootData);

    if (inStart == inEnd) {
        return node;
    }

    // Find the index of rootData in the inOrder array
    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; ++inIndex) {
        if (inOrder[inIndex] == rootData) {
            break;
        }
    }

    // Recursively build left and right subtrees
    node->left = buildTreeFromInPreOrder(inOrder, preOrder, inStart, inIndex - 1, preIndex, arraysLength);
    node->right = buildTreeFromInPreOrder(inOrder, preOrder, inIndex + 1, inEnd, preIndex, arraysLength);

    return node;
}


// Make the tree empty
void BinaryTree::makeEmpty() {
    delete root; // Triggers recursive deletion of all nodes
    root = nullptr;
}