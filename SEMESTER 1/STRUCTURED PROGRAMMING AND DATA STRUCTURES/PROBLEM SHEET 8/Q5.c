#include<stdio.h>

typedef struct
{
    int emp_id;
    char salesperson_name[20];
    int monthly_sales;
}company;

void calculate(company c[])
{

    for(int i = 0; i < 2; i++)
    {
        int commission = 0;

        if(c[i].monthly_sales < 25000)
            commission = c[i].monthly_sales * 0.02;
        else if(25000 < c[i].monthly_sales > 50000)
            commission = c[i].monthly_sales * 0.05;
        else if(50000 < c[i].monthly_sales > 100000)
            commission = c[i].monthly_sales * 0.08;
        else if(c[i].monthly_sales > 100000)
            commission = c[i].monthly_sales * 0.10;
        else
            commission = 0;


        int total_earrnings = 0;

        total_earrnings = 15000 + commission;

        printf("\n------ COMMISSION DETAILS ------\n");
        printf("Employee ID       : %d\n", c[i].emp_id);
        printf("Salesperson Name  : %s\n", c[i].salesperson_name);
        printf("Monthly Sales     : %d\n", c[i].monthly_sales);
        printf("Commission Amount : %d\n", commission);
        printf("Total Earnings    : %d\n", total_earrnings);
    }
}

int main()
{ 
    company c[2];

    for(int i = 0; i < 2; i++)
    {
        printf("\nEnter Employee ID: ");
        scanf("%d", &c[i].emp_id);

        printf("Enter Salesperson Name: ");
        scanf("%s", c[i].salesperson_name);

        printf("Enter Monthly Sales: ");
        scanf("%d", &c[i].monthly_sales);
    }

    calculate(c);

}