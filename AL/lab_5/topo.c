#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 6


int adj[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;

// Function to add an edge to the adjacency matrix
void addEdge(int u, int v) {
  adj[u][v] = 1;
}

// Function to mark a vertex as visited
void setVisited(int v) {
  visited[v] = true;
}

// Function to check if a vertex is visited
bool isVisited(int v) {
  return visited[v];
}

// Function to push a vertex onto the stack
void push(int v) {
  stack[++top] = v;
}

// Function to pop a vertex from the stack
int pop() {
  return stack[top--];
}

// A recursive function to perform DFS traversal
void DFS(int v) {
  setVisited(v);

  // Recur for all unvisited adjacent vertices
  for (int i = 0; i < MAX_VERTICES; i++) {
    if (adj[v][i] == 1 && !isVisited(i)) {
      DFS(i);
    }
  }

  // Push the current vertex to the stack after all its adjacent vertices are explored
  push(v);
}

// Function to perform topological sort
void topologicalSort() {
  for (int i = 0; i < MAX_VERTICES; i++) {
    if (!isVisited(i)) {
      DFS(i);
    }
  }

  // Print contents of stack
  printf("Topological Sort Order: ");
  while (top != -1) {
    printf("%d ", pop());
  }
  printf("\n");
}

int main() {
  // Example graph
  addEdge(2, 3);
  addEdge(3, 1);
  addEdge(5, 2);
  addEdge(5, 0);
  addEdge(4, 0);
  addEdge(4, 1);

  topologicalSort();

  return 0;
}