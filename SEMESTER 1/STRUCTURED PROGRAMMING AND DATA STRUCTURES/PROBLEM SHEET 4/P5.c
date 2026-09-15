#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[500], key[50];
    int i, j, found, count = 0;

    printf("Enter text: ");
    fgets(text, 500, stdin);

    printf("Enter keyword: ");
    scanf("%s", key);

    for (i = 0; text[i] != '\0'; i++)
    {
        found = 1;

        for (j = 0; key[j] != '\0'; j++)
        {
            if (tolower(text[i + j]) != tolower(key[j]))
            {
                found = 0;
                break;
            }
        }

        if (found)
        {
            printf("Position: %d\n", i);
            count++;
        }
    }

    printf("Occurrences: %d", count);

    return 0;
}