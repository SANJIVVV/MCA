#include <stdio.h>

int main() {
    int n, a[100], i;
    int count = 0, current = 0, longest = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {
        if(a[i] > 80) {
            current++;
        } else {
            if(current >= 3)
                count++;

            if(current > longest)
                longest = current;

            current = 0;
        }
    }

    if(current >= 3)
        count++;

    if(current > longest)
        longest = current;

    printf("Overload Sequences: %d\n", count);
    printf("Longest Overload Duration: %d intervals\n", longest);

    return 0;
}
