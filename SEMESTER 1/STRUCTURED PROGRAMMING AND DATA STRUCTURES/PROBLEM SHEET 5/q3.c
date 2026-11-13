#include <stdio.h>

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    int status[R][C];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &status[i][j]);
        }
    }

    for (int j = 0; j < C; j++) {
        int failures = 0;

        for (int i = 0; i < R; i++) {
            if (status[i][j] == 0) {
                failures++;
            }
        }

        printf("Time %d: %d failure", j + 1, failures);

        if (failures != 1)
            printf("s");

        printf("\n");
    }

    return 0;
}