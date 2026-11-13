#include<stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push()
{
    if(top == MAX - 1)
    {
        printf("\n STACK OVERFLOW");
    }else{
        int ele;
        printf("\n ENTER THE ELEMENT TO BE INSERTED: ");
        scanf("%d",&ele);
        top++;
        stack[top] = ele;
}
}


void pop()
{
    if(top == -1)
    {
        printf("\n STACK UNDERFLOW");
    }else{
        printf("\n THE REMOVED ELEMENT IS :%d",stack[top--]);
    }
}

void display()
{
    int i;
    for (i=0;i<=top;i++)
    {
        printf("%d",stack[i]);
    }
}


int main()
{
    int choice;

    printf("\n STACK OPERATIONS");
    printf("\n1.PUSH \n2.POP \n3.DISPLAY");
    while(1)
    {
        printf("\n ENTER THE CHOICE :");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("\n ENTER THE VALID CHOICE");
        }
    }
}
