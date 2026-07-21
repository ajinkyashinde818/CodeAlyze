#include <stdio.h>
int main(void){
    // Your code here!
    int N;
    scanf("%d", &N);
    char S[N+1];
    scanf("%s", S);
    int K;
    scanf("%d", &K);
    
    char target = S[K-1];
    int i;
    for(i = 0; i < N; i++){
        if(target != S[i]){
            putchar('*');
        }else{
            putchar(S[i]);
        }
    }
    putchar('\n');
    
    return 0;
}
