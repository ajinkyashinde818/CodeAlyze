#include <stdio.h>

int main(void) {
    int N, K; char S[10]; 
    scanf("%d%s%d", &N, S, &K);
    char base = S[K - 1];
    for (int i = 0; i < N; i++)
    {
        if (S[i] != base) S[i] = '*';
    }
    printf("%s\n", S);

    return 0;
}
