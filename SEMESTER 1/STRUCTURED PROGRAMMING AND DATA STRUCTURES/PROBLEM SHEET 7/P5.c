#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define Max 100

int stack[Max];
int top = -1;
char exp[Max];
int i, a, b;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    if (strlen(exp) == 0)
    {
        printf("Error: Empty expression.\n");
        return 0;
    }

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else if (exp[i] == '+' || exp[i] == '-' ||
                 exp[i] == '*' || exp[i] == '/')
        {
            if (top < 1)
            {
                printf("Error: Insufficient operands for operator '%c'.\n", exp[i]);
                return 0;
            }

            b = pop();
            a = pop();

            if (exp[i] == '+')
                push(a + b);
            else if (exp[i] == '-')
                push(a - b);
            else if (exp[i] == '*')
                push(a * b);
            else if (exp[i] == '/')
            {
                if (b == 0)
                {
                    printf("Error: Division by zero.\n");
                    return 0;
                }

                push(a / b);
            }
        }
        else
        {
            printf("Error: Invalid symbol '%c'.\n", exp[i]);
            return 0;
        }
    }

    if (top != 0)
    {
        printf("Error: Invalid postfix expression.\n");
        return 0;
    }

    printf("Final Result: %d\n", pop());

    return 0;
}
