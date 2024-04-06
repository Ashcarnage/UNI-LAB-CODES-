#include<stdio.h>
#define inf 1000
#define n 4

int getmin(int a, int b){
    return (a<b)? a : b;
}

void floyds_algo(int graph[][n]){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                graph[i][j] = getmin(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    } 
}

void prnMat(int mat[][n]){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int value;
            printf("Enter the path value from node %d to %d  (use INF for no connection): ",i+1,j+1);
            scanf("%d",&value);
            if (value==-1){
                arr[i][j] = inf;
            }
            else arr[i][j] = value;
        }
    }
    floyds_algo(arr);
    prnMat(arr);
}