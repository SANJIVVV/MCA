#include <stdio.h>

int main() {
    int n, a[100], i;
    int current = 1, longest = 1;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i < n; i++) {

        if(a[i] < a[i-1]) {
            current++;
        } else {
            if(current > longest)
                longest = current;

            current = 1;
        }
    }

    if(current > longest)
        longest = current;

    printf("Longest Recovery Sequence: %d hours\n", longest);

    return 0;
}
