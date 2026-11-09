
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// INSERTION AT FRONT
void insertion_Front(void)
{
    struct node *newnode = malloc(sizeof(struct node));

    printf("\n ENTER THE DATA TO BE INSERTED : ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// INSERTION AT BACK
void insertion_Back(void)
{
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp;

    printf("\n ENTER THE DATA TO BE INSERTED : ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

// DELETION AT FRONT
void deletion_Front(void)
{
    struct node *temp;

    if(head == NULL)
    {
        printf("\n LIST IS EMPTY");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// DELETION AT BACK
void deletion_Back(void)
{
    struct node *temp;
    struct node *previous;

    if(head == NULL)
    {
        printf("\n LIST IS EMPTY");
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            previous = temp;
            temp = temp->next;
        }

        if(temp == head)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            previous->next = NULL;
            free(temp);
        }
    }
}

// SEARCH
void search(void)
{
    struct node *temp = head;
    int x, value = 0;

    printf("\n ENTER THE ELEMENT TO BE SEARCHED : ");
    scanf("%d", &x);

    while(temp != NULL)
    {
        if(temp->data == x)
        {
            value = 1;
            break;
        }

        temp = temp->next;
    }

    if(value == 1)
        printf("\n ELEMENT IS FOUND");
    else
        printf("\n ELEMENT IS NOT FOUND");
}

// DISPLAY
void display(void)
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("\n LIST IS EMPTY");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL");
    }
}

// MAIN FUNCTION
int main()
{
    int option;

    while(1)
    {
        printf("\n\n ------- LINKED LIST OPERATIONS ------- ");
        printf("\n 1. INSERTION AT FRONT");
        printf("\n 2. INSERTION AT BACK");
        printf("\n 3. DELETION AT FRONT");
        printf("\n 4. DELETION AT BACK");
        printf("\n 5. SEARCH");
        printf("\n 6. DISPLAY");
        printf("\n 7. EXIT");

        printf("\n ENTER THE OPTION : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                insertion_Front();
                break;

            case 2:
                insertion_Back();
                break;

            case 3:
                deletion_Front();
                break;

            case 4:
                deletion_Back();
                break;

            case 5:
                search();
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);

            default:
                printf("\n INVALID OPTION.....");
        }
    }

    return 0;
}
