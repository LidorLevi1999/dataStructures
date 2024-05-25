#include <algorithm>
#include "BinaryTree.h"
#include <vector>
#include "Stack.h"
#include "ItemType.h"

// Constructor
BinaryTree::BinaryTree(const int& rootItem) {
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
int BinaryTree::getTreeHeightRecursively(TreeNode* node) {
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
BinaryTree::BinaryTree(vector<int> inOrder, vector<int> preOrder, int arraysLength) {
    int preIndex = 0;
    root = buildTreeFromInPreOrder(inOrder, preOrder, 0, arraysLength - 1, preIndex, arraysLength);
}


TreeNode* BinaryTree::buildTreeFromInPreOrder(vector<int> inOrder, vector<int> preOrder, int inStart, int inEnd, int& preIndex, int arraysLength) {
    if (preIndex >= arraysLength || inStart > inEnd) {
        return nullptr;
    }

    int rootData = preOrder[preIndex++];
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

int BinaryTree::recursiveHeightCalc(vector<int> inOrder, vector<int> preOrder, int inStart, int inEnd, int& preIndex, int arraysLength){
    TreeNode* tree = buildTreeFromInPreOrder(inOrder, preOrder, inStart, inEnd, preIndex, arraysLength);
    int height = getTreeHeightRecursively(tree);
    return height;
}

int BinaryTree::getTreeHeightNonRecursively(TreeNode* root) {
    if (root == nullptr) {
        return -1; // Return -1 to count edges; return 0 to count nodes
    }

    Stack S;
    S.Push(ItemType(root, -1, -1, START));
    int returnValue = -1;

    while (!S.IsEmpty()) {
        ItemType curr = S.Pop();
        switch (curr.line) {
            case START:
                if (curr.node == nullptr) {
                    returnValue = -1;
                } else {
                    curr.line = AFTER_LEFT;
                    S.Push(curr);
                    S.Push(ItemType(curr.node->getLeftChild(), -1, -1, START));
                }
                break;

            case AFTER_LEFT:
                curr.leftHeight = returnValue;
                curr.line = AFTER_RIGHT;
                S.Push(curr);
                S.Push(ItemType(curr.node->getRightChild(), -1, -1, START));
                break;

            case AFTER_RIGHT:
                curr.rightHeight = returnValue;
                returnValue = 1 + std::max(curr.leftHeight, curr.rightHeight);
                break;
        }
    }

    return returnValue;
}

int BinaryTree::nonRecursiveHeightCalc(vector<int> inOrder, vector<int> preOrder, int inStart, int inEnd, int& preIndex, int arraysLength){
    TreeNode* tree = buildTreeFromInPreOrder(inOrder, preOrder, inStart, inEnd, preIndex, arraysLength);
    int height = getTreeHeightNonRecursively(tree);
    return height;
}

int BinaryTree::nonRecursiveHeightCalc2(TreeNode* root){
    int height = getTreeHeightNonRecursively(root);
    return height;
}

int BinaryTree::recursiveHeightCalc2(TreeNode* root){
    int height = getTreeHeightRecursively(root);
    return height;
}