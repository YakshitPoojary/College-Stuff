#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,low,high,count;
    printf("Enter number of inputs: ");
    scanf("%d",&n);
    printf("Enter range of the inputs in (a,b) form: ");
    scanf("%d,%d",&low,&high);
    
    int input[n];
    int countarray[high+1];
    int sortarray[n];

    printf("Enter the inputs: \n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &input[i]);
    }

    //Step 1: Initialize to size of input range 2 3 1 2 4 5 2 1 5 4
    printf("\n\nInitialize to size of input range\n");
    for(int i = 0; i<high+1; i++)
    {
        countarray[i] = 0;
    }

    for(int i=0;i<high+1;i++)
    {
        printf("%d - %d\n",i,countarray[i]);
    }

    //Step 2: Count of each input
    printf("\nCount of each input\n");
    for(int i = 0; i<high+1; i++)
    {
        count = 0;
        for(int j=0; j<n; j++)
        {
            if(input[j]==i)
            {
                count = count + 1;
            }
        }
        countarray[i]=count;
    }

    for(int i=0;i<high+1;i++)
    {
        printf("%d - %d\n",i,countarray[i]);
    }

    //Step 3: Cummulative addition
    printf("\nCummulative addition\n");
    for(int i=1;i<high+1;i++)
    {
        countarray[i]=countarray[i] + countarray[i-1];
    } 
    for(int i=0;i<high+1;i++)
    {
        printf("%d - %d\n",i,countarray[i]);
    }

    //Step 4: Right shift
    printf("\nRight shift\n");
    for(int i=1;i<high+1;i++)
    {
        countarray[i]=countarray[i-1];
    }
    for(int i=0;i<high+1;i++)
    {
        printf("%d - %d\n",i,countarray[i]);
    }
}
