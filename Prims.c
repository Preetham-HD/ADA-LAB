#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

int minval(int key[], bool visited[])
{
  int mini = INT_MAX;
  int mini_index;

  for (int i = 0; i < V; i++)
  {
    if (visited[i] == false && key[i] < mini)
    {
      mini = key[i];
      mini_index = i;
    }
  }
  return mini_index;
}


void primsAlgorithm(int graph[V][V])
{

  int parent[V];
  parent[0] = -1; 

  int key[V];
  bool visited[V];
  for (int i = 0; i < V; i++)
  {
    key[i] = INT_MAX;
    visited[i] = false;
  }
  key[0] = 0;

 

  for (int i = 0; i < V; i++)
  {
    int u = minval(key, visited);
   
    visited[u] = true;

    for (int j = 0; j < V; j++)
    {
      if (graph[u][j] && visited[j] == false && graph[u][j] < key[j])
      {
        parent[j] = u;        
        key[j] = graph[u][j]; 
      }
    }
  }
  printminispantree(parent, graph);
}

void printminispantree(int parent[], int graph[V][V])
{
  printf("Edge   Weight\n");
  for (int i = 1; i < V; i++)
  {
    printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
  }
}

int main()
{
    int  n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=n; j++){
            printf("Enter the value of edge %d %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Hence the minimum spannig tree is: ");
    primsAlgorithm(graph);

    
 
//   int graph[V][V] = {
//       {0, 2, 0, 6, 0},
//       {2, 0, 3, 8, 5},
//       {0, 3, 0, 0, 7},
//       {6, 8, 0, 0, 9},
//       {0, 5, 7, 9, 0}};
//   primsAlgorithm(graph);

// Hence the minimum spannig tree is: Edge   Weight
// 4 - 1    6
// 1 - 2    2
// 2 - 3    3
// 0 - 4    7

  return 0;
}
