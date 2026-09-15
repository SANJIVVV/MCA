#include <stdio.h>

int main() {
    int n, a[100], i;
    int current = 1, longest = 1;
    int start = 0, bestStart = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i < n; i++) {

        if(a[i] > a[i-1]) {
            current++;
        } else {
            if(current > longest) {
                longest = current;
                bestStart = start;
            }

            current = 1;
            start = i;
        }
    }

    if(current > longest) {
        longest = current;
        bestStart = start;
    }

    printf("Longest Growth Period: %d days\n", longest);
    printf("Total Growth: %d\n",
           a[bestStart + longest - 1] - a[bestStart]);

    return 0;
}
