#include <stdio.h>

int main() {
    int n, a[100], i;
    float avg, difference;
    int count = 0, position = -1;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i < n - 1; i++) {

        avg = (a[i-1] + a[i+1]) / 2.0;
        difference = a[i] - avg;

        if(difference < 0)
            difference = -difference;

        if(difference > 50) {
            count++;

            if(position == -1)
                position = i + 1;
        }
    }

    printf("Anomalies Detected: %d\n", count);

    if(position != -1)
        printf("Anomaly Position: %d\n", position);

    return 0;
}
