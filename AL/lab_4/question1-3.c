#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    int indegree;
    struct Node *next;
} node;

typedef struct graph{
    node *adj_list[20];
    bool visited[20];
} Graph;

node* createNode(int val){
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->indegree = 0;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int n){
    Graph * g = malloc(sizeof(Graph));
    for (int i = 0;i<n;i++){
        g->adj_list[i] = malloc(sizeof(node));
        g->visited[i] = false;
    }
    return g;
}

void add_edge(Graph * graph,int src,int dest){
    node * Newnode = createNode(dest);
    node* curr = graph->adj_list[src];
    while(curr!=NULL && curr->indegree!=0){
        curr = curr->next;
    }
    curr = Newnode;
    graph->adj_list[dest]->indegree++;
}

void dfs(Graph *graph,int vertex,int *queue){
    node * temp = graph->adj_list[vertex];
    graph->visited[vertex] = true;
    while(temp!=NULL){
        int dest = temp->data;
        temp->indegree--;
        if(!graph->visited[dest]){
            if(temp->indegree==0){
                *(queue+1) = dest;
                printf("%d",*(queue+1));
                dfs(graph,dest,queue);
            }
        }
        temp = temp->next;
    }
}

int* topological_sort(Graph *graph,int nodes){
    int *queue;
    for(int n = 0; n<nodes;n++){
        if (graph->adj_list[n]->indegree==0){
            dfs(graph,n,queue);
        } 
    }
    return queue;
}
int main(){
    int n,i=0;
    printf("Enter the number of nodes in the graph : ");
    scanf("%d",&n);
    Graph * graph = createGraph(n);
    do{
        int dest;
        printf("Enter the destination node for the source node %d : ",i);
        scanf("%d",&dest);
        if (dest!=-1 && dest!=-2)
            add_edge(graph,i,dest);
        if (dest==-2)
            i++;
    }while(i<n);

    int* queue = topological_sort(graph,n);
    for(int pos = 0;pos<sizeof(queue)/4;pos++){
        printf("%d\n",queue[pos]);
    }
}
