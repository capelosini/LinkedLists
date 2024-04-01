#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node{
    int data;
    node* next;
    node* prev;
};

node* createList(int initValue){
    node* n = (node*)malloc(sizeof(node));
    n->data = initValue;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void push(node* n, int value){
    node* new = (node*)malloc(sizeof(node));
    new->data=value;
    new->next=NULL;
    while(n->next != NULL){
        n=n->next;
    }
    new->prev=n;
    n->next=new;
}

void printList(node* n){
    while (n->next != NULL){
        printf("%d\n", n->data);
        n=n->next;
    }
    printf("%d\n", n->data);
}

void pop(node* n, int i){
    int c=0;
    while (c <= i){
        if (c == i){
            if (n->prev != NULL && n->next != NULL){
                // printf("\nMIDDLE ELEMENT\n");
                n->prev->next=n->next;
                n->next->prev=n->prev;
                free(n);
            } else if (n->prev == NULL){
                // printf("\nFIRST ELEMENT\n");
                n->data=n->next->data;
                node* temp = n->next;
                n->next=n->next->next;
                n->next->prev=n;
                free(temp);
            } else {
                // printf("\nLAST ELEMENT\n");
                n->prev->next=NULL;
                free(n);
            }
            return;
        }
        if(n->next == NULL){ break; }
        n=n->next;
        c++;
    }
}

int length(node* n, int i){
    if (n->next == NULL){
        return i;
    }
    length(n->next, i+1);
}

int main(){
    node* list = createList(2);
    push(list, 3);
    push(list, 4);
    push(list, 5);
    push(list, 6);
    printList(list);
    printf("\nLength: %d\n", length(list, 0));
    pop(list, 3);
    printList(list);
    printf("\nLength: %d\n", length(list, 0));
    return 0;
}