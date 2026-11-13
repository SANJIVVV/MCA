#include <stdio.h>

int main() {
    int r, c, id;
    scanf("%d %d", &r, &c);

    int emp[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &emp[i][j]);
        }
    }

    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (emp[i][j] == id) {
                printf("Employee Found\n");
                printf("Team: %d\n", i + 1);
                printf("Position: %d\n", j + 1);
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
        printf("Employee Not Found\n");

    return 0;
}