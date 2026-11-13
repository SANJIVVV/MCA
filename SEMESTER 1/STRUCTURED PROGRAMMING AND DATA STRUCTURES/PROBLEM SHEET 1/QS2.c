
 #include <stdio.h>

int main() {
    int n, i, x;
    int sum = 0, actualSum = 0;
    int duplicate = 0, missing;

    printf("Enter N: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        actualSum += a[i];
    }

    for (i = 1; i <= n; i++)
        sum += i;

    for (i = 0; i < n; i++) {
        for (x = i + 1; x < n; x++) {
            if (a[i] == a[x]) {
                duplicate = a[i];
                break;
            }
        }
    }

    missing = sum - (actualSum - duplicate);

    printf("Duplicate = %d\n", duplicate);
    printf("Missing = %d\n", missing);

    return 0;
}
