#include<stdio.h>
#include<stdlib.h>

void Merge(int *arr,int left , int mid, int right){
    int n1 = mid-left+1;
    int n2 = right-mid;
    int arr1[n1],arr2[n2];
    for(int i = 0;i<n1;i++){
        arr1[i] = arr[left+i];
    }
    for(int j = 0;j<n2;j++){
        arr2[j] = arr[mid+1+j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while(i<n1 && j<n2){
        if (arr1[i]<=arr2[j]){
            arr[k] = arr1[i++];
        }
        else{
           arr[k] = arr2[j++];
        }
        k++;
    }
    while(i<n1){
        arr[k++] = arr1[i++];
    }
    while(j<n2){
        arr[k++] = arr2[j++];
    }
}

void MergeSort(int *arr,int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}

void display(int *arr, int n){
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0]);
    display(arr,right);
    MergeSort(arr,left,right);
    display(arr,right);
}