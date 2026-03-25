#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node for level order traversal
struct QNode {
    struct Node* node;
    int hd;
    struct QNode* next;
};

// Create tree node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Create queue node
struct QNode* createQNode(struct Node* node, int hd) {
    struct QNode* q = (struct QNode*)malloc(sizeof(struct QNode));
    q->node = node;
    q->hd = hd;
    q->next = NULL;
    return q;
}

// Enqueue
void enqueue(struct QNode** front, struct QNode** rear, struct Node* node, int hd) {
    struct QNode* temp = createQNode(node, hd);
    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

// Dequeue
struct QNode* dequeue(struct QNode** front, struct QNode** rear) {
    if (*front == NULL) return NULL;
    struct QNode* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    return temp;
}

// Vertical order (simple version using array)
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct QNode *front = NULL, *rear = NULL;

    // Range of HD (adjust if needed)
    int minHD = -100, maxHD = 100;
    int arr[201][100]; // store nodes
    int count[201] = {0};

    enqueue(&front, &rear, root, 0);

    while (front != NULL) {
        struct QNode* temp = dequeue(&front, &rear);
        struct Node* curr = temp->node;
        int hd = temp->hd;

        int index = hd - minHD;
        arr[index][count[index]++] = curr->data;

        if (curr->left)
            enqueue(&front, &rear, curr->left, hd - 1);
        if (curr->right)
            enqueue(&front, &rear, curr->right, hd + 1);

        free(temp);
    }

    // Print vertical order
    for (int i = 0; i <= maxHD - minHD; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
}

// Main
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    verticalOrder(root);

    return 0;
}
