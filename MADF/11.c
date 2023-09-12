#include<stdio.h>
int count=0,size = 1;
typedef struct
{
	int price;
	int wt;
	int object[50];
}Tuple;
void purge(Tuple[]);
void Knapsack(int[], int[], int, int);
int main()
{
    int m,n,i,price[20],wt[20];
    printf("Enter the number of objects: ");
    scanf("%d",&n);
    printf("Enter the maximum capacity of the Knapsack: ");
    scanf("%d",&m);
    printf("\n");
	for(i=0;i<n;i++){
        printf("Enter the profit and weight of object %d: ",i+1);
        scanf("%d %d", &price[i], &wt[i]);
    }
    Knapsack(price,wt,m,n);
    printf("\nStep Count = %d", count);
}
void purge(Tuple S[50])
{
	int i,j;
	for(i=0;i<size;i++)
	{										
		count++;
		for(j=0;j<size;j++)
		{								
			count++;
			if(S[i].price < S[j].price && S[i].wt > S[j].wt)
			{ 	
				count++;
				S[i].price = -1;				count++;				
				S[i].wt = -1;					count++;
			}	
		}
		count++;
	}
	count++;
}
void Knapsack(int p[],int w[],int m,int n)
{
	Tuple S[50];
	int i,j,k,l;
	S[0].wt = 0;								
	S[0].price = 0; 						
	for(i=0;i<n;i++)
	{							
		count++;
		S[0].object[i] = 0;						count++;
	}
	count++;
	for(i=0;i<n;i++)
	{							
		count++;
		for(j=0,k=size;j<size;j++,k++)
		{			
			count++;
			if(S[j].wt==-1)
			{ 
				count++;	
				continue;	
			}
			S[k].wt = S[j].wt + w[i];			count++;
			if(S[k].wt > m)
			{					
				count++;
				S[k].wt = -1;					count++;
				S[k].price = -1;				count++;
				continue;						count++;
			}
			S[k].price = S[j].price + p[i]; 	count++;
			for(l=0;l<n;l++)
			{					
				count++;			
				S[k].object[l] = S[j].object[l];count++;
			}
			count++;
			S[k].object[i]++;					count++;			
		}
		count++;
		size = size*2;
	}
	purge(S);
	int max_profit = -1, max_weight = -1,index;		
	for(i=0;i<size;i++)
	{							
		count++;
		if(S[i].wt < max_weight)
		{ 					
			count++; 	
			continue;	
		}

		else if(S[i].wt > max_weight)
		{				
			count++;
			max_weight = S[i].wt;					count++;
			max_profit = S[i].price;				count++;
			index = i;								count++;
		}
		else
		{
			if(S[i].price > max_profit){			count++;
				max_profit = S[i].price;			count++;
				index = i; 							count++;
			}
		}
	}
	count++;
	printf("Maximum profit = %d\n",max_profit);		
	printf("\nObjects selected are:\n");			
	for(i=0;i<n;i++)
	{							
		count++;
		printf("x[%d] -> ",i+1);					count++;
		if(S[index].object[i]!=1)
		{					
			count++;
			printf("%d  ", 0);						count++;
		}
		else
		{		
			printf("%d  ",S[index].object[i]);		count++;
		}
		printf("\n");								count++;
	}
	count++;
}




