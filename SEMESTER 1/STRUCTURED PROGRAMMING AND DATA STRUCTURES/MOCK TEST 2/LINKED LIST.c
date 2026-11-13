#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
    printf("Inserted\n");
}

void display()
{
    struct node *temp = head;

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;

    while (1) {
        printf("\n1.Insert \n2.Display\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
