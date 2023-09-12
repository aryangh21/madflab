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
        printf("%d found at pos: %d", x, pos);
    printf("\nStep Count: %d", count);
    return 0;
}
int binary_search(int arr[], int start, int end, int x)
{
    int mid;
    while(start<=end)
    {
        count++;
        mid = (start+end)/2;
        count++;
        if(arr[mid]==x)
            return mid;
        count++;
        if(x<arr[mid])
        {
            end = mid-1;
            count++;
        }
        else
        {
            start = mid+1;
            count++;
        }
        count++;
    }
    count++;
    return -1;
}
