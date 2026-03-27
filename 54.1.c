int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 1000;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;
    int level = 0;

    while (front < rear) {
        int size = rear - front;
        result[level] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            int index = leftToRight ? i : size - 1 - i;
            result[level][index] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        leftToRight = !leftToRight;
        level++;
    }

    *returnSize = level;
    return result;
}
