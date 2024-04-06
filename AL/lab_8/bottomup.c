#include<stdio.h>
#include<stdlib.h>
#define max_size 100

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftup(int arr[],int n,int i){
    if(i>=n-1){
        return;
    }
    int largestValue = i;
    int leftchildvalue = i*2+1;
    int rightchildvalue = i*2+2;

    if (arr[leftchildvalue]>arr[largestValue]){
        largestValue = leftchildvalue;
    }
    else if (arr[rightchildvalue]>arr[largestValue]){
        largestValue = rightchildvalue;
    }
    if(largestValue!=i){
        swap(&arr[largestValue],&arr[i]);
        siftup(arr,n,largestValue);
    }
}

void bottomUpHeap(int arr[],int n){
    for(int i = (n-1)/2-1;i>=0;i--){
        siftup(arr,n,i);
    }
}

void prntheap(int arr[], int n){
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
    printf("Enter elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Originial array : ");
    prntheap(arr,n);
    bottomUpHeap(arr,n);
    printf("Heapified array : ");
    prntheap(arr,n);
}