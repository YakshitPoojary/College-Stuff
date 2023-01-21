#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int b1,b2,n1,n2,num1[5],num2[5];

void binary_addition(int n1,int n2)
{
    int temp,i=0,j=0;
    
    temp=n1;
    while(temp>0)
    {
        num1[i]=temp%2;
        temp=temp/2;
        i++;
    }
    printf("The binary for %d is: ",n1);
    for(i=3;i>=0;i--)
    {
        printf("%d",num1[i]);
    }
    
    printf("\n");
    
    temp=n2;
    while(temp>0)
    {
        num2[j]=temp%2;
        temp=temp/2;
        j++;
    }
    printf("The binary for %d is: ",n2);
    for(j=3;j>=0;j--)
    {
        printf("%d",num2[j]);
    }
    
    int sum[5],add,carry=0;
    for(i=1+i;i<=4;i++)
    {
        add=(num1[i]+num2[i]+carry)%2;
        carry=(num1[i]+num2[i]+carry)/2;
        sum[i]=add;
    }
    if(carry!=0)
    {
        sum[i]=carry;
        i++;
    }
    
    printf("\nSum is: ");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",sum[i]);
    }
    
    if(n1<0)
    {
        for(i=4;i>=0;i--)
        {
            if (num1[i]==0)
            {
                num1[i]=1;
            }
            else
            {
                num1[i]=0;
            }
        }
    }
}

int main()
{
    printf("Enter a number 1 : ");
    scanf("%d",&n1);
    printf("Enter a number 2 : ");
    scanf("%d",&n2);
    binary_addition(n1,n2);

    return 0;
}
