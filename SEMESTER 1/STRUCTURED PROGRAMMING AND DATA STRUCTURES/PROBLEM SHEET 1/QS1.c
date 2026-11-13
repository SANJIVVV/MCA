#include <stdio.h>

int main() {
    int n, d, a, b;

    for (n = 10; n <= 99; n++) {
        for (d = 10; d <= 99; d++) {
            if (n >= d) continue;

            a = n / 10;
            b = n % 10;

            int c = d / 10;
            int e = d % 10;

            if (b == c && b != 0 && n * e == d * a)
                printf("%d/%d = %d/%d\n", n, d, a, e);

            if (a == e && a != 0 && n * c == d * b)
                printf("%d/%d = %d/%d\n", n, d, b, c);
        }
    }

    return 0;
}
