#include <stdio.h>
#include <stdlib.h>

struct Treenode{
    int data;
    struct Treenode* left;
    struct Treenode* right;
};

struct Treenode* insert(struct Treenode* root,int data){
    if (root == NULL){
        struct Treenode* node = (struct Treenode*)malloc(sizeof(struct Treenode));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (data < root->data){
        root->left = insert(root->left,data);
    }else if (data > root->data){
        root->right = insert(root->right,data);
    }

    return root;
}

struct Treenode* leftRotate(struct Treenode* root){
    struct Treenode* temp1 = root->right;
    struct Treenode* temp = root->right->left;
    root->right->left = root;
    root->right = temp;

    return temp1;
}

void freeTree(struct Treenode* root){
    if (root == NULL){
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    
    free(root);

}

int main(){
    struct Treenode* root = NULL;

    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);

    printf("旋转前根节点的值：%d\n",root->data);

    root = leftRotate(root);

    printf("旋转后根节点的值：%d\n",root->data);

    freeTree(root);

    return 0;
}