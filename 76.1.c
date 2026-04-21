#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];
int n; // number of vertices

void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int countComponents() {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main() {
    n = 5;

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Example graph
    // Component 1: 0-1-2
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;

    // Component 2: 3-4
    adj[3][4] = adj[4][3] = 1;

    int result = countComponents();
    printf("Number of connected components: %d\n", result);

    return 0;
}
