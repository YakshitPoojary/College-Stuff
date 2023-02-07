#include <stdio.h>
#include <stdlib.h>

int main() {

    int n,counter=0;
    printf("Number of Inputs: ");
    scanf("%d",&n);
   
    int inputs[n];
   
    for(int i=0;i<n;i++)
    {
        int num = rand()%100;
        inputs[i]=num;
    }
   
    printf("Before Sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", inputs[i]);
    }
    printf("\n");
   
    int i, temp, j;
    for (i = 1; i < n; i++)
    {
        temp = inputs[i];
        j = i - 1;
       
        while (j >= 0 && inputs[j] > temp)
        {
            inputs[j + 1] = inputs[j];
            j = j - 1;
            counter++;
        }
        inputs[j + 1] = temp;
    }
   
    printf("\n");
    printf("After Sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", inputs[i]);
    }
    printf("\n");
   
    printf("\n");
    printf("Number of Comparisons: %d",counter);

    return 0;
}