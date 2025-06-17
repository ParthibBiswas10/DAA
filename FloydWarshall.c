#include<stdio.h>
#define inf 999
#define v 4 //for this graph;
int graph[v][v];
int parent[v][v];
int distance[4][4];
void initialize(int graph[][v]){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            distance[i][j]=graph[i][j];
            if(i==j|| graph[i][j]==inf) parent[i][j]=-1;
            else parent[i][j]=i;
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
void printParent(){
    printf("Parent Matrix: \n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",parent[i][j]);
        }
        printf("\n");
    }
}
void printDistance(){
     printf("Distance Matrix: \n");
     for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",distance[i][j]);
        }
        printf("\n");
    }
}
void printAllPath(){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("Path from %d to %d: ",i,j);
            if(distance[i][j]==inf) printf("no path");
            else{
                printPath(i,j);
            }
        }
    }
}
int main(){
    //Weighted Directed Graph input: 
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d ",&graph[i][j]);
        }
        printf("\n");
    }
    floyd(graph);
    printDistance();
    printParent();
    printAllPath();

}