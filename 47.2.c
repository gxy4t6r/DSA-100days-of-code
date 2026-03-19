#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
