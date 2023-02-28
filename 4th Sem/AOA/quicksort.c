#include <stdio.h>
#include <stdlib.h>

void interchange(int a[], int i, int j)
{
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int partition(int a[], int s, int e)
{
  int pivot = a[s];
  int i = s;
  int j = e;

  do
  {
    do
    {
      i++;
    }while(pivot>=a[i]);
    
    do
    {
      j--;
    }while(pivot<=a[j]);

    if(i<j)
    {
      interchange(a,i,j);
    }
  }while(i<=j);

  a[s] = a[j];
  a[j] = pivot;
  return j;
}

void quicksort(int a[], int s, int e)
{
  if(s<e)
  {
    int pi=partition(a,s,e+1);

    quicksort(a,s,pi-1);
    quicksort(a,pi+1,e);
  }
}

int main()
{
  int n=7;
  int a[7]={25,12,13,5,70,23,10};
  int s=0,e=n-1;

  printf("Array Before Quicksort: ");
  for(int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  printf("\n\n");

  quicksort(a,s,e);

  printf("Array After Quicksort: ");
  for(int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}