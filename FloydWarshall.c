#include<stdio.h>
#define inf 999
int v=4; //for this graph;
int graph[4][4];
int parent[4][4];
int distance[4][4];
void initialize(int graph[][v]){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            distance[i][j]=graph[i][j];
        }
    }
}
void floyd(int graph[][4]){
    initialize(graph);
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                   graph[i][j]=graph[i][k]+graph[k][j];
                   parent[i][j]=parent[k][j];
                }
            }
        }
    }
}
int main(){
    //Weighted Directed Graph input: 
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d ",&graph[i][j]);
        }
    }
    floyd(graph);
    printDistance();
    printParent();
    printPath();

}