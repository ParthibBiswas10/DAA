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
void kruskal(int vertex, int e, int graph[][3]){
    
    int count=0;
    int total=0;
    int u,v,w;
    int mst[e][3];
     for (int i = 0; i <vertex; i++)
        parent[i] = i;

    sort(graph, e);
    for(int i=0;i<e && count<vertex-1;i++){   
        u=graph[i][0];
        v=graph[i][1];
        w=graph[i][2];

        if(find(u)!=find(v)){
            mst[count][0]=u;
            mst[count][1]=v;
            mst[count][2]=w;    
            count++;
            union_set(u,v); 
            total+=w;

        }

    }
    printf("\nMST edges: \n");
    for(int i=0;i<count;i++){
        printf("%d -- %d -- %d ",mst[i][0], mst[i][1], mst[i][2]);
        printf("\n");
    }
    printf("Total Weight of MST: %d\n", total);

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

/*Ankara Messi NOtes: 
    at line 47-50, we did mst[count][] not mst[i][] coz i is the index in all edges, not the MST!
    at line 40 , i tracks how many edges we’ve checked from the full list (total E edges) and count tracks how many edges we’ve added to MST (goal: V - 1)
    
    at line 21, 3 loops needed...the 3rd loop is required because Without the k loop, we can only swap the weights and not the vertices, We use k to swap all 3 values of each edge (source, destination, weight) so the edge order stays correct when sorting by weight.                     
*/