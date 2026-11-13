#include <stdio.h>

int main() {
    int balance = 10000, amount;

    printf("Enter withdrawal amount: ");
    scanf("%d", &amount);

    if (amount <= 0)
        printf("Invalid amount");
    else if (amount > balance)
        printf("Insufficient balance");
    else if (amount % 100 != 0)
        printf("Enter amount in multiples of 100");
    else {
        balance -= amount;
        printf("Withdrawal successful\n");
        printf("Remaining Balance: %d", balance);
    }

    return 0;
}


