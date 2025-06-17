#include<stdio.h>
#define inf 999
int graph[4][4];
int parent[4][4];
int distance[4][4];
int main(){
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