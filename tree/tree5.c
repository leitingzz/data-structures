#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    int data;
    struct treeNode* left;
    struct treeNode* right;
    int height;
}treeNode,*treePtr;

int getHeight(treePtr n){
    return (n == NULL) ? 0 : n->height;
}

int getBalance(treePtr n){
    return (n == NULL) ? 0 :getHeight(n->left) - getHeight(n->right);
}

void Updataheight(treePtr n){
    int leftH = getHeight(n->left->height);
    int rightH = getHeight(n->right->height);
    n->height = ((leftH > rightH) ? leftH : rightH) + 1;
}

treePtr leftRotate(treePtr root){
    treePtr temp1 = root->right->left;
    treePtr temp2 = root->right;
    root->right->left = root;
    root->right = temp1;
    return temp2;
}

