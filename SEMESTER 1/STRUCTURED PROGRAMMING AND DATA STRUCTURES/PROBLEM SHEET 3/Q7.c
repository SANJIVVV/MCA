#include <stdio.h>

int main() {
    int n, a[100], i;
    int current = 0, longest = 0;
    int alerts = 0, first = -1;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {

        if(a[i] >= 5) {
            current++;
        } else {
            if(current >= 3) {
                alerts++;

                if(first == -1)
                    first = i - current + 1;

                if(current > longest)
                    longest = current;
            }

            current = 0;
        }
    }

    if(current >= 3) {
        alerts++;

        if(first == -1)
            first = n - current;

        if(current > longest)
            longest = current;
    }

    printf("Security Alerts: %d\n", alerts);
    printf("Longest Suspicious Sequence: %d\n", longest);
    printf("First Alert Position: %d\n", first + 1);

    return 0;
}
