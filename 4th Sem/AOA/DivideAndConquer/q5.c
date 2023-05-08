#include <stdlib.h>
#include <stdio.h>

void merge(int array[], int start, int mid, int end, int n)
{
    int h=start;
    int i=start;
    int j=mid+1;
    int soln[n];

    while(h<=mid & j<=end)
    {
        if(array[h]<=array[j])
        {
            soln[i]=array[h];
            h++;
        }
        else
        {
            soln[i]=array[j];
            j++;
        }
        i++;
    }

    if(h>mid)
    {
        for(int k=j;k<=end;k++)
        {
            soln[i]=array[k];
            i++;
        }
    }
    else
    {
        for(int k=h;k<=mid;k++)
        {
            soln[i]=array[k];
            i++;
        }
    }

    for(int i=start;i<=end;i++)
    {
        array[i]=soln[i];
    }
}

void mergesort(int start, int end, int array[], int n)
{
    if(start<end)
    {
        int mid = (start+end)/2;
        mergesort(start,mid,array,n);
        mergesort(mid+1,end,array,n);
        merge(array,start,mid,end,n);
    }
}

int main()
{
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    int array[n];
    int soln[n];

    printf("Enter elements: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

    printf("\nNumbers in Array are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }

    mergesort(0,n-1,array,n);

    printf("\nNumbers in Array are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }

}