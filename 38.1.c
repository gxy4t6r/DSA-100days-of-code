#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;
    if (front == -1) front = rear = 0;
    else if (front == 0) front = MAX - 1;
    else front--;
    deque[front] = x;
}

void insertRear(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;
    if (front == -1) front = rear = 0;
    else if (rear == MAX - 1) rear = 0;
    else rear++;
    deque[rear] = x;
}

int deleteFront() {
    if (front == -1) return -1;
    int x = deque[front];
    if (front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
    return x;
}

int deleteRear() {
    if (front == -1) return -1;
    int x = deque[rear];
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = MAX - 1;
    else rear--;
    return x;
}

void display() {
    if (front == -1) return;
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}
