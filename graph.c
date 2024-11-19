#include <stdio.h>
#include <stdlib.h>

#define n 5

void bfs(int graph[n][n], int start) {
    int visited[n] = {0};
    int queue[n], front = 0, rear = 0;

    visited[start] = 1;  // Mark the starting vertex as visited (1 = true)
    queue[rear++] = start;

    printf("BFS starting from vertex %d: ", start);

    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;  // Mark vertex as visited
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int graph[n][n], int visited[n], int current) {
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

int main() {
    int graph[n][n] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int choice, startVertex;
    int visited[n] = {0};

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    printf("Enter\n1 - DFS\n2 - BFS\n");
    scanf("%d", &choice);

    if (startVertex >= 0 && startVertex < n) {
        if (choice == 1) {
            printf("DFS starting from vertex %d: ", startVertex);
            dfs(graph, visited, startVertex);
            printf("\n");
        } else if (choice == 2) {
            bfs(graph, startVertex);
        } else {
            printf("Invalid choice! Please enter 1 for DFS or 2 for BFS.\n");
        }
    } else {
        printf("Invalid vertex! Please enter a valid vertex between 0 and %d.\n", n-1);
    }

    return 0;
}
