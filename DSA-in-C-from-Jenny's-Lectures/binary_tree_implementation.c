#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if(x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter left child of %d \n", x);
    newnode->left = create();
    printf("Enter right child of %d \n", x);
    newnode->right = create();
    return newnode;
}

void preorder(struct node *root)
{
    if(root != 0)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root != 0)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root != 0)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void main()
{
    struct node *root;
    root = 0;
    root = create();
    printf("Preorder traversal: ");
    preorder(root);
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
}