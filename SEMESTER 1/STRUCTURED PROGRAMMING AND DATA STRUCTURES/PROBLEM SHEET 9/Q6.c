#include <stdio.h>
#include <string.h>

typedef struct
{
    int ticket_no;
    char passenger_name[20];
    char source[20];
    char destination[20];
    int distance;
    char passenger_category[20];
} transport;

void calculate(transport t[])
{
    for (int i = 0; i < 2; i++)
    {
        float basic_fare = t[i].distance * 2;
        float discount = 0;

        if (strcmp(t[i].passenger_category, "Child") == 0)
            discount = basic_fare * 0.50;
        else if (strcmp(t[i].passenger_category, "Senior") == 0)
            discount = basic_fare * 0.30;

        float final_fare = basic_fare - discount;

        printf("\n------ PASSENGER FARE DETAILS ------\n");
        printf("Ticket Number     : %d\n", t[i].ticket_no);
        printf("Passenger Name    : %s\n", t[i].passenger_name);
        printf("Source            : %s\n", t[i].source);
        printf("Destination       : %s\n", t[i].destination);
        printf("Distance (km)     : %d\n", t[i].distance);
        printf("Passenger Category: %s\n", t[i].passenger_category);
        printf("Basic Fare        : Rs. %.2f\n", basic_fare);
        printf("Discount          : Rs. %.2f\n", discount);
        printf("Final Fare        : Rs. %.2f\n", final_fare);
    }
}

int main()
{
    transport t[2];

    for (int i = 0; i < 2; i++)
    {
        printf("\nEnter Ticket Number: ");
        scanf("%d", &t[i].ticket_no);

        printf("Enter Passenger Name: ");
        scanf("%19s", t[i].passenger_name);

        printf("Enter Source: ");
        scanf("%19s", t[i].source);

        printf("Enter Destination: ");
        scanf("%19s", t[i].destination);

        printf("Enter Distance (in km): ");
        scanf("%d", &t[i].distance);

        printf("Enter Passenger Category (Child/Senior/Regular): ");
        scanf("%19s", t[i].passenger_category);
    }

    calculate(t);
    return 0;
}
