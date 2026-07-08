#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Node* createNode(Node* head,Node* tail, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

