#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, at = 0, pos = -1;

    printf("Enter email: ");
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '@')
        {
            at++;
            pos = i;
        }
    }

    if (at != 1)
        printf("Invalid Email");
    else if (pos == 0 || pos == strlen(s) - 1)
        printf("Invalid Email");
    else if (s[pos + 1] == '.')
        printf("Invalid Email");
    else if (strstr(s + pos, "..") != NULL)
        printf("Invalid Email");
    else
        printf("Valid Email");

    return 0;
}