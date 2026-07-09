#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Node* createNode(Node* tail, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(tail == NULL){
        tail = newNode;
    } else{
        tail->next = newNode;
    }
    return newNode;
}

void freeList(Node* head){
    Node* temp = head;
    Node* next;
    while(temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
}
