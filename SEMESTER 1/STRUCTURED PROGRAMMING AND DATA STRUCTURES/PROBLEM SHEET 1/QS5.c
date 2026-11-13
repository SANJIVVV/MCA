 #include <stdio.h>

int main() {
    float price, total, discount = 0;
    int quantity;

    printf("Enter item price: ");
    scanf("%f", &price);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    total = price * quantity;

    if (total >= 5000)
        discount = total * 0.10;
    else if (total >= 2000)
        discount = total * 0.05;

    printf("\nSubtotal: %.2f", total);
    printf("\nDiscount: %.2f", discount);
    printf("\nFinal Bill: %.2f", total - discount);

    return 0;
}
