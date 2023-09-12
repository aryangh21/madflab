#include<stdio.h>
int n,m,count=0;

void BruteForce(char text[], char pattern[])
{
	int i,j;
	count++;
	for(i=0;i<=n-m;i++)
	{
		count+=2;
		for(j=0;j<m && text[i+j]==pattern[j];)
		{	count+=2;	j++;		}	
		count+=2;
		if(j==m)
		{
			count+=2;
			printf("Pattern match found at index %d\n", i);
			return;
		}			
	}
	count++;
	printf("Pattern not found\n");
}

void main()
{
	printf("Enter length of text: ");
	scanf("%d", &n);
	printf("Enter length of pattern: ");
	scanf("%d", &m);
	char text[n],pattern[m];
	printf("Enter text: ");
	scanf("%s", &text);
	printf("Enter pattern: ");
	scanf("%s", &pattern);
	count++;
	BruteForce(text,pattern);
	printf("\nStep count= %d", count);
}

