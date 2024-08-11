#include<stdio.h>
int visited[4]={0,0,0,0};
int adj[4][4]={
    {0,1,1,1},
    {1,0,1,0},
    {0,1,0,1},
    {1,0,1,0},
};

void DFS(int i){
    int j;
    printf("\n %d",i);
    visited[i]=1;
    for (j = 0; j < 4; j++)
    {
        if(adj[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
    
}
int main()
{
    DFS(0);
    return 0;
}