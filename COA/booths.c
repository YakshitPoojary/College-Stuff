#include <stdio.h>
#include <math.h>

int main()
{
    int b1,b2,n1=0,n2=0,rem;
    int temp;
    printf("Enter 4 digit binary number 1: ");
    scanf("%d",&b1);
    printf("Enter 4 bit binary number 2: ");
    scanf("%d",&b2);
   
    for (int i=0;i<=3;i++)
    {
        rem = b1%10;
        b1=b1/10;
        temp = pow(2,i)*rem;
        n1 += temp;
    }
    printf("\nThe decimal of binary number 1 is %d",n1);
   
    for (int i=0;i<=3;i++)
    {
        rem = b2%10;
        b2=b2/10;
        temp = pow(2,i)*rem;
        n2 += temp;
    }
    printf("\nThe decimal of binary number 2 is %d",n2);
   
   
    return 0;
}