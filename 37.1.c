#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = -1;

void insert(int value) {
    if (size == MAX - 1) return;
    size++;
    pq[size] = value;
}

int getMaxIndex() {
    int max = pq[0];
    int index = 0;
    for (int i = 1; i <= size; i++) {
        if (pq[i] > max) {
            max = pq[i];
            index = i;
        }
    }
    return index;
}

int delete() {
    if (size == -1) return -1;
    int index = getMaxIndex();
    int item = pq[index];
    for (int i = index; i < size; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    return item;
}

void display() {
    for (int i = 0; i <= size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(30);
    insert(20);
    insert(50);

    display();

    printf("%d\n", delete());

    display();

    return 0;
}
