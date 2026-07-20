#if !defined(LIST_H)
#define LIST_H

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data);
void freeList(Node* head);
Node* searchByValue(Node* head, int value);
void searchByLocate(Node* head, int num);
Node* insert(Node* head, int num, Node** tail);
Node* delete(Node* head, int a, Node** tail, int* num);
Node* reverseList(Node* head, Node** tail);
Node* fideMiddle(Node* head, int num);
void hasCycle(Node* head);

#endif 
