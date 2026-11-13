#include<stdio.h>
int main()
{
    int arr[100], n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = 0, length = 0, longest = 0;
    for(i=0;i<n;i++)
    {
        if(arr[i] > 80)
        {
            length++;
            printf("\n%d %d", arr[i], length);
        }
        else
        {
            if(length >= 3)
            {
                count++;
                if(length > longest)
                {
                    longest = length;
                }
            }
            length = 0;
        }
    }
    printf("\nOverload Sequences: %d", count);
    printf("\nLongest Overload Duration: %d", longest);
    return 0;
}
