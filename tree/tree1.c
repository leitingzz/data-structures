
//简单二叉树

#include <stdio.h>
#include <stdlib.h>

struct Treenode
{
    int data;
    struct Treenode *left;
    struct Treenode *right;
};

void preOrder(struct Treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {   
        printf("%d\n",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Treenode *root = (struct Treenode *)malloc(sizeof(struct Treenode));
    root->data = 10;
    root->left = NULL;
    root->right = NULL;

    struct Treenode *childL = (struct Treenode *)malloc(sizeof(struct Treenode));
    childL->data = 20;
    childL->left = NULL;
    childL->right = NULL;

    struct Treenode *childR = (struct Treenode *)malloc(sizeof(struct Treenode));
    childR->data = 30;
    childR->left = NULL;
    childR->right = NULL;

    root->left = childL;
    root->right = childR;

    printf("前序遍历结果：\n");
    preOrder(root);

    free(root);
    free(childL);
    free(childR);

    return 0;
}