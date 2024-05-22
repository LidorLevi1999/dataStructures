#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <vector>
using namespace std;

class BinaryTree {
private:
    TreeNode* root;
    // Helper function to get the height of the tree recursively
    static int getTreeHeightRecursively(TreeNode* node);
    // Helper function to build the tree recursively
    static TreeNode* buildTreeFromInPreOrder(vector<int> inOrder, vector<int> preOrder, int inStart, int inEnd, int& preIndex, int arraysLength);

public:
    // Constructor
    BinaryTree(const int& rootItem);

    // Constructor to build tree from inOrder and preOrder arrays
    BinaryTree(vector<int> inOrder, vector<int> preOrder, int arraysLength);

    // Destructor
    ~BinaryTree();

    // Get the root of the tree
    TreeNode* getRoot() const;

    // Get the height of the tree recursively
    int getTreeHeightRecursively() const;

    // Make the tree empty
    void makeEmpty();

    static int recursiveHeightCalc(vector<int> inOrder, vector<int> preOrder, int inStart, int inEnd, int &preIndex, int arraysLength);
};

#endif // BINARYTREE_H
