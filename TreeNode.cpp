#include "TreeNode.h"

// Constructor
TreeNode::TreeNode(const int& item, TreeNode* leftNode, TreeNode* rightNode)
        : data(item), left(leftNode), right(rightNode) {}

// Get left child
TreeNode* TreeNode::getLeftChild() const {
    return left;
}

// Get right child
TreeNode* TreeNode::getRightChild() const {
    return right;
}

// Destructor to recursively delete child nodes
TreeNode::~TreeNode() {
    delete left;
    delete right;
}
