#include<stdio.h>
void prims(int graph[][],int v){
    int parent[v];
    int key[v];
    int visited[v];
    for(int i=0;i<v;i++){
        key[i]=999;
        visited[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<v;i++){
        
    }

}

int main(){
    int v,e;
    
    printf("Enter no of Vertices: ");
    scanf("%d",&v);
     //printf("Enter no of Edges: ");
    //scanf("%d",&e);
    int graph[v][v];
    printf("Enter Adjacency Matrix:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
        scanf("%d", graph[i][j]);
        }
    }
    prims(graph,v);

}