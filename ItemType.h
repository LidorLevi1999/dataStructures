#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include "TreeNode.h"
#include <cstddef>  // For size_t

class ItemType {

public:
    TreeNode* node;
    int leftHeight;
    int rightHeight;
    int line;

    ItemType(TreeNode* n, int lh, int rh, int ln)
            : node(n), leftHeight(lh), rightHeight(rh), line(ln) {}
};

#endif // ITEMTYPE_H
