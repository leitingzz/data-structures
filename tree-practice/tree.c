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
    printf("%d ", root->data);
    inorderprint(root->right);
    return;

}

void preorderprint(TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorderprint(root->left);
    preorderprint(root->right);
    return;
}

void postorderprint(TreeNode* root){
    if(root == NULL){
        return;
    }
    postorderprint(root->left);
    postorderprint(root->right);
    printf("%d ", root->data);
    return;
}

void enqueue(queue** head, queue** tail, TreeNode* node){
    if(node == NULL){
        return;
    }
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->node = node;
    temp->next = NULL;

    if(*head == NULL){
        *head = temp;
        *tail = temp;
    }else{
        (*tail)->next = temp;
        *tail = temp;
    }
    return;
}

TreeNode* dequeue(queue** head, queue** tail){
    if(*head == NULL){
        return NULL;
    }
    queue* temp = *head;
    TreeNode* node = temp->node;
    if((*head)->next == NULL){
        *head = NULL;
        *tail = NULL;
        free(temp);
        return node;
    }

    *head = (*head)->next;
    free(temp);
    return node;
}

void levelorderPrint(TreeNode* root){
    queue* head = NULL;
    queue* tail = NULL;
    enqueue(&head, &tail, root);
    while(head != NULL){
        TreeNode* temp = dequeue(&head, &tail);
        printf("%d ", temp->data);
        if(temp->left != NULL){
            enqueue(&head, &tail, temp->left);
        }
        if(temp->right != NULL){
            enqueue(&head, &tail, temp->right);
        }
    }
    return;
}

int countNodes(TreeNode*root){
    
}