#include <stdio.h>

int countSuccessful(int login[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (login[i] == 1)
            count++;
    }

    return count;
}

int main() {
    int n;

    scanf("%d", &n);

    int login[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &login[i]);
    }

    printf("Successful Logins: %d", countSuccessful(login, n));

    return 0;
}