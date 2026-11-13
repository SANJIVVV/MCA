#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    int mainSum = 0, secSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        mainSum += a[i][i];
        secSum += a[i][n - 1 - i];
    }

    printf("Main Diagonal Sum: %d\n", mainSum);
    printf("Secondary Diagonal Sum: %d\n", secSum);
    printf("Difference: %d\n", mainSum - secSum);

    return 0;
}