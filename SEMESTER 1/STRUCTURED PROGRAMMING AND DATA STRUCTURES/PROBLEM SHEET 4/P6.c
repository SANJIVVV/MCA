#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[500];
    char word[5][20] = {
        "malware",
        "phishing",
        "ransomware",
        "attack",
        "virus"
    };

    int i, j, k, found;
    int count = 0;

    printf("Enter message: ");
    fgets(s, 500, stdin);

    for (i = 0; i < 5; i++)
    {
        found = 0;

        for (j = 0; s[j] != '\0'; j++)
        {
            k = 0;

            while (word[i][k] != '\0' &&
                   s[j + k] != '\0' &&
                   tolower(s[j + k]) == tolower(word[i][k]))
            {
                k++;
            }

            if (word[i][k] == '\0')
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            printf("Found: %s\n", word[i]);
            count++;
        }
    }

    printf("Total: %d\n", count);

    if (count == 0)
        printf("SAFE");
    else if (count <= 2)
        printf("SUSPICIOUS");
    else
        printf("HIGH RISK");

    return 0;
}