#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("\n Stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("\n Stack underflow");
        return 0;
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *sp,int i){
    int position=sp->top-i+1;
    if(position<0){
        printf("\n Invalid peek operation");
        return -1;
    }
    else{
        return sp->arr[position];
    }
}

int stackTop(struct stack *sp){
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp){
    return sp->arr[0];
}
int main()
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size * sizeof(int));
    printf("\n Before pushing");
    if(isFull(sp)){
        printf("\n stack overflow");
    }
    else{
        printf("\n stack is not full");
    }
    if(isEmpty(sp)){
        printf("\n stack underflow");
    }
    else{
        printf("\n stack is not empty");
    }

    printf("\n After pushing");
    push(sp,10);
    push(sp,20);
    push(sp,30);
    push(sp,40);
    push(sp,50);
    push(sp,60);
    push(sp,70);
    push(sp,80);
    push(sp,90);
    push(sp,100);
    printf("\n Value popped=%d",pop(sp));
    if(isFull(sp)){
        printf("\n stack overflow");
    }
    else{
        printf("\n stack is not full");
    }
    if(isEmpty(sp)){
        printf("\n stack underflow");
    }
    else{
        printf("\n stack is not empty");
    }
    for(int j=1;j<=sp->top+1;j++){
        printf("\n The value at position %d is %d",j,peek(sp,j));
    }
    printf("\n Stack top=%d",stackTop(sp));
    printf("\n Stack bottom=%d",stackBottom(sp));
    return 0;
}
