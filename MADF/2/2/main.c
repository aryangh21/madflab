#include<stdio.h>
#include<stdlib.h>
void MaxMin(int, int, int*, int*);
int arr[10];
int main()
{
    int i, n, max, min;
    printf("Enter no. of terms: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d", &arr[i]);

    }
    MaxMin(1, n, &max, &min);
    printf("Maximum Value: %d", max);
    printf("\nMinimum Value: %d", min);
    return 0;
}
void MaxMin(int i, int j, int *max, int *min)
{
    int mid, max1, min1;
    if(i==j)
    {
        *min = arr[i];
        *max = arr[i];
    }
    else if(i==j-1)
    {
        if(arr[i]>arr[j])
        {
            *max = arr[i];
            *min = arr[j];
        }
        else
        {
            *max = arr[j];
            *min = arr[i];
        }
    }
    else
    {
        mid = (i+j)/2;
        MaxMin(i, mid, max, min);
        MaxMin(mid+1, j, &max1, &min1);
        if(*max<max1)
            *max = max1;
        if(*min>min1)
            *min = min1;
    }
}
