#include<stdio.h>
int count=0, s_count=0;
int G[20][20];
void Print(int[], int);
void NextValue(int[], int, int, int);
void mColoring(int[], int, int, int);
int main()
{
	int n, i, j;
	printf("Enter no of vertices : ");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			G[i][j]=0;
		}
	}
	int edges;
	printf("Enter no of edges :");
	scanf("%d", &edges);
	printf("Enter edges: \n");
	int origin,dest;
	for(i=0;i<edges;i++)
	{
		scanf("%d %d", &origin, &dest);
		G[origin][dest] = 1;
		G[dest][origin] = 1;
	}
	int m;
	printf("Enter no of colours (m) : ");
	scanf("%d", &m);
	int x[n+1];
	for(i=1;i<=n;i++)
	{
		x[i]=0;
	}
	mColoring(x,n,m,1);
	printf("Step Count: %d", count);
	return 0;
}

void Print(int x[],int n)
{
	int i;
	printf("solution %d: ", ++s_count);
	for(i=1;i<=n;i++)
	{
		count++;
		printf("%d ", x[i]);	count++;
	}
	count++;
	printf("\n");
}
void NextValue(int x[],int n,int m,int k)
{
	do
	{
		count++;
		x[k]=(x[k]+1)%(m+1);//next highest color	
		count++;
		if(x[k]==0) //all colors have been used
		{
			count++;
			return;
		}
		count++;
		int j;
		for(j=1;j<=n;j++)
		{
			count++;
			//checking if this color is distinct from adjacent colors
			count++;
			if(G[k][j]!=0 && (x[k]==x[j]))//if (k,j) is an edge and if adjacent vertex have same colour
			{
				count++;
				break;
			}
		}
		count++;
		count++;
		if(j==n+1)//new colour found
		{
			count++;
			return;
		}
	}while(1);
	count++;
}
void mColoring(int x[],int n,int m,int k)
{
	do
	{
		count++;
		//generate all legal assignments for x[k]
		count++;
		NextValue(x,n,m,k);
		count++;
		if(x[k]==0)//no new colour possible
		{
			count++;
			return;
		}
		count++;
		if(k==n)//atmost m colours has been used to colour n vertices
		{
			count++;
			Print(x,n);
		}
		else
		{	
			count++;
			mColoring(x,n,m,k+1);
		}
	}while(1);
}



