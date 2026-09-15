#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[50];
    int i;

    printf("Enter username: ");
    scanf("%s", s);

    if (strlen(s) < 6 || strlen(s) > 15)
    {
        printf("Invalid Username\n");
        printf("Reason: Length should be 6 to 15");
    }
    else if (!isalpha(s[0]))
    {
        printf("Invalid Username\n");
        printf("Reason: First character should be alphabet");
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '_')
            {
                printf("Invalid Username\n");
                printf("Reason: Only alphabets, digits and _ are allowed");
                return 0;
            }
        }

        printf("Valid Username");
    }

    return 0;
}