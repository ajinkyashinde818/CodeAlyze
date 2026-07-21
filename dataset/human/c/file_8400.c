#include<stdio.h>
#include<string.h>

int main(void){
    int N, K;
    
    
    scanf("%d", &N);
    char S[N];
    scanf("%s", S);
    scanf("%d", &K);

    for(int i=0; i<N; i++){
        if(S[i] != S[K-1]){
            S[i] = '*';
        }
    }
    printf("%s\n", S);
    
    return 0;
}
