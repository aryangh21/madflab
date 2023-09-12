#include <stdio.h>
#include <stdlib.h>
int count = 0;
int binary_search(int[], int, int, int);
int main()
{
    int arr[20], n, i, x, pos;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        count++;
        scanf("%d", &arr[i]);
        count++;
    }
    count++;
    printf("Enter element to be searched: ");
    scanf("%d", &x);
    pos = binary_search(arr, 0, n-1, x);
    if(pos==-1)
            printf("Element not found!");
    else
        printf("Element found at pos: %d", pos);
    printf("\nStep Count: %d", count);
    return 0;
}
int binary_search(int arr[], int start, int end, int x)
{
    count++;
    count++;
    if(start>end)
        return -1;
    else
    {
        int mid = (start+end)/2;
        count++;
        if(arr[mid]==x)
            return mid;
        count++;
        if(arr[mid]>x)
        {
            return binary_search(arr, start, mid-1, x);
            count++;
        }
        count++;
        return binary_search(arr, mid+1, end, x);
        count++;
    }
}
