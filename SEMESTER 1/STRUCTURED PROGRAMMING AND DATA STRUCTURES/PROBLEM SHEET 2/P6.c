#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    int emp[100], i, j;
    printf("Enter score: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &emp[i]);
    }
    int max = emp[0], second = emp[0], count = 0;
    for(i=1;i<n;i++)
    {
        if(emp[i] > max)
        {
            max = emp[i];

        }
    }
    for(i=0;i<n;i++)
    {
        if(emp[i] == max)
        {
            count++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(emp[i] > second && emp[i] != max)
        {
            second = emp[i];
        }
    }
    printf("Highest score: %d", max);
    printf("\nSecond highest: %d", second);
    printf("\nCount: %d", count);
    printf("\nRanks:");
    int rank;
    for(i=0;i<n;i++)
    {
        rank = 1;
        for(j=0;j<n;j++)
        {
            if(emp[j] > emp[i])
            {
                rank++;
            }
        }
        printf("\nEmployee %d: Rank %d", i+1, rank);
    }
    return 0;
}
