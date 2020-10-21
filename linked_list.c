#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* Next;
    int v;
};
typedef struct Node Node;

typedef struct {
    Node* begin;
} List;

List* createList() {
    List* L = (List*) malloc(sizeof(List));
    if(L == NULL) return NULL;

    L->begin = NULL;
    return L;
}

void add(List* l, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    Node *a, *p;

    node->v = data;
    if(l->begin == NULL)  {
        l->begin = node;
        node->Next = NULL;
    }

    else {                     
        p = l->begin;
        a = p;
        while(p != NULL) {
            a = p;
            p = p->Next;
        }
        a->Next = node;
        node->Next = NULL;
    }
}

void printList(List* l) {
    Node* p = l->begin;
    if(p != NULL) {
        do {
            printf("%d ", p->v);
            p = p->Next;
        } while(p != NULL);
        printf("\n");
    }
}

int isEmpty(List* l){
    return (l->begin == NULL);
}

void removeBack(List* l) {
    Node *p, *a; 
    p = l->begin;
    a = p;
    
    
    if(p->Next == NULL) {
        l->begin = NULL;
        return;
    }

    while(p->Next != NULL) {
        a = p;
        p = p->Next;
    }
    a->Next = NULL;
    free(p);
}

int size(List* l) {
    Node* p = l->begin;
    int length = 0;
    
    if(l->begin == NULL) return 0;

    while(p != NULL) {
        p = p->Next;
        length++;
    }
    return length;
    
}

int main (void) {
    List *list = createList();
    if(isEmpty) printf("Empty list\n");

    add(list, 10);
    add(list, 20);
    add(list, 30);
    add(list, 40);
    add(list, 50); 
    printList(list);

    removeBack(list);
    printList(list);
    printf("Lenght: %d\n\n", size(list)); 

    printf("Final Lenght: %d\n\n", size(list)); 
    return 0;
}