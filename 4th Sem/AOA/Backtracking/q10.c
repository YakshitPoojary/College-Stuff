#include <stdio.h>
#include <stdlib.h>

int sos(int array[], int n, int m, int sum)
{

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

    int m;
    printf("Enter Sum: ");
    scanf("%d",&m);
    int sum=0;

}