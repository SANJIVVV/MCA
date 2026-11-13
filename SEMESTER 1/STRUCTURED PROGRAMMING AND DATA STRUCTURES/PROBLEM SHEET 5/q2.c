#include <stdio.h>

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    int tickets[R][C];
    int maxTotal = 0, dept = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &tickets[i][j]);
        }
    }

    for (int i = 0; i < R; i++) {
        int total = 0;

        for (int j = 0; j < C; j++) {
            total += tickets[i][j];
        }

        if (total > maxTotal) {
            maxTotal = total;
            dept = i + 1;
        }
    }

    printf("Department %d\n", dept);
    printf("Total Tickets: %d\n", maxTotal);

    return 0;
}