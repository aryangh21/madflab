#include<stdio.h>
#include<stdlib.h>
int count = 0;
int main()
{
	int a = 0, b = 1, c, n, i;
	printf("Enter no. of terms: ");
	scanf("%d", &n);
	printf("Fibonacci Series: ");
	printf("%d %d ", a, b);
	count += 2;
	for(i=2;i<n;i++)
	{
		count++;
		c = b;
		count++;
		b = a+b;
		count++;
		a = c;
		count++;
		printf("%d ", b);
		count++;
	}
	count++;
	printf("\nStep count: %d", count);
	return 0;
}
