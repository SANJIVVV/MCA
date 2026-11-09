
#include <stdio.h>

typedef struct
{
    int product_id;
    char product_name[30];
    int quantity;
    float price;
} product;

void calculate(product p[])
{
    int i;
    float cost, total = 0, discount = 0;
    float discounted_amount, gst, final_amount;

    for(i = 0; i < 5; i++)
    {
        cost = p[i].quantity * p[i].price;
        total = total + cost;

        printf("\nProduct ID: %d", p[i].product_id);
        printf("\nProduct Name: %s", p[i].product_name);
        printf("\nQuantity: %d", p[i].quantity);
        printf("\nUnit Price: %.2f", p[i].price);
        printf("\nProduct Cost: %.2f\n", cost);
    }

    if(total > 5000)
        discount = total * 0.10;

    discounted_amount = total - discount;

    gst = discounted_amount * 0.05;

    final_amount = discounted_amount + gst;

    printf("\nTotal Amount: %.2f", total);
    printf("\nDiscount: %.2f", discount);
    printf("\nDiscounted Amount: %.2f", discounted_amount);
    printf("\nGST (5%%): %.2f", gst);
    printf("\nFinal Amount: %.2f", final_amount);
}

int main()
{
    product p[5];
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("\nEnter Product ID: ");
        scanf("%d", &p[i].product_id);

        printf("Enter Product Name: ");
        scanf("%s", p[i].product_name);

        printf("Enter Quantity: ");
        scanf("%d", &p[i].quantity);

        printf("Enter Unit Price: ");
        scanf("%f", &p[i].price);
    }

    calculate(p);

    return 0;
}
