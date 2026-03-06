#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d inserted\n", value);
    }
}

// Pop operation
void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d deleted\n", stack[top]);
        top--;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    pop();
    pop();

    return 0;
}
