#include<stdio.h>

int main(void){

    int N,K,i;
    char S[10],ans[10],c[1];

    scanf("%d",&N);
    scanf("%s",S);
    scanf("%d",&K);

    for(i = 0;i < N;i++){
        if(S[i] != S[K - 1]){
            S[i] = '*';
        }else{
            continue;
        }
    }

    printf("%s",S);

    return 0;
}
