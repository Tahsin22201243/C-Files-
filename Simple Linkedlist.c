#include<stdio.h>
#include<stdlib.h>

struct{
    int data;
    struct Node *next;
};

int main(){
    struct Node *a = NULL; 
    struct Node *b = NULL; 
    struct Node *c = NULL; 
    struct Node *d = NULL; 
    a = (struct Node*)malloc(sizeof(struct Node));
    b = (struct Node*)malloc(sizeof(struct Node));
    c = (struct Node*)malloc(sizeof(struct Node));
    d = (struct Node*)malloc(sizeof(struct Node));

    a->data = 10;
    b->data = 20;
    c->data = 30;
    d->data = 40;

    a->Next = 10;
    b->Next = 20;
    c->Next = 30;
    d->Next = 40;

    while(a! = NULL){

        printf("%d->",a->data);
        a = a->next;
    }
    return 0;


}