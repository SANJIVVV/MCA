#include <stdio.h>

int main() {
    char id[20], name[50];
    int units;
    float charge, fixed = 100, surcharge = 0, total;

    printf("Enter Consumer ID: ");
    scanf("%s", id);

    printf("Enter Consumer Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Units Consumed: ");
    scanf("%d", &units);

    if (units < 0) {
        printf("Invalid units!");
        return 0;
    }

    if (units <= 100)
        charge = units * 1.50;
    else if (units <= 300)
        charge = units * 2.50;
    else if (units <= 500)
        charge = units * 4.00;
    else
        charge = units * 6.00;

    total = charge + fixed;

    if (total > 2000) {
        surcharge = total * 0.05;
        total += surcharge;
    }

    printf("\nElectricity Bill\n");
    printf("-------------------------\n");
    printf("Consumer ID   : %s\n", id);
    printf("Consumer Name : %s\n", name);
    printf("Units         : %d\n", units);
    printf("Charge        : Rs. %.2f\n", charge);
    printf("Fixed Charge  : Rs. %.2f\n", fixed);
    printf("Surcharge     : Rs. %.2f\n", surcharge);
    printf("Total Bill    : Rs. %.2f\n", total);

    return 0;
}
