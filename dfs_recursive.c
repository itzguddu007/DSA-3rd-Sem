#include <stdio.h>
#include <stdlib.h>

void dfs(int n, int **adj, int start, int *visited) {
    // Step 1: Print and mark the current node as visited
    printf("%d ", start);
    visited[start] = 1;

    // Step 2: Visit all unvisited neighbors (0 → n-1)
    for (int i = 0; i < n; i++) {
        if (adj[start][i] && !visited[i]) {
            dfs(n, adj, i, visited);  // Recursive call
        }
    }
}

int main() {
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Allocate adjacency matrix
    int **adj = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        adj[i] = malloc(n * sizeof(int));

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    int *visited = calloc(n, sizeof(int));

    printf("DFS Traversal: ");
    dfs(n, adj, start, visited);
    printf("\n");

    // Free memory
    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);
    free(visited);

    return 0;
}
