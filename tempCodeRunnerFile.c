#include<stdio.h>
int minkey(int key[],int v,int visited[]){
    int min=999;
    int minIndex=-1;
    for(int i=0;i<v;i++){
        if(visited[i]==0 && key[i]<min){
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void prims(int graph[][100],int v){
    int parent[v];
    int key[v];
    int visited[v];
    for(int i=0;i<v;i++){
        key[i]=999;
        visited[i]=0;
    }
    key[0]=0;
    int total=0;
    parent[0]=-1;
    for(int i=0;i<v;i++){
        int u=minkey(key,v,visited);
         if(u == -1) {
        printf("Graph is disconnected. MST cannot be formed.\n");
        return;
    }
        visited[u]=1;
        for(int j=0;j<v;j++){
            if(graph[u][j]  && visited[j]==0 && graph[u][j]<key[j]){
                parent[j]=u;
                key[j]=graph[u][j];
                
            }
        }
    }
    //Print of MST:
    for(int i=1;i<v;i++){
        printf("%d--%d--%d\n",parent[i],i,key[i]);
    }
    for(int i=1;i<v;i++) {
        total+=key[i];}
    printf("Min Cost: %d",total);

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
        scanf("%d", &graph[i][j]);
        }
    }
    prims(graph,v);

}