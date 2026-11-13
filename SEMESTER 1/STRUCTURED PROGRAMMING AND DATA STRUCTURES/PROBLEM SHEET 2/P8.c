#include<stdio.h>
int main()
{
    int arr[100], n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    float sum = 0, avg, diff = 0;
    int count = 0, position = 0;
    for(i=0;i<n-2;i++)
    {
        sum = arr[i] + arr[i+2];
        avg = sum / 2;
        diff = arr[i+1] - avg;
        if(diff > 50.0)
        {
            count++;
            position = i + 2;
            printf("\nAnomalies Detected: %d", count);
            printf("\nAnomaly Position: %d", position);
        }
    }
}
