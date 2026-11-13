#include <stdio.h>

int main() {
    int r, c, emp;

    scanf("%d %d", &r, &c);

    int a[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("ENTER THE NUMBER :");
    scanf("%d", &emp);

    int count = 0;

    for (int j = 0; j < c; j++) {
        if (a[emp - 1][j] == 1)
            count++;
    }

    printf("Applications Accessible: %d", count);

    return 0;
}
