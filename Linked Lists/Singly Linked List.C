#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void listtrav(struct Node *ptr)
{
    while(ptr!=NULL){
    printf("Element = %d\n",ptr->data);
    ptr=ptr->next;
    }
}
struct Node *insatbeg(struct Node *head,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct Node *insatmiddle(struct Node *head,int data,int index){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node *insatend(struct Node *head,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node *insafter(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}
struct Node *delatbeg(struct Node *head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct Node *delatmid(struct Node *head,int index){
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct Node *delatend(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
struct Node *delval(struct Node *head, int value){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
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
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=NULL;
    printf("Before insertion\n");
    listtrav(head);
    printf("After insertion\nBefore deletion\n");
    head=insatbeg(head,5);
    head=insatmiddle(head,15,2);
    head=insatend(head,35);
    head=insafter(head, second, 25);
    listtrav(head);
    printf("After deletion\n");
    head=delatbeg(head);
    head=delatmid(head,2);
    head=delatend(head);
    head=delval(head,15);
    listtrav(head);
    return 0;
}
