#include <stdio.h>
#include <stdlib.h>
#define infinity 9999
int n, cost[20][20], count = 0;
void dijkstras(int);
int main()
{
    int source, i, j;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter source vertex: ");
    scanf("%d", &source);
    printf("Enter cost of edges - \n");
    for(i=0;i<n;i++)
    {
        count++;
        for(j=0;j<n;j++)
        {
            count++;
            scanf("%d", &cost[i][j]);   count++;
            if(cost[i][j]==0 && i!=j)
            .00
            {
                cost[i][j] = infinity;  count++;
            }
            count++;
        }
        count++;
    }
    count++;
    dijkstras(source);
    printf("\nStep Count: %d", count);
    return 0;
}
void dijkstras(int source)
{
    int distance[n], s[n], index, i, j;
    for(i=0;i<n;i++)
    {
        count++;
        distance[i] = cost[source][i];  count++;
        s[i] = 0;   count++;
    }
    count++;
    distance[source] = 0;
    for(i=0;i<n;i++)
    {
        count++;
        int min = infinity; count++;
        for(j=0;j<n;j++)
        {
            count++;
            if(s[i]==0 && distance[j]<=min)
            {
                min = distance[j];  count++;
                index = j;  count++;
            }
            count++;
        }
        count++;
        s[index] = 1;   count++;
        for(j=0;j<n;j++)
        {
            count++;
            if(!s[j] && cost[index][j]!=infinity && distance[index]!=infinity && distance[index]+cost[index][j]<distance[j])
            {
                distance[j] = distance[index] + cost[index][j]; count++;
            }
            count++;
        }
        count++;
    }
    count++;
    printf("\nVertex\t\tDistance from Source\n");
    for(i=0;i<n;i++)
    {
        count++;
        count++;
        if(distance[i]==infinity)
        {
            printf("%d\t\tNo Path\n", i);   count++;
        }
        else
        {
            printf("%d\t\t%d\n", i, distance[i]);   count++;
        }
    }
}
