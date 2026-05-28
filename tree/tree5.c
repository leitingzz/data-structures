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

treePtr rightRotate(treePtr root){
    treePtr temp1 = root->left->right;
    treePtr temp2 = root->left;
    root->left->right = root;
    root->left = temp1;
    return temp2;
}

treePtr insert(treePtr root,int data){
    if (root == NULL){
        treePtr newNode = (treePtr)malloc(sizeof(treeNode));
        root = newNode;
        root->data = data;
        root->height = 1;
        root->left = root->right = NULL;
    }

    if(data < root->data){
        root->left = insert(root->left,data);
    }else if (data > root->data){
        root->right = insert(root->right,data);
    }else return root;

    Updataheight(root);

    int Balance = getBalance(root);

    if (Balance > 1 && data < root->left->data) return rightRotate(root);
    if (Balance < -1 && data > root->right->data) return leftRotate(root);

    if (Balance > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (Balance < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

