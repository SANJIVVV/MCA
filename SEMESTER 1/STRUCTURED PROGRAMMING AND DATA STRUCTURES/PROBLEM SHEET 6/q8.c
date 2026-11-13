#include <stdio.h>

int longestIncreasing(int arr[], int n) {
    int maxLen = 1, currentLen = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            currentLen++;
        } else {
            currentLen = 1;
        }

        if (currentLen > maxLen)
            maxLen = currentLen;
    }

    return maxLen;
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Longest Increasing Run: %d", longestIncreasing(arr, n));

    return 0;
}
