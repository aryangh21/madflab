#include<stdio.h>
int n,m,count=0;

int last(char c, char pattern[])
{
	int i;
	count++;
	for(i=m-1;i>0;i--)
	{
		count+=2;
		if(c==pattern[i])
		{	count++;	return i;	}
	}
	count+=2;
	return -1;
}

int min(int a, int b)
{
	count+=2;
	if(a<b)
		return a;
	return b;
}

void BM(char text[], char pattern[])
{
	int i, j=n-1;
	for(i=m-1;i<=n-1;)
	{
		if(pattern[j]==text[i])
		{
			if(j==0)
			{
				count+=2;
				printf("Pattern match found at index %d\n", i);
				return;
			}	
			else
			{
				i++; j--;	
			}	
		}
		else
		{
			i=i+m-min(j, 1+last(text[i],pattern));
			j=m-1;
		}
	}
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
	BM(text,pattern);
	printf("\nStep count= %d", count);
}

