#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int value) {
    if (size == MAX) return;
    int i = size;
    heap[i] = value;
    size++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

int extractMin() {
    if (size <= 0) return -1;
    if (size == 1) {
        size--;
        return heap[0];
    }
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
    return root;
}

void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(5);
    insert(30);
    insert(2);
    insert(8);

    display();

    printf("%d\n", extractMin());

    display();

    return 0;
}
