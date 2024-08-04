#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createnode(int value){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}

void printlist(struct Node *head){
    struct Node *ptr=head;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

void revlist(struct Node *head){
    struct Node *current=head;
    struct Node *beforenode=NULL;
    struct Node *afternode=NULL;
    while(current!=NULL){
        afternode=current->next;
        current->next=beforenode;
        beforenode=current;
        current=afternode;
    }
    current=beforenode;
    printlist(current);
}
int main()
{
    struct Node *head;
    head=createnode(10);
    head->next=createnode(20);
    head->next->next=createnode(30);
    head->next->next->next=createnode(40);
    printf("\n original list:");
    printlist(head);
    printf("\n reversed list:");
    revlist(head);
    return 0;
}
