#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    queue[++rear] = x;
}

int dequeue() {
    if (front > rear) return -1;
    return queue[front++];
}

void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void reverseQueue() {
    while (front <= rear)
        push(dequeue());

    while (top != -1)
        enqueue(pop());
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    reverseQueue();

    display();

    return 0;
}
