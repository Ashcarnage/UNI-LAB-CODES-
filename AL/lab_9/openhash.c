#include<stdio.h>
#include<stdlib.h>

typedef struct _ {
    int data;
    struct _ *next;
}node;

node** chaining(){
    node **chain =  malloc(10*sizeof(node));
    for(int i =0;i<10;i++){
        chain[i] = NULL;
    }
    return chain;
}

node** insert(int value,node **chain){
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    int key = value%10;
    if(chain[key]==NULL)
        chain[key]=newNode;
    else{
        node *temp = chain[key];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return chain;
}

void printhash(node **chain){
    for(int i =0; i<10;i++){
        node *temp = chain[i];
        printf("chain[%d] ->",i);
        while(temp){
            printf("%d ->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    node **chain = chaining();
    insert(7,chain);
    insert(0,chain);
    insert(3,chain);
    insert(10,chain);
    insert(4,chain);
    insert(5,chain);
    printhash(chain);
}
