#include <stdio.h>
#include <stdlib.h>

struct Treenode
{
    int data;
    struct Treenode *childL;
    struct Treenode *childR;
};

struct Treenode  *insert(struct Treenode *root,int data)
{
    if (root == NULL)
    {
        struct Treenode *node = (struct Treenode *)malloc(sizeof(struct Treenode));
        node->data = data;
        node->childL = NULL;
        node->childR = NULL;

        return node;
    }

    if (data < root->data)
    {
        root->childL = insert(root->childL,data);
    }

    else if (data > root->data)
    {
        root->childR = insert(root->childR,data);
    }

    return root;
};

void inOrder(struct Treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrder(root->childL);
        printf("%d\n",root->data);
        inOrder(root->childR);
    }
}

void FreeTree(struct Treenode *root)
{
    if (root == NULL)
    {
        return;
    }

    FreeTree(root->childL);
    FreeTree(root->childR);

    printf("正在释放：%d\n",root->data);
    free(root);
}

int main()
{
    struct Treenode *root = NULL;
    int num[] = {10,5,15,3,7};
    for (int i = 0;i < 5;i++)
    {
        root = insert(root,num[i]);
    }
    
    inOrder(root);

    FreeTree(root);

    root = NULL;
    printf("内存已全部释放\n");
    
    return 0;
}