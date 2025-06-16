#include<stdio.h>
int main(){
    int v,e;
    
    printf("Enter no of Vertices: ");
    scanf("%d",&v);
     printf("Enter no of Edges: ");
    scanf("%d",&e);
    int graph[e][3];
    printf("Enter Source-Destination-Weight:\n");
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&graph[i][0],&graph[i][1],&graph[i][2]);
    }
    prims(v, e, graph);

}