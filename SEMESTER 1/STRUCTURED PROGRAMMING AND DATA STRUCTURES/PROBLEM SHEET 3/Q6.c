#include <stdio.h>

int main() {
    int n, a[100], i, j;
    int highest, second;
    int count = 0, rank;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    highest = a[0];

    for(i = 1; i < n; i++) {
        if(a[i] > highest)
            highest = a[i];
    }

    second = -1;

    for(i = 0; i < n; i++) {
        if(a[i] != highest && a[i] > second)
            second = a[i];
    }

    for(i = 0; i < n; i++) {
        if(a[i] == highest)
            count++;
    }

    printf("Highest Score: %d\n", highest);
    printf("Second Highest: %d\n", second);
    printf("Employees with Highest Score: %d\n", count);

    printf("Ranks:\n");

    for(i = 0; i < n; i++) {
        rank = 1;

        for(j = 0; j < n; j++) {
            if(a[j] > a[i])
                rank++;
        }

        printf("Employee %d: Rank %d\n", i + 1, rank);
    }

    return 0;
}
