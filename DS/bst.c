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

        if(ptr -> data != num)
        {
            printf("This node doesnt exist");
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
        else
        {
            printf("This node has both the left and right child");
        }
    }
    return root;
}

void inorder (struct node* ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        printf("%d\n",ptr->data);
        inorder(ptr->right);
    }
}

void preorder (struct node* ptr)
{
    if(ptr)
    {
        printf("%d\n",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder (struct node* ptr)
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\n",ptr->data);
    }
}

int left_height(struct node * ptr)
{
    int ht = 0;
    while (ptr) 
    {
        ht++;
        ptr = ptr->left;
    }
 
    return ht;
}

int right_height(struct node * ptr)
{
    int ht = 0;
    while (ptr) 
    {
        ht++;
        ptr = ptr->right;
    }
 
    return ht;
}

int countnodes(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = left_height(root);
    int rh = right_height(root);
    return 1 + countnodes(root->left) + countnodes(root -> right);
    
}

int main() 
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    int num,n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i = 0; i<n;i++)
    {
        printf("Enter integer data: ");
        scanf("%d", &num);
        root = insert(root,num);
    }
    

    printf("\n\nInorder traversal: \n");
    inorder(root);
    
    printf("\n\nPreorder traversal: \n");
    preorder(root);

    printf("\n\nPostorder traversal: \n");
    postorder(root);

    /*printf("Enter data of node to be deleted: ");
    scanf("%d",&num);
    delete(root,num);

    printf("\n\nInorder traversal: \n");
    inorder(root);
    
    printf("\n\nPreorder traversal: \n");
    preorder(root);

    printf("\n\nPostorder traversal: \n");
    postorder(root);*/

    int nodes = countnodes(root);
    printf("This tree has %d nodes.",nodes);
    return 0;
}

