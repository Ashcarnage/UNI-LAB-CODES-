#include<stdio.h>
#include<stdlib.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int l, int h){
    int piviot = a[l];
    int i = l+1;
    int j = h-1;
    while(!(i>=j)){
        while(piviot>a[i] && i<h-1)++i;
        while(a[j]>piviot && j>0)--j;
        swap(&a[i],&a[j]);
        i++;
    }
    swap(&a[--i],&a[j]);
    swap(&a[l],&a[j]);
    return j;
}

void quick_sort(int *a,int l, int h){
    if(l<h){
        int s = partition(a,l,h);
        quick_sort(a,l,s);
        quick_sort(a,s+1,h);
    }
}

void display(int *a,int n){
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int arr [] = {12,18,2,20,9,5,6,7};
    int n = 8;
    display(arr,n);
    quick_sort(arr,0,n);
    display(arr,n);
}
