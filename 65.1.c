#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

int dfsCycle(struct Graph* graph, int v, int visited[], int parent) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        int adjV = temp->vertex;

        if (!visited[adjV]) {
            if (dfsCycle(graph, adjV, visited, v))
                return 1;
        } else if (adjV != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int isCycle(struct Graph* graph) {
    int visited[100] = {0};

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfsCycle(graph, i, visited, -1))
                return 1;
        }
    }

    return 0;
}

int main() {
    struct Graph* graph = createGraph(4);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);

    if (isCycle(graph))
        printf("Cycle exists\n");
    else
        printf("No cycle\n");

    return 0;
}
