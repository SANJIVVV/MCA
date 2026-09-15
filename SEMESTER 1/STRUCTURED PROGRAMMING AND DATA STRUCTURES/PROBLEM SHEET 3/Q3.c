#include <stdio.h>

int main() {
    int n, a[100], i;
    int spikes = 0;
    int largest = 0, position = 0;
    int increase;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i < n; i++) {

        if(a[i] >= 1.5 * a[i-1]) {
            spikes++;

            increase = a[i] - a[i-1];

            if(increase > largest) {
                largest = increase;
                position = i + 1;
            }
        }
    }

    printf("Number of Spikes: %d\n", spikes);
    printf("Largest Spike: %d MB\n", largest);
    printf("Position: %d\n", position);

    return 0;
}
