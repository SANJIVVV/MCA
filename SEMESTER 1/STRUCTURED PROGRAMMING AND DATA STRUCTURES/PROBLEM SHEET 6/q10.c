#include <stdio.h>

int rowTotal(int load[][10], int rows, int cols, int row) {
    int total = 0;

    for (int j = 0; j < cols; j++) {
        total += load[row - 1][j];
    }

    return total;
}

int highestRow(int load[][10], int rows, int cols) {
    int maxRow = 0, maxTotal = 0;

    for (int i = 0; i < rows; i++) {
        int total = 0;

        for (int j = 0; j < cols; j++) {
            total += load[i][j];
        }

        if (total > maxTotal) {
            maxTotal = total;
            maxRow = i + 1;
        }
    }

    return maxRow;
}

int main() {
    int rows, cols, row;

    scanf("%d %d", &rows, &cols);

    int load[10][10];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &load[i][j]);
        }
    }

    scanf("%d", &row);

    printf("Team %d Total Load: %d\n", row,
           rowTotal(load, rows, cols, row));

    printf("Highest Load Team: Team %d",
           highestRow(load, rows, cols));

    return 0;
}