#include <stdio.h>
#include <string.h>
#include <ctype.h>

int searchString(char list[][20], int n, char key[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i], key) == 0) {
            return i;
        }
    }
}

int main() {
    int n;
    char list[50][20];
    char key[20];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter %d strings :\n", n);
    for (int i = 0; i < n; i++) {
            scanf("%s", list[i]);
        }


    printf("Enter string to search: ");
    scanf("%s", key);


    int index = searchString(list, n, key);

    if (index != -1) {
        printf("String found at position %d.\n", index);
    } else {
        printf("String not found.\n");
    }
}

