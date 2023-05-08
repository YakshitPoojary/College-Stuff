#include <stdio.h>
#include <stdlib.h>

struct Items
{
    int weight;
    int profit;
    float ratio;
};

struct fractional
{

};

int main()
{
    int n;
    printf("Enter number of items: ");
    scanf("%d",&n);

    struct Items array[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter Profit and Weight of Item %d: ",i+1);
        scanf("%d %d",&array[i].profit,&array[i].weight);
        array[i].ratio = ((float) array[i].profit / array[i].weight);
    }

    int m;
    printf("Enter Maximum Weight: ");
    scanf("%d",&m);

    for(int i=0;i<n;i++)
    {
        printf("\nProfit and Weight of Item %d is %d and %d with ratio %0.2f",i+1,array[i].profit,array[i].weight,array[i].ratio);
    }

    float soln[n];
    for(int i=0;i<n;i++)
    {
        soln[i]=0.0;
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(array[i].ratio<array[j].ratio)
            {
                struct Items temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("\nProfit and Weight of Item %d is %d and %d with ratio %0.2f",i+1,array[i].profit,array[i].weight,array[i].ratio);
    }

    int curr_w=0;
    int rem_w=m;
    float f_profit=0.0;

    for(int i=0;i<n;i++)
    {
        if(curr_w==m)
        {
            break;
        }

        if(curr_w + array[i].weight <= m)
        {
            soln[i]=1;
            f_profit = f_profit+array[i].profit;
            curr_w = curr_w + array[i].weight;
            rem_w = rem_w - curr_w;
        }
        else
        {
            curr_w = m;
            float fraction = (float)rem_w/array[i].weight;
            f_profit = f_profit + fraction*array[i].profit;
            soln[i]=fraction;
        }
        
    }

    printf("\n[");
    for(int i=0;i<n;i++)
    {
        printf("%0.2f ",soln[i]);
    }
    printf("]");
    
}