#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        int i = 1;
        int newIndex;

        while (i < SIZE) {
            newIndex = (index + i * i) % SIZE;

            if (hashTable[newIndex] == -1) {
                hashTable[newIndex] = key;
                return;
            }
            i++;
        }

        printf("Table full\n");
    }
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d: %d\n", i, hashTable[i]);
}

int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    display();

    return 0;
}
