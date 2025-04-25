#include<stdio.h>
#define max 5
void BFS(int arr[][max],int s,int size){
    int front=-1;
    int rear=-1;
    int visited[size];
    for(int i=0;i<size;i++){
        visited[i]=0;
    }
    int queue[size];
    queue[++rear]=s;
    front++;
    visited[s]=1;
    while(rear>front){
        s=queue[front++];
        printf("%c--",s+65);
        for(int i=0;i<size;i++){
            if(arr[s][i] &&visited[i]==0){
                queue[rear++]=i;
                visited[i]=1;
            }
        }

    }

}

int main(){
    printf("Enter no of Vertices: ");
    int size;
    scanf("%d",&size);
    printf("Enter Adjacency Matrix of Graph: \n");
    int  arr[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int start=0;
    BFS(arr,start,size);
}