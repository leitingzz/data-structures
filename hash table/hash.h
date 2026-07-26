#if !defined(HASH_H)
#define HASH_H
#define NUM 10

typedef struct Node{
    int data;
    struct Node* next;
}Node;

int hashFunc(int data);
void insert(Node* hash_table[]);
void search(Node* hash_table[]);
void delete(Node* hash_table[]);

#endif