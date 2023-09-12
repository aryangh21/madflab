#include <stdio.h>
#include <stdlib.h>
void quick(int[], int, int);
int partition(int[], int, int);
int main()
{
    int arr[20], n, i;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    quick(arr, 0, n-1);
    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    return 0;
}
void quick(int arr[], int start, int end)
{
    int p;
    if(start<end)
    {
        p = partition(arr, start, end);
        quick(arr, start, p-1);
        quick(arr, p+1, end);
    }
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start-1, j, temp;
    for(j=start;j<end;j++)
    {
	if(arr[j]<pivot)
	{
		i++;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
    }
    temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return(i+1);
}
