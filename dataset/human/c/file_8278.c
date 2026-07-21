#include <stdio.h>

int main(void){
    int N,K,n;
    char S[20];

    scanf("%d",&N);
    scanf("%s",S);
    scanf("%d",&K);

    for(n=0 ; n < N ; n++){
        if(S[n] != S[K-1]){
            S[n] = '*';
        }
    }
    printf("%s\n",S);
    return 0;
}
