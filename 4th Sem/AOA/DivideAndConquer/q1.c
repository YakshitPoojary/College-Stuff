#include <stdio.h>
#include <stdlib.h>

struct pair
{
    int max;
    int min;
};

struct pair maxmin(int start,int end,int array[])
{
    struct pair minmax,left,right;
    if(start==end)
    {
       minmax.max=minmax.min=array[start];
    }
    else if(start==end-1)
    {
        if(array[start]>array[end])
        {
            minmax.min = array[end];
            minmax.max = array[start];
        }
        else
        {
            minmax.max = array[end];
            minmax.min = array[start];
        }
    }
    else
    {
        int mid = (start+end)/2;
        left = maxmin(start,mid,array);
        right= maxmin(mid+1,end,array);

        if(left.max>right.max)
        {
            minmax.max = left.max;
        }
        else
        {
            minmax.max = right.max;
        }
        
        if(left.min<right.min)
        {
            minmax.min = left.min;
        }
        else
        {
            minmax.min = right.min;
        }
    }
    return minmax;
}

int main()
{
    int n;
    printf("Enter number of integers: ");
    scanf("%d",&n);

    int array[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

    printf("\nNumbers in Array are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }

    //Straightforward Approach

    // min=max=array[0];

    // for(int i=1;i<n;i++)
    // {
    //     if(min > array[i])
    //     {
    //         min = array[i];
    //     }
    //     if(max < array[i])
    //     {
    //         max = array[i];
    //     }
    // }

    // printf("/nMin and Max of this array are %d and %d respectively.",min,max);

    //Divide and Conquer
    struct pair minmax = maxmin(0,n-1,array);
    printf("\nMin and Max of this array are %d and %d respectively.",minmax.min,minmax.max);
}