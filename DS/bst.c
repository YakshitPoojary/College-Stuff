#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root, int num)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;
    struct node* ptr=root;
    struct node* prev = NULL;
    
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        while(ptr != NULL)
        {
            prev = ptr;
            if(newnode -> data <= ptr -> data)
            {
                ptr = ptr -> left;
            }
            else
            {
                ptr = ptr -> right;
            }
        }
        if(newnode -> data <= prev -> data)
        {
            prev -> left = newnode;
        }
        else
        {
            prev -> right = newnode;
        }
    }
    return root;
}

struct node* delete(struct node* root,int num)
{
    
    struct node* ptr=root;
    struct node* prev = NULL;
    
    if(root==NULL)
    {
        printf("There is no root node");
    }
    else
    {
        while(ptr -> data != num)
        {
            prev = ptr;
            if(num <= ptr-> data)
            {
                ptr = ptr -> left;
            }
            else
            {
                ptr = ptr -> right;
            }
        }
        if(ptr -> left == NULL && ptr -> right != NULL )
        {
            if(ptr == prev -> left)
            {
                prev -> left = ptr -> right;
            }
            else
            {
                prev -> right = ptr -> right;
            }
            free(ptr);
        }
        else if(ptr -> right == NULL && ptr -> left != NULL)
        {
            if(ptr == prev -> left)
            {
                prev -> left = ptr -> left;
            }
            else
            {
                prev -> right = ptr -> left;
            }
            free(ptr);
        }
        else if(ptr -> left == NULL && ptr -> right == NULL)
        {
            if(ptr == prev -> left)
            {
                prev -> left = NULL;
            }
            else
            {
                prev -> right =NULL;
            }
            free(ptr);
        }
    }
    return root;
}

void inorder (struct node* ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        printf("%d ",ptr->data);
        inorder(ptr->right);
    }
}

void preorder (struct node* ptr)
{
    if(ptr)
    {
        printf("%d ",ptr->data);
        inorder(ptr->left);
        inorder(ptr->right);
    }
}

void postorder (struct node* ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        inorder(ptr->right);
        printf("%d ",ptr->data);
    }
}

int main() {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    int num;
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,0);
    root = insert(root,-1);
    root = insert(root,6);
    root = insert(root,7);
    root = insert(root,3);
    root = insert(root,4);
    root = delete(root,3);
    inorder(root);
    return 0;
}
