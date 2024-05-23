#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(const int& item, TreeNode* leftNode = nullptr, TreeNode* rightNode = nullptr);

    // Assign left child
    void assignLeft(TreeNode* leftNode);

    // Assign right child
    void assignRight(TreeNode* rightNode);

    // Get left child
    TreeNode* getLeftChild() const;

    // Get right child
    TreeNode* getRightChild() const;

    // Get data
    int getData() const;

    // Destructor to recursively delete child nodes
    ~TreeNode();
};

#endif // TREENODE_H
