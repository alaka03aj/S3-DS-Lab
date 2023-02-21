#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct node {
    int vertex;
    struct node *next;
} node_t;       //adjacency list

node_t *graph[MAX_SIZE];
bool visited[MAX_SIZE];

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int vertex){
    if (rear == MAX_SIZE-1){
        printf("Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue(){
    if (front == -1 && rear == -1){
        printtf("Underflow\n");
        return;
    }
    int v = queue[front];
    if (front == 0)
        front = rear = -1;
    else
        front++;
    return v;
}

void add_edge(int u, int v){
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void bfs(int start){
    //printf("%d",start);
    visited[start] = true;
    enqueue(start);

    while(front<=rear){
        int v = dequeue();
        printf("%d ",v);

        node_t *adjList = graph[v];
        while(adjList!=NULL){
            int u = adjList->vertex;
            while(!visited[u]){
                visited[u] = true;
                enqueue(u);
            }
            adjList = adjList->next;
        }
    }
}

int main() {
    int num_vertices, num_edges, u, v, start;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        graph[i] = NULL;
        visited[i] = false;
    }

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        printf("Enter the endpoints of edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    bfs(start);
    return 0;
}
