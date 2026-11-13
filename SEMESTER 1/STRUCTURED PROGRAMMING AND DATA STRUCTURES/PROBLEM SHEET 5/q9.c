#include <stdio.h>
#include <string.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    char names[r][c][50];
    char search[50];
    int found = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%s", names[i][j]);
        }
    }

    scanf("%s", search);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (strcmp(names[i][j], search) == 0) {
                printf("FOUND\n");
                printf("Row: %d\n", i + 1);
                printf("Column: %d\n", j + 1);
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
        printf("NOT FOUND");

    return 0;
}