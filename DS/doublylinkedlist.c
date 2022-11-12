#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* prev;
    struct node* next;
};

void traverse(struct node* ptr)
{
    if(ptr==NULL)
    {
        printf("No elements in linked list\n\n");
    }
    else
    {
        while(ptr->next!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\n",ptr->data);
    }
}

void travreverse(struct node* ptr,struct node* head)
{
    if(ptr==NULL)
    {
        printf("\nNo elements in linked list\n");
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        while(ptr!=head)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->prev;
        }
        printf("%d\n",head->data);
    }
}

struct node* addbeg(struct node* head,int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = val;
    newnode -> next = head;
    return newnode;
}

struct node* addbefore(struct node* head,int val,int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;
    newnode -> data = val;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    
    if(head==NULL)
    {
        head -> data = newnode -> data;
    }
    else
    {
       while(ptr -> data != key)
       {
           ptr = ptr -> next;
       }
       newnode -> prev = ptr -> prev;
       newnode -> next = ptr;
       if (ptr!=head)
       {
        ptr -> prev -> next = newnode;
       }
       ptr -> prev = newnode;
       if(ptr==head)
       {
         return newnode;
       }
    }
    return head;
}

struct node* addafter(struct node* head,int val,int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;
    newnode -> data = val;
    
    if(head==NULL)
    {
        head -> data = newnode -> data;
    }
    else
    {
       while(ptr -> data != key)
       {
           ptr = ptr -> next;
       }
       newnode -> prev = ptr;
       newnode -> next = ptr -> next;
       if (ptr->next!=NULL)
       {
        ptr -> next -> prev = newnode;
       }
       ptr -> next = newnode;
    }
    return head;
}

struct node* addend(struct node* head,int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;
    newnode -> data = val;
    if(head==NULL)
    {
        return newnode;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr= ptr->next;
        }
        ptr->next=newnode;
        newnode->prev=ptr;
        return head;
    }
}

struct node* delete(struct node* head,int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("\nThere isn't a single node in this linked list!\n");
    }
    else
    {
        struct node* ptr = head;
        while(ptr->data==val)
        {
            ptr = ptr -> next;
        }
        if(ptr==head)
        {
            return(ptr->next);
        }
        else if(ptr->next==NULL)
        {
            ptr->prev->next=NULL;
        }
        
    }
}

int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head=NULL;
    int val,key,choice;
    
    do
    {
        printf("\n1)Traverse \n2)Traverse Reverse \n3)Add at beginning\n4)Add a node after key \n5)Add a node before key \n6)Add at end \n7)Delete a node \n8)Exit\n\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                traverse(head);
                break;


            case 2:
                travreverse(head,head);
                break;

            case 3: 
                printf("Enter data to add to linked list: ");
                scanf("%d",&val);
                head=addbeg(head,val);
                break;

            case 4:
                printf("Enter data to add to linked list: ");
                scanf("%d",&val);
                printf("After which node: ");
                scanf("%d",&key);
                head = addafter(head,val,key);
                break;

            case 5:
                printf("Enter data to add to linked list: ");
                scanf("%d",&val);
                printf("Before which node: ");
                scanf("%d",&key);
                head=addbefore(head,val,key);
                break;

            case 6:
                printf("Enter data to add to linked list: ");
                scanf("%d",&val);
                head=addend(head,val);
                break;

            case 7:
                printf("Enter data to delete from linked list: ");
                scanf("%d",&val);
                head=delete(head,val);
                break;
                
            default:
                printf("Incorrect choice \n\n");
                break;
        }
    }while(choice!=8);
    return 0;
}
