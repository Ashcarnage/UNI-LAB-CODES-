#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node *next;
};

// Structure to represent an adjacency list graph
struct Graph {
    int numVertices;
    struct Node** adjLists; // Array of pointers to adjacency lists
    int visited[MAX_VERTICES]; // Boolean array to store visited nodes
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with numVertices vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Create an adjacency list for each vertex
    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    for (int i = 0; i < numVertices; ++i) {
        graph->adjLists[i] = NULL;
        graph->visited[i]=0;
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the destination
    struct Node* newNode = createNode(dest);

    // Add the node to the adjacency list of source
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        struct Node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp) {
            printf("-> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to perform BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Mark the current node as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    // Loop as long as queue is not empty
    while (front != rear) {
        // Dequeue a vertex from queue
        startVertex = queue[++front];

        // Print the dequeued vertex
        printf("%d ", startVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node* temp = graph->adjLists[startVertex];

        // Mark adjacent nodes as visited and enqueue them if not already visited
        while (temp) {
            if (!graph->visited[temp->data]) {
                graph->visited[temp->data] = 1;
                queue[++rear] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Perform BFS traversal from vertex 0
    printf("\nBFS traversal starting from vertex 0: ");
    BFS(graph, 0);

    return 0;
}
