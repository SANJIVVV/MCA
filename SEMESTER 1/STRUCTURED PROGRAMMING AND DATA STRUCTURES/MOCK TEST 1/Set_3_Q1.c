#include <stdio.h>
#include <string.h>

void rotate(char arr[][20], int n, int k) {
    char temp[20];

    for (int r = 0; r < k; r++) {
        strcpy(temp, arr[n - 1]);
        for (int i = n - 1; i > 0; i--) {
            strcpy(arr[i], arr[i - 1]);
        }
        strcpy(arr[0], temp);
    }
}

int main() {
    int n, k;
    printf("Enter the No of Bank Accounts :");
    scanf("%d", &n);

    char accounts[n][20], original[n][20];

    for (int i = 0; i < n; i++) {
        scanf("%s", accounts[i]);
        strcpy(original[i], accounts[i]);
    }

    printf("Enter the K element :");
    scanf("%d", &k);

  k%= n;
    rotate(accounts, n, k);

    printf("Rearranged Element\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", accounts[i]);

    printf("Original List\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", original[i]);

}
