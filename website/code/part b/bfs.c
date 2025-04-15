#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Queue structure for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        // Queue is full
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element
int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        return -1;
    }
    item = q->items[q->front];
    if (q->front >= q->rear) {
        // Queue has only one element, reset after dequeue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Function to perform BFS traversal from a given vertex
void BFS(int graph[][MAX_VERTICES], int start_vertex, int n) {
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices
    Queue q;
    initQueue(&q);

    // Mark the starting vertex as visited and enqueue it
    visited[start_vertex] = 1;
    enqueue(&q, start_vertex);

    printf("BFS traversal starting from vertex %d:\n", start_vertex);

    while (!isEmpty(&q)) {
        // Dequeue a vertex from the queue and print it
        int current_vertex = dequeue(&q);
        printf("%d ", current_vertex);

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        for (int i = 0; i < n; i++) {
            if (graph[current_vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, start_vertex;

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

    // Input starting vertex for BFS
    printf("Enter the starting vertex (0 to %d): \n", n - 1);
    scanf("%d", &start_vertex);

    // Call BFS function to perform traversal
    BFS(graph, start_vertex, n);

    return 0;
}
