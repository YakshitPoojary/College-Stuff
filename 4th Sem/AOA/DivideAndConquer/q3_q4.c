#include <stdio.h>
#include <stdlib.h>

void interchange(int array[], int i, int j)
{
    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

int partition(int array[], int start, int end)
{
    int pivot = array[start];
    int i = start;
    int j = end;

    do
    {
        do
        {
            i++;
        }while (pivot>array[i]);

        do
        {
            j--;
        }while (pivot<array[j]);

        if(i<j)
        {
            interchange(array,i,j);
        } 
    }while(i<=j);

    array[start]=array[j];
    array[j]=pivot;
    return j;
}

void quicksort(int start, int end, int array[])
{
    if(start<end)
    {
        int pi = partition(array,start,end);
        quicksort(array,start,pi-1);
        quicksort(array,pi+1,end);
    }
}

int main()
{
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    int array[n];

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

    quicksort(0,n-1,array);

    printf("\nNumbers in Array are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
}