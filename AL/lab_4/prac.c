#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}node;

node* createNode(int value){
    node * newNode  = malloc(sizeof(node));
    newNode->data=value;
    newNode->left = newNode->right=NULL;
    return newNode;
}

int countNodes(node * root){
    if(root==NULL)return 0;
    return (1+countNodes(root->left)+countNodes(root->right));
}

node* GenerateTree(node * root,int val){
    if (!root){
        return createNode(val);
    }
    else{
        if(root->data>val){
            root->left = GenerateTree(root->left,val);
        }
        else if(root->data<val){
            root->right = GenerateTree(root->right,val);
        }
        else{
            printf("please enter a unique number... \n");
        }
    }
    return root;
}

int main(){
    int maxN = 10;
    node* root = NULL;
    int n;
    for(int i = 0;i<maxN;i++){
        printf("Enter value for node %d  : ",i+1);
        scanf("%d",&n);
        root = GenerateTree(root,n);
    }
    printf("FUNCTION COUNT  : %d ",countNodes(root));
}