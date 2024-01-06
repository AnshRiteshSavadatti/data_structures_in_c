#include <stdio.h>

// Function to generate the transitive closure of a zero-one matrix using Warshall's algorithm
void generateTransitiveClosure(int graph[][100], int vertices) {
    int closure[100][100];  // Assuming a maximum size of 100 for the matrix

    // Initialize the closure matrix with the given zero-one matrix
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            closure[i][j] = graph[i][j];
        }
    }

    // Update the closure matrix using Warshall's algorithm
    for (int k = 0; k < vertices; ++k) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }

    // Print the transitive closure matrix
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            printf("%d ", closure[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices;

    // Get the number of vertices from the user
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Declare a zero-one matrix (adjacency matrix)
    int graph[100][100];  // Assuming a maximum size of 100 for the matrix

    // Get the adjacency matrix from the user
    printf("Enter the zero-one matrix (adjacency matrix):\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Generate and display the transitive closure
    generateTransitiveClosure(graph, vertices);

    return 0;
}