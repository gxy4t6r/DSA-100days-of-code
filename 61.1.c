#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int vertices;

void initGraph(int v) {
    vertices = v;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            adj[i][j] = 0;
}

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void printGraph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initGraph(4);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);

    printGraph();
    return 0;
}
