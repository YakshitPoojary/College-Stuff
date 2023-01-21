#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node* next;
};

struct node* addtolist1(struct node* head1, int coefficient,int exponent)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> coeff = coefficient;
    newnode -> exp = exponent;
    newnode -> next = NULL;
    struct node * ptr = head1;

    if(head1==NULL)
    {
        head1 = newnode;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
    
    return head1;
}

struct node* addtolist2(struct node* head2, int coefficient,int exponent)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> coeff = coefficient;
    newnode -> exp = exponent;
    newnode -> next = NULL;
    struct node * ptr = head2;

    if(head2==NULL)
    {
        head2 = newnode;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
    
    return head2;
}

struct node* add(struct node* head3,struct node* head1, struct node* head2,int degree1,int degree2, int i)
{
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* ptr3=head3;

    if(degree1>degree2)
    {    
        if(ptr2 -> exp < i)
        {
            if(head3==NULL)
            {
                newnode -> coeff = ptr1 -> coeff ;
                newnode -> exp = i;
                newnode -> next = NULL;
                head3 =  newnode;
            }
            else
            {
                while(ptr1->exp != i)
                {
                    ptr1 = ptr1 -> next;
                }
                while(ptr3 -> exp != i+1)
                {
                    ptr3 = ptr3 -> next;
                }
                newnode -> coeff = ptr1 -> coeff ;
                newnode -> exp = i;
                newnode -> next = NULL;
                ptr3 -> next = newnode;
                
            }
        }
        else
        {
            while(ptr1->exp!=i)
            {
                ptr1 = ptr1 -> next;
            }
            while(ptr2->exp!=i)
            {
                ptr2 = ptr2 -> next;
            }
            while(ptr3 -> exp != i+1)
            {
                ptr3 = ptr3 -> next;
            }
            newnode -> coeff = ptr1 -> coeff + ptr2 -> coeff;
            newnode -> exp = i;
            newnode -> next = NULL;
            ptr3 -> next = newnode;
        }
    }

    else if(degree2>degree1)
    {
        if(ptr1 -> exp != i)
        {
            if(head3==NULL)
            {
                newnode -> coeff = ptr2 -> coeff ;
                newnode -> exp = i;
                newnode -> next = NULL;
                head3 =  newnode;
            }
            else
            {
                while(ptr2->exp != i)
                {
                    ptr2 = ptr2 -> next;
                }
                while(ptr1->exp!=i)
                {
                    ptr1 = ptr1 -> next;
                }
                while(ptr3 -> exp != i+1)
                {
                    ptr3 = ptr3 -> next;
                }
                newnode -> coeff = ptr2 -> coeff ;
                newnode -> exp = i;
                newnode -> next = NULL;
                ptr3 -> next = newnode;
                
            }
        }
        else
        {
            while(ptr2->exp!=i)
            {
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
            while(ptr3 -> exp != i+1)
            {
                ptr3 = ptr3 -> next;
            }
            newnode -> coeff = ptr1 -> coeff + ptr2 -> coeff;
            newnode -> exp = i;
            newnode -> next = NULL;
            ptr3 -> next = newnode;
        }
    }

    else
    {
        if(head3==NULL)
        {
            newnode -> coeff = ptr1 -> coeff + ptr2 -> coeff;
            newnode -> exp = i;
            newnode -> next = NULL;
            head3 =  newnode;
        }
        else
        {
            while(ptr1->exp!=i)
            {
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
            while(ptr3 -> exp != i+1)
            {
                ptr3 = ptr3 -> next;
            }
            newnode -> coeff = ptr1 -> coeff + ptr2 -> coeff;
            newnode -> exp = i;
            newnode -> next = NULL;
            ptr3 -> next = newnode;
        }
    }
    return head3;
}

void display(struct node* head3)
{
    struct node * ptr = head3;
    printf("\n\nThe result is: ");
    while(ptr->next!=NULL)
    {
        printf("%dx^%d + ",ptr->coeff,ptr->exp);
        ptr=ptr->next;
    }
    printf("%d",ptr->coeff);
}

int main()
{
    struct node* head1 = (struct node*)malloc(sizeof(struct node));
    head1=NULL;
    struct node* head2 = (struct node*)malloc(sizeof(struct node));
    head2=NULL;
    struct node* head3 = (struct node*)malloc(sizeof(struct node));
    head3=NULL;

    int coefficient,exponent;
    int degree1,degree2;

    printf("\n\nEnter degree of polynomial equation 1: ");
    scanf("%d",&degree1);
    for(exponent=degree1;exponent>=0;exponent--)
    {
        printf("Enter coefficient of exponent %d: ",exponent);
        scanf("%d",&coefficient);
        head1=addtolist1(head1,coefficient,exponent);
    }

    printf("\n\nEnter degree of polynomial equation 2: ");
    scanf("%d",&degree2);
    for(exponent=degree2;exponent>=0;exponent--)
    {
        printf("Enter coefficient of exponent %d: ",exponent);
        scanf("%d",&coefficient);
        head2=addtolist2(head2,coefficient,exponent);
    }
    
    if(degree1>degree2)
    {
        for(int i=degree1;i>=0;i--)
        {
            head3=add(head3,head1,head2,degree1,degree2,i);
        }
    }
    else if(degree2>degree1)
    {
        for(int i=degree2;i>=0;i--)
        {
            head3=add(head3,head1,head2,degree1,degree2,i);
        }
    }
    else
    {
        for(int i=degree1;i>=0;i--)
        {
            head3=add(head3,head1,head2,degree1,degree2,i);
        }
    }

    display(head3);
    return 0;
}