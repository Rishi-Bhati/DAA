#include <stdio.h>
#include <stdlib.h>

// Define infinity for unreachable edges
#define INF 99999

// Function to print the distance matrix
void printMatrix(int matrix[][20], int n) {
    // Loop through each row
    for (int i = 0; i < n; i++) {
        // Loop through each column
        for (int j = 0; j < n; j++) {
            // If distance is infinity, print INF
            if (matrix[i][j] == INF)
                printf("INF\t");
            // Otherwise print the distance
            else
                printf("%d\t", matrix[i][j]);
        }
        // New line after each row
        printf("\n");
    }
}

// Function to implement Floyd's algorithm
void floyds(int graph[][20], int n) {
    // Create distance matrix and initialize it as input graph
    int dist[20][20];
    
    // Copy the input graph to distance matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Core of Floyd's algorithm using dynamic programming
    // k is the intermediate vertex
    for (int k = 0; k < n; k++) {
        // i is the source vertex
        for (int i = 0; i < n; i++) {
            // j is the destination vertex
            for (int j = 0; j < n; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the distance
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printf("\nShortest distances between all pairs of vertices:\n");
    printMatrix(dist, n);
}

int main() {
    int graph[20][20];
    int n;

    // Input number of vertices
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (Enter %d for infinity):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the input graph
    printf("\nInput Graph (Adjacency Matrix):\n");
    printMatrix(graph, n);

    // Apply Floyd's algorithm
    floyds(graph, n);

    return 0;
}
