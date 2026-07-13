#if !defined(LIST_H)
#define LIST_H

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data);
void freeList(Node* head);
Node* searchByValue(Node* head, int value);
Node* searchByLocate(Node* head, int locate);
Node* insert(Node* head, int num);
Node* delete(Node* head, int a);

#endif // LISTH
