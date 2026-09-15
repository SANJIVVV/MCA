#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[500];
    char word[100][50];
    int count[100] = {0};

    int i, j, k;
    int n = 0;
    int unique = 0;
    int longest = 0, shortest = 100;
    int max = 0, maxpos = 0;

    printf("Enter paragraph:\n");
    fgets(s, 500, stdin);

    i = 0;

    while (s[i] != '\0')
    {
        while (s[i] == ' ' || s[i] == '\n')
            i++;

        if (s[i] == '\0')
            break;

        j = 0;

        while (s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
        {
            word[n][j] = tolower(s[i]);
            i++;
            j++;
        }

        word[n][j] = '\0';
        n++;
    }

    for (i = 0; i < n; i++)
    {
        count[i] = 1;

        for (j = 0; j < i; j++)
        {
            if (strcmp(word[i], word[j]) == 0)
            {
                count[j]++;
                count[i] = 0;
                break;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (strlen(word[i]) > longest)
            longest = strlen(word[i]);

        if (strlen(word[i]) < shortest)
            shortest = strlen(word[i]);

        if (count[i] > 0)
            unique++;

        if (count[i] > max)
        {
            max = count[i];
            maxpos = i;
        }
    }

    printf("\nTEXT ANALYTICS REPORT\n");
    printf("---------------------\n");

    printf("Total Characters : %d\n", strlen(s));
    printf("Total Words : %d\n", n);

    for (i = 0; i < n; i++)
    {
        if (strlen(word[i]) == longest)
        {
            printf("Longest Word : %s\n", word[i]);
            break;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (strlen(word[i]) == shortest)
        {
            printf("Shortest Word : %s\n", word[i]);
            break;
        }
    }

    printf("Unique Words : %d\n", unique);

    printf("Repeated Words : ");

    for (i = 0; i < n; i++)
    {
        if (count[i] > 1)
            printf("%s ", word[i]);
    }

    printf("\nMost Frequent Word : %s\n", word[maxpos]);
    printf("Frequency : %d", max);

    return 0;
}