#include<stdio.h>
#include<stdlib.h>
#define max_ver 100
typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct g{
    int vertices;
    Node **AdjList; 
    int visited[max_ver];
}Graph;

Node* createNode(int val){
    Node *newnode = malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->data = val;
    return newnode;
}

Graph* createGraph(int vertices){
    Graph *graph = malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->AdjList = malloc(vertices*sizeof(Node));
    for(int i = 0;i<vertices;i++){
        graph->AdjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph *graph,int src, int des){
    Node * newNode = createNode(des);
    newNode->next = graph->AdjList[src];
    graph->AdjList[src] = newNode;
}

void BFS(Graph * graph, int startVertex){
    int queue[max_ver];
    int front=-1, rear = -1;
    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;
    while(front!=rear){
        startVertex = queue[++front];
        printf("%d ",startVertex);
        Node *temp = graph->AdjList[startVertex];
        while(temp){
            if(!graph->visited[temp->data]){
                graph->visited[temp->data] = 1;
                queue[++rear] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main(){
    int vertices = 10;
    Graph *graph = createGraph(10);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    BFS(graph,0);


}

