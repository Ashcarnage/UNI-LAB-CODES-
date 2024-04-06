#include<stdio.h>
#include<stdlib.h>

int getMax(int a, int b){
    return (a>b)? a : b;
}

int** NapSac(int w[] , int p[], int n, int m){
    int **mat = (int **)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (i==0||j==0){
                mat[i][j] = 0;
            }
            else if (w[i]<=j){
                mat[i][j] = getMax(mat[i-1][j],p[i] + mat[i-1][j-w[i]]);
            }
            else mat[i][j] = mat[i-1][j];
        }
    }
    return mat;  
}

void prnMat(int **mat,int n, int m){
    for(int i = 0;i<m;i++){
        for(int j = 0; j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int w[] =  {0,2,3,4,5};
    int p[] = {0,1,2,5,6};
    int n = 9;
    int m = sizeof(p)/sizeof(int);
    int **arr;
    arr= NapSac(w,p,n,m);
    int i=m-1,j=n-1;
    printf("napsack selected items : \n");
    while(i!=0 && j!=0){
        if(arr[i][j]!=arr[i-1][j]){
            printf("item no %d \n",i);
            j = j-w[i];
        }
        i--;
    }
    //prnMat(arr,n,m);

}