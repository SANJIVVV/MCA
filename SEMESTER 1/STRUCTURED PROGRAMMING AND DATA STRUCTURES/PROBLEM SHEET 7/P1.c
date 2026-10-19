
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max 20

int n,i;
char stack[Max][20];
char vehicles[20];
int top=-1;

void push(){
    printf("Enter the vehicle number: ");

    if(top == Max - 1){
        printf("Stack Overflow! Parking stack is full.\n");
    }
    else{
        scanf("%19s",vehicles);
        strcpy(stack[++top],vehicles);
        printf("Vehicle %s pushed into the stack\n",stack[top]);
    }
}

void pop(){
    if(top==-1){
        printf("Stack Underflow! No vehicle is present.\n");
    }
    else{
        printf("Vehicle %s removed from the stack.\n",stack[top--]);
    }
}

void peek(){
    if(top==-1){
        printf("Stack Underflow! No vehicle is present.\n");
    }
    else{
        printf("Top vehicle: %s\n",stack[top]);
    }
}

void display(){
    if(top==-1){
        printf("The stack is empty.\n");
    }
    else{
        printf("Vehicles currently parked:\n");
        for(i=top;i>=0;i--){
            printf("%s\n",stack[i]);
        }
    }
}

void search(){
    printf("Enter the vehicle number: ");
    scanf("%19s",vehicles);

    int found=0;

    for(i=0;i<=top;i++){
        if(strcmp(vehicles,stack[i])==0){
            found=1;
            printf("Vehicle %s is present in the parking stack.\n",vehicles);
            break;
        }
    }

    if(found==0){
        printf("Vehicle %s is not present in the parking stack.\n",vehicles);
    }
}

void menu(){
    printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Search 6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&n);

    switch(n){
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

int main(){
    menu();
    return 0;
}
