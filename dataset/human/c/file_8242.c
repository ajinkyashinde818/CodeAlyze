#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void){
    int N, K;
    scanf("%d", &N);
    char S[N], s;
    scanf("%s", S);
    scanf("%d", &K);
    s = S[K - 1];
    for (int i = 0; i < N; i++) {
        if (S[i] != s) {
            S[i] = '*';
        }
    }
    printf("%s", S);
    return 0;
}
