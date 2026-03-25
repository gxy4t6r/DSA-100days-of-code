#include <stdio.h>
#include <stdlib.h>

// Structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Search function
struct Node* search(struct Node* root, int key) {
    // Base case: root is NULL or key found
    if (root == NULL || root->data == key) {
        return root;
    }

    // If key is smaller → search left
    if (key < root->data) {
        return search(root->left, key);
    }

    // If key is greater → search right
    return search(root->right, key);
}

// Helper to create node
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

// Main
int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    int key = 40;
    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Element found: %d", result->data);
    else
        printf("Element not found");

    return 0;
}
