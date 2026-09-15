#include <stdio.h>

int main() {
    int n, a[100], i;
    int previousTrend = 0;
    int currentTrend;
    int reversals = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i < n; i++) {

        if(a[i] > a[i-1])
            currentTrend = 1;
        else if(a[i] < a[i-1])
            currentTrend = -1;
        else
            continue;

        if(previousTrend != 0 && currentTrend != previousTrend)
            reversals++;

        previousTrend = currentTrend;
    }

    printf("Trend Reversals: %d\n", reversals);

    return 0;
}
