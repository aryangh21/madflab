#include<stdio.h>
#include<stdlib.h>
int count = 0;
int main()
{
	int a[100][100], b[100][100], c[100][100];
	int i, j, k;
	int r1, c1, r2, c2;
	printf("Enter no. of rows and columns in matrix 1: ");
	scanf("%d %d", &r1, &c1);
	printf("Enter matrix 1 - \n");
	for(i=0;i<r1;i++)
	{
		count++;
		for(j=0;j<c1;j++)
		{
			count++;
			scanf("%d", &a[i][j]);
			count++;
		}
		count++;
	}
	count++;
	printf("Enter no. of rows and columns in matrix 2: ");
	scanf("%d %d", &r2, &c2);
	printf("Enter matrix 2 - \n");
	for(i=0;i<r2;i++)
	{
		count++;
		for(j=0;j<c2;j++)
		{
			count++;
			scanf("%d", &b[i][j]);
			count++;
		}
		count++;
	}
	count++;
	if(c1!=r2)
	{
		printf("Invalid dimensions!");
		exit(0);
	}
	for(i=0;i<r1;i++)
	{
		count++;
		for(j=0;j<c2;j++)
		{
			count++;
			c[i][j] = 0;
			count++;
			for(k=0;k<c1;k++)
			{
				count++;
				c[i][j] += a[i][k] * b[k][j];
				count++;
			}
			count++;
		}
		count++;
	}
	count++;
	printf("Resultant matrix:\n");
	for(i=0;i<r1;i++)
	{
		count++;
		for(j=0;j<c2;j++)
		{
			count++;
			printf("%8d", c[i][j]);
			count++;
		}
		printf("\n");
		count++;
		count++;
	}
	printf("Strp Count: %d", count);
	return 0;
}

