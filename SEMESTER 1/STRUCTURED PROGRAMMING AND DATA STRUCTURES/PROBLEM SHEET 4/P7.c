#include <stdio.h>

int main()
{
    char a[20], b[20];
    int a1, a2, a3;
    int b1, b2, b3;

    printf("Enter current version: ");
    scanf("%s", a);

    printf("Enter new version: ");
    scanf("%s", b);

    sscanf(a, "%d.%d.%d", &a1, &a2, &a3);
    sscanf(b, "%d.%d.%d", &b1, &b2, &b3);

    if (b1 > a1)
        printf("New Version is NEWER");
    else if (b1 < a1)
        printf("New Version is OLDER");
    else if (b2 > a2)
        printf("New Version is NEWER");
    else if (b2 < a2)
        printf("New Version is OLDER");
    else if (b3 > a3)
        printf("New Version is NEWER");
    else if (b3 < a3)
        printf("New Version is OLDER");
    else
        printf("New Version is SAME");

    return 0;
}