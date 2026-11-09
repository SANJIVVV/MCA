#include <stdio.h>

typedef struct
{
    int reg_no;
    char name[30];
    int marks[5];
} student;

void calculate(student s[])
{
    int total, i, j;
    float avg, percentage;
    char grade;

    for(i = 0; i < 2; i++)
    {
        total = 0;

        for(j = 0; j < 5; j++)
        {
            total = total + s[i].marks[j];
        }

        avg = total / 5.0;
        percentage = (total / 500.0) * 100;

        if(percentage >= 90)
            grade = 'O';
        else if(percentage >= 80)
            grade = 'P';
        else if(percentage >= 70)
            grade = 'A';
        else if(percentage >= 60)
            grade = 'B';
        else if(percentage >= 50)
            grade = 'C';
        else
            grade = 'F';

        printf("\nRegister Number: %d", s[i].reg_no);
        printf("\nName: %s", s[i].name);
        printf("\nTotal Marks: %d", total);
        printf("\nAverage: %.2f", avg);
        printf("\nPercentage: %.2f", percentage);
        printf("\nGrade: %c\n", grade);
    }
}

int main()
{
    student s[2];
    int i, j;

    for(i = 0; i < 2; i++)
    {
        printf("\nEnter Register Number: ");
        scanf("%d", &s[i].reg_no);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter 5 Subject Marks: ");

        for(j = 0; j < 5; j++)
        {
            scanf("%d", &s[i].marks[j]);
        }
    }

    calculate(s);

    return 0;
}
