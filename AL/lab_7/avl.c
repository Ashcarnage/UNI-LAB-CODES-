#include<stdio.h>
#include<stdlib.h>

typedef struct _{
    int data;
    struct _ *right;
    struct _ *left;

}node;

int max(int a, int b){
    return (a>b)? a:b;
}

int height(node *root){
    if(root){
        return(max(height(root->left),height(root->right))+1);
    }
    return 0;
}

node* createNode(int data){
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left=newNode->right = NULL;
    return newNode;
}

int balfac(node *root){
    return (height(root->left)-height(root->right));
}

node* leftrotate(node *x){
    node *y = x->right;
    node *z = y->left;

    y->left = x;
    x->right = z;

    return y;
}

node* rightrotate(node *x){
    node *y = x->left;
    node *z = y->right;

    y->right = x;
    x->left = z;
    
    return y;
}

node* InsertVal(node * root, int item){
    if(!root){
        node *newNode = createNode(item);
        return newNode;
    }
    if(item>root->data){
        root->right = InsertVal(root->right,item);
    }
    else if(item<root->data){
        root->left = InsertVal(root->left,item);
    }
    else return root;

    int bal = balfac(root);

    if(bal>1 && item<root->left->data){
        root = rightrotate(root);
    }
    if(bal>1 && item>root->left->data){
        root->left = leftrotate(root->left);
        root = rightrotate(root);
    }
    if(bal<-1 && item>root->right->data){
        root = leftrotate(root);
    }
    if(bal<-1 && item<root->right->data){
        root->right = rightrotate(root->right);
        root = leftrotate(root);
    }
    return root;
}

node* createAvl(){
    int n,data;
    node* root = NULL;
    printf("Enter the size of the avl tree : ");
    scanf("%d",&n);
    printf("Enter elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root = InsertVal(root,data);
    }
    return root;
}

void preorder(node *root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    node *root = createAvl();
    preorder(root);
}
