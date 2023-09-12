#include<stdio.h>
int count = 0, m, n;
void printX(int[], int[], int);
void SumOfSub(int[], int[], int, int, int);
int main()
{
	int r=0, i;
	printf("Enter size : ");
	scanf("%d", &n);
	int w[n+1];
	int x[n+1];
	printf("Enter elements in the set : \n");
	for(i=1;i<=n;i++)
	{
		x[i]=0;
		scanf("%d", &w[i]);
		r+=w[i];
	}
	printf("Enter target sum : ");
	scanf("%d", &m);
	SumOfSub(w,x,0,1,r);
	printf("Step Count: %d", count);
	return 0;
}
void printX(int x[],int w[],int k)
{
	int i;
	printf("( ");
	for(i=1;i<=k;i++)
	{
		count++;	
		printf("%d ", x[i]);
		count++;
	}
	count++;
	printf(")\t(");
	for(i=1;i<=k;i++)
	{
		count++;
		if(x[i]==1)
		{
			count++;
			printf("%d ", w[i]);
		}
		count++;
	}
	count++;
	printf(")\n");
}
void SumOfSub(int w[],int x[],int S,int k,int r)
{
	if(k>n)
	{
		count++;
		return;
	}
	count++;
	x[k] = 1;	count++;
	count++;
	if(S+w[k]==m)
	{
		count++;
		printX(x,w,k);
	}
	else if(S+w[k]+w[k+1]<=m)
	{
		count++;
		SumOfSub(w,x,S+w[k],k+1,r);
	}
	if((S+r-w[k]>=m) && (S+w[k+1]<=m))
	{
		x[k]=0;			count++;
		SumOfSub(w,x,S,k+1,r);		count++;
	}
	count++;
}
