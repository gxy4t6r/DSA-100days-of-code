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
}

void topoDFS(struct Graph* graph, int v, int visited[], int stack[], int *top) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->vertex])
            topoDFS(graph, temp->vertex, visited, stack, top);
        temp = temp->next;
    }

    stack[++(*top)] = v;
}

void topologicalSort(struct Graph* graph) {
    int visited[100] = {0};
    int stack[100];
    int top = -1;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i])
            topoDFS(graph, i, visited, stack, &top);
    }

    while (top >= 0)
        printf("%d ", stack[top--]);
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
