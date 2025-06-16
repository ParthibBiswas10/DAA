#include<stdio.h>
void prims(){
    
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
    prims(v, e, graph);

}