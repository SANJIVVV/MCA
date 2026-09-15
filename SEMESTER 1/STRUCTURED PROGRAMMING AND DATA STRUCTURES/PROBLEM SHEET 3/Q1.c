#include <stdio.h>

int main() {
    int n, a[100], i;
    int patterns = 0, largest = 0, increase;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n - 2; i++) {
        if(a[i] < a[i+1] && a[i+1] < a[i+2])
            patterns++;
    }

    for(i = 1; i < n; i++) {
        increase = a[i] - a[i-1];

        if(increase > largest)
            largest = increase;
    }

    printf("Degradation Patterns: %d\n", patterns);
    printf("Largest Increase: %d ms\n", largest);

    return 0;
}
