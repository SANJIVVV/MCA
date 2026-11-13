#include <stdio.h>

int findEmployee(int id[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (id[i] == key)
            return i + 1;
    }

    return -1;
}

int main() {
    int n, key;

    scanf("%d", &n);

    int id[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &id[i]);
    }

    scanf("%d", &key);

    int pos = findEmployee(id, n, key);

    if (pos == -1)
        printf("Employee Not Found");
    else
        printf("First Occurrence: Position %d", pos);

    return 0;
}