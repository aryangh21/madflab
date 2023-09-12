#include <stdio.h>
#include <stdlib.h>
void NQueens(int[], int, int);
int Place(int[], int, int);
void Print(int[], int);
int solution_count = 0;
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int x[n+1];
    NQueens(x, 1, n);
    return 0;
}
void NQueens(int x[], int k, int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(Place(x, k, i))
        {
            x[k] = i;
            if(k==n)
            {
                Print(x, n);
            }
            else
            {
                NQueens(x, k+1, n);
            }
        }
    }
}
int Place(int x[], int k, int i)
{
    int j;
    for(j=1;j<k;j++)
    {
        if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))      //same column and same diagoal
        {
            return 0;
        }
    }
    return 1;
}
void Print(int x[], int n)
{
    char board[n+1][n+1];
    int i, j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            board[i][j] = '*';
        }
        board[i][x[i]] = 'Q';
    }
    solution_count++;
    printf("Solution %d:\n", solution_count);
    printf("[ ");
    for(i=1;i<=n;i++)
    {
        if(i==n)
        {
            printf("%d ]", x[i]);
        }
        else
        {
            printf("%d, ", x[i]);
        }
    }
    printf("\n\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%4c ", board[i][j]);
        }
        printf("\n");
    }
}



