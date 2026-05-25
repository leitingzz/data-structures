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

struct treeNode* leftRotate(struct treeNode* root){
    struct treeNode* temp1 = root->right->left;
    struct treeNode* temp2 = root->right;
    root->right->left = root;
    root->right = temp1;
    return temp2;
}

struct treeNode* rightRotate(struct treeNode* root){
    struct treeNode* temp1 = root->left;
    struct treeNode* temp2= root->left->right;
    root->left->right = root;
    root->left = temp2;
    return temp1;
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
        root->left = insert(root->left,data);
    }else return root;

    updataHeight(root);

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data) return rightRotate(root);
    if (balance < -1 && data > root->right->data) return leftRotate(root);
    
    if (balance > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}