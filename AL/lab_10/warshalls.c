#include<stdio.h>
#include<stdlib.h>

void Warshall_algo(int arr[][4], int n){
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n ; i++){
            for(int j =0; j<n; j++){
                arr[i][j] = arr[i][j]||(arr[i][k] && arr[k][j]);
                printf("%d ",arr[i][j]);

            }
        printf("\n");
        }
    printf("\n");
    }
}

void prnMat(int arr[][4], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
    printf("\n");
    }
}

int main(){

    int adjMat[][4] = {{0,0,1,0},
                      {0,0,0,1},
                      {0,1,0,0},
                      {0,0,1,0}
                     };
    Warshall_algo(adjMat,4);
    prnMat(adjMat,4);

}