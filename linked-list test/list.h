#if !defined(LIST_H)
#define LIST_H

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(Node* tail, int data);
void freeList(Node* head);

#endif // LISTH
