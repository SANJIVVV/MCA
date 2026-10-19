
#include <stdio.h>
#include <string.h>
#define Max 100

char stack[Max];
char exp[Max];
int top = -1;
int i;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int main()
{
    int balanced = 1;

    printf("Enter an expression: ");
    scanf("%99s", exp);

    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                balanced = 0;
                printf("No matching opening bracket found for '%c'.\n", exp[i]);
                break;
            }

            char ch = pop();

            if ((exp[i] == ')' && ch != '(') ||
                (exp[i] == '}' && ch != '{') ||
                (exp[i] == ']' && ch != '['))
            {
                balanced = 0;
                printf("Mismatched brackets found.\n");
                break;
            }
        }
    }

    if (balanced == 1 && top == -1)
        printf("Balanced Expression\n");
    else if (balanced == 1)
        printf("Unbalanced Expression: Opening brackets remain in the stack.\n");
    else
        printf("Unbalanced Expression\n");

    return 0;
}
