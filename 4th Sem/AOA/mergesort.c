#include <stdio.h>

void merge(int a[], int b[],int low, int mid, int high)
{
    int h=low;
    int i=low;
    int j= mid+1;
    do
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }while(h<=mid && j<=high);

    if(h>mid)
    {
        for(int k=j;k<=high;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(int k=h;k<=mid;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(int k=low;k<=high;k++)
    {
        a[k]=b[k];
    }
}

void mergesort(int a[], int b[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(a,b,low,mid);
        mergesort(a,b,mid+1,high);
        merge(a,b,low,mid,high);
    }
}

int main()
{
    int n=8;
    int a[8]={2,4,5,7,1,2,3,6};
    int low=0,high=n-1;
    int b[8];

    printf("Array Before Quicksort: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\n");

    mergesort(a,b,low,high);

    printf("Array After Quicksort: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\n");
}