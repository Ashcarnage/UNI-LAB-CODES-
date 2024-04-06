#include<stdio.h>
#include<string.h>
#define max_len 256

void horspool(char *text, char *pattern){
    int m =  strlen(pattern);
    int n = strlen(text);
    int d = max_len;
    int shift[d];
    // initializing the shift table
    for (int i = 0; i<d ;i++){
        shift[i] = m;
    }
    // making the shift table 
    for(int i = 0;i<m;i++){
        shift[pattern[i]] -= 1;
    }
    int i = m-1;
    int flag = 1;
    while(i<n){
        int j = 0;
        while(j<m && text[i-j]== pattern[m-j-1]) {
            // printf("%c = %c\n",text[i-j],pattern[m-j-1]);
            // printf("%d \n",j);
            j++;
        }
        //printf("length of m = %d, j = %d\n",m,j);
        if(j==m){
            printf("Successful search at start index : %d \n",i-m+1);
            flag = 0;
            break;

        }
        else{
            // printf("%c \n",text[i-j]);
            // printf("shift[%c] = %d \n",text[i-(j)],shift[text[i-(j)]]);
            i += shift[text[i-j]];
            // printf("i = %d\n",i);
        }
    }
    if(flag) printf("String not found");

}




int main(){
    char text[] = "CABASCDABABDABACDABABCABAB";
    char pattern[]="ABAB";
    horspool(text, pattern);
}