#include<stdio.h>
int main(){
    char S[10];
    int N,K;
    scanf("%d",&N);
    scanf("%s",S);
    scanf("%d",&K);
    for(int i=0;i<N;i++){
        if(S[i]!=S[K-1]){
            S[i]='*';
        }
    }
    printf("%s\n",S);
}
