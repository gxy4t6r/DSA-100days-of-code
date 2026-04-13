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

void kahnTopoSort(struct Graph* graph) {
    int indegree[100] = {0};

    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    int queue[100], front = 0, rear = 0;

    for (int i = 0; i < graph->V; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    int count = 0;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        struct Node* temp = graph->adj[v];
        while (temp) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0)
                queue[rear++] = temp->vertex;
            temp = temp->next;
        }
    }

    if (count != graph->V)
        printf("\nCycle exists\n");
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    kahnTopoSort(graph);

    return 0;
}
