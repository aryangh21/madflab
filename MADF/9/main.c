#include <stdio.h>
#include <stdlib.h>
void floyd(int[20][20], int);
int min(int, int);
int main()
{
    int cost[20][20], n, i, j, e = 0;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix - \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j]!=0)
            {
                e++;
            }
            if(cost[i][j]==0 && i!=j)
            {
                cost[i][j] = 999;
            }
        }
    }
    floyd(cost, n);
    return 0;
}
void floyd(int cost[20][20], int n)
{
    int i, j, k;
    printf("\nA(0) - \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%4d", cost[i][j]);
        }
        printf("\n");
    }
    for(k=0;k<n;k++)
    {
        printf("\nA(%d) - \n", k+1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
                }
                printf("%4d", cost[i][j]);
            }
            printf("\n");
        }
    }
}
int min(int x, int y)
{
    if(x<y)
        return x;
    else
        return y;
}



