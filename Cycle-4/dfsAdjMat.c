#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];

void dfs(int vertex, int n){
    visited[vertex] = true;
    printf("%d ",vertex);

    for (int i=0; i<n; i++){
        if (graph[vertex][i] == 1 && !visited[i]){
            dfs(i,n);
        }
    }
}

void main(){
    int n, start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix of graph below.\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter the starting element: ");
    scanf("%d",&start);
    dfs(start,n);
}