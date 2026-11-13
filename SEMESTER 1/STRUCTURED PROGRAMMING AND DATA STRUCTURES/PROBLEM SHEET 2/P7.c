#include<stdio.h>
int main()
{
    int arr[100], n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = 0, alert = 0, longest = 0, position = 0;
    for(i=0;i<n;i++)
    {
        if(arr[i] >=5)
        {
            count++;
            printf("\n%d %d ", arr[i], count);
        }
        else
        {
            if(count >= 3)
            {
                alert++;
                if(count > longest)
                {
                    longest = count;
                }
                if(position == 0)
                {
                    position = i - count + 1;
                }
            }
            count = 0;
        }
    }
    printf("\nSecurity Alerts: %d", alert);
    printf("\nLongest suspicious sequence: %d", longest);
    printf("\nFirst alert position: %d", position);
    return 0;
}
