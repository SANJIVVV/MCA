#include<stdio.h>
#include<string.h>

typedef struct 
{
    int vehicle_no;
    char vehicle_type[20];
    char customer_name[20];
    int no_of_rental_days;
}vehicles;


void calculate(vehicles v[])
{
    int R_amount = 0, total, discount, final_amount;

    for(int i = 0; i < 2; i++)
    {
        if(strcmp(v[i].vehicle_type, "Two-wheeler") == 0)
            R_amount = 500 * v[i].no_of_rental_days;

        else if(strcmp(v[i].vehicle_type, "Hatchback") == 0)
            R_amount = 1200 * v[i].no_of_rental_days;

        else if(strcmp(v[i].vehicle_type, "Sedan") == 0)
            R_amount = 1800 * v[i].no_of_rental_days;

        else if(strcmp(v[i].vehicle_type, "SUV") == 0)
            R_amount = 2500 * v[i].no_of_rental_days;

        else
        {
            printf("\nInvalid Vehicle Type!\n");
            continue;
        }

        total = R_amount + 200;

        if(v[i].no_of_rental_days > 7)
            discount = total * 0.10;
        else
            discount = 0;

        final_amount = total - discount;

        printf("\n------ RENTAL BILL ------\n");
        printf("Vehicle No       : %d\n", v[i].vehicle_no);
        printf("Vehicle Type     : %s\n", v[i].vehicle_type);
        printf("Customer Name    : %s\n", v[i].customer_name);
        printf("Rental Days      : %d\n", v[i].no_of_rental_days);
        printf("Rental Amount    : %d\n", R_amount);
        printf("Security Charge  : 200\n");
        printf("Total Amount     : %d\n", total);
        printf("Discount         : %d\n", discount);
        printf("Final Amount     : %d\n", final_amount);
    }
}




int main()
{
    vehicles v[2];

    for(int i = 0;i<2;i++)
    {
        printf("ENTER THE VEHICLE NO");
        scanf("%d",&v[i].vehicle_no);

        printf("ENTER THE VEHICLE TYPE");
        scanf("%s",v[i].vehicle_type);

        printf("ENTER THE CUSTOMER NAME");
        scanf("%s",v[i].customer_name);

        printf("ENTER NO OF RENTAL DAYS");
        scanf("%d",&v[i].no_of_rental_days);

    }

    calculate(v);
}
