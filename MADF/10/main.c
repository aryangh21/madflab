#include <stdio.h>
#include <stdlib.h>
struct edge
{
    int x, y, w;
};
int count = 0;
void path(int[], int);
void print_path(int[], int, int);
void bellman_ford(struct edge[20], int, int, int);

int main()
{
    struct edge v[20];
    int n, e, i, s;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter no. of edges: ");
    scanf("%d", &e);
    printf("Enter edges n weights(x y w) - \n");
    for(i=0;i<e;i++)
    {
    	count++;
        int x, y, w;	count++;
        scanf("%d %d %d", &x, &y, &w);	count++;
        v[i].x = x;	count++;
        v[i].y = y;	count++;
        v[i].w = w;	count++;
    }
    count++;
    printf("Enter source vertex: ");
    scanf("%d", &s);
    bellman_ford(v, n, e, s);
    printf("Step Count: %d", count);
    return 0;
}
void bellman_ford(struct edge v[20], int n, int e, int s)
{
    int dist[n], parent[n], i, j;
    for(i=1;i<=n;i++)
    {
    	count++;
        dist[i] = 9999;	count++;
        parent[i] = -1;	count++;
    }
    count++;
    dist[s] = 0;
    for(i=1;i<=n;i++)
    {
    	count++;
        for(j=0;j<e;j++)
        {
        	count++;
            int src = v[j].x;	count++;
            int dest = v[j].y;	count++;
            int w = v[j].w;	count++;
            count++;
            if(dist[src]!=9999 && dist[dest]>dist[src]+w)
            {
                dist[dest] = dist[src]+w;	count++;
                parent[dest] = src;	count++;
            }
        }
        count++;
    }
    count++;
    for(j=0;j<e;j++)
    {
    	count++;
        int src = v[j].x;	count++;
        int dest = v[j].y;	count++;
        int w = v[j].w;	count++;
        count++;
        if(dist[dest]>dist[src]+w)
        {
            printf("Negative edge cycle!");	count++;
            return;
        }
    }
    count++;
    for(i=1;i<=n;i++)
    {
    	count++;
        printf("\nThe distance from %d to %d = %d\n", s, i, dist[i]);	count++;
    }
    count++;
    printf("\n");
    print_path(parent, s, n);
}
void print_path(int parent[], int src, int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
    	count++;
        printf("Path to %d from %d: %d", i, src, src);	count++;
        path(parent, i);	count++;
        printf("\n");	count++;
    }
    count++;
}
void path(int parent[], int i)
{
    if(parent[i]==-1)
    {
        return;
    }
    path(parent, parent[i]);
    printf(" - %d", i);
}





