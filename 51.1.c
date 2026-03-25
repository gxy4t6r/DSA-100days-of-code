#include <stdio.h>
#include <stdlib.h>

// Structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert (for testing)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// LCA function
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If both values are smaller → go left
    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    // If both values are greater → go right
    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    // Otherwise, this is the LCA
    return root;
}

// Main
int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int n1 = 20, n2 = 40;

    struct Node* lca = LCA(root, n1, n2);

    if (lca != NULL)
        printf("LCA of %d and %d is %d", n1, n2, lca->data);
    else
        printf("LCA not found");

    return 0;
}
