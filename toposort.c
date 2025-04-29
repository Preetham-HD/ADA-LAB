#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n; 
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    push(v);
}

void toposort() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    top = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    printf("Topological Sort Order:\n");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int e, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    toposort();

    return 0;
}



/*
Sample Input/Output:

Enter number of vertices: 6
Enter number of edges: 6
Enter edges (u v) where u and v are vertex indices (0 to 5):
5 2
5 0
4 0
4 1
2 3
3 1
Topological Sort Order:
4 5 2 3 1 0 
*/
