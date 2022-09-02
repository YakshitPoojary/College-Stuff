#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int b1,b2,n1,n2,num1[100],num2[100];

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
    int temp1,temp2,i=0,j=0;
    temp1=n1;
    temp2=n2;
    while(temp1>0)
    {
        num1[i]=temp1%2;
        temp1=temp1/2;
        i++;
    }
    printf("The binary for %d is: ",n1);
    for(i=i-1;i>=0;i--)
    {
        printf("%d",num1[i]);
    }
    
    printf("\n");

    while(temp2>0)
    {
        num2[j]=temp2%2;
        temp2=temp2/2;
        j++;
    }
    printf("The binary for %d is: ",n2);
    for(j=j-1;j>=0;j--)
    {
        printf("%d",num2[j]);
    }
}

void binary_addition(int b1,int b2)
{
    int sum[100],add,i=0,carry=0;
    int temp1,temp2;
    while(b1!=0 || b2!=0)
    {
        temp1=b1%10;
        temp2=b2%10;
        b1=b1/10;
        b2=b2/10;
        add=(temp1+temp2+carry)%2;
        carry=(temp1+temp2+carry)/2;
        sum[i]=add;
        i++;
    }
    if(carry==0)
    {
        sum[i]=carry;
    }

    printf("\nSum is: ");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",sum[i]);
    }

}

int main()
{
    int choice;
    printf("\n1) Binary to decimal \n2) Decimal to binary \n3) Binary addition \n4) Exit");
    int i=0;
    while(i==0)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter a binary number 1 : ");
            scanf("%d",&b1);
            printf("Enter a binary number 2 : ");
            scanf("%d",&b2);
            binary_to_decimal(b1,b2);
            break;

        case 2:
            printf("\nEnter a number: ");
            scanf("%d",&n1);
            printf("Enter a number: ");
            scanf("%d",&n2);
            decimal_to_binary(n1,n2);
            break;

        case 3:
            printf("Enter a binary number 1 : ");
            scanf("%d",&b1);
            printf("Enter a binary number 2 : ");
            scanf("%d",&b2);
            binary_addition(b1,b2);
            break;

        case 4:
            exit(1);
            i=1;
        
        default:
            printf("Invalid Choice!!");
            break;
        }
    }

    return 0;
}