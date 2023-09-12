#include<stdio.h>
#include<stdlib.h>
#define infinity 9999
int G[20][20],spanning[20][20],n, parent[20], count = 0;
int prims();
int krushkals();
int find(int);
int Union(int, int);
int main()
{
	int i,j,total_cost, x;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	while(1)
	{
		count = 0;
		printf("\n\t\t1. PRIMS ALGORITHM");
		printf("\n\t\t2. KRUSHKALS ALGORITHM");
		printf("\n\t\t3. EXIT");
		printf("\n\t\tENTER YOUR CHOICE: ");
		scanf("%d", &x);
		printf("EDGE   :  WEIGHT\n");
		switch(x)
		{
			case 1:
				total_cost=prims();
				break;
			case 2:
				total_cost=krushkals();
				break;
			case 3:
				printf("End of program!");
				exit(0);
				break;
			default:
				printf("Invalid choice!");
				break;
		}
		for(i=0;i<n;i++)
		{
			count++;
			for(j=0;j<n;j++)
			{
				count++;
				if(spanning[i][j]!=0)
				{
					printf("%d - %d : %d\n", i+1, j+1, spanning[i][j]);
					count++;
				}
				count++;
			}
			count++;
		}
		printf("\n\nTotal cost of spanning tree=%d",total_cost);
		printf("\nStep Count: %d", count);
	}
	return 0;
}
int prims()
{
	int cost[20][20];
	int u, v, min_distance, distance[20], from[20];
	int visited[20], no_of_edges, i, min_cost,j ;
	//create cost[][] matrix,spanning[][]
	for(i=0;i<n;i++)
	{
		count++;
		for(j=0;j<n;j++)
		{
			count++;
			count++;
			if(G[i][j]==0)
			{
				cost[i][j]=infinity;
				count++;
			}
			else
			{
				cost[i][j]=G[i][j];
				count++;
			}
			count++;
			spanning[i][j]=0;
			count++;
		}
		count++;
	}
	count++;
	//initialise visited[],distance[] and from[]
	distance[0]=0;
	visited[0]=1;
	for(i=1;i<n;i++)
	{
		count++;
		distance[i]=cost[0][i];
		count++;
		from[i]=0;
		count++;
		visited[i]=0;
		count++;
	}
	count++;
	min_cost=0; //cost of spanning tree
	no_of_edges=n-1; //no. of edges to be added
	while(no_of_edges>0)
	{
		count++;
	//find the vertex at minimum distance from the tree
		min_distance=infinity;
		count++;
		for(i=1;i<n;i++)
		{
			count++;
			if(visited[i]==0&&distance[i]<min_distance)
			{
				v=i;
				count++;
				min_distance=distance[i];
				count++;
			}
			count++;
		}
		u=from[v];
		count++;
		//insert the edge in spanning tree
		spanning[u][v]=distance[v];
		count++;
		no_of_edges--;
		count++;
		visited[v]=1;
		count++;
		//updated the distance[] array
		for(i=1;i<n;i++)
		{
			count++;
			if(visited[i]==0&&cost[i][v]<distance[i])
			{
				distance[i]=cost[i][v];
				count++;
				from[i]=v;
				count++;
			}
			count++;
		}
		count++;
		min_cost=min_cost+cost[u][v];
		count++;
	}
	count++;
	return(min_cost);
}
int krushkals()
{
	int cost[20][20];
	int u, v, min_distance, distance[20], from[20];
	int visited[20], no_of_edges, i, min_cost,j ;
	//create cost[][] matrix,spanning[][]
	for(i=0;i<n;i++)
	{
		count++;
		for(j=0;j<n;j++)
		{
			count++;
			count++;
			if(G[i][j]==0)
			{
				cost[i][j]=infinity;
				count++;
			}
			else
			{
				cost[i][j]=G[i][j];
				count++;
			}
			count++;
			spanning[i][j]=0;
			count++;
		}
		count++;
	}
	count++;
	//initialise visited[],distance[] and from[]
	distance[0]=0;
	visited[0]=1;
	for(i=1;i<n;i++)
	{
		count++;
		distance[i]=cost[0][i];
		count++;
		from[i]=0;
		count++;
		visited[i]=0;
		count++;
	}
	min_cost=0; //cost of spanning tree
	no_of_edges=n-1; //no. of edges to be added
	while(no_of_edges>0)
	{
	//find the vertex at minimum distance from the tree
		count++;
		min_distance=infinity;
		count++;
		for(i=1;i<n;i++)
		{
			count++;
			if(visited[i]==0&&distance[i]<min_distance)
			{
				v=i;
				count++;
				min_distance=distance[i];
				count++;
			}
			count++;
		}
		count++;
		u = find(u);	count++;
		v = find(v);	count++;
		u=from[v];	count++;
		//insert the edge in spanning tree
		spanning[u][v]=distance[v];	count++;
		no_of_edges--;	count++;
		visited[v]=1;	count++;
		//updated the distance[] array
		for(i=1;i<n;i++)
		{
			count++;
			if(visited[i]==0&&cost[i][v]<distance[i])
			{
				distance[i]=cost[i][v];	count++;
				from[i]=v;	count++;
			}
			count++;
		}
		count++;
		if(Union(u, v))
		{
			min_cost = min_cost + cost[u][v];	count++;
		}
		count++;
	}
	count++;
	return(min_cost);
}
int find(int i)
{
	while(parent[i])
	i = parent[i];
	return i;
}
int Union(int i, int j)
{
	if(i!=j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}



