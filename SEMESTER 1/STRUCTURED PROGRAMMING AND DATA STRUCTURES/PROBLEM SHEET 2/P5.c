#include<stdio.h>
int main()
{
    int arr[100], n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = 1, max = 1;
    for(i=0;i<n-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            count++;
            printf("\n%d %d %d", arr[i], arr[i+1], count);
        }
        else
        {
            if(count > max)
            {
                max = count;
            }
            count = 1;
        }
    }
    if(count > max)
    {
        max = count;
    }
    printf("\nLongest recovery sequence: %d", max);
    return 0;
}

