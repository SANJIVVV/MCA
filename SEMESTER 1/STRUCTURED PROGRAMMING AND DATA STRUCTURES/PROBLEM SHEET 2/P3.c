#include<stdio.h>
int main()
{
    int n, arr[100], i, count = 0;
    int largest = 0, position = 0, spike;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        if(arr[i+1] >= arr[i])
        {
            spike = arr[i+1] - arr[i];
            if(spike >= 50)
            {
                printf("\n%d -> %d", arr[i], arr[i+1]);
                count++;
            }
            if(spike > largest)
            {
                largest = spike;
                position = i + 2;
            }
        }
    }
    printf("\nNumber of spikes: %d", count);
    printf("\nLargest spike: %d", largest);
    printf("\nPosition: %d", position);
    return 0;
}
