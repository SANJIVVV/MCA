#include<stdio.h>
int main()
{
    int arr[100], n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int diff = 0, unstable_count = 0, stable_count = 1, longest_stable_count = 1;
    float change, largest_change = 0;
    for(i=0;i<n-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            diff = arr[i] - arr[i+1];
        }
        else
        {
            diff = arr[i+1] - arr[i];
        }
        change = ((float)(diff) / arr[i]) * 100;
        printf("\n%d -> %d %.2f ", arr[i], arr[i+1], change);
        if(change > 30)
        {
            printf("Unstable");
            unstable_count++;
            stable_count = 1;
        }
        else
        {
            printf("Stable");
            stable_count++;
            if(stable_count > longest_stable_count)
            {
                longest_stable_count = stable_count;
            }
        }
        if(change > largest_change)
        {
            largest_change = change;
        }
    }
    printf("\nUnstable Deployments: %d", unstable_count);
    printf("\nLongest Stable Sequence: %d", stable_count);
    printf("\nLargest Percentage Change: %.2f", largest_change);
    return 0;
}
