#include <stdio.h>
#include <string.h>

int main() {
    int r, c;

    scanf("%d %d", &r, &c);

    char user[r][c][50];
    int found = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%s", user[i][j]);
        }
    }

    printf("Duplicate Usernames:\n");

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            int duplicate = 0;

            for (int k = 0; k < i; k++) {
                for (int l = 0; l < c; l++) {
                    if (strcmp(user[i][j], user[k][l]) == 0)
                        duplicate = 1;
                }
            }

            if (!duplicate) {
                int count = 0;

                for (int k = 0; k < r; k++) {
                    for (int l = 0; l < c; l++) {
                        if (strcmp(user[i][j], user[k][l]) == 0)
                            count++;
                    }
                }

                if (count > 1) {
                    printf("%s\n", user[i][j]);
                    found = 1;
                }
            }
        }
    }

    if (!found)
        printf("No Duplicates");

    return 0;
}