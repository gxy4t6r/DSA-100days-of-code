#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(struct TreeNode* root, int index, int total) {
    if (!root) return true;
    if (index >= total) return false;
    return isComplete(root->left, 2 * index + 1, total) &&
           isComplete(root->right, 2 * index + 2, total);
}

bool isHeap(struct TreeNode* root) {
    if (!root->left && !root->right) return true;
    
    if (!root->right)
        return root->val <= root->left->val && isHeap(root->left);

    if (root->val <= root->left->val &&
        root->val <= root->right->val)
        return isHeap(root->left) && isHeap(root->right);

    return false;
}

bool isMinHeap(struct TreeNode* root) {
    int total = countNodes(root);
    return isComplete(root, 0, total) && isHeap(root);
}
