#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node* next;
} Node;

Node* insertSorted(Node* head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data < value)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

void bucketSort(float arr[], int n) {
    Node** buckets = (Node**)malloc(n * sizeof(Node*));

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        buckets[idx] = insertSorted(buckets[idx], arr[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }

    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(buckets);
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = 6;

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}
