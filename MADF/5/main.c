#include <stdio.h>
#include <stdlib.h>
void multiply(int[10][10], int[10][10], int[10][10]);
int count = 0;
int main()
{
    int arr1[10][10], arr2[10][10], res[10][10];
    int i, j;
    printf("Enter elements of matrix 1(2X2):\n");
    for(i=1;i<=2;i++)
    {
        count++;
        for(j=1;j<=2;j++)
        {
            count++;
            scanf("%d", &arr1[i][j]);
            count++;
        }
        count++;
    }
    count++;
    printf("Enter elements of matrix 2(2X2):\n");
    for(i=1;i<=2;i++)
    {
        count++;
        for(j=1;j<=2;j++)
        {
            count++;
            scanf("%d", &arr2[i][j]);
            count++;
        }
        count++;
    }
    count++;
    multiply(arr1, arr2, res);
    printf("Product of the two matrices is: \n");
    for(i=1;i<=2;i++)
    {
        count++;
        for(j=1;j<=2;j++)
        {
            count++;
            printf("%4d ", res[i][j]);
            count++;
        }
        count++;
        printf("\n");
        count++;
    }
    count++;
    printf("\nStep Count: %d", count);
    return 0;
}
void multiply(int a[10][10], int b[10][10], int res[10][10])
{
    int p, q, r, s, t, u, v;
    p = (a[1][1]+a[2][2])*(b[1][1]+b[2][2]);count++;
    q = (a[2][1]+a[2][2])*b[1][1];count++;
    r = a[1][1]*(b[1][2]-b[2][2]);count++;
    s = a[2][2]*(b[2][1]-b[1][1]);count++;
    t = (a[1][1]+a[1][2])*b[2][2];count++;
    u = (a[2][1]-a[1][1])*(b[1][1]+b[1][2]);count++;
    v = (a[1][2]-a[2][2])*(b[2][1]+b[2][2]);count++;

    res[1][1] = p+s-t+v;count++;
    res[1][2] = r+t;count++;
    res[2][1] = q+s;count++;
    res[2][2] = p+r-q+u;count++;
}





