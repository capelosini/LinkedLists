#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node node;

node* createNode();
void push(node* n, int value);
void pop(node* n, int i);
int count(node* n, int i);
int length(node* n);
void printList(node* n);

struct node{
    int data;
    node* next;
};

node* createNode(int initValue){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = initValue;
    newNode->next = NULL;
}

void push(node* n, int value){
    while (n->next != NULL){
        n = n->next;
    }
    node* newNode=createNode(value);
    n->next = newNode;
}

void pop(node* n, int i){
    if (i==0){
        node* nextNode = n->next;
        n->data = nextNode->data;
        n->next = nextNode->next;
        free(nextNode);
        return;
    }
    
    int j=0;
    while (i != j+1){
        if (n->next->next == NULL){ return; }
        n=n->next;
        j++;
    }
    node* nextNode = n->next;
    n->next = nextNode->next;
    free(nextNode);
    return;
}

int count(node* n, int i){
    i++;
    if (n->next == NULL){
        return i;
    }
    count(n->next, i);
}

int length(node* n){
    int i=0;
    return count(n, 0);
}

void printList(node* n){
    while (n->next != NULL){
        printf("%d\n", n->data);
        n=n->next;
    }
    printf("%d\n", n->data);
}

int main(){

    node* list = createNode(1);

    push(list, 2);
    push(list, 3);
    push(list, 4);
    push(list, 5);

    printList(list);
    printf("Length: %d\n", length(list));
    pop(list, 0);
    printList(list);
    printf("Length: %d\n", length(list));

    return 0;
}