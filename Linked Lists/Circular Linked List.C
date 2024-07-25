#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *lltrav(struct Node *head){
    struct Node *ptr=head;
    do
    {
        printf("\nElement:%d",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    
}
struct Node *insatbeg(struct Node *head, int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head->next;
    ptr->data=data;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
struct Node *insatend(struct Node *head, int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head->next;
    ptr->data=data;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return head;
}
struct Node *insatindex(struct Node *head,int index, int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    struct Node *q=p->next;
    ptr->data=data;
    int i=0;
    while (p->next!=head && i<index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=ptr;
    ptr->next=q;
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=fourth;
    fourth->data=40;
    fourth->next=head;
    printf("\nBefore insertion");
    lltrav(head);
    printf("\nAfter insertion");
    head=insatbeg(head,5);
    head=insatend(head,45);
    head=insatindex(head,2,11);
    lltrav(head);
    return 0;
}
