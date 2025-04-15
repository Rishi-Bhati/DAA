#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Array to keep track of visited vertices
int visited[MAX_VERTICES];

// Array to store the topological order
int topoOrder[MAX_VERTICES];

// Index for the topological order array
int index;

// Recursive function to perform DFS and fill topoOrder
void topologicalSortUtil(int graph[][MAX_VERTICES], int vertex, int n) {
    // Mark the current vertex as visited
    visited[vertex] = 1;

    // Recur for all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            topologicalSortUtil(graph, i, n);
        }
    }

    // After visiting all adjacent vertices, add current vertex to topoOrder
    topoOrder[index] = vertex;
    index--;
}

// Function to perform topological sort
void topologicalSort(int graph[][MAX_VERTICES], int n) {
    // Initialize visited array and index
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    index = n - 1;

    // Call the recursive helper function for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, n);
        }
    }

    // Print the topological order
    printf("Topological Sort Order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", topoOrder[i]);
    }
    printf("\n");
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n;

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

    // Perform topological sort
    topologicalSort(graph, n);

    return 0;
}
