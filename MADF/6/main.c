#include <stdio.h>
#include <stdlib.h>
int count = 0, n, m, p[20], w[20], c[20];
float x[20], r[20];
void max_profit();
void dec_weight();
void min_weight();
int main()
{
    int i, ch;
    printf("Enter number of objects(n): ");
    scanf("%d", &n);
    printf("Enter bag capacity(m): ");
    scanf("%d", &m);
    printf("Enter profit and weight(p w) - \n");
    for(i=0;i<n;i++)
    {
        count++;
        printf("Object no. %d: ", i+1);
        count++;
        scanf("%d %d", &p[i], &w[i]);
        count++;
        r[i] = (float)p[i]/(float)w[i];
        count++;
    }
    count++;
    while(1)
    {
        count++;
        for(i=0;i<n;i++)
        {
            count++;
            c[i] = 0;
            x[i] = 0;
            count +=2;
        }
        count++;
        printf("\n\n\t\t1. Maximum Profit\n");
        printf("\t\t2. Decreasing weight\n");
        printf("\t\t3. Minimum Weight\n");
        printf("\t\t4. Exit\n");
        printf("\t\tEnter your choice: ");
        scanf("%d", &ch);
        count = count+6;
        switch(ch)
        {
            count++;
            case 1:
                count++;
                max_profit();
                break;
            case 2:
                count++;
                dec_weight();
                break;
            case 3:
                count++;
                min_weight();
                break;
            case 4:
                count++;
                printf("\n\nStep Count = %d", count);
                printf("\nEnd of program!");
                exit(0);
            default:
                printf("Invalid Choice!\n");
                printf("Try again!");
                count = count+2;
                break;
        }
    }
    return 0;
}
void max_profit()
{
    int temp = m, max, i, j;
    float sum = 0;
    while(temp!=0)
    {
        count++;
        for(i=0;i<n;i++)
        {
            count++;
            if(c[i]!=1)
            {
                count++;
                max = p[i];
                j = i;
                count = count+2;
                break;
            }
        }
        count++;
        for(i=0;i<n;i++)
        {
            count++;
            if(max<p[i]&&c[i]!=1)
            {
                count++;
                max = p[i];
                j = i;
                count = count+2;
            }
        }
        c[j] = 1;
        count++;
        if(temp>w[j])
        {
            count++;
            temp -= w[j];
            x[j] = 1;
            count = count+2;
        }
        else
        {
            x[j] = (float)temp/(float)w[j];
            temp = 0;
            count = count+2;
        }
    }
    printf("\t[ ");
    for(i=0;i<n;i++)
    {
        count++;
        printf("%0.2f, ", x[i]);
        sum += p[i]*x[i];
        count = count+2;
    }
    printf(" ]");
    printf("\n\t\tTotal profit = %0.2f", sum);
}
void dec_weight()
{
    int temp = m, max, i, j;
    float sum = 0;
    while(temp!=0)
    {
        count++;
        for(i=0;i<n;i++)
        {
            count++;
            if(c[i]!=1)
            {
                count++;
                max = r[i];
                j = i;
                count = count+2;
                break;
            }
        }
        count++;
        for(i=0;i<n;i++)
        {
            count++;
            if(max<r[i]&&c[i]!=1)
            {
                count++;
                max = r[i];
                j = i;
                count = count+2;
            }
        }
        count++;
        c[j] = 1;
        count++;
        if(temp>w[j])
        {
            count++;
            temp -= w[j];
            x[j] = 1;
            count = count+2;
        }
        else
        {
            x[j] = (float)temp/(float)w[j];
            temp = 0;
            count = count+2;
        }
    }
    printf("\t[ ");
    for(i=0;i<n;i++)
    {
        printf("%0.2f, ", x[i]);
        sum += p[i]*x[i];
    }
    printf(" ]");
    printf("\n\t\tTotal profit = %0.2f", sum);
}
void min_weight()
{
    int temp = m, min, i, j;
    float sum = 0;
    while(temp!=0)
    {
        count++;
        for(i=0;i<n;i++)
        {
            count++;
            if(c[i]!=1)
            {
                count++;
                min = w[i];
                j = i;
                count = count+2;
                break;
            }
        }
        count++;
        for(i=0;i<n;i++)
        {
            count++;
            if(min>w[i]&&c[i]!=1)
            {
                count++;
                min = w[i];
                j = i;
                count = count+2;
            }
        }
        count++;
        c[j] = 1;
        count++;
        if(temp>w[j])
        {
            count++;
            temp -= w[j];
            x[j] = 1;
            count = count+2;
        }
        else
        {
            x[j] = (float)temp/(float)w[j];
            temp = 0;
            count = count+2;
        }
    }
    printf("\t[ ");
    for(i=0;i<n;i++)
    {
        printf("%0.2f, ", x[i]);
        sum += p[i]*x[i];
    }
    printf(" ]");
    printf("\n\t\tTotal profit = %0.2f", sum);
}




