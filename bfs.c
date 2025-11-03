#include <stdio.h>
#include <stdlib.h>

void bfs(int n, int **adj, int start) {
    int *visited = calloc(n, sizeof(int));
    int *queue = malloc(n * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;  

    printf("BFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
    free(visited);
    free(queue);
}

int main() {
    int n, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Allocate adjacency matrix dynamically
    int **adj = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        adj[i] = malloc(n * sizeof(int));

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(n, adj, start);

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);

    return 0;
}
