#include <stdio.h>
#include <math.h>

int b1,b2,n1,n2;

void binary_to_decimal(int b1,int b2)
{
    int temp,rem,i=0,j=0;
    n1=0;
    n2=0;
    while(b1!=0)
    {
        rem = b1%10;
        b1=b1/10;
        temp = pow(2,i)*rem;
        n1 += temp;
        i++;
    }
    printf("\nThe decimal of binary number 1 is %d",n1);
   
    while(b2!=0)
    {
        rem = b2%10;
        b2=b2/10;
        temp = pow(2,j)*rem;
        n2 += temp;
        j++;
    }
    printf("\nThe decimal of binary number 2 is %d",n2);
}

void decimal_to_binary(int n1,int n2)
{
    int rem,temp,i=0,j=0;
    int num1[100],num2[100];
    while(n1>0)
    {
        num1[i]=n1%2;
        n1=n1/2;
        i++;
    }
    
    for(i=i-1;i>=0;i--)
    {
        printf("%d",num1[i]);
    }
    
    printf("\n");

    while(n2>0)
    {
        num2[j]=n2%2;
        n2=n2/2;
        j++;
    }
    for(j=j-1;j>=0;j--)
    {
        printf("%d",num2[j]);
    }
}

int main()
{
    printf("Enter a 4 digit binary number 1 : ");
    scanf("%d",&b1);
    printf("Enter a 4 digit binary number 2 : ");
    scanf("%d",&b2);
    binary_to_decimal(b1,b2);

    printf("\nEnter a number: ");
    scanf("%d",&n1);
    printf("Enter a number: ");
    scanf("%d",&n2);
    decimal_to_binary(n1,n2);

    return 0;
}