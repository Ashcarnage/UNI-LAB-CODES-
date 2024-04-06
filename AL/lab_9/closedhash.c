#include<stdio.h>
#include<stdlib.h>
#define n 10

int h[n];

void insert(int key){
    int i;
    int hkey = key%10;
    for(i=0;i<n;i++){
        int index = (hkey+i)%10;
        if (!h[index]) {
            h[index] = key;
            break;
        }
    }
    if(i==10) printf("Value couldn't be inserted!!\n");
}

int search(int srch){
    int i;
    int hkey = srch %10;
    for(i=0;i<n;i++){
        int index = (hkey+i)%10;
        if(srch==h[index]){
            return index;
        }
    }
    if(i==10) printf("Search item not found!!\n");
    return -1;
}

void display(){
    for(int i=0;i<n;i++){
        printf("%d ",h[i]);
    }
    printf("\n");
}

int main(){
    int l[] = {20,30,10,22,45,46,37,28,13,11};
    for(int i = 0;i<n;i++){
        insert(l[i]);
    }
    int ele = search(13);
    display();
    printf("The element is found at index %d\n",ele);

}