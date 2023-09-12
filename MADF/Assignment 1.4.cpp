#include<stdio.h>
#include<stdlib.h>
int count = 0;
int main()
{
	int n, i, r = 1;
	printf("Enter a number: ");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		count++;
		r *= i;
		count++;
	}
	count++;
	printf("Factorial of %d is: %d", n, r);
	printf("\nStep Count: %d", count);
	return 0;
}
