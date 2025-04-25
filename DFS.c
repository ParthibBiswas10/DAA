#include<stdio.h>
#define max 5
void DFS(int arr[][max],int s,int size){
    int top=-1;
    int visited[size];
    for(int i=0;i<size;i++){
        visited[i]=0;
    }
    int stack[size];
    stack[++top]=s;
    visited[s]=1;
    while(top!=-1){
        s=stack[top--];
        printf("%c--",s+65);
        for(int i=0;i<size;i++){
            if(arr[s][i] &&visited[i]==0){
                stack[++top]=i;
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
    DFS(arr,start,size);


}