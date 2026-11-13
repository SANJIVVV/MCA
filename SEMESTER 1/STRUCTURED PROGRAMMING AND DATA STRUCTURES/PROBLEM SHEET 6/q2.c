#include <stdio.h>

int findHighest(int a, int b, int c) {
    int max = a;

    if (b > max)
        max = b;

    if (c > max)
        max = c;

    return max;
}

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    printf("Highest Server Load: %d", findHighest(a, b, c));

    return 0;
}