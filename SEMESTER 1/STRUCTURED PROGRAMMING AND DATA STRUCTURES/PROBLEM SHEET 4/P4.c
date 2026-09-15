#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i;
    int info = 0, warning = 0, error = 0;

    printf("Enter 4 log messages:\n");

    for (i = 0; i < 4; i++)
    {
        fgets(s, 100, stdin);

        if (strstr(s, "INFO") != NULL)
            info++;

        if (strstr(s, "WARNING") != NULL)
            warning++;

        if (strstr(s, "ERROR") != NULL)
            error++;
    }

    printf("INFO messages: %d\n", info);
    printf("WARNING messages: %d\n", warning);
    printf("ERROR messages: %d\n", error);

    if (error == 0)
        printf("System Status: NORMAL");
    else
        printf("System Status: ATTENTION REQUIRED");

    return 0;
}