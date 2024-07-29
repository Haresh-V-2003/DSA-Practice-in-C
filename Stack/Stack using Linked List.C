#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node *top){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void *stackTrav(struct Node *top){
    while(top!=NULL){
        printf("\n Element=%d",top->data);
        top=top->next;
    }
}

struct Node *push(struct Node *top,int value){
    if(isFull(top)){
        printf("\n Stack overflow");
    }
    else{
        struct Node *n=(struct Node*)malloc(sizeof(struct Node));
        n->data=value;
        n->next=top;
        top=n;
        return top;
    }
}
//treat top as a pointer of a pointer since we are calling it by reference
int pop(struct Node **top){
    if(isEmpty(*top)){
        printf("\n Stack underflow");
    }
    else{
        struct Node *n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}

int peek(struct Node *top,int pos){
    struct Node *ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}

int stackTop(struct Node *top){
    return top->data;
}

int stackBottom(struct Node *top){
    struct Node *q=top;
    if(q==NULL){
        return -1;
    }
    else{
        while(q->next!=NULL){
            q=q->next;
        }
        return q->data;
    }
}
int main()
{
    struct Node *top=NULL;
    top=push(top,10);
    top=push(top,20);
    top=push(top,30);
    stackTrav(top);
    //pass top as reference since it went into an infinite loop when we passed it as a value
    int element=pop(&top);
    stackTrav(top);
    printf("\n The value at position 2 is:%d",peek(top,2));
    printf("\n Top of the stack is:%d",stackTop(top));
    printf("\n Bottom of the stack is:%d",stackBottom(top));
    return 0;
}
