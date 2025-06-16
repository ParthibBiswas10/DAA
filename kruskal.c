#include<stdio.h>
#define max 100
int parent[max];
int find(int a){
    if(parent[a]!=a){
        parent[a]=find(parent[a]);
    }
    return parent[a];
}
void union_set(int u, int v){
    int rootu = find(u);
    int rootv = find(v);
    if(rootu!=rootv)   parent[rootv] = rootu;
  
}
//sort in increasing order based on weight
void sort(int graph[][3], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (graph[j][2] > graph[j+1][2]) {
                for (int k = 0; k < 3; k++) {
                    int temp = graph[j][k];
                    graph[j][k] = graph[j+1][k];
                    graph[j+1][k] = temp;
                }
            }
        }
    }
}
void kruskal(int v, int e, int graph[][3]){
    
    int count=0;
    int toal=0;
    int u,v,w;
    int mst[e][3];
     for (int i = 0; i <v; i++)
        parent[i] = i;

    sort(graph, e);
    for(int i=0;i<e && count<v-1;i++){    //i tracks how many edges we’ve checked from the full list (total E edges) and count tracks how many edges we’ve added to MST (goal: V - 1)
                             
        u=graph[i][0];
        v=graph[i][1];
        w=graph[i][2];

        if(find(u)!=find(v)){
            mst[i][0]=u;
            mst[i][1]=v;
            mst[i][2]=w;    
            count++;
            union_set(u,v); 
            toal+=w;

        }

    }

}
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
    kruskal(v, e, graph);
}