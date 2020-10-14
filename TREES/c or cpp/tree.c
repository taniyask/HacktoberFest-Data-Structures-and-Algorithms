/*Program to implement binary trees, find its height, and print the values in various orders
Author: Taniya S. Kulkarni*/

#include <stdio.h>
#include <stdlib.h>

struct tree	//Tree structure
{
    int num;
    struct tree *right;
    struct tree *left;
};


struct tree *insert()		//Funtion to insert values into tree
{
    struct tree *ptr;
    int val;
    printf("\nEnter number (Enter -1 to stop): ");
    scanf("%d", &val);
    if(val == -1)
    {
        return NULL;
    }
    ptr = (struct tree*)malloc(sizeof(struct tree));
    ptr->num = val;
    printf("\nENTER LEFT CHILD OF %d: ", val);
    ptr->left = insert();
    printf("\nENTER RIGHT CHILD OF %d:", val);
    ptr->right = insert();
    return ptr;
}

int height(struct tree *ptr)		//Function to find the height of the entire tree
{
    if(ptr == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = height(ptr->left);
        int right_height = height(ptr->right);
        if(left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}

int node_height (struct tree *ptr, int val, int lev)		//Funtion to find the height/level of a given node
{
    int dlev;
    if(ptr == NULL)
        return 0;
    if(ptr->num == val)
    {
        return lev;
    }
    dlev = node_height(ptr->left, val, lev+1);
    if(dlev != 0)
    {
        return dlev;
    }
    dlev = node_height(ptr->right, val, lev+1);
    return dlev;
}

int get_height(struct tree *ptr, int val)
{
    return node_height (ptr, val, 1);
}

void preorder(struct tree *ptr)		//Funtion to print values of tree in preorder form
{
    if(ptr == NULL)
    {
        return;
    }
    else
    {
        printf(" %d ", ptr->num);
        preorder (ptr->left);
        preorder (ptr->right);
    }
}

void postorder(struct tree *ptr)	//Funtion to print values of tree in postorder form
{
    if(ptr == NULL)
    {
        return;
    }
    else
    {
        postorder (ptr->left);
        postorder (ptr->right);
        printf(" %d ", ptr->num);
    }
}

void inorder(struct tree *ptr)		//Funtion to print values of tree in inorder form
{
    if(ptr == NULL)
    {
        return;
    }
    else
    {
        inorder (ptr->left);
        printf(" %d ", ptr->num);
        inorder (ptr->right);
    }
}

int main()
{
    struct tree *root;
    root = insert();
    printf("\n-------------------------");
    printf("\n\n PREORDERED TRAVERSAL:\n");
    preorder(root);
    printf("\n\n-------------------------");
    printf("\n-------------------------");
    printf("\n\n POSTORDERED TRAVERSAL:\n");
    postorder(root);
    printf("\n\n-------------------------");
    printf("\n-------------------------");
    printf("\n\n INORDERED TRAVERSAL:\n");
    inorder(root);
    printf("\n\n-------------------------");
    printf("\n-------------------------");
    printf("\n\n HEIGHT OF TREE:\n");
    printf(" %d ", height(root));
    printf("\n\n-------------------------");
     printf("\n-------------------------");
    printf("\n\n HEIGHT OF EACH NODE:\n");
    int flag = 1;
    while(flag)
    {
        int val;
        printf("  \n Enter node whose height you wish to find: ");
        scanf("%d", &val);
        int lev = get_height(root, val);
        if (lev != 0)
        {
            printf("   Level of node %d: %d", val, get_height(root, val));
        }
        else
        {
            printf("  %d is not a node! ", val);   
        }
        printf("\n\n  Do you wish to check the height of another node? (1/0): ");
        scanf("%d", &flag);
    }
    printf("\n\n-------------------------");
    
    return 0;
}
