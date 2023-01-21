#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* add(struct node* front,int num)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = num;
    newnode -> next = front;
    struct node* ptr = front;

    if(front==NULL)
    {
        front = newnode;
        front -> next = front;
    }
    else
    {
        while(ptr-> next != front)
        {
            ptr = ptr -> next;
        }
        ptr -> next = newnode;
    }

    return front;
}

struct node* delete(struct node* front,int key)
{
    struct node* ptr = front;
    struct node* prev = front;
    while(prev -> next != front)
    {
        prev = prev -> next;
    }

    while(ptr->next != ptr)
    {
        for(int i = 1;i<key;i++)
        {
            ptr = ptr -> next;
            prev = prev -> next;
        }
        printf("\n%d is eliminated",ptr->data);
        prev -> next = ptr -> next;
        free(ptr);
        ptr=prev->next;
    }

    return ptr;
}

int main()
{
    struct node* front = (struct node*)malloc(sizeof(struct node));
    front=NULL;

    int n,num,key;
    printf("\nEnter number of nodes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter data of node %d: ",i+1);
        scanf("%d",&num);
        front = add(front,num);
    }

    printf("\n\nEnter key: ");
    scanf("%d",&key);

    front = delete(front,key);
    printf("\n\n%d is safe!",front->data);
    return 0;
}