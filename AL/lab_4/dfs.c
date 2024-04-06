#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct graph{
    int vertices;
    Node ** adjList; 
}Graph;

Node* createNode(int data){
    Node * newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices){
    Graph * g = malloc(sizeof(Graph));
    g->vertices = vertices;
    g->adjList = malloc(vertices*sizeof(Node));

    for(int i= 0;i<vertices;i++){
        g->adjList[i] = NULL;
    }
    return g;
}

// Undirected Graph
void addEdge(Graph *g,int src, int des){
    Node *newNode = createNode(des);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjList[des];
    g->adjList[des] = newNode;
}

void DFSutil(Graph* g, int vertex, int visited[]){
    visited[vertex] = 1;
    printf("%d ",vertex);
    Node * temp = g->adjList[vertex];
    while(temp!=NULL){
        if(!visited[temp->data]){
            DFSutil(g,temp->data,visited);
        }
        temp = temp->next;
    }
}

void DFS(Graph *g, int startVertex){
    int* visited = malloc(g->vertices* sizeof(int)); 
    for (int i = 0;i< g->vertices;i++){
        visited[i] = 0;
    }
    DFSutil(g,startVertex,visited);
}

int main() {
    Graph* g = createGraph(5);

    // Add edges to the graph
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 0, 3); // Additional edge from 0 to 3

    printf("DFS starting from vertex 0:\n");
    DFS(g, 0);
    return 0;
}


