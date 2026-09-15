#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, n;

    printf("Enter number or email: ");
    scanf("%s", s);

    if (strchr(s, '@') != NULL)
    {
        for (i = 0; s[i] != '@'; i++)
            printf("*");

        printf("%s", s + i);
    }
    else
    {
        n = strlen(s);

        for (i = 0; i < n - 4; i++)
            printf("*");

        for (i = n - 4; i < n; i++)
            printf("%c", s[i]);
    }

    return 0;
}