#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max 20

int n,i;
char stack[Max][100];
char link[100];
int top=-1;

void push(){
    if(top==Max-1){
        printf("Stack Overflow! Browsing history is full.\n");
    }
    else{
        printf("Enter the URL: ");
        scanf("%99s",link);
        strcpy(stack[++top],link);
        printf("URL %s visited and pushed into the stack.\n",stack[top]);
    }
}

void pop(){
    if(top==-1){
        printf("No back operation is possible. Browsing history is empty.\n");
    }
    else{
        printf("Back operation: %s removed.\n",stack[top--]);
    }
}

void peek(){
    if(top==-1){
        printf("No current page available.\n");
    }
    else{
        printf("Current page: %s\n",stack[top]);
    }
}

void display(){
    if(top==-1){
        printf("Browsing history is empty.\n");
    }
    else{
        printf("Browsing history:\n");
        for(i=top;i>=0;i--){
            printf("%s\n",stack[i]);
        }
    }
}

void search(){
    printf("Enter the URL to search: ");
    scanf("%99s",link);

    int found=0;

    for(i=0;i<=top;i++){
        if(strcmp(link,stack[i])==0){
            found=1;
            printf("URL %s is present in the browsing history.\n",link);
            break;
        }
    }

    if(found==0){
        printf("URL %s is not present in the browsing history.\n",link);
    }
}

void menu(){
    printf("\n1.Push 2.Back 3.Peek 4.Display 5.Search 6.End\n");
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
}
