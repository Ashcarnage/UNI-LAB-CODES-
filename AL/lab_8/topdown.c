#include<stdio.h>
#include<stdlib.h>
#define max_size 100

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void topDown(int arr[], int i){
    int parentIndx;
    if (i%2==0) parentIndx = i/2-1;
    else parentIndx = i/2;
    if (!(parentIndx>=0)){
        return;
    }
    if(arr[parentIndx]<arr[i]){
        swap(&arr[parentIndx],&arr[i]);
        topDown(arr,parentIndx);
    }
}

void maxHeap(int arr[],int n){
    for(int i = 0;i<n;i++){
        topDown(arr,i);
    }
}

void prntHeap(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[max_size];
    int n;
    printf("Enter the size of the heap : ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Original array : ");
    prntHeap(arr,n);
    maxHeap(arr,n);
    printf("Top down max heap : ");
    prntHeap(arr,n);
}
