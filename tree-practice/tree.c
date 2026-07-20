#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

TreeNode* insert(TreeNode* root, int value){
    if(root == NULL){
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->data = value;
        node->left = NULL;
        node->right = NULL;
        root = node;
    }else if(value < root->data){
        root->left = insert(root->left, value);
    }else{
        root->right = insert(root->right, value);
    }
    return root;
}

void inorderprint(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorderprint(root->left);
    printf(root->data);
    inorderprint(root->right);
    return;

}