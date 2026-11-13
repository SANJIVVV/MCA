#include<stdio.h>
int main()
{
    int arr[100], n, i;
    scanf("%d", &n);
    int count = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n-2;i++)
    {
        if(arr[i] < arr[i+1] && arr[i+1] < arr[i+2])
        {
            count++;
            printf("\n%d %d %d %d", arr[i], arr[i+1], arr[i+2], count);
        }
    }
    printf("\nDegradation Patterns: %d", count);
    return 0;
}
