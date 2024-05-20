#include "TreeNode.h"

// Constructor
TreeNode::TreeNode(const ItemType& item, TreeNode* leftNode, TreeNode* rightNode)
        : data(item), left(leftNode), right(rightNode) {}

// Assign left child
void TreeNode::assignLeft(TreeNode* leftNode) {
    if (left != nullptr) {
        delete left;
    }
    left = leftNode;
}

// Assign right child
void TreeNode::assignRight(TreeNode* rightNode) {
    if (right != nullptr) {
        delete right;
    }
    right = rightNode;
}

// Get left child
TreeNode* TreeNode::getLeftChild() const {
    return left;
}

// Get right child
TreeNode* TreeNode::getRightChild() const {
    return right;
}

// Get data
ItemType TreeNode::getData() const {
    return data;
}

// Destructor to recursively delete child nodes
TreeNode::~TreeNode() {
    delete left;
    delete right;
}
