#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct Queue *q,int value){
    if(isFull(q)){
        printf("\n Queue overflow");
    }
    else{
        q->r++;
        q->arr[q->r]=value;
        printf("\n Enqueued value=%d",q->arr[q->r]);
    }
}

int dequeue(struct Queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("\n Queue is empty");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main()
{
    struct Queue q;
    q.size=10;
    q.f=-1;
    q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,10);
    enqueue(&q,20);
    printf("\n Dequeued value=%d",dequeue(&q));
    return 0;
}
