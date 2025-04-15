#include <stdio.h>
#include <stdlib.h>

// Function to print the matrix
void printMatrix(int matrix[][20], int n) {
    // Loop through each row
    for (int i = 0; i < n; i++) {
        // Loop through each column
        for (int j = 0; j < n; j++) {
            // Print the element followed by a tab
            printf("%d\t", matrix[i][j]);
        }
        // New line after each row
        printf("\n");
    }
}

// Function to implement Warshall's algorithm for transitive closure
void warshall(int graph[][20], int n) {
    // Create a matrix to store transitive closure
    int reach[20][20];
    
    // Initialize reach matrix as input graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            reach[i][j] = graph[i][j];
    
    // Update reach matrix using dynamic programming
    // k is the intermediate vertex
    for (int k = 0; k < n; k++) {
        // i is the source vertex
        for (int i = 0; i < n; i++) {
            // j is the destination vertex
            for (int j = 0; j < n; j++) {
                // If vertex k is on a path from i to j,
                // then update reach[i][j]
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    
    // Print the transitive closure matrix
    printf("\nTransitive closure matrix:\n");
    printMatrix(reach, n);
}

int main() {
    int graph[20][20];
    int n;

    // Input number of vertices
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);

    // Input the adjacency matrix (0 or 1)
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the input graph
    printf("\nInput Graph (Adjacency Matrix):\n");
    printMatrix(graph, n);

    // Apply Warshall's algorithm
    warshall(graph, n);

    return 0;
}
