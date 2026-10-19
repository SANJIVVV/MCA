
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 20

struct Operation {
    int id;
    char name[30];
};

struct Operation stack[Max];
int top = -1;
int n, i, id;
char name[30];

void push() {
    if (top == Max - 1) {
        printf("Stack Overflow! Undo stack is full.\n");
    }
    else {
        printf("Enter Operation ID: ");
        scanf("%d", &id);

        printf("Enter Operation Name: ");
        scanf(" %29[^\n]", name);

        top++;
        stack[top].id = id;
        strcpy(stack[top].name, name);

        printf("Operation %d %s pushed into the stack.\n",
               stack[top].id, stack[top].name);
    }
}

void pop() {
    if (top == -1) {
        printf("No undo operation is available.\n");
    }
    else {
        printf("Undo operation: %d %s removed.\n",
               stack[top].id, stack[top].name);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("No undo operation is available.\n");
    }
    else {
        printf("Most recent operation: %d %s\n",
               stack[top].id, stack[top].name);
    }
}

void display() {
    if (top == -1) {
        printf("No undo operation is available.\n");
    }
    else {
        printf("Available undo operations:\n");

        for (i = top; i >= 0; i--) {
            printf("%d %s\n", stack[i].id, stack[i].name);
        }
    }
}

void search() {
    int found = 0;

    printf("Enter Operation ID to search: ");
    scanf("%d", &id);

    for (i = 0; i <= top; i++) {
        if (stack[i].id == id) {
            found = 1;
            printf("Operation ID %d found in the undo stack.\n", id);
            break;
        }
    }

    if (found == 0) {
        printf("Operation ID %d not found.\n", id);
    }
}

void menu() {
    printf("\n1.Push 2.Undo 3.Peek 4.Display 5.Search 6.End\n");
    printf("Enter your choice: ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            search();
            break;
        case 6:
            printf("Program ended.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
    }

    menu();
}

int main() {
    menu();
    return 0;
}

