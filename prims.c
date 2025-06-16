#include <stdio.h>
#include <limits.h>

int minkey(int key[], int v, int visited[]) {
    int min = 999, minIndex = -1;
    for (int i = 0; i < v; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void prims(int graph[][100], int v) {
    int parent[v];
    int key[v];
    int visited[v];

    for (int i = 0; i < v; i++) {
        key[i] = 999;
        visited[i] = 0;
    }

    key[0] = 0;         
    parent[0] = -1;

    for (int count = 0; count < v; count++) {
        int u = minkey(key, v, visited);
        visited[u] = 1;

        for (int j = 0; j < v; j++) {
            if (graph[u][j] && !visited[j] && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    int total = 0;
    printf("Edge\tWeight\n");
    for (int i = 1; i < v; i++) {
        printf("%d - %d\t%d\n", parent[i], i, key[i]);
        total += key[i];
    }

    printf("Min Cost: %d\n", total);
}

int main() {
    int v;
    printf("Enter no of Vertices: ");
    scanf("%d", &v);

    int graph[100][100]; // Adjust size if needed
    printf("Enter Adjacency Matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prims(graph, v);
    return 0;
}

/*
    try this input: 
        Enter no of Vertices: 7
        Enter Adjacency Matrix:
0 28 0 0 0 10 0
28 0 16 0 0 0 14
0 16 0 12 0 0 0
0 0 12 0 22 0 18
0 0 0 22 0 25 24
10 0 0 0 25 0 0
0 14 0 18 24 0 0

answer should be 99

*/