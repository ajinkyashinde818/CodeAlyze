#include<stdio.h>

int main(void){
    int N,K;
    char S[10]={};
    scanf("%d",&N);
    scanf("%s",S);
    scanf("%d",&K);
    char c = S[K-1];
    for(int i=0;i<N;i++){
        if(c==S[i]){
            printf("%c",S[i]);
        }else{
            printf("*");
        }
    }
    return 0;
}
