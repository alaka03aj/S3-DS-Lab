#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int vertex){
    if (rear == MAX_SIZE - 1){
        printf("Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue(){
    if (front == -1 || front>rear){
        printf("underflow\n");
        return -1;
    }
    int item = queue[front];
    front++;
    return item;
}

void bfs(int start, int n){
    printf("Starts from: %d",start);
    visited[start] = true;
    enqueue(start);

    while(front<=rear){
        int vertex = dequeue();
        printf("%d",vertex);

        for (int i=0; i<n; i++){
            if (graph[vertex][i]==1 && !visited[i]){
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bfs(start, n);

    return 0;
}