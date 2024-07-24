#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
void dlltrav(struct Node *head){
    do{
        printf("Element : %d\n",head->data);
        head=head->next;
    }while(head!=NULL);
}
struct Node *insatbeg(struct Node *head, int value){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    p->prev=NULL;
    p->data=value;
    p->next=head;
    head=p;
    return head;
}
struct Node *insatend(struct Node *head, int value){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    struct Node *q=head;
    p->data=value;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=p;
    p->prev=q;
    p->next=NULL;
    return head;
}
struct Node *insatindex(struct Node *head, int index, int value){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    struct Node *q=head->next;
    ptr->data=value;
    int i=0;
    while(i<index-1 && p!=NULL){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=ptr;
    q->prev=ptr;
    ptr->prev=p;
    ptr->next=q;
    return head;
}
struct Node *insafterval(struct Node *head, int aftval, int value){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    struct Node *q=head->next;
    ptr->data=value;
    while(p->data!=aftval && p!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=ptr;
    q->prev=ptr;
    ptr->prev=p;
    ptr->next=q;
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    head->prev=NULL;
    head->data=10;
    head->next=second;
    second->prev=head;
    second->data=20;
    second->next=third;
    third->prev=second;
    third->data=30;
    third->next=NULL;
    printf("\n Before insertion\n");
    dlltrav(head);
    head=insatbeg(head,5);
    head=insatend(head,35);
    head=insatindex(head,2,15);
    head=insafterval(head,20,25);
    printf("\n After insertion\n");
    dlltrav(head);
}
