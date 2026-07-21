#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    char S[N+1];
    int K;
    scanf("%s %d", S, &K);
    S[N] = '\0';
    char x = S[K-1];
    for(int i=0;i<N;i++){
        if((S[i]-x)!=0){
            S[i] = '*';
        }
    }
    printf("%s", S);
    return 0;
}
