#include <stdio.h>
#include <stdlib.h>

int binarysearch(int start, int end, int key, int array[])
{
    if(start>end)
    {
        return -1;
    }
    else
    {
        int mid = (start+end)/2;
        if(key > array[mid])
        {
            binarysearch(mid+1,end,key,array);
        }
        else if(key < array[mid])
        {
            binarysearch(start,mid-1,key,array);
        }
        else
        {
            return mid;
        }
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

    //Sort this array
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(array[i]>array[j])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

    printf("\nNumbers in Array are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }

    int key;
    printf("\nEnter your key: ");
    scanf("%d", &key);

    int key_index=binarysearch(0,n-1,key, array);
    printf("\n%d",key_index);


}
