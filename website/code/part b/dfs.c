#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Array to keep track of visited vertices
int visited[MAX_VERTICES];

// Function to perform DFS traversal from a given vertex
void DFS(int graph[][MAX_VERTICES], int vertex, int n) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    // Print the visited vertex
    printf("%d ", vertex);

    // Recur for all adjacent vertices that are not visited
    for (int i = 0; i < n; i++) {
        // If there is an edge from vertex to i and i is not visited
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, n);
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, start_vertex;

    // Initialize visited array to 0
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0;
    }

    // Input number of vertices
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);

    // Input adjacency matrix (0 or 1)
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input starting vertex for DFS
    printf("Enter the starting vertex (0 to %d): \n", n - 1);
    scanf("%d", &start_vertex);

    // Print DFS traversal
    printf("DFS traversal starting from vertex %d:\n", start_vertex);
    DFS(graph, start_vertex, n);
    printf("\n");

    return 0;
}
