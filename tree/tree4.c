#include <stdio.h>
#include <stdlib.h>

struct treeNode{
    int data;
    int height;
    struct treeNode* left;
    struct treeNode* right;
};

int getHeight(struct treeNode* n){
    return (n == NULL) ? 0 : n->height;
}

int getBalance(struct treeNode* n){
    return (n == NULL) ? 0 : getHeight(n->left) - getHeight(n->right);
}

void updataHeight(struct treeNode* n){
    int leftH = getHeight(n->left);
    int rightH = getHeight(n->right);
    n->height = ((leftH > rightH) ? leftH : rightH) + 1;
}

struct treeNode* insert(struct treeNode* root,int data){
    if (root == NULL){
        root = (struct treeNode*)malloc(sizeof(struct treeNode));
        root->data = data;
        root->height = 1;
        root->left = root->right = NULL;
    }

    if (data > root->data){
        root->right = insert(root->right,data);
    }else if (data < root->data){
        root->left = insert(root->left);
    }else return root;

    updataHeight(root);

    int balance = getBalance(root);

    
}