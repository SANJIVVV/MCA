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

    for (int i = 0; i < r; i++) {
        int highest = a[i][0];
        int lowest = a[i][0];
        int count = 0;

        for (int j = 0; j < c; j++) {
            if (a[i][j] > highest)
                highest = a[i][j];

            if (a[i][j] < lowest)
                lowest = a[i][j];

            if (a[i][j] > 80)
                count++;
        }

        printf("Department %d\n", i + 1);
        printf("Highest: %d\n", highest);
        printf("Lowest: %d\n", lowest);
        printf("Above 80: %d\n", count);
    }

    return 0;
}