#include<stdio.h>
int main()
{
    int arr[100], n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = 1, max = 1, start = 0, maxstart = 0;
    int growth;
    for(i=0;i<n-1;i++)
    {
        if(arr[i+1] > arr[i])
        {
            count++;
            printf("%d %d %d", arr[i], arr[i+1], count);
        }
        else
        {
            if(count > max)
            {
                max = count;
                maxstart = start;
            }
            count = 1;
            start = i + 1;
        }
    }
    if(count > max)
    {
        max = count;
        maxstart = start;
    }
    growth = arr[maxstart + max - 1] - arr[maxstart];
    printf("Total growth: %d - %d = %d", arr[maxstart + max - 1] - arr[maxstart], growth);
    return 0;
}
