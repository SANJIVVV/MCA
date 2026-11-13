#include <stdio.h>

int main() {
    int r, c;

    scanf("%d %d", &r, &c);

    int a[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int j = 0; j < c; j++) {
        int total = 0;

        for (int i = 0; i < r; i++) {
            total += a[i][j];
        }

        printf("Product %d: %d\n", j + 1, total);
    }

    return 0;
}