
#include<stdio.h>

typedef struct {
    int patient_id;
    char patient_name[20];
    int no_of_days;
    float cons_fee;
    float medical_charg;
    float lab_charg;
} patient;

void calculate(patient p[])
{
    float total_exp = 0, f_total = 0;
    float discount = 0, final_am;

    for(int i = 0; i < 5; i++)
    {
        total_exp = (p[i].cons_fee * p[i].no_of_days)
                    + p[i].medical_charg
                    + p[i].lab_charg;

        printf("\nPATIENT ID : %d", p[i].patient_id);
        printf("\nPATIENT NAME : %s", p[i].patient_name);
        printf("\nNO OF DAYS : %d", p[i].no_of_days);
        printf("\nCONSULTATION FEE : %.2f", p[i].cons_fee);
        printf("\nMEDICAL CHARGE : %.2f", p[i].medical_charg);
        printf("\nLAB CHARGE : %.2f", p[i].lab_charg);
        printf("\nPATIENT TOTAL : %.2f\n", total_exp);

        f_total += total_exp;
    }

    if(f_total > 10000)
    {
        discount = f_total * 0.1;
    }

    final_am = f_total - discount;

    printf("\n----------------------------");
    printf("\nGRAND TOTAL : %.2f", f_total);
    printf("\nDISCOUNT : %.2f", discount);
    printf("\nFINAL AMOUNT : %.2f", final_am);

}

int main()
{
    patient p[5];

    for(int i = 0; i < 5; i++)
    {
        printf("\nENTER THE PATIENT ID: ");
        scanf("%d", &p[i].patient_id);

        printf("ENTER THE PATIENT NAME: ");
        scanf("%19s", p[i].patient_name);

        printf("ENTER NO OF DAYS: ");
        scanf("%d", &p[i].no_of_days);

        printf("ENTER THE CONS FEE: ");
        scanf("%f", &p[i].cons_fee);

        printf("ENTER THE MEDICAL CHARGE: ");
        scanf("%f", &p[i].medical_charg);

        printf("ENTER THE LAB CHARGE: ");
        scanf("%f", &p[i].lab_charg);
    }

    calculate(p);

    return 0;
}
