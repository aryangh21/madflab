#include<stdio.h>
#include<stdlib.h>
int count = 0;
int main()
{
	int n, i;
	printf("ENter no. to be checked: ");
	scanf("%d", &n);
	for(i=2;i<n;i++)
	{
		count++;
		if(n%i==0)
		{
			printf("Number is not prine!");
			count++;
			printf("\nStep Count: %d", count);
			count++;
			exit(0);
		}
	}
	count++;
	printf("Number is prime!");
	printf("\nStep Count: %d", count);
	return 0;
}
