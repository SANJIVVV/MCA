#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[r][c];
    int max, server, time;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);

            if (i == 0 && j == 0) {
                max = a[i][j];
                server = 1;
                time = 1;
            }

            if (a[i][j] > max) {
                max = a[i][j];
                server = i + 1;
                time = j + 1;
            }
        }
    }

    printf("Highest CPU Usage: %d\n", max);
    printf("Server: %d\n", server);
    printf("Time Interval: %d\n", time);

    return 0;
}