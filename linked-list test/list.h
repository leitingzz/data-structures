#if !defined(LIST_H)
#define LIST_H

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(Node* tail, int data);
void freeList(Node* head);
Node* searchByValue(Node* head, int value);
Node* searchByLocate(Node* head, int locate);


#endif // LISTH
