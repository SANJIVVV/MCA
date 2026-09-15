#include <stdio.h>

int main() {
    int n, a[100], i;
    int unstable = 0;
    int current = 1, longest = 1;
    float change, largest = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i < n; i++) {

        change = ((float)(a[i] - a[i-1]) / a[i-1]) * 100;

        if(change < 0)
            change = -change;

        if(change > largest)
            largest = change;

        if(change > 30) {
            unstable++;
            current = 1;
        } else {
            current++;

            if(current > longest)
                longest = current;
        }
    }

    printf("Unstable Deployments: %d\n", unstable);
    printf("Longest Stable Sequence: %d\n", longest);
    printf("Largest Percentage Change: %.2f%%\n", largest);

    return 0;
}
