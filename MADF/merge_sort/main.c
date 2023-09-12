#include <stdio.h>
#include <stdlib.h>
int count = 0;
void merge_sort(int[], int, int);
void merge(int[], int[], int, int, int, int);
void copy(int[], int[], int, int);
int main()
{
    int arr[20], n, i;
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
    merge_sort(arr, 0, n-1);
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    {
        count++;
        printf("%d ", arr[i]);
        count++;
    }
    count++;
    printf("\nStep Count: %d", count);
    return 0;
}
void merge_sort(int arr[], int start, int end)
{
    int mid, temp[20];
    if(start<end)
    {
        count++;
        mid = (start+end)/2; count++;
        merge_sort(arr, start, mid); count++;
        merge_sort(arr, mid+1, end); count++;
        merge(arr, temp, start, mid, mid+1, end); count++;
        copy(arr, temp, start, end); count++;
    }
    count++;
}
void merge(int arr[], int temp[], int start1, int end1, int start2, int end2)
{
    int i = start1, j = start2, k = start1;
    while((i<=end1)&&(j<=end2))
    {
        count++;
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
            count++;
        }
        else
        {
            temp[k++] = arr[j++];
            count++;
        }
        count++;
    }
    count++;
    while(i<=end1)
    {
        count++;
        temp[k++] = arr[i++];
        count++;
    }
    count++;
    while(j<=end2)
    {
        count++;
        temp[k++] = arr[j++];
        count++;
    }
    count++;
}
void copy(int arr[], int temp[], int start, int end)
{
    int i;
    for(i=start;i<=end;i++)
    {
        count++;
        arr[i] = temp[i];
        count++;
    }
    count++;
}




