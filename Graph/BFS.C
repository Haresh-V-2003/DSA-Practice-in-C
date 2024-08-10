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
    q.size=100;
    q.f=0;
    q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    int node;
    int i=2;//i denotes the starting node
    int visited[4]={0,0,0,0};
    int adj[4][4]={
        {0,1,1,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0},
    };
    printf("\n %d",i);
    visited[i]=1;
    enqueue(&q,i);
    while(!isEmpty(&q)){
        node=dequeue(&q);
        for(int j=0;j<4;j++){
            if(adj[node][j]==1 && visited[j]==0){
                printf("\n %d",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
    return 0;
}
