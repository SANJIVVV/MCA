#include<stdio.h>
int main()
{
    int arr[100], n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int reversal = 0, direction = 0;
    for(i=0;i<n-1;i++)
    {
        if(arr[i] < arr[i+1])
        {
            if(direction == -1)
            {
                reversal++;
            }
            direction = 1;
        }
        else if(arr[i] > arr[i+1])
        {
            if(direction == 1)
            {
                reversal++;
            }
            direction = -1;
        }
    }
    printf("Trend reversal: %d", reversal);
    return 0;
}
