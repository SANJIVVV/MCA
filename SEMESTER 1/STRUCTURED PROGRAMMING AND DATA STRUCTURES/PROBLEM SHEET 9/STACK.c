#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(void)
{
    int x;
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        printf("Enter element: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("Element pushed\n");
    }
}

void pop(void)
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted element: %d\n", stack[top--]);
}

void display(void)
{
    int i;
    if (top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void peek(void)
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

int main(void)
{
    int choice;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
