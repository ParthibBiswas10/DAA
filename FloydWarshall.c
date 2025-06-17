#include <stdio.h>
#define inf 999
#define v 4

int graph[v][v];
int parent[v][v];
int distance[v][v];

void initialize(int graph[][v]) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            distance[i][j] = graph[i][j];
            if (i == j || graph[i][j] == inf)
                parent[i][j] = -1;
            else
                parent[i][j] = i;
        }
    }
}

void floyd(int graph[][v]) {
    initialize(graph);
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
}

void printParent() {
    printf("\nParent Matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%3d ", parent[i][j]);
        }
        printf("\n");
    }
}

void printDistance() {
    printf("\nDistance Matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (distance[i][j] == inf)
                printf("inf ");
            else
                printf("%d ", distance[i][j]);
        }
        printf("\n");
    }
}

void printPath(int a, int b) {
    if (a == b) {
        printf("%d ", a);
    } else if (parent[a][b] == -1) {
        printf("no path ");
    } else {
        printPath(a, parent[a][b]);
        printf("%d ", b);
    }
}

void printAllPath() {
    printf("\nAll Shortest Paths with Costs:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("Path from %d to %d: ", i, j);
            if (distance[i][j] == 999) {
                printf("no path\n");
            } else {
                printPath(i, j);
                printf("--> cost: %d\n", distance[i][j]);
            }
        }
    }
}

int main() {
    printf("Enter the weighted adjacency matrix (use 999 for INF):\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floyd(graph);
    printDistance();
    printParent();
    printAllPath();

    return 0;
}
