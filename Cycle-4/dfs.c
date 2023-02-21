#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

int visited[MAX_NODES];
typedef struct node {
    int val;
    struct node* next;
} Node;

Node* newNode(int val){
    Node* new = (Node *)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    return new;
}

void dfs(int node, Node** graph){
    visited[node] = 1;
    printf("%d ", node);

    Node* current = graph[node];
    while (current != NULL) {
        int neighbor = current->val;
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
        current = current->next;
    }
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    // Create graph
    Node* graph[MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        graph[i] = NULL;
        visited[i] = 0;
    }

    // Add edges
    for (int i = 0; i < num_edges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);

        Node* new_node = newNode(destination);
        new_node->next = graph[source];
        graph[source] = new_node;
    }

    // Perform DFS
    int visited[MAX_NODES] = {0};
    dfs(0, graph);

    return 0;
}



