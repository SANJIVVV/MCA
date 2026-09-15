#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[100];
    int i;
    int u = 0, l = 0, d = 0, sp = 0;

    printf("Enter password: ");
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (isupper(s[i]))
            u = 1;
        else if (islower(s[i]))
            l = 1;
        else if (isdigit(s[i]))
            d = 1;
        else
            sp = 1;
    }

    if (strlen(s) < 8)
    {
        printf("Weak Password\n");
        printf("Missing: Minimum 8 characters");
    }
    else if (u && l && d && sp)
    {
        printf("Strong Password");
    }
    else
    {
        printf("Moderate Password\n");
        printf("Missing: ");

        if (u == 0)
            printf("Uppercase ");

        if (l == 0)
            printf("Lowercase ");

        if (d == 0)
            printf("Digit ");

        if (sp == 0)
            printf("Special Character");
    }

    return 0;
}